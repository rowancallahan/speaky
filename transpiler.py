"""
Spoken Python Transpiler — Tokenizer / Parser / Code Generator

Proper architecture replacement for the regex-based transpiler.
Pipeline: source text -> preprocess_stt -> tokenize -> parse -> generate
"""

from dataclasses import dataclass, field
from enum import Enum, auto
from typing import List, Optional, Union


# ============================================================================
# Token types
# ============================================================================

class TokenType(Enum):
    # Block openers/closers
    KEYWORD_OPEN = auto()
    KEYWORD_CLOSE = auto()

    # Block kinds
    KEYWORD_FUNCTION = auto()
    KEYWORD_CLASS = auto()
    KEYWORD_IF = auto()
    KEYWORD_ELIF = auto()
    KEYWORD_ELSE = auto()
    KEYWORD_FOR = auto()
    KEYWORD_WHILE = auto()
    KEYWORD_WITH = auto()
    KEYWORD_TRY = auto()
    KEYWORD_EXCEPT = auto()
    KEYWORD_FINALLY = auto()

    # Assignment / declaration
    KEYWORD_LET = auto()
    KEYWORD_BE = auto()
    KEYWORD_ASSIGN = auto()

    # Augmented assignment keywords
    KEYWORD_INCREASE = auto()
    KEYWORD_DECREASE = auto()
    KEYWORD_MULTIPLY = auto()
    KEYWORD_DIVIDE = auto()
    KEYWORD_BY = auto()

    # Operators (already resolved to Python symbols)
    OPERATOR = auto()

    # Function/method calls
    KEYWORD_CALL = auto()
    KEYWORD_DOT = auto()

    # Parameters and arguments
    KEYWORD_PARAMETERS = auto()
    # KEYWORD_WITH already defined above — used for both "with" blocks and call args
    KEYWORD_IN = auto()
    KEYWORD_AS = auto()
    KEYWORD_INHERITS = auto()

    # String literal markers
    KEYWORD_STRING_LITERAL = auto()
    KEYWORD_F_STRING_LITERAL = auto()
    KEYWORD_OPEN_EXPRESSION = auto()
    KEYWORD_CLOSE_EXPRESSION = auto()

    # Indexing/slicing
    KEYWORD_INDEX = auto()
    KEYWORD_SLICE = auto()
    KEYWORD_AT = auto()
    KEYWORD_FROM = auto()
    KEYWORD_TO = auto()

    # Collection literals
    KEYWORD_LIST_OF = auto()

    # Decorator / comment
    KEYWORD_DECORATOR = auto()
    KEYWORD_COMMENT = auto()

    # Enchantment
    KEYWORD_ENCHANT = auto()
    KEYWORD_ENCHANT_TYPE = auto()  # "string", "rejection", "math"

    # Pass-through Python keywords
    KEYWORD_RETURN = auto()
    KEYWORD_IMPORT = auto()
    KEYWORD_FROM_PY = auto()
    KEYWORD_PASS = auto()
    KEYWORD_BREAK = auto()
    KEYWORD_CONTINUE = auto()

    # Literals and identifiers
    IDENTIFIER = auto()
    NUMBER = auto()
    STRING_CONTENT = auto()

    # Catch-all for words that pass through
    WORD = auto()

    EOF = auto()


@dataclass
class Token:
    type: TokenType
    value: str
    position: int = 0  # word position in line


# ============================================================================
# AST Node types
# ============================================================================

@dataclass
class FunctionDef:
    name: str
    params: List[str]

@dataclass
class ClassDef:
    name: str
    parent: Optional[str]

@dataclass
class IfBlock:
    condition: str

@dataclass
class ElifBlock:
    condition: str

@dataclass
class ElseBlock:
    pass

@dataclass
class ForLoop:
    var: str
    iterable: str

@dataclass
class WhileLoop:
    condition: str

@dataclass
class WithBlock:
    expr: str
    alias: Optional[str]

@dataclass
class TryBlock:
    pass

@dataclass
class ExceptBlock:
    exc_type: Optional[str]
    exc_var: Optional[str]

@dataclass
class FinallyBlock:
    pass

@dataclass
class CloseBlock:
    kind: str

@dataclass
class Assignment:
    var: str
    value: str

@dataclass
class AugmentedAssignment:
    var: str
    op: str
    value: str

@dataclass
class Decorator:
    name: str

@dataclass
class Comment:
    text: str

@dataclass
class Enchantment:
    enchant_type: str
    body: str

@dataclass
class ExpressionStatement:
    """Catch-all for expression lines (calls, operators, pass-through, etc.)."""
    code: str

@dataclass
class BlankLine:
    pass


# ============================================================================
# Operator mappings (order matters -- longer phrases first)
# ============================================================================

OPERATOR_PHRASES = [
    # Comparison - sentence forms first
    ("is not equal to", "!="),
    ("is equal to", "=="),
    ("is greater than or equal to", ">="),
    ("is less than or equal to", "<="),
    ("is greater than", ">"),
    ("is less than", "<"),
    # Comparison - terse forms
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
    # Augmented assignment (must be before simple operators)
    ("times assign", "*="),
    ("plus assign", "+="),
    ("minus assign", "-="),
    # Logical (must distinguish "logical and" from tuple "and")
    ("logical and", "and"),
    ("logical or", "or"),
    ("logical not", "not"),
    # Simple arithmetic
    ("times", "*"),
    ("concatenate", "+"),
    ("plus", "+"),
    ("minus", "-"),
    ("assign", "="),
]

# Pre-split operator phrases for word-by-word matching
_OPERATOR_PHRASE_WORDS = [(phrase.split(), op) for phrase, op in OPERATOR_PHRASES]


# ============================================================================
# STT Preprocessor (kept as-is -- runs before tokenization)
# ============================================================================

