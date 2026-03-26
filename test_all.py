"""Complete test suite for Spoken Python.

Three test layers:
1. Unit tests: specific input → expected output
2. Validation tests: transpiler output is valid Python (tree-sitter)
3. Execution tests: transpiled code actually runs correctly
"""
import sys
sys.path.insert(0, '.')

from spoken_python import transpile

# Try to import tree-sitter for validation tests
try:
    from tree_sitter_language_pack import get_parser
    PYTHON_PARSER = get_parser('python')
    HAS_TREE_SITTER = True
except ImportError:
    HAS_TREE_SITTER = False


def assert_transpile(src, expected, name=""):
    result = transpile(src)
    assert result == expected, f"FAIL {name}:\n  expected: {repr(expected)}\n  got:      {repr(result)}"


def assert_valid_python(src, name=""):
    """Assert that transpiler output is valid Python per tree-sitter."""
    if not HAS_TREE_SITTER:
        return  # skip if tree-sitter not installed
    python_code = transpile(src)
    tree = PYTHON_PARSER.parse(bytes(python_code, 'utf8'))
    assert not tree.root_node.has_error, (
        f"FAIL {name}: output is not valid Python:\n"
        f"  spoken: {repr(src[:80])}\n"
        f"  python: {repr(python_code)}"
    )


def assert_executes(src, name=""):
    """Assert that transpiled code executes without error."""
    python_code = transpile(src)
    try:
        exec(python_code, {})
    except Exception as e:
        raise AssertionError(
            f"FAIL {name}: transpiled code raised {type(e).__name__}: {e}\n"
            f"  spoken: {repr(src[:80])}\n"
            f"  python: {repr(python_code)}"
        )


# ═══════════════════════════════════════════════════════════════
# Layer 1: Unit Tests — exact transpilation output
# ═══════════════════════════════════════════════════════════════

