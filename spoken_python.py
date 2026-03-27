#!/usr/bin/env python3
"""
Spoken Python Preprocessor v0.1
Transpiles Spoken Python (.spk) to Python (.py)
"""

import sys
import re
from dataclasses import dataclass


@dataclass
class TranspilerState:
    indent_level: int = 0
    lines_out: list = None

    def __post_init__(self):
        if self.lines_out is None:
            self.lines_out = []

    @property
    def indent(self):
        return "    " * self.indent_level


# Operator mappings (order matters — longer phrases first)
OPERATOR_MAP = [
    # Comparison — sentence forms first
    ("is not equal to", "!="),
    ("is equal to", "=="),
    ("is greater than or equal to", ">="),
    ("is less than or equal to", "<="),
    ("is greater than", ">"),
    ("is less than", "<"),
    # Comparison — terse forms
    ("greater than or equal to", ">="),
    ("less than or equal to", "<="),
    ("not equals", "!="),
    ("equals", "=="),
    ("greater than", ">"),
    ("less than", "<"),
    # Arithmetic
    ("to the power of", "**"),
    ("integer divided by", "//"),
    ("divided by", "/"),
    ("modulo", "%"),
    ("times", "*"),
    ("concatenate", "+"),
    ("plus", "+"),
    ("minus", "-"),
    # Terse assignment (legacy support)
    ("times assign", "*="),
    ("plus assign", "+="),
    ("minus assign", "-="),
    ("assign", "="),
]


def preprocess_stt(source):
    """Clean up common STT artifacts before transpilation.

    - Periods → sentence boundaries → split into separate lines
    - Preserves decimal numbers like 3.14
    - Commas before newlines → stripped
    - Multiple spaces → single space
    """
    lines = []
    for line in source.splitlines():
        if not line.strip():
            lines.append("")
            continue
        # Split on periods followed by space or end-of-line (sentence boundaries)
        # Preserves decimals like 3.14 (period followed by digit, not space)
        parts = re.split(r'\.(?=\s|$)', line)
        for part in parts:
            cleaned = part.strip()
            # Strip trailing commas/periods
            cleaned = cleaned.rstrip(".,;")
            # Collapse multiple spaces
            cleaned = re.sub(r"  +", " ", cleaned)
            if cleaned:
                lines.append(cleaned)
    return "\n".join(lines)


def process_let_assignment(text):
    """Process 'let X be Y' → 'X = Y'"""
    match = re.match(r"^let\s+(\w+)\s+be\s+(.+)$", text.strip())
    if match:
        var = match.group(1)
        value = match.group(2)
        return f"{var} = {value}"
    return None


def process_augmented_assignment(text):
    """Process natural augmented assignments:
        increase X by Y   → X += Y
        decrease X by Y   → X -= Y
        multiply X by Y   → X *= Y
        divide X by Y     → X /= Y
    """
    patterns = [
        (r"^increase\s+(\w+)\s+by\s+(.+)$", "+="),
        (r"^decrease\s+(\w+)\s+by\s+(.+)$", "-="),
        (r"^multiply\s+(\w+)\s+by\s+(.+)$", "*="),
        (r"^divide\s+(\w+)\s+by\s+(.+)$", "/="),
    ]
    stripped = text.strip()
    for pattern, op in patterns:
        match = re.match(pattern, stripped)
        if match:
            var = match.group(1)
            value = match.group(2)
            return f"{var} {op} {value}"
    return None


def replace_operators(text):
    """Replace spoken operators with Python operators."""
    for spoken, python_op in OPERATOR_MAP:
        text = text.replace(spoken, python_op)
    return text


def parse_string_literal(text):
    """Extract string literal from text, returning (string_expr, remaining_text).

    String literal runs from 'string literal' keyword to end of line
    or next recognized keyword boundary.
    """
    match = re.search(r"\bstring literal\b\s*", text)
    if not match:
        return text, ""

    before = text[: match.start()]
    after = text[match.end() :]

    # Find where the string content ends — at next keyword or end of line
    # For now, take the rest of the segment until a known keyword
    end_keywords = [
        "string literal",
        "open ",
        "close ",
        "call ",
        "assign",
        "equals",
        "plus",
        "minus",
        "times",
        "divided by",
        "greater than",
        "less than",
        "concatenate",
        "key ",
        "value ",
    ]

    end_pos = len(after)
    for kw in end_keywords:
        idx = after.find(kw)
        if idx > 0 and idx < end_pos:
            end_pos = idx

    string_content = after[:end_pos].strip()
    remaining = after[end_pos:]

    return before + f'"{string_content}"' + remaining, ""