def preprocess_stt(source):
    """Clean up common STT artifacts before transpilation.

    - Periods -> sentence boundaries -> split into separate lines
    - Preserves decimal numbers like 3.14
    - Commas before newlines -> stripped
    - Multiple spaces -> single space
    """
    import re
    lines = []
    for line in source.splitlines():
        if not line.strip():
            lines.append("")
            continue
        parts = re.split(r'\.(?=\s|$)', line)
        for part in parts:
            cleaned = part.strip()
            cleaned = cleaned.rstrip(".,;")
            cleaned = re.sub(r"  +", " ", cleaned)
            if cleaned:
                lines.append(cleaned)
    return "\n".join(lines)


# ============================================================================
# Tokenizer
# ============================================================================

class Tokenizer:
    """Word-by-word scanner that produces tokens from a spoken Python line."""

    # Multi-word keywords that should be recognized as single tokens.
    # Ordered longest-first so greedy matching works.
    MULTI_WORD_KEYWORDS = [
        (["open", "expression"], TokenType.KEYWORD_OPEN_EXPRESSION),
        (["close", "expression"], TokenType.KEYWORD_CLOSE_EXPRESSION),
        (["f", "string", "literal"], TokenType.KEYWORD_F_STRING_LITERAL),
        (["string", "literal"], TokenType.KEYWORD_STRING_LITERAL),
        (["list", "of"], TokenType.KEYWORD_LIST_OF),
        (["enchant", "with"], TokenType.KEYWORD_ENCHANT),
        (["open", "function"], None),   # handled specially
        (["open", "class"], None),
        (["open", "if"], None),
        (["open", "elif"], None),
        (["open", "else"], None),
        (["open", "for"], None),
        (["open", "while"], None),
        (["open", "with"], None),
        (["open", "try"], None),
        (["open", "except"], None),
        (["open", "finally"], None),
    ]

    SINGLE_KEYWORDS = {
        "open": TokenType.KEYWORD_OPEN,
        "close": TokenType.KEYWORD_CLOSE,
        "function": TokenType.KEYWORD_FUNCTION,
        "class": TokenType.KEYWORD_CLASS,
        "if": TokenType.KEYWORD_IF,
        "elif": TokenType.KEYWORD_ELIF,
        "else": TokenType.KEYWORD_ELSE,
        "for": TokenType.KEYWORD_FOR,
        "while": TokenType.KEYWORD_WHILE,
        "try": TokenType.KEYWORD_TRY,
        "except": TokenType.KEYWORD_EXCEPT,
        "finally": TokenType.KEYWORD_FINALLY,
        "let": TokenType.KEYWORD_LET,
        "be": TokenType.KEYWORD_BE,
        "call": TokenType.KEYWORD_CALL,
        "dot": TokenType.KEYWORD_DOT,
        "parameters": TokenType.KEYWORD_PARAMETERS,
        "with": TokenType.KEYWORD_WITH,
        "in": TokenType.KEYWORD_IN,
        "as": TokenType.KEYWORD_AS,
        "inherits": TokenType.KEYWORD_INHERITS,
        "index": TokenType.KEYWORD_INDEX,
        "slice": TokenType.KEYWORD_SLICE,
        "at": TokenType.KEYWORD_AT,
        "from": TokenType.KEYWORD_FROM,
        "to": TokenType.KEYWORD_TO,
        "decorator": TokenType.KEYWORD_DECORATOR,
        "comment": TokenType.KEYWORD_COMMENT,
        "increase": TokenType.KEYWORD_INCREASE,
        "decrease": TokenType.KEYWORD_DECREASE,
        "multiply": TokenType.KEYWORD_MULTIPLY,
        "divide": TokenType.KEYWORD_DIVIDE,
        "by": TokenType.KEYWORD_BY,
        "return": TokenType.KEYWORD_RETURN,
        "import": TokenType.KEYWORD_IMPORT,
        "pass": TokenType.KEYWORD_PASS,
        "break": TokenType.KEYWORD_BREAK,
        "continue": TokenType.KEYWORD_CONTINUE,
    }

    def __init__(self, line: str):
        self.words = line.strip().split() if line.strip() else []
        self.pos = 0
        self.tokens: List[Token] = []

    def peek_words(self, n):
        """Peek at the next n words without consuming them."""
        if self.pos + n <= len(self.words):
            return self.words[self.pos:self.pos + n]
        return None

    def consume(self, n=1):
        """Consume n words and return them."""
        result = self.words[self.pos:self.pos + n]
        self.pos += n
        return result

    def at_end(self):
        return self.pos >= len(self.words)

    def remaining_words(self):
        return self.words[self.pos:]

    def tokenize(self) -> List[Token]:
        """Tokenize the entire line into a list of tokens."""
        if not self.words:
            return [Token(TokenType.EOF, "")]

        tokens = []
        while not self.at_end():
            token = self._next_token()
            if token:
                tokens.append(token)

        tokens.append(Token(TokenType.EOF, "", self.pos))
        return tokens

    def _next_token(self) -> Optional[Token]:
        """Scan the next token from the word stream."""
        pos = self.pos

        # Try multi-word keywords (longest first)
        for phrase_words, ttype in self.MULTI_WORD_KEYWORDS:
            n = len(phrase_words)
            peeked = self.peek_words(n)
            if peeked and [w.lower() for w in peeked] == phrase_words:
                if ttype is not None:
                    self.consume(n)
                    value = " ".join(phrase_words)
                    return Token(ttype, value, pos)
                else:
                    # Compound block opener like "open function" —
                    # Don't consume; let single-keyword logic handle
                    # "open" and "function" as separate tokens.
                    break

        word = self.words[self.pos]
        lower = word.lower()

        # Check for single keywords
        if lower in self.SINGLE_KEYWORDS:
            self.consume()
            return Token(self.SINGLE_KEYWORDS[lower], word, pos)

        # Number literal
        if self._is_number(word):
            self.consume()
            return Token(TokenType.NUMBER, word, pos)

        # Default: identifier/word pass-through
        self.consume()
        return Token(TokenType.WORD, word, pos)

    def _is_number(self, word):
        """Check if a word is a numeric literal."""
        try:
            float(word)
            return True
        except ValueError:
            return False


