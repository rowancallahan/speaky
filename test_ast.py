"""AST comparison tests for Spoken Python.

For each test: spoken sentence → transpile → Python string → ast.parse
Verifies that our transpiled output produces an IDENTICAL Python AST
to the hand-written expected Python.
"""
import ast
import sys
sys.path.insert(0, '.')
from spoken_python import transpile


# (name, spoken_sentence, expected_python)
TESTS = [
    # ── Assignment ────────────────────────────────────────
    ("let assign", "the x is 5", "x = 5"),
    ("terse assign", "x assign 5", "x = 5"),
    ("let string", 'the name is string literal Alice', 'name = "Alice"'),
    ("let empty list", "the x is empty list", "x = []"),
    ("let empty dict", "the x is empty dict", "x = {}"),
    ("let empty tuple", "the x is empty tuple", "x = ()"),
    ("let empty set", "the x is empty set", "x = set()"),
    ("let empty string", 'the x is empty string', 'x = ""'),

    # ── Augmented assignment ──────────────────────────────
    ("increase by", "increase x by 1", "x += 1"),
    ("decrease by", "decrease x by 2", "x -= 2"),
    ("multiply by", "multiply x by 3", "x *= 3"),
    ("divide by", "divide x by 4", "x /= 4"),
    ("plus assign", "x plus assign 1", "x += 1"),
    ("minus assign", "x minus assign 1", "x -= 1"),

    # ── Attribute access (dot) ────────────────────────────
    ("dot assign", "self dot data assign 5", "self.data = 5"),
    ("dot augmented", "self dot grad plus assign out dot grad", "self.grad += out.grad"),
    ("dot call", "call x dot append with 5", "x.append(5)"),

    # ── Function calls ────────────────────────────────────
    ("implicit call", "print with x", "print(x)"),
    ("implicit call string", 'print with string literal hello', 'print("hello")'),
    ("implicit call assign", "the result is foo with x", "result = foo(x)"),
    ("explicit call", "call print with x", "print(x)"),
    ("call no args", "call foo", "foo()"),

    # ── Collections ───────────────────────────────────────
    ("tuple multi", "x assign open paren 1 and 2 and 3 close paren", "x = (1, 2, 3)"),
    ("tuple empty", "x assign open paren close paren", "x = ()"),
    ("tuple single", "x assign open paren self close paren", "x = (self,)"),
    ("grouping", "x assign group a plus b end group times c", "x = (a + b) * c"),
    ("list of", "list of 1 2 3", "[1, 2, 3]"),
    ("index", "index x at 0", "x[0]"),
    ("slice", "slice x from 1 to 5", "x[1:5]"),

    # ── Comparison ────────────────────────────────────────
    ("equals", "x equals 5", "x == 5"),
    ("logical and", "x assign a logical and b", "x = a and b"),

    # ── Strings ───────────────────────────────────────────
    ("string literal", 'x assign string literal hello world', 'x = "hello world"'),
    ("enchant string", 'enchant with string hello variable name', 'f"hello {name}"'),
    ("enchant string dotted", 'enchant with string data is variable self dot data', 'f"data is {self.data}"'),

    # ── Comments ──────────────────────────────────────────
    ("comment", "comment this is a note", "# this is a note"),
    ("as an aside", "as an aside gradient computation", "# gradient computation"),

    # ── Escape hatch ──────────────────────────────────────
    ("literally", "literally x = [1, 2, 3]", "x = [1, 2, 3]"),

    # ── Passthrough ───────────────────────────────────────
    ("return", "return x", "return x"),
    ("import", "import os", "import os"),
    ("from import", "from os import path", "from os import path"),
    ("pass", "pass", "pass"),
    ("break", "break", "break"),

    # ── Enchant math ──────────────────────────────────────
    ("mat mul", "enchant with math A mat mul B", "A @ B"),
    ("transpose", "enchant with math transpose of A", "A.T"),

    # ── Function definitions ──────────────────────────────
    ("function def",
     "function greet with parameters name\n    call print with name\nclose function greet",
     "def greet(name):\n    print(name)"),
    ("function multi params",
     "function add with parameters x and y and z\n    pass\nclose function",
     "def add(x, y, z):\n    pass"),
    ("function defaults",
     "function foo with parameters x and y with default 5\n    return x plus y\nclose function",
     "def foo(x, y=5):\n    return x + y"),
    ("function unpack",
     "function foo with parameters x and unpack arguments and unpack keyword kwargs\n    pass\nclose function",
     "def foo(x, *arguments, **kwargs):\n    pass"),
    ("function no params",
     "function main\n    pass\nclose function",
     "def main():\n    pass"),

    # ── Class definitions ─────────────────────────────────
    ("class inherit",
     "class Dog inherits Animal\n    pass\nclose class Dog",
     "class Dog(Animal):\n    pass"),

    # ── Conditionals ──────────────────────────────────────
    ("if else",
     "if x equal to 5\n    print with x\nelse\n    print with 0\nclose if",
     "if x == 5:\n    print(x)\nelse:\n    print(0)"),
    ("bare if else if else",
     "if x greater than 10\n    print with string literal big\nelse if x greater than 5\n    print with string literal medium\nelse\n    print with string literal small\nclose if",
     'if x > 10:\n    print("big")\nelif x > 5:\n    print("medium")\nelse:\n    print("small")'),
    ("bare for loop",
     "for i in range with 10\n    print with i\nclose for",
     "for i in range(10):\n    print(i)"),
    ("bare while loop",
     "while x greater than 0\n    decrease x by 1\nclose while",
     "while x > 0:\n    x -= 1"),

    # ── Exception handling ────────────────────────────────
    ("try except",
     "open try\n    call foo\nopen except ValueError as e\n    call print with e\nclose try",
     "try:\n    foo()\nexcept ValueError as e:\n    print(e)"),

    # ── Decorators ────────────────────────────────────────
    ("decorator simple",
     "decorator staticmethod\nfunction my_method\n    pass\nclose function",
     "@staticmethod\ndef my_method():\n    pass"),
    ("decorator with args",
     'decorator call app dot route with string literal /\nfunction index\n    pass\nclose function',
     '@app.route("/")\ndef index():\n    pass'),

    # ── Pipe operator ─────────────────────────────────────
    ("then pipe",
     "the result is cars then filter rows",
     "result = cars >> filter_rows"),
    ("pipe keyword",
     "the result is data pipe group by",
     "result = data >> group_by"),
    ("then chain",
     "the result is cars then filter rows then arrange",
     "result = cars >> filter_rows >> arrange"),
    ("multi-word variable then pipe",
     "the clean data is raw data then filter rows",
     "clean_data = raw_data >> filter_rows"),

    # ── Multi-word identifiers ─────────────────────────────
    ("multi-word variable",
     "the horse power is 200",
     "horse_power = 200"),
    ("multi-word variable three words",
     "the miles per gallon is 30",
     "miles_per_gallon = 30"),
    ("multi-word function def",
     "function fizz buzz with parameters n\n    pass\nclose function",
     "def fizz_buzz(n):\n    pass"),
    ("multi-word function call",
     "call fizz buzz with 15",
     "fizz_buzz(15)"),
    ("multi-word call args",
     "call foo with horse power and fuel type",
     "foo(horse_power, fuel_type)"),
    ("multi-word params",
     "function compute with parameters horse power and fuel type\n    pass\nclose function",
     "def compute(horse_power, fuel_type):\n    pass"),

    # ── Spoken dplyr verbs ────────────────────────────────
    ("count with string literal",
     "count with string literal make",
     'count("make")'),
    ("group_by with string literal",
     "group by with string literal make",
     'group_by("make")'),
    ("arrange with string literal",
     "arrange with string literal mpg",
     'arrange("mpg")'),
    ("filter_rows with string literal",
     "filter rows with string literal mpg > 20",
     'filter_rows("mpg > 20")'),
    ("select_cols two cols",
     "select cols with string literal make and string literal mpg",
     'select_cols("make", "mpg")'),

    # ── Nested blocks ─────────────────────────────────────
    ("nested function",
     "function foo with parameters x\n    if x greater than 0\n        return x\n    close if\n    return 0\nclose function foo",
     "def foo(x):\n    if x > 0:\n        return x\n    return 0"),
]


def run():
    passed = failed = 0
    for name, spoken, expected_python in TESTS:
        our_python = transpile(spoken)

        # Check 1: string output matches
        if our_python != expected_python:
            print(f"FAIL [{name}]: output mismatch")
            print(f"  spoken:   {spoken[:70]}")
            print(f"  expected: {expected_python}")
            print(f"  got:      {our_python}")
            failed += 1
            continue

        # Check 2: ASTs are identical
        try:
            our_ast = ast.dump(ast.parse(our_python))
            expected_ast = ast.dump(ast.parse(expected_python))
            if our_ast == expected_ast:
                passed += 1
            else:
                print(f"FAIL [{name}]: AST mismatch")
                failed += 1
        except SyntaxError as e:
            print(f"FAIL [{name}]: SyntaxError: {e}")
            failed += 1

    print(f"\n{passed} passed, {failed} failed")
    print("Each test: spoken sentence \u2192 transpile \u2192 Python string = expected \u2192 ast.parse identical")
    return failed


if __name__ == "__main__":
    sys.exit(1 if run() else 0)