def process_string_literals(text):
    """Process all string literals in a line."""
    result = text
    safety = 0
    while "string literal" in result and safety < 10:
        result, _ = parse_string_literal(result)
        safety += 1
    return result


def process_f_string(text):
    """Process f-string literals."""
    pattern = r"\bf string literal\b\s*"
    match = re.search(pattern, text)
    if not match:
        return text

    before = text[: match.start()]
    after = text[match.end() :]

    # Replace open expression / close expression with { }
    after = re.sub(r"\bopen expression\b", "{", after)
    after = re.sub(r"\bclose expression\b", "}", after)

    return before + 'f"' + after.strip() + '"'


def process_call(text):
    """Process function/method calls: call X with Y Z → X(Y, Z)
    Handles both standalone and inline calls.
    """
    # Process all calls from right to left (innermost first)
    result = process_all_calls(text.strip())
    return result


def process_all_calls(text):
    """Recursively process all 'call' expressions in text."""
    # Find the rightmost 'call' to process innermost calls first
    # Pattern: call <func> with <args> OR call <func> (no args)

    # Try 'call X with Y' pattern — find rightmost
    last_call_idx = text.rfind("call ")
    if last_call_idx == -1:
        return text

    before = text[:last_call_idx]
    after = text[last_call_idx:]

    # Try with args
    match = re.match(r"call\s+(\S+(?:\s+dot\s+\S+)?)\s+with\s+(.+)", after)
    if match:
        func = match.group(1).replace(" dot ", ".")
        args_raw = match.group(2).strip()
        args_raw = process_string_literals(args_raw)
        args_raw = replace_operators(args_raw)
        args = smart_split_args(args_raw)
        replacement = f"{func}({', '.join(args)})"
        result = before + replacement
        # Recurse for any remaining calls
        if "call " in result:
            result = process_all_calls(result)
        return result

    # Try no args
    match2 = re.match(r"call\s+(\S+(?:\s+dot\s+\S+)?)\s*$", after)
    if match2:
        func = match2.group(1).replace(" dot ", ".")
        replacement = f"{func}()"
        result = before + replacement
        if "call " in result:
            result = process_all_calls(result)
        return result

    # No match — might be partial, return as-is
    return text


def smart_split_args(args_text):
    """Split arguments, respecting quoted strings."""
    args = []
    current = ""
    in_quotes = False

    for char in args_text:
        if char == '"' and not in_quotes:
            in_quotes = True
            current += char
        elif char == '"' and in_quotes:
            in_quotes = False
            current += char
        elif char == " " and not in_quotes:
            if current.strip():
                args.append(current.strip())
            current = ""
        else:
            current += char

    if current.strip():
        args.append(current.strip())

    return args


def process_index(text):
    """Process indexing: index X at Y → X[Y]"""
    pattern = r"\bindex\s+(\S+)\s+at\s+(\S+)"
    return re.sub(pattern, r"\1[\2]", text)


def process_slice(text):
    """Process slicing: slice X from Y to Z → X[Y:Z]"""
    pattern = r"\bslice\s+(\S+)\s+from\s+(\S+)\s+to\s+(\S+)"
    return re.sub(pattern, r"\1[\2:\3]", text)


def process_list_literal(text):
    """Process list of X Y Z → [X, Y, Z]"""
    pattern = r"\blist of\s+(.+)"
    match = re.match(pattern, text.strip())
    if match:
        items = match.group(1).strip().split()
        return "[" + ", ".join(items) + "]"
    return text


def process_decorator(text):
    """Process decorator X → @X"""
    pattern = r"^decorator\s+(.+)"
    match = re.match(pattern, text.strip())
    if match:
        return "@" + match.group(1).strip()
    return text


def process_comment(text):
    """Process comment X → # X"""
    pattern = r"^comment\s+(.+)"
    match = re.match(pattern, text.strip())
    if match:
        return "# " + match.group(1).strip()
    return text


# ─── Enchantments ───────────────────────────────────────────────────────────