UNIT_TESTS = {
    # ── Block structures ─────────────────────────────────
    "function_def_terse": (
        "open function foo parameters x y\n    pass\nclose function foo",
        "def foo(x, y):\n    pass",
    ),
    "function_def_sentence": (
        "open function greet with parameters name\n    pass\nclose function greet",
        "def greet(name):\n    pass",
    ),
    "function_def_multi_params": (
        "open function add with parameters x and y and z\n    pass\nclose function",
        "def add(x, y, z):\n    pass",
    ),
    "function_no_params": (
        "open function main\n    pass\nclose function",
        "def main():\n    pass",
    ),
    "class_def": (
        "open class Dog\n    pass\nclose class Dog",
        "class Dog:\n    pass",
    ),
    "class_inherit": (
        "open class Dog inherits Animal\n    pass\nclose class Dog",
        "class Dog(Animal):\n    pass",
    ),
    "if_else": (
        "open if x equals 5\n    call print with x\nopen else\n    call print with 0\nclose if",
        "if x == 5:\n    print(x)\nelse:\n    print(0)",
    ),
    "for_loop": (
        "open for i in call range with 10\n    call print with i\nclose for",
        "for i in range(10):\n    print(i)",
    ),
    "while_loop": (
        "open while x greater than 0\n    x minus assign 1\nclose while",
        "while x > 0:\n    x -= 1",
    ),
    "nested_blocks": (
        "open function foo parameters x\n    open if x greater than 0\n        return x\n    close if\n    return 0\nclose function foo",
        "def foo(x):\n    if x > 0:\n        return x\n    return 0",
    ),

    # ── Assignment ────────────────────────────────────────
    "assign_terse": ("x assign 5", "x = 5"),
    "let_be": ("let x be 5", "x = 5"),
    "let_be_string": ('let name be string literal Alice', 'name = "Alice"'),

    # ── Augmented assignment ──────────────────────────────
    "increase_by": ("increase x by 1", "x += 1"),
    "decrease_by": ("decrease x by 2", "x -= 2"),
    "multiply_by": ("multiply x by 3", "x *= 3"),
    "divide_by": ("divide x by 4", "x /= 4"),
    "plus_assign": ("x plus assign 1", "x += 1"),
    "minus_assign": ("x minus assign 1", "x -= 1"),

    # ── Comparison ────────────────────────────────────────
    "equals": ("x equals 5", "x == 5"),
    "is_equal_to": (
        "open if x is equal to 5\n    pass\nclose if",
        "if x == 5:\n    pass",
    ),
    "is_not_equal_to": (
        "open if x is not equal to 0\n    pass\nclose if",
        "if x != 0:\n    pass",
    ),
    "is_greater_than": (
        "open if x is greater than 3\n    pass\nclose if",
        "if x > 3:\n    pass",
    ),

    # ── Logical operators ─────────────────────────────────
    "logical_and": (
        "open if x logical and y\n    pass\nclose if",
        "if x and y:\n    pass",
    ),

    # ── Function calls ────────────────────────────────────
    "call_with_args": ("call print with x", "print(x)"),
    "call_no_args": ("call foo", "foo()"),
    "call_method": ("call x dot append with 5", "x.append(5)"),

    # ── Strings ───────────────────────────────────────────
    "string_literal": ('x assign string literal hello world', 'x = "hello world"'),

    # ── Comments ──────────────────────────────────────────
    "comment": ("comment this is a note", "# this is a note"),
    "aside": ("aside helper function", "# helper function"),
    "as_an_aside": ("as an aside this computes the gradient", "# this computes the gradient"),

    # ── Literally ─────────────────────────────────────────
    "literally": ("literally x = [1, 2, 3]", "x = [1, 2, 3]"),
    "literally_complex": (
        "literally other = other if isinstance(other, Value) else Value(other)",
        "other = other if isinstance(other, Value) else Value(other)",
    ),

    # ── Collections ───────────────────────────────────────
    "index": ("index x at 0", "x[0]"),
    "slice": ("slice x from 1 to 5", "x[1:5]"),
    "list_literal": ("list of 1 2 3", "[1, 2, 3]"),
    "empty_list": ("let x be empty list", "x = []"),
    "empty_dict": ("let x be empty dict", "x = {}"),
    "empty_dictionary": ("let x be empty dictionary", "x = {}"),
    "empty_tuple": ("let x be empty tuple", "x = ()"),
    "empty_set": ("let x be empty set", "x = set()"),
    "empty_string": ('let x be empty string', 'x = ""'),

    # ── Parentheses and tuples ────────────────────────────
    "tuple_multi": ("x assign open paren 1 and 2 and 3 close paren", "x = (1, 2, 3)"),
    "tuple_empty": ("x assign open paren close paren", "x = ()"),
    "tuple_single": ("x assign open paren self close paren", "x = (self,)"),
    "grouping": ("x assign group a plus b end group times c", "x = (a + b) * c"),

    # ── Attribute access (into/dot) ─────────────────────────
    "into_attr": ("self into data assign 5", "self.data = 5"),
    "into_nested": ("self into grad plus assign out into grad", "self.grad += out.grad"),
    "into_call": ("call x into append with 5", "x.append(5)"),

    # ── Default parameters ────────────────────────────────
    "default_param_simple": (
        "open function foo with parameters x and y with default 5\n    pass\nclose function",
        "def foo(x, y=5):\n    pass",
    ),
    "default_param_multi": (
        "open function init with parameters self and data and children with default empty tuple and op with default empty string\n    pass\nclose function",
        'def init(self, data, children=(), op=""):\n    pass',
    ),

    # ── Unpack args ───────────────────────────────────────
    "unpack_args": (
        "open function foo with parameters x and unpack arguments and unpack keyword kwargs\n    pass\nclose function",
        "def foo(x, *arguments, **kwargs):\n    pass",
    ),

    # ── Decorator with args ───────────────────────────────
    "decorator_with_args": (
        'decorator call app dot route with string literal /\nopen function index\n    pass\nclose function',
        '@app.route("/")\ndef index():\n    pass',
    ),

    # ── F-string dotted vars ──────────────────────────────
    "enchant_string_dotted_var": (
        'enchant with string data is variable self dot data',
        'f"data is {self.data}"',
    ),

    # ── Passthrough ───────────────────────────────────────
    "return": ("return x", "return x"),
    "import": ("import os", "import os"),
    "from_import": ("from os import path", "from os import path"),
    "pass": ("pass", "pass"),
    "break": ("break", "break"),
    "blank_lines": ("x assign 1\n\ny assign 2", "x = 1\n\ny = 2"),

    # ── Enchant with string ───────────────────────────────
    "enchant_string_simple": (
        'enchant with string hello variable name',
        'f"hello {name}"',
    ),
    "enchant_string_multi_var": (
        'enchant with string hello variable name you are variable age',
        'f"hello {name} you are {age}"',
    ),
    "enchant_string_with_assign": (
        'greeting assign enchant with string hello variable name',
        'greeting = f"hello {name}"',
    ),
    "enchant_string_var_shorthand": (
        'enchant with string hi var name',
        'f"hi {name}"',
    ),

    # ── Enchant with math ─────────────────────────────────
    "enchant_math_matmul": ("enchant with math A mat mul B", "A @ B"),
    "enchant_math_dot": ("enchant with math A dot B", "nope.dot(A, B)"),
    "enchant_math_transpose": ("enchant with math transpose of A", "A.T"),
    "enchant_math_inverse": ("enchant with math inverse of A", "nope.linalg.inv(A)"),
    "enchant_math_determinant": ("enchant with math determinant of A", "nope.linalg.det(A)"),
    "enchant_math_cross": ("enchant with math A cross product B", "nope.cross(A, B)"),
    "enchant_math_ewise_times": ("enchant with math A element wise times B", "A * B"),
    "enchant_math_ewise_plus": ("enchant with math A element wise plus B", "A + B"),
    "enchant_math_ewise_minus": ("enchant with math A element wise minus B", "A - B"),
    "enchant_math_ewise_div": ("enchant with math A element wise divided by B", "A / B"),
    "enchant_math_transpose_matmul": (
        "enchant with math transpose of A mat mul B",
        "A.T @ B",
    ),
    "enchant_math_chained_transpose": (
        "enchant with math transpose of X mat mul transpose of Y",
        "X.T @ Y.T",
    ),
    "enchant_math_inverse_matmul": (
        "enchant with math inverse of A mat mul B",
        "nope.linalg.inv(A) @ B",
    ),
    "enchant_math_compound_ewise": (
        "enchant with math A element wise times B element wise plus C",
        "A * B + C",
    ),
    "enchant_math_with_assign": (
        "C assign enchant with math A mat mul B",
        "C = A @ B",
    ),
    "enchant_math_det_assign": (
        "det assign enchant with math determinant of A",
        "det = nope.linalg.det(A)",
    ),

    # ── STT mode ──────────────────────────────────────────
    "stt_periods": (None, None),  # handled separately below
}