# ============================================================================
# Parser
# ============================================================================

class Parser:
    """
    Parses a single line of spoken Python (as a word list) into an AST node.

    The parser works at the line level -- each line becomes one AST node.
    It uses word-by-word scanning without regex.
    """

    def __init__(self):
        pass

    def parse_line(self, line: str):
        """Parse a single line into an AST node."""
        stripped = line.strip()

        if not stripped:
            return BlankLine()

        words = stripped.split()
        if not words:
            return BlankLine()

        first = words[0]

        # --- Comments ---
        # "comment X" or "as an aside X" or "aside X"
        if first == "comment" and len(words) > 1:
            return Comment(" ".join(words[1:]))
        if first == "aside" and len(words) > 1:
            return Comment(" ".join(words[1:]))
        if first == "as" and len(words) > 3 and words[1] == "an" and words[2] == "aside":
            return Comment(" ".join(words[3:]))

        # --- Literal passthrough: "literally <raw python>" ---
        if first == "literally":
            return ExpressionStatement(" ".join(words[1:]))

        # --- Decorators ---
        # "decorator staticmethod" → @staticmethod
        # "decorator call app dot route with string literal /" → @app.route("/")
        if first == "decorator" and len(words) > 1:
            body = " ".join(words[1:])
            if words[1] == "call":
                body = self._process_expression(body)
            return Decorator(body)

        # --- Block openers ---
        if first == "open" and len(words) > 1:
            return self._parse_open_block(words)

        # --- Bare block openers (no "open" prefix) ---
        # function, class, for, while, if, elif, else all work without "open"
        if first == "function" and len(words) > 1:
            return self._parse_open_block(["open"] + words)
        if first == "class" and len(words) > 1:
            return self._parse_open_block(["open"] + words)
        if first == "for" and "in" in words:
            return self._parse_open_block(["open"] + words)
        if first == "while" and len(words) > 1:
            return self._parse_open_block(["open"] + words)
        if first == "if" and len(words) > 1:
            return self._parse_open_block(["open"] + words)
        if first == "elif" and len(words) > 1:
            return self._parse_open_block(["open"] + words)
        # "else if X" → treat as elif
        if first == "else" and len(words) > 1 and words[1] == "if":
            return self._parse_open_block(["open", "elif"] + words[2:])
        if first == "else" and len(words) == 1:
            return self._parse_open_block(["open"] + words)

        # --- Block closers ---
        if first == "close":
            kind = words[1] if len(words) > 1 else "block"
            return CloseBlock(kind)

        # --- Enchantments (standalone) ---
        if first == "enchant" and len(words) > 2 and words[1] == "with":
            enchant_type = words[2]
            body = " ".join(words[3:]) if len(words) > 3 else ""
            return Enchantment(enchant_type, body)

        # --- "let X be Y" ---
        if first == "let":
            return self._parse_let(words)

        # --- Augmented assignments: increase/decrease/multiply/divide X by Y ---
        if first in ("increase", "decrease", "multiply", "divide"):
            result = self._parse_augmented(words)
            if result is not None:
                return result

        # --- "X assign enchant with Y ..." → Assignment with enchantment value ---
        if "assign" in words and "enchant" in words:
            assign_idx = words.index("assign")
            enchant_idx = words.index("enchant")
            if enchant_idx == assign_idx + 1:
                var = " ".join(words[:assign_idx])
                enchant_type = words[enchant_idx + 2] if enchant_idx + 2 < len(words) else ""
                body = " ".join(words[enchant_idx + 3:]) if enchant_idx + 3 < len(words) else ""
                enchant_result = self._process_enchantment(enchant_type, body)
                return Assignment(var, enchant_result)

        # --- "X assign Y" (simple assignment: 'assign' at index 1, not part of compound like 'minus assign') ---
        if "assign" in words:
            assign_idx = words.index("assign")
            # Only treat as assignment if 'assign' is at position 1 (var assign value)
            # and not preceded by plus/minus/times (those are augmented operators)
            if assign_idx == 1:
                var = words[0]
                value_text = " ".join(words[assign_idx + 1:])
                value = self._process_expression(value_text)
                return Assignment(var, value)

        # --- General expression (calls, operators, pass-through, etc.) ---
        return self._parse_expression_statement(stripped)

    def _parse_open_block(self, words):
        """Parse 'open <kind> ...' blocks."""
        kind = words[1]

        if kind == "function":
            return self._parse_function_def(words)
        elif kind == "class":
            return self._parse_class_def(words)
        elif kind == "if":
            cond_words = words[2:]
            condition = self._process_expression(" ".join(cond_words))
            return IfBlock(condition)
        elif kind == "elif":
            cond_words = words[2:]
            condition = self._process_expression(" ".join(cond_words))
            return ElifBlock(condition)
        elif kind == "else":
            return ElseBlock()
        elif kind == "for":
            return self._parse_for(words)
        elif kind == "while":
            cond_words = words[2:]
            condition = self._process_expression(" ".join(cond_words))
            return WhileLoop(condition)
        elif kind == "with":
            return self._parse_with_block(words)
        elif kind == "try":
            return TryBlock()
        elif kind == "except":
            return self._parse_except(words)
        elif kind == "finally":
            return FinallyBlock()

        # Unknown block -- treat as expression
        return ExpressionStatement(" ".join(words))

    def _parse_function_def(self, words):
        """Parse function definitions. Supports two forms:

        Preferred form:
            function greet with parameters name and age
            → def greet(name, age):

        Terse form (legacy):
            function greet parameters name age
            → def greet(name, age):
        """
        # words[0]="open", words[1]="function"
        if len(words) < 3:
            return ExpressionStatement(" ".join(words))

        name = words[2]
        params = []

        # Preferred form: "function X with parameters P1 and P2"
        with_idx = self._find_word(words, "with", start=3)
        if with_idx is not None:
            param_idx = self._find_word(words, "parameters", start=with_idx + 1)
            if param_idx is not None and param_idx == with_idx + 1:
                # "with parameters P1 and P2 ..."
                raw_params = words[param_idx + 1:]
                params = self._parse_param_list(raw_params)
                return FunctionDef(name, params)

        # Terse form: "function X parameters P1 P2 P3"
        param_idx = self._find_word(words, "parameters", start=3)
        if param_idx is not None:
                params = words[param_idx + 1:]

        return FunctionDef(name, params)

    def _parse_param_list(self, raw_words):
        """Parse a parameter list with 'and' separators, defaults, and unpack.

        Examples:
            [self, and, data]                          → ["self", "data"]
            [self, and, x, with, default, 5]           → ["self", "x=5"]
            [self, and, unpack, arguments]              → ["self", "*args"]
            [self, and, unpack, keyword, arguments]     → ["self", "**kwargs"]
            [x, with, default, empty, tuple]            → ["x=()"]
        """
        # Split on "and" into groups
        groups = []
        current = []
        for w in raw_words:
            if w == "and":
                if current:
                    groups.append(current)
                current = []
            else:
                current.append(w)
        if current:
            groups.append(current)

        params = []
        for group in groups:
            if not group:
                continue

            # "unpack arguments" → *args
            if group[0] == "unpack" and len(group) >= 2:
                if group[1] == "keyword" and len(group) >= 3:
                    # "unpack keyword arguments" → **kwargs (or **<word>)
                    param_name = group[2] if len(group) == 3 else "kwargs"
                    params.append("**" + param_name)
                else:
                    # "unpack arguments" → *args (or *<word>)
                    param_name = group[1] if len(group) == 2 else "args"
                    params.append("*" + param_name)
                continue

            # Check for "with default X"
            default_idx = None
            for i, w in enumerate(group):
                if w == "with" and i + 1 < len(group) and group[i + 1] == "default":
                    default_idx = i
                    break

            if default_idx is not None:
                param_name = " ".join(group[:default_idx])
                default_val = " ".join(group[default_idx + 2:])
                # Process the default value through expression pipeline
                default_val = self._process_expression(default_val)
                params.append(param_name + "=" + default_val)
            else:
                params.append(" ".join(group))

        return params

    def _parse_class_def(self, words):
        """Parse: open class <name> [inherits <parent>]"""
        if len(words) < 3:
            return ExpressionStatement(" ".join(words))

        name = words[2]
        parent = None

        inh_idx = self._find_word(words, "inherits", start=3)
        if inh_idx is not None and inh_idx + 1 < len(words):
            parent = " ".join(words[inh_idx + 1:]).strip()

        return ClassDef(name, parent)

    def _parse_for(self, words):
        """Parse: open for <var> in <iterable_expr>"""
        # Find "in" keyword
        in_idx = self._find_word(words, "in", start=2)
        if in_idx is None:
            return ExpressionStatement(" ".join(words))

        var = " ".join(words[2:in_idx])
        iterable_text = " ".join(words[in_idx + 1:])
        iterable = self._process_expression(iterable_text)
        return ForLoop(var, iterable)

    def _parse_with_block(self, words):
        """Parse: open with <expr> [as <alias>]"""
        # Find "as" keyword
        as_idx = self._find_word(words, "as", start=2)
        if as_idx is not None:
            expr_text = " ".join(words[2:as_idx])
            alias = words[as_idx + 1] if as_idx + 1 < len(words) else None
        else:
            expr_text = " ".join(words[2:])
            alias = None

        expr = self._process_expression(expr_text)
        return WithBlock(expr, alias)

    def _parse_except(self, words):
        """Parse: open except [<Type> [as <var>]]"""
        # words[0]="open", words[1]="except"
        remaining = words[2:]
        if not remaining:
            return ExceptBlock(None, None)

        as_idx = self._find_word_in(remaining, "as")
        if as_idx is not None:
            exc_type = " ".join(remaining[:as_idx]) or None
            exc_var = remaining[as_idx + 1] if as_idx + 1 < len(remaining) else None
        else:
            exc_type = " ".join(remaining).strip() or None
            exc_var = None

        return ExceptBlock(exc_type, exc_var)

    def _parse_let(self, words):
        """Parse: let <var> be <value_expr>"""
        # Find "be" keyword
        be_idx = self._find_word(words, "be", start=1)
        if be_idx is None or be_idx < 2:
            return ExpressionStatement(" ".join(words))

        var = words[1]
        value_text = " ".join(words[be_idx + 1:])

        # Check if value contains an enchantment
        if "enchant with " in value_text:
            enchant_idx = value_text.index("enchant with ")
            enchant_part = value_text[enchant_idx:]
            enchant_words = enchant_part.split()
            if len(enchant_words) >= 3:
                etype = enchant_words[2]
                ebody = " ".join(enchant_words[3:]) if len(enchant_words) > 3 else ""
                value = self._process_enchantment(etype, ebody)
            else:
                value = value_text
        else:
            value = self._process_expression(value_text)

        return Assignment(var, value)

    def _parse_augmented(self, words):
        """Parse: increase/decrease/multiply/divide X by Y"""
        if len(words) < 4:
            return None

        verb = words[0]
        # Find "by"
        by_idx = self._find_word(words, "by", start=2)
        if by_idx is None:
            return None

        var = words[1]
        value_text = " ".join(words[by_idx + 1:])
        value = self._replace_operators(value_text)

        op_map = {
            "increase": "+=",
            "decrease": "-=",
            "multiply": "*=",
            "divide": "/=",
        }
        op = op_map.get(verb)
        if op is None:
            return None

        return AugmentedAssignment(var, op, value)

    def _parse_expression_statement(self, text):
        """Parse a general expression line into an ExpressionStatement."""
        result = self._process_expression(text)
        return ExpressionStatement(result)

    # ── Expression Processing ───────────────────────────────────────────

    def _process_expression(self, text):
        """Process a general expression: inline enchantments, strings, calls, operators."""
        if not text:
            return text

        # Inline enchantments
        if "enchant with " in text:
            enchant_idx = text.index("enchant with ")
            before = text[:enchant_idx]
            enchant_part = text[enchant_idx:]
            before = self._replace_operators(before)
            ew = enchant_part.split()
            if len(ew) >= 3:
                etype = ew[2]
                ebody = " ".join(ew[3:]) if len(ew) > 3 else ""
                enchant_result = self._process_enchantment(etype, ebody)
                return before + enchant_result
            return before + enchant_part

        # f-strings before regular strings
        if "f string literal" in text:
            text = self._process_f_string(text)

        # String literals
        if "string literal" in text:
            text = self._process_string_literals(text)

        # Explicit function calls: "call X with Y"
        if "call " in text:
            text = self._process_all_calls(text)

        # Implicit function calls: "X with Y" → X(Y)
        # (only when "with" follows an identifier, not a keyword)
        if " with " in text and "call " not in text:
            text = self._process_implicit_calls(text)

        # Indexing
        text = self._process_index(text)

        # Slicing
        text = self._process_slice(text)

        # Empty collections: empty list, empty dict, empty tuple, empty set, empty string
        text = self._process_empty(text)

        # List literals
        if text.strip().startswith("list of "):
            text = self._process_list_literal(text)

        # Parentheses and tuples:
        #   "open paren X and Y close paren" → (X, Y)
        #   "open paren close paren" → ()
        #   "open paren X close paren" → (X,)   (single-element tuple)
        #   "open paren X close paren" in non-tuple context → (X)
        #   For grouping (not tuple), say "group X and Y end group"
        text = self._process_parens(text)

        # Attribute access: "X into Y" → "X.Y", "X dot Y" → "X.Y"
        text = self._process_dot_access(text)

        # Operators
        text = self._replace_operators(text)

        return text

    def _replace_operators(self, text):
        """Replace spoken operator phrases with Python operators, word-by-word."""
        words = text.split()
        if not words:
            return text

        result_words = []
        i = 0
        while i < len(words):
            matched = False
            # Try longest operator phrases first
            for phrase_words, op in _OPERATOR_PHRASE_WORDS:
                plen = len(phrase_words)
                if i + plen <= len(words):
                    candidate = [w.lower() for w in words[i:i + plen]]
                    if candidate == phrase_words:
                        result_words.append(op)
                        i += plen
                        matched = True
                        break
            if not matched:
                result_words.append(words[i])
                i += 1

        return " ".join(result_words)

    def _process_string_literals(self, text):
        """Process all 'string literal ...' in text."""
        result = text
        safety = 0
        while "string literal" in result and safety < 10:
            result = self._parse_one_string_literal(result)
            safety += 1
        return result

    def _parse_one_string_literal(self, text):
        """Extract one string literal from text."""
        # Find "string literal" by scanning words
        idx = text.find("string literal")
        if idx == -1:
            return text

        before = text[:idx]
        after = text[idx + len("string literal"):]
        after = after.lstrip()  # strip space after marker

        # Find where the string content ends
        end_keywords = [
            "string literal", "open ", "close ", "call ", "assign",
            "equals", "plus", "minus", "times", "divided by",
            "greater than", "less than", "concatenate", "key ", "value ",
        ]

        end_pos = len(after)
        for kw in end_keywords:
            pos = after.find(kw)
            if pos > 0 and pos < end_pos:
                end_pos = pos

        string_content = after[:end_pos].strip()
        remaining = after[end_pos:]

        return before + '"' + string_content + '"' + remaining

    def _process_f_string(self, text):
        """Process f-string literals."""
        marker = "f string literal"
        idx = text.find(marker)
        if idx == -1:
            return text

        before = text[:idx]
        after = text[idx + len(marker):].lstrip()

        # Replace open expression / close expression with { }
        after = self._replace_phrase(after, "open expression", "{")
        after = self._replace_phrase(after, "close expression", "}")

        return before + 'f"' + after.strip() + '"'

    def _replace_phrase(self, text, phrase, replacement):
        """Replace all occurrences of a phrase in text."""
        while phrase in text:
            idx = text.find(phrase)
            text = text[:idx] + replacement + text[idx + len(phrase):]
        return text

    def _process_all_calls(self, text):
        """Process all 'call X [with args]' patterns, innermost first."""
        last_call_idx = text.rfind("call ")
        if last_call_idx == -1:
            return text

        before = text[:last_call_idx]
        after = text[last_call_idx:]

        # Parse: call <func> [dot <method>] [with <args>]
        words = after.split()
        # words[0] == "call"
        if len(words) < 2:
            return text

        # Build function name (possibly with dot)
        func_parts = [words[1]]
        i = 2
        while i + 1 < len(words) and words[i] in ("dot", "into"):
            func_parts.append(words[i + 1])
            i += 2

        func_name = ".".join(func_parts)

        # Check for "with" keyword
        if i < len(words) and words[i] == "with":
            args_text = " ".join(words[i + 1:])
            # Process nested constructs in args
            args_text = self._process_string_literals(args_text)
            args_text = self._replace_operators(args_text)
            args = self._smart_split_args(args_text)
            replacement = func_name + "(" + ", ".join(args) + ")"
        elif i >= len(words):
            # No args
            replacement = func_name + "()"
        else:
            # Trailing words but no "with" -- treat rest as part of context
            # This shouldn't normally happen with well-formed input
            replacement = func_name + "()"
            # Put remaining words back
            remaining_tail = " ".join(words[i:])
            replacement = replacement + " " + remaining_tail

        result = before + replacement

        # Recurse for remaining calls
        if "call " in result:
            result = self._process_all_calls(result)

        return result

    def _smart_split_args(self, args_text):
        """Split arguments respecting quoted strings, character by character."""
        args = []
        current = []
        in_quotes = False

        for ch in args_text:
            if ch == '"' and not in_quotes:
                in_quotes = True
                current.append(ch)
            elif ch == '"' and in_quotes:
                in_quotes = False
                current.append(ch)
            elif ch == ' ' and not in_quotes:
                token = "".join(current).strip()
                if token:
                    args.append(token)
                current = []
            else:
                current.append(ch)

        token = "".join(current).strip()
        if token:
            args.append(token)

        return args

    def _process_implicit_calls(self, text):
        """Process implicit calls: '<name> with <args>' → name(args).

        Only triggers when <name> looks like a function (identifier or dotted name),
        not when preceded by known keywords like 'open', 'parameters', 'enchant'.
        """
        # Words that take "with" but are NOT function calls
        NON_CALL_WITH = {"open", "parameters", "enchant", "default"}

        words = text.split()
        # Find rightmost "with" that follows an identifier
        for idx in range(len(words) - 1, 0, -1):
            if words[idx] != "with":
                continue
            prev = words[idx - 1]
            # Check the word before "with" isn't a keyword
            if prev.lower() in NON_CALL_WITH:
                continue
            # Check it looks like a function name (identifier or dotted)
            if not prev[0].isalpha() and prev[0] != '_':
                continue

            # Build the function name (could be dotted: x.append with 5)
            func_name = prev
            func_start = idx - 1
            # Check for dotted prefix: a.b.c with args
            while func_start >= 2 and words[func_start - 1] == ".":
                func_name = words[func_start - 2] + "." + func_name
                func_start -= 2

            args_text = " ".join(words[idx + 1:])
            args_text = self._process_string_literals(args_text)
            args_text = self._replace_operators(args_text)
            args = self._smart_split_args(args_text)

            before = " ".join(words[:func_start])
            result = func_name + "(" + ", ".join(args) + ")"
            text = (before + " " + result).strip()

            # Only process the rightmost one per pass
            break

        return text

    def _process_index(self, text):
        """Process 'index X at Y' -> 'X[Y]' by word scanning."""
        words = text.split()
        result = []
        i = 0
        changed = False
        while i < len(words):
            if (words[i] == "index"
                    and i + 3 <= len(words)
                    and i + 2 < len(words)
                    and words[i + 2] == "at"):
                # index X at Y
                var = words[i + 1]
                idx_val = words[i + 3] if i + 3 < len(words) else ""
                result.append(var + "[" + idx_val + "]")
                i += 4
                changed = True
            else:
                result.append(words[i])
                i += 1

        return " ".join(result) if changed else text

    def _process_slice(self, text):
        """Process 'slice X from Y to Z' -> 'X[Y:Z]' by word scanning."""
        words = text.split()
        result = []
        i = 0
        changed = False
        while i < len(words):
            if (words[i] == "slice"
                    and i + 5 <= len(words)
                    and words[i + 2] == "from"
                    and words[i + 4] == "to"):
                var = words[i + 1]
                start = words[i + 3]
                end = words[i + 5] if i + 5 < len(words) else ""
                result.append(var + "[" + start + ":" + end + "]")
                i += 6
                changed = True
            else:
                result.append(words[i])
                i += 1

        return " ".join(result) if changed else text

    def _process_dot_access(self, text):
        """Replace 'X into Y' and 'X dot Y' with 'X.Y' for attribute access.

        Only applies outside of call expressions (which handle dot/into separately).
        """
        words = text.split()
        if not words:
            return text
        result = []
        i = 0
        while i < len(words):
            if i + 1 < len(words) and words[i] in ("into", "dot") and result:
                # Join previous word with next word via dot
                prev = result.pop()
                result.append(prev + "." + words[i + 1])
                i += 2
            else:
                result.append(words[i])
                i += 1
        return " ".join(result)

    def _process_empty(self, text):
        """Process 'empty X' → empty collection literal.

        empty list       → []
        empty dictionary → {}
        empty dict       → {}
        empty tuple      → ()
        empty set        → set()
        empty string     → ""
        """
        EMPTY_MAP = {
            "empty list": "[]",
            "empty dictionary": "{}",
            "empty dict": "{}",
            "empty tuple": "()",
            "empty set": "set()",
            "empty string": '""',
        }
        for spoken, python_val in EMPTY_MAP.items():
            if spoken in text:
                text = text.replace(spoken, python_val)
        return text

    def _process_list_literal(self, text):
        """Process 'list of X Y Z' -> '[X, Y, Z]'"""
        stripped = text.strip()
        words = stripped.split()
        if len(words) >= 2 and words[0] == "list" and words[1] == "of":
            items = words[2:]
            return "[" + ", ".join(items) + "]"
        return text

    def _process_parens(self, text):
        """Process open paren / close paren pairs.

        Tuple semantics: items separated by 'and' become comma-separated.
            open paren X and Y close paren  → (X, Y)
            open paren close paren          → ()
            open paren X close paren        → (X,)  (single-element tuple)

        For grouping (not tuple), use 'group ... end group':
            group X plus Y end group        → (X + Y)
        """
        # Process grouping first: group ... end group → ( ... )
        while "group " in text and "end group" in text:
            start = text.find("group ")
            end = text.find("end group", start)
            if end == -1:
                break
            inner = text[start + len("group "):end].strip()
            text = text[:start] + "(" + inner + ")" + text[end + len("end group"):]

        # Process paren pairs: open paren ... close paren → (...)
        while "open paren" in text and "close paren" in text:
            start = text.find("open paren")
            end = text.find("close paren", start)
            if end == -1:
                break
            inner = text[start + len("open paren"):end].strip()

            if not inner:
                # Empty: open paren close paren → ()
                replacement = "()"
            elif " and " in inner:
                # Multiple items: split on 'and', comma-join → (X, Y, Z)
                items = [item.strip() for item in inner.split(" and ")]
                replacement = "(" + ", ".join(items) + ")"
            else:
                # Single item → (X,) — trailing comma for single-element tuple
                replacement = "(" + inner + ",)"

            text = text[:start] + replacement + text[end + len("close paren"):]

        return text

    # ── Enchantment Processing ──────────────────────────────────────────

    def _process_enchantment(self, enchant_type, body):
        """Dispatch to the right enchantment processor."""
        if enchant_type == "string":
            return self._enchant_string(body)
        elif enchant_type == "rejection":
            return self._enchant_rejection(body)
        elif enchant_type == "math":
            return self._enchant_math(body)
        return enchant_type + " " + body

    def _enchant_string(self, body):
        """Build f-string from spoken template.

        Supports dotted variable refs:
            variable self dot data  → {self.data}
            variable x into name    → {x.name}
        """
        parts = []
        words = body.split()
        i = 0
        while i < len(words):
            if words[i] in ("variable", "var") and i + 1 < len(words):
                # Collect the variable name, including dot chains
                var_parts = [words[i + 1]]
                i += 2
                while i + 1 < len(words) and words[i] in ("dot", "into"):
                    var_parts.append(words[i + 1])
                    i += 2
                parts.append("{" + ".".join(var_parts) + "}")
            else:
                parts.append(words[i])
                i += 1
        return 'f"' + " ".join(parts) + '"'

    # Regex mini-language mappings
    REGEX_MAP = [
        ("one or more of", "+"),
        ("zero or more of", "*"),
        ("any digit", "\\d"),
        ("any digits", "\\d+"),
        ("any letter", "[a-zA-Z]"),
        ("any letters", "[a-zA-Z]+"),
        ("any word character", "\\w"),
        ("any word characters", "\\w+"),
        ("any whitespace", "\\s"),
        ("any character", "."),
        ("any characters", ".*"),
        ("start of string", "^"),
        ("end of string", "$"),
        ("word boundary", "\\b"),
        ("open group", "("),
        ("close group", ")"),
        ("named group", "(?P<"),
        ("either", "(?:"),
        ("or", "|"),
        ("literal dot", "\\."),
        ("literal star", "\\*"),
        ("literal plus", "\\+"),
        ("literal open paren", "\\("),
        ("literal close paren", "\\)"),
        ("literal backslash", "\\\\\\\\"),
        ("any of", "["),
        ("end any of", "]"),
        ("not any of", "[^"),
    ]

    # Pre-split for word scanning
    _REGEX_PHRASE_WORDS = None

    @classmethod
    def _get_regex_phrases(cls):
        if cls._REGEX_PHRASE_WORDS is None:
            cls._REGEX_PHRASE_WORDS = [(phrase.split(), regex) for phrase, regex in cls.REGEX_MAP]
        return cls._REGEX_PHRASE_WORDS

    LITERAL_MAP = {
        "at": "@",
        "dash": "-",
        "underscore": "_",
        "space": " ",
        "colon": ":",
        "slash": "/",
        "hash": "#",
    }

    def _enchant_rejection(self, body):
        """Build regex pattern from spoken description, word-by-word."""
        words = body.split()
        result = []
        i = 0
        regex_phrases = self._get_regex_phrases()

        while i < len(words):
            matched = False

            # Special: "exactly N"
            if words[i] == "exactly" and i + 1 < len(words):
                try:
                    n = int(words[i + 1])
                    result.append("{" + str(n) + "}")
                    i += 2
                    matched = True
                except ValueError:
                    pass

            # Special: "between N and M"
            if not matched and words[i] == "between" and i + 3 < len(words):
                try:
                    n = int(words[i + 1])
                    if words[i + 2] == "and":
                        m = int(words[i + 3])
                        result.append("{" + str(n) + "," + str(m) + "}")
                        i += 4
                        matched = True
                except (ValueError, IndexError):
                    pass

            # Special: "named group X"
            if not matched and words[i] == "named" and i + 2 < len(words) and words[i + 1] == "group":
                name = words[i + 2]
                result.append("(?P<" + name + ">")
                i += 3
                matched = True

            # Special: "optional X"
            if not matched and words[i] == "optional" and i + 1 < len(words):
                # Process the next token
                next_regex = None
                consumed = 0
                for try_len in range(min(4, len(words) - i - 1), 0, -1):
                    next_phrase = words[i + 1:i + 1 + try_len]
                    for phrase_w, regex in regex_phrases:
                        if next_phrase == phrase_w:
                            next_regex = regex
                            consumed = try_len
                            break
                    if next_regex:
                        break
                if next_regex is None:
                    next_word = words[i + 1]
                    next_regex = self.LITERAL_MAP.get(next_word, next_word)
                    consumed = 1
                result.append(next_regex + "?")
                i += 1 + consumed
                matched = True

            # Special: "not any of"
            if not matched and words[i] == "not" and i + 2 < len(words) and words[i + 1] == "any" and words[i + 2] == "of":
                result.append("[^")
                i += 3
                matched = True

            # Regular phrase lookup (longest first)
            if not matched:
                for phrase_w, regex in regex_phrases:
                    plen = len(phrase_w)
                    if i + plen <= len(words) and words[i:i + plen] == phrase_w:
                        result.append(regex)
                        i += plen
                        matched = True
                        break

            if not matched:
                word = words[i]
                result.append(self.LITERAL_MAP.get(word, word))
                i += 1

        pattern = "".join(result)
        return 'r"' + pattern + '"'

    def _enchant_math(self, body):
        """Build numpy-style matrix expressions, word-by-word."""
        words = body.split()
        result_tokens = []
        i = 0

        while i < len(words):
            matched = False

            # "transpose of X"
            if i + 2 <= len(words) and words[i] == "transpose" and words[i + 1] == "of":
                operand = words[i + 2] if i + 2 < len(words) else "?"
                result_tokens.append(operand + ".T")
                i += 3
                matched = True

            # "inverse of X"
            elif i + 2 < len(words) and words[i] == "inverse" and words[i + 1] == "of":
                operand = words[i + 2]
                result_tokens.append("nope.linalg.inv(" + operand + ")")
                i += 3
                matched = True

            # "determinant of X"
            elif i + 2 < len(words) and words[i] == "determinant" and words[i + 1] == "of":
                operand = words[i + 2]
                result_tokens.append("nope.linalg.det(" + operand + ")")
                i += 3
                matched = True

            # "cross product"
            elif i + 1 < len(words) and words[i] == "cross" and words[i + 1] == "product":
                left = result_tokens.pop() if result_tokens else "?"
                right = words[i + 2] if i + 2 < len(words) else "?"
                result_tokens.append("nope.cross(" + left + ", " + right + ")")
                i += 3
                matched = True

            # "mat mul"
            elif i + 1 < len(words) and words[i] == "mat" and words[i + 1] == "mul":
                result_tokens.append("@")
                i += 2
                matched = True

            # "element wise times/plus/minus/divided by"
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

            # "dot"
            elif words[i] == "dot":
                left = result_tokens.pop() if result_tokens else "?"
                right = words[i + 1] if i + 1 < len(words) else "?"
                result_tokens.append("nope.dot(" + left + ", " + right + ")")
                i += 2
                matched = True

            if not matched:
                result_tokens.append(words[i])
                i += 1

        return " ".join(result_tokens)

    # ── Helpers ─────────────────────────────────────────────────────────

    def _find_word(self, words, target, start=0):
        """Find the index of a word in the list, starting from `start`."""
        for i in range(start, len(words)):
            if words[i] == target:
                return i
        return None

    def _find_word_in(self, words, target):
        """Find index of target in words list."""
        for i, w in enumerate(words):
            if w == target:
                return i
        return None