def process_enchant_string(body):
    """enchant with string: builds an f-string from a template with variable slots.

    Grammar:
        enchant with string <text with {varnames} embedded>
        Words that are variable names get wrapped in {}, rest becomes literal text.

    To mark a variable: use 'variable <name>' or 'var <name>'
    Everything else is literal text.

    Examples:
        enchant with string hello variable name you are variable age years old
        → f"hello {name} you are {age} years old"

        enchant with string the result is variable x
        → f"the result is {x}"
    """
    parts = []
    words = body.split()
    i = 0
    while i < len(words):
        if words[i] in ("variable", "var") and i + 1 < len(words):
            parts.append("{" + words[i + 1] + "}")
            i += 2
        else:
            parts.append(words[i])
            i += 1
    return 'f"' + " ".join(parts) + '"'


# Regex mini-language mappings (order: longer phrases first)
REGEX_MAP = [
    # Quantifiers
    ("one or more of", "+"),
    ("zero or more of", "*"),
    # "optional" handled specially in the parser — applies ? to next token
    ("exactly", "{"),       # handled specially
    ("between", "{"),       # handled specially

    # Character classes
    ("any digit", r"\d"),
    ("any digits", r"\d+"),
    ("any letter", r"[a-zA-Z]"),
    ("any letters", r"[a-zA-Z]+"),
    ("any word character", r"\w"),
    ("any word characters", r"\w+"),
    ("any whitespace", r"\s"),
    ("any character", "."),
    ("any characters", ".*"),

    # Anchors
    ("start of string", "^"),
    ("end of string", "$"),
    ("word boundary", r"\b"),

    # Groups
    ("open group", "("),
    ("close group", ")"),
    ("named group", "(?P<"),   # handled specially
    ("either", "(?:"),         # handled specially — starts alternation group
    ("or", "|"),

    # Escapes
    ("literal dot", r"\."),
    ("literal star", r"\*"),
    ("literal plus", r"\+"),
    ("literal open paren", r"\("),
    ("literal close paren", r"\)"),
    ("literal backslash", r"\\\\"),

    # Common patterns
    ("any of", "["),           # handled specially
    ("end any of", "]"),
    ("not any of", "[^"),      # handled specially
]


def process_enchant_rejection(body):
    """enchant with rejection: builds a regex pattern from spoken description.

    Grammar uses natural phrases that map to regex constructs.

    Examples:
        enchant with rejection start of string any digits literal dot any digits end of string
        → r"^\\d+\\.\\d+$"

        enchant with rejection any letters at literal dot any letters
        → r"[a-zA-Z]+@\\.[a-zA-Z]+"
    """
    words = body.split()
    result = []
    i = 0

    while i < len(words):
        matched = False

        # Try matching multi-word phrases (longest first)
        for phrase_len in range(5, 0, -1):
            if i + phrase_len > len(words):
                continue
            phrase = " ".join(words[i:i + phrase_len])

            # Special: "exactly N" → {N}
            if phrase_len >= 2 and words[i] == "exactly":
                try:
                    n = int(words[i + 1])
                    result.append("{" + str(n) + "}")
                    i += 2
                    matched = True
                    break
                except (ValueError, IndexError):
                    pass

            # Special: "between N and M" → {N,M}
            if phrase_len >= 4 and words[i] == "between":
                try:
                    n = int(words[i + 1])
                    if words[i + 2] == "and":
                        m = int(words[i + 3])
                        result.append("{" + str(n) + "," + str(m) + "}")
                        i += 4
                        matched = True
                        break
                except (ValueError, IndexError):
                    pass

            # Special: "named group X" → (?P<X>
            if phrase_len >= 3 and phrase.startswith("named group"):
                name = words[i + 2]
                result.append("(?P<" + name + ">")
                i += 3
                matched = True
                break

            # Special: "optional X" → X? (makes the NEXT token optional)
            if phrase_len == 1 and words[i] == "optional":
                # Peek ahead, process next token, append ? after it
                if i + 1 < len(words):
                    # Recursively process the next token to get its regex form
                    next_word = words[i + 1]
                    # Check if next word(s) form a known phrase
                    next_regex = None
                    for try_len in range(min(4, len(words) - i - 1), 0, -1):
                        next_phrase = " ".join(words[i + 1:i + 1 + try_len])
                        for spoken, regex in REGEX_MAP:
                            if next_phrase == spoken:
                                next_regex = regex
                                i += 1 + try_len
                                break
                        if next_regex:
                            break
                    if next_regex is None:
                        # It's a literal
                        literal_map = {"at": "@", "dash": "-", "underscore": "_",
                                       "space": " ", "colon": ":", "slash": "/", "hash": "#"}
                        next_regex = literal_map.get(next_word, next_word)
                        i += 2
                    result.append(next_regex + "?")
                    matched = True
                    break
                else:
                    result.append("?")
                    i += 1
                    matched = True
                    break

            # Special: "any of XYZ" → [XYZ]
            if phrase_len >= 2 and words[i] == "not" and i + 1 < len(words) and words[i + 1] == "any" and i + 2 < len(words) and words[i + 2] == "of":
                result.append("[^")
                i += 3
                matched = True
                break

            # Regular phrase lookup
            for spoken, regex in REGEX_MAP:
                if phrase == spoken:
                    result.append(regex)
                    i += phrase_len
                    matched = True
                    break
            if matched:
                break

        if not matched:
            # Pass through as literal (e.g. specific characters like "at" → @)
            word = words[i]
            # Common literal words
            literal_map = {
                "at": "@",
                "dash": "-",
                "underscore": "_",
                "space": " ",
                "colon": ":",
                "slash": "/",
                "hash": "#",
            }
            result.append(literal_map.get(word, word))
            i += 1

    pattern = "".join(result)
    return f'r"{pattern}"'