# ═══════════════════════════════════════════════════════════════
# Layer 2: Validation Tests — output is valid Python
# ═══════════════════════════════════════════════════════════════

VALIDATION_CASES = [
    "let x be 5",
    "let name be string literal world",
    "call print with x",
    "open function greet with parameters name\n    call print with name\nclose function greet",
    "open if x is equal to 5\n    call print with x\nopen else\n    call print with 0\nclose if",
    "increase x by 1",
    "let y be empty list",
    "let z be empty dict",
    "let t be empty tuple",
    "let s be empty set",
    "x assign open paren 1 and 2 and 3 close paren",
    "x assign open paren close paren",
    "x assign group a plus b end group times c",
    "open if x logical and y\n    pass\nclose if",
    "comment this is a note",
    "as an aside testing",
    "literally x = [1, 2, 3]",
    "open class Dog inherits Animal\n    pass\nclose class Dog",
    "open for i in call range with 10\n    call print with i\nclose for",
    "open while x is greater than 0\n    decrease x by 1\nclose while",
    "open try\n    call foo\nopen except ValueError as e\n    call print with e\nclose try",
    "decorator staticmethod\nopen function my_method\n    pass\nclose function",
    "enchant with string hello variable name",
    "x assign enchant with math A mat mul B",
]


# ═══════════════════════════════════════════════════════════════
# Layer 3: Execution Tests — code actually runs
# ═══════════════════════════════════════════════════════════════

EXECUTION_CASES = [
    "let x be 5",
    "let y be empty list",
    "let z be empty dict",
    "let t be empty tuple",
    "let s be empty set",
    'let q be empty string',
    "x assign open paren 1 and 2 and 3 close paren",
    "let a be 10\nincrease a by 5",
    "let b be 20\ndecrease b by 3",
    "open function add with parameters x and y\n    return x plus y\nclose function add",
]


# ═══════════════════════════════════════════════════════════════
# Test Runner
# ═══════════════════════════════════════════════════════════════

def run_all():
    passed = failed = skipped = 0

    # Layer 1: Unit tests
    print("=== Unit Tests ===")
    for name, (src, expected) in UNIT_TESTS.items():
        if src is None:
            skipped += 1
            continue
        try:
            assert_transpile(src, expected, name)
            print(f"  PASS: {name}")
            passed += 1
        except AssertionError as e:
            print(f"  FAIL: {name}")
            print(f"    {e}")
            failed += 1

    # STT test (special case — needs stt_mode)
    stt_src = "let x be 5. let y be 10. let z be x plus y."
    stt_expected = "x = 5\ny = 10\nz = x + y"
    stt_result = transpile(stt_src, stt_mode=True)
    if stt_result == stt_expected:
        print("  PASS: stt_periods")
        passed += 1
    else:
        print(f"  FAIL: stt_periods\n    expected: {repr(stt_expected)}\n    got: {repr(stt_result)}")
        failed += 1

    # Layer 2: Validation tests
    print("\n=== Validation Tests (valid Python output) ===")
    if HAS_TREE_SITTER:
        for i, src in enumerate(VALIDATION_CASES):
            name = f"valid_python_{i}"
            try:
                assert_valid_python(src, name)
                print(f"  PASS: {name}: {src[:50]}")
                passed += 1
            except AssertionError as e:
                print(f"  {e}")
                failed += 1
    else:
        print("  SKIPPED: tree-sitter not installed")
        skipped += len(VALIDATION_CASES)

    # Layer 3: Execution tests
    print("\n=== Execution Tests (code runs) ===")
    for i, src in enumerate(EXECUTION_CASES):
        name = f"exec_{i}"
        try:
            assert_executes(src, name)
            print(f"  PASS: {name}: {src[:50]}")
            passed += 1
        except AssertionError as e:
            print(f"  {e}")
            failed += 1

    print(f"\n{'='*50}")
    print(f"TOTAL: {passed} passed, {failed} failed, {skipped} skipped")
    return failed


if __name__ == "__main__":
    failures = run_all()
    sys.exit(1 if failures else 0)