# ============================================================================
# Code Generator
# ============================================================================

class CodeGenerator:
    """Generates Python source code from AST nodes, managing indentation."""

    def __init__(self):
        self.indent_level = 0
        self.lines: List[str] = []

    @property
    def indent(self):
        return "    " * self.indent_level

    def generate(self, nodes: List) -> str:
        """Generate Python code from a list of AST nodes."""
        for node in nodes:
            self._emit(node)
        return "\n".join(self.lines)

    def _emit(self, node):
        if isinstance(node, BlankLine):
            self.lines.append("")

        elif isinstance(node, Comment):
            self.lines.append(self.indent + "# " + node.text)

        elif isinstance(node, Decorator):
            self.lines.append(self.indent + "@" + node.name)

        elif isinstance(node, FunctionDef):
            param_str = ", ".join(node.params) if node.params else ""
            self.lines.append(self.indent + "def " + node.name + "(" + param_str + "):")
            self.indent_level += 1

        elif isinstance(node, ClassDef):
            if node.parent:
                self.lines.append(self.indent + "class " + node.name + "(" + node.parent + "):")
            else:
                self.lines.append(self.indent + "class " + node.name + ":")
            self.indent_level += 1

        elif isinstance(node, IfBlock):
            self.lines.append(self.indent + "if " + node.condition + ":")
            self.indent_level += 1

        elif isinstance(node, ElifBlock):
            self.indent_level = max(0, self.indent_level - 1)
            self.lines.append(self.indent + "elif " + node.condition + ":")
            self.indent_level += 1

        elif isinstance(node, ElseBlock):
            self.indent_level = max(0, self.indent_level - 1)
            self.lines.append(self.indent + "else:")
            self.indent_level += 1

        elif isinstance(node, ForLoop):
            self.lines.append(self.indent + "for " + node.var + " in " + node.iterable + ":")
            self.indent_level += 1

        elif isinstance(node, WhileLoop):
            self.lines.append(self.indent + "while " + node.condition + ":")
            self.indent_level += 1

        elif isinstance(node, WithBlock):
            line = self.indent + "with " + node.expr
            if node.alias:
                line += " as " + node.alias
            line += ":"
            self.lines.append(line)
            self.indent_level += 1

        elif isinstance(node, TryBlock):
            self.lines.append(self.indent + "try:")
            self.indent_level += 1

        elif isinstance(node, ExceptBlock):
            self.indent_level = max(0, self.indent_level - 1)
            if node.exc_type and node.exc_var:
                self.lines.append(self.indent + "except " + node.exc_type + " as " + node.exc_var + ":")
            elif node.exc_type:
                self.lines.append(self.indent + "except " + node.exc_type + ":")
            else:
                self.lines.append(self.indent + "except:")
            self.indent_level += 1

        elif isinstance(node, FinallyBlock):
            self.indent_level = max(0, self.indent_level - 1)
            self.lines.append(self.indent + "finally:")
            self.indent_level += 1

        elif isinstance(node, CloseBlock):
            self.indent_level = max(0, self.indent_level - 1)

        elif isinstance(node, Assignment):
            self.lines.append(self.indent + node.var + " = " + node.value)

        elif isinstance(node, AugmentedAssignment):
            self.lines.append(self.indent + node.var + " " + node.op + " " + node.value)

        elif isinstance(node, Enchantment):
            parser = Parser()
            result = parser._process_enchantment(node.enchant_type, node.body)
            self.lines.append(self.indent + result)

        elif isinstance(node, ExpressionStatement):
            self.lines.append(self.indent + node.code)


# ============================================================================
# Pipeline: the main transpile function
# ============================================================================

def transpile(source: str, stt_mode: bool = False) -> str:
    """Transpile Spoken Python source to Python.

    Pipeline: preprocess_stt (optional) -> parse lines -> generate code.
    """
    if stt_mode:
        source = preprocess_stt(source)

    parser = Parser()
    nodes = []
    for line in source.splitlines():
        node = parser.parse_line(line)
        nodes.append(node)

    generator = CodeGenerator()
    return generator.generate(nodes)