# Numpy/matrix operation mappings
NUMPY_OP_MAP = [
    # Must check longer phrases first
    ("transpose of", ".T"),          # handled specially
    ("inverse of", ""),              # handled specially — nope.linalg.inv()
    ("determinant of", ""),          # handled specially — nope.linalg.det()
    ("dot product", "@"),
    ("dot", "@"),
    ("cross product", ""),           # handled specially — nope.cross()
    ("element wise times", "*"),
    ("element wise divided by", "/"),
    ("element wise plus", "+"),
    ("element wise minus", "-"),
    ("matrix multiply", "@"),
]


def process_enchant_math(body):
    """enchant with math: builds numpy-style matrix expressions.

    Grammar:
        transpose of X         → X.T
        inverse of X           → nope.linalg.inv(X)
        determinant of X       → nope.linalg.det(X)
        X mat mul Y            → X @ Y
        X dot Y                → nope.dot(X, Y)
        X cross product Y      → nope.cross(X, Y)
        X element wise times Y → X * Y
        X element wise divided by Y → X / Y
        X element wise plus Y  → X + Y
        X element wise minus Y → X - Y
    """
    words = body.split()
    result_tokens = []
    i = 0

    while i < len(words):
        matched = False

        # "transpose of X"
        if i + 2 <= len(words) and words[i] == "transpose" and words[i + 1] == "of":
            operand = words[i + 2]
            result_tokens.append(operand + ".T")
            i += 3
            matched = True

        # "inverse of X"
        elif i + 2 < len(words) and words[i] == "inverse" and words[i + 1] == "of":
            operand = words[i + 2]
            result_tokens.append(f"nope.linalg.inv({operand})")
            i += 3
            matched = True

        # "determinant of X"
        elif i + 2 < len(words) and words[i] == "determinant" and words[i + 1] == "of":
            operand = words[i + 2]
            result_tokens.append(f"nope.linalg.det({operand})")
            i += 3
            matched = True

        # "cross product" — infix: X cross product Y → nope.cross(X, Y)
        elif i + 1 < len(words) and words[i] == "cross" and words[i + 1] == "product":
            left = result_tokens.pop() if result_tokens else "?"
            right = words[i + 2] if i + 2 < len(words) else "?"
            result_tokens.append(f"nope.cross({left}, {right})")
            i += 3
            matched = True

        # "mat mul" — infix: X mat mul Y → X @ Y
        elif i + 1 < len(words) and words[i] == "mat" and words[i + 1] == "mul":
            result_tokens.append("@")
            i += 2
            matched = True

        # "element wise times/divided by/plus/minus"
        elif i + 2 < len(words) and words[i] == "element" and words[i + 1] == "wise":
            op_word = words[i + 2]
            if op_word == "times":
                result_tokens.append("*")
                i += 3
                matched = True
            elif op_word == "plus":
                result_tokens.append("+")
                i += 3
                matched = True
            elif op_word == "minus":
                result_tokens.append("-")
                i += 3
                matched = True
            elif op_word == "divided" and i + 3 < len(words) and words[i + 3] == "by":
                result_tokens.append("/")
                i += 4
                matched = True

        # "dot" — infix: X dot Y → nope.dot(X, Y)
        elif words[i] == "dot":
            left = result_tokens.pop() if result_tokens else "?"
            right = words[i + 1] if i + 1 < len(words) else "?"
            result_tokens.append(f"nope.dot({left}, {right})")
            i += 2
            matched = True

        if not matched:
            result_tokens.append(words[i])
            i += 1

    return " ".join(result_tokens)


ENCHANTMENT_PROCESSORS = {
    "string": process_enchant_string,
    "rejection": process_enchant_rejection,
    "math": process_enchant_math,
}


def process_enchantment(text):
    """Process 'enchant with <type> <body>' lines."""
    match = re.match(r"^enchant with\s+(\w+)\s+(.+)$", text.strip())
    if not match:
        return text

    enchant_type = match.group(1)
    body = match.group(2)

    processor = ENCHANTMENT_PROCESSORS.get(enchant_type)
    if processor:
        return processor(body)

    return text  # Unknown enchantment — pass through


def transpile_line(line, state):
    """Transpile a single line of Spoken Python to Python."""
    stripped = line.strip()

    # Blank lines
    if not stripped:
        state.lines_out.append("")
        return

    # Comments
    if stripped.startswith("comment "):
        state.lines_out.append(state.indent + process_comment(stripped))
        return

    # Decorators
    if stripped.startswith("decorator "):
        state.lines_out.append(state.indent + process_decorator(stripped))
        return

    # --- Block openers ---

    # open function
    func_match = re.match(
        r"^open function\s+(\w+)(?:\s+parameters\s+(.+))?$", stripped
    )
    if func_match:
        name = func_match.group(1)
        params = func_match.group(2)
        param_str = ", ".join(params.split()) if params else ""
        state.lines_out.append(f"{state.indent}def {name}({param_str}):")
        state.indent_level += 1
        return

    # open class
    class_match = re.match(
        r"^open class\s+(\w+)(?:\s+inherits\s+(.+))?$", stripped
    )
    if class_match:
        name = class_match.group(1)
        parent = class_match.group(2)
        if parent:
            state.lines_out.append(f"{state.indent}class {name}({parent.strip()}):")
        else:
            state.lines_out.append(f"{state.indent}class {name}:")
        state.indent_level += 1
        return

    # open if
    if_match = re.match(r"^open if\s+(.+)$", stripped)
    if if_match:
        condition = process_expression(if_match.group(1))
        state.lines_out.append(f"{state.indent}if {condition}:")
        state.indent_level += 1
        return

    # open elif
    elif_match = re.match(r"^open elif\s+(.+)$", stripped)
    if elif_match:
        state.indent_level = max(0, state.indent_level - 1)
        condition = process_expression(elif_match.group(1))
        state.lines_out.append(f"{state.indent}elif {condition}:")
        state.indent_level += 1
        return

    # open else
    if stripped == "open else":
        state.indent_level = max(0, state.indent_level - 1)
        state.lines_out.append(f"{state.indent}else:")
        state.indent_level += 1
        return

    # open for
    for_match = re.match(r"^open for\s+(.+?)\s+in\s+(.+)$", stripped)
    if for_match:
        var = for_match.group(1)
        iterable = process_expression(for_match.group(2))
        state.lines_out.append(f"{state.indent}for {var} in {iterable}:")
        state.indent_level += 1
        return

    # open while
    while_match = re.match(r"^open while\s+(.+)$", stripped)
    if while_match:
        condition = process_expression(while_match.group(1))
        state.lines_out.append(f"{state.indent}while {condition}:")
        state.indent_level += 1
        return

    # open with
    with_match = re.match(r"^open with\s+(.+?)(?:\s+as\s+(\w+))?\s*$", stripped)
    if with_match:
        expr = process_expression(with_match.group(1))
        alias = with_match.group(2)
        if alias:
            state.lines_out.append(f"{state.indent}with {expr} as {alias}:")
        else:
            state.lines_out.append(f"{state.indent}with {expr}:")
        state.indent_level += 1
        return

    # open try
    if stripped == "open try":
        state.lines_out.append(f"{state.indent}try:")
        state.indent_level += 1
        return

    # open except
    except_match = re.match(
        r"^open except(?:\s+(\w+)(?:\s+as\s+(\w+))?)?\s*$", stripped
    )
    if except_match:
        state.indent_level = max(0, state.indent_level - 1)
        exc_type = except_match.group(1)
        exc_var = except_match.group(2)
        if exc_type and exc_var:
            state.lines_out.append(f"{state.indent}except {exc_type} as {exc_var}:")
        elif exc_type:
            state.lines_out.append(f"{state.indent}except {exc_type}:")
        else:
            state.lines_out.append(f"{state.indent}except:")
        state.indent_level += 1
        return

    # open finally
    if stripped == "open finally":
        state.indent_level = max(0, state.indent_level - 1)
        state.lines_out.append(f"{state.indent}finally:")
        state.indent_level += 1
        return

    # --- Block closers ---
    close_match = re.match(r"^close\s+(function|class|if|for|while|with|try)", stripped)
    if close_match:
        state.indent_level = max(0, state.indent_level - 1)
        return

    # --- Enchantments ---
    if stripped.startswith("enchant with "):
        result = process_enchantment(stripped)
        state.lines_out.append(f"{state.indent}{result}")
        return

    # --- Natural sentence forms ---

    # "let X be Y" → X = Y
    let_result = process_let_assignment(stripped)
    if let_result is not None:
        # Process the value side for calls, strings, enchantments, etc.
        eq_idx = let_result.index("=")
        var_part = let_result[:eq_idx + 1]
        val_part = let_result[eq_idx + 1:].strip()
        if "enchant with " in val_part:
            val_part = process_enchantment(val_part)
        else:
            val_part = process_expression(val_part)
        state.lines_out.append(f"{state.indent}{var_part} {val_part}")
        return

    # "increase/decrease/multiply/divide X by Y"
    aug_result = process_augmented_assignment(stripped)
    if aug_result is not None:
        aug_result = replace_operators(aug_result)
        state.lines_out.append(f"{state.indent}{aug_result}")
        return

    # --- Regular expressions ---
    result = process_expression(stripped)
    state.lines_out.append(f"{state.indent}{result}")


def process_expression(text):
    """Process a general expression line."""
    # Order matters here

    # Inline enchantments (e.g. "x assign enchant with string ...")
    if "enchant with " in text:
        enchant_idx = text.index("enchant with ")
        before = text[:enchant_idx]
        enchant_part = text[enchant_idx:]
        before = replace_operators(before)
        enchant_result = process_enchantment(enchant_part)
        return before + enchant_result

    # f-strings before regular strings
    if "f string literal" in text:
        text = process_f_string(text)

    # String literals
    if "string literal" in text:
        text = process_string_literals(text)

    # Function calls — anywhere in the line
    if "call " in text:
        text = process_all_calls(text)

    # Indexing and slicing
    text = process_index(text)
    text = process_slice(text)

    # List literals
    if text.strip().startswith("list of "):
        text = process_list_literal(text)

    # Operators
    text = replace_operators(text)

    return text


def transpile(source, stt_mode=False):
    """Transpile a full Spoken Python source to Python.

    Delegates to the new tokenizer/parser/codegen pipeline in transpiler.py.

    Args:
        source: Spoken Python source code
        stt_mode: If True, preprocess for STT artifacts (periods → newlines, etc.)
    """
    from transpiler import transpile as _transpile_new
    return _transpile_new(source, stt_mode=stt_mode)


def main():
    if len(sys.argv) < 2:
        print("Usage: python spoken_python.py <input.spk> [-o output.py] [--stt] [--run] [--dialect NAME]")
        sys.exit(1)

    input_file = sys.argv[1]
    stt_mode = "--stt" in sys.argv
    run_mode = "--run" in sys.argv

    # Dialect support
    dialect = None
    if "--dialect" in sys.argv:
        d_idx = sys.argv.index("--dialect")
        if d_idx + 1 < len(sys.argv):
            dialect = sys.argv[d_idx + 1]
        else:
            print("Error: --dialect requires a name (church_latin, toki_pona)", file=sys.stderr)
            sys.exit(1)

    with open(input_file) as f:
        source = f.read()

    # Translate dialect → English Spoken Python first
    if dialect:
        from dialects.preprocessor import translate_dialect
        source = translate_dialect(source, dialect)

    result = transpile(source, stt_mode=stt_mode)

    if "-o" in sys.argv:
        out_idx = sys.argv.index("-o")
        if out_idx + 1 < len(sys.argv):
            output_file = sys.argv[out_idx + 1]
            with open(output_file, "w") as f:
                f.write(result)
            print(f"Written to {output_file}")
        else:
            print("Error: -o requires a filename", file=sys.stderr)
            sys.exit(1)
    elif run_mode:
        exec(compile(result, input_file, "exec"))
    else:
        print(result)


if __name__ == "__main__":
    main()
