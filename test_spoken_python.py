"""Tests for the Spoken Python preprocessor."""
import pytest
from spoken_python import transpile


def test_function_definition():
    assert transpile("open function foo parameters x y\n    pass\nclose function foo") == \
        "def foo(x, y):\n    pass"


def test_function_no_params():
    assert transpile("open function main\n    pass\nclose function") == \
        "def main():\n    pass"


def test_class_definition():
    assert transpile("open class Dog\n    pass\nclose class Dog") == \
        "class Dog:\n    pass"


def test_class_inheritance():
    assert transpile("open class Dog inherits Animal\n    pass\nclose class Dog") == \
        "class Dog(Animal):\n    pass"


def test_if_else():
    src = "open if x equals 5\n    call print with x\nopen else\n    call print with 0\nclose if"
    expected = "if x == 5:\n    print(x)\nelse:\n    print(0)"
    assert transpile(src) == expected


def test_for_loop():
    src = "open for i in call range with 10\n    call print with i\nclose for"
    expected = "for i in range(10):\n    print(i)"
    assert transpile(src) == expected


def test_while_loop():
    src = "open while x greater than 0\n    x minus assign 1\nclose while"
    expected = "while x > 0:\n    x -= 1"
    assert transpile(src) == expected


def test_operators():
    assert transpile("x assign 5") == "x = 5"
    assert transpile("x plus assign 1") == "x += 1"
    assert transpile("y assign x times 2 plus 1") == "y = x * 2 + 1"
    assert transpile("x to the power of 2") == "x ** 2"
    assert transpile("x integer divided by 3") == "x // 3"


def test_comparison_operators():
    assert transpile("x equals 5") == "x == 5"
    assert transpile("x not equals 5") == "x != 5"
    assert transpile("x greater than or equal to 5") == "x >= 5"
    assert transpile("x less than or equal to 5") == "x <= 5"


def test_string_literal():
    assert transpile("x assign string literal hello world") == 'x = "hello world"'


def test_function_call_with_args():
    assert transpile("call print with x") == "print(x)"
    assert transpile("call range with 0 10") == "range(0, 10)"


def test_function_call_no_args():
    assert transpile("call foo") == "foo()"


def test_method_call():
    assert transpile("call x dot append with 5") == "x.append(5)"


def test_comment():
    assert transpile("comment this is a note") == "# this is a note"


def test_decorator():
    src = "decorator staticmethod\nopen function my_method\n    pass\nclose function"
    expected = "@staticmethod\ndef my_method():\n    pass"
    assert transpile(src) == expected


def test_indexing():
    assert transpile("index x at 0") == "x[0]"


def test_slicing():
    assert transpile("slice x from 1 to 5") == "x[1:5]"


def test_list_literal():
    assert transpile("list of 1 2 3") == "[1, 2, 3]"


def test_pass_through_keywords():
    assert transpile("return x") == "return x"
    assert transpile("import os") == "import os"
    assert transpile("from os import path") == "from os import path"
    assert transpile("pass") == "pass"
    assert transpile("break") == "break"
    assert transpile("continue") == "continue"


def test_try_except():
    src = "open try\n    call foo\nopen except ValueError as e\n    call print with e\nclose try"
    expected = "try:\n    foo()\nexcept ValueError as e:\n    print(e)"
    assert transpile(src) == expected


def test_blank_lines_preserved():
    assert transpile("x assign 1\n\ny assign 2") == "x = 1\n\ny = 2"


def test_nested_blocks():
    src = (
        "open function foo parameters x\n"
        "    open if x greater than 0\n"
        "        return x\n"
        "    close if\n"
        "    return 0\n"
        "close function foo"
    )
    expected = (
        "def foo(x):\n"
        "    if x > 0:\n"
        "        return x\n"
        "    return 0"
    )
    assert transpile(src) == expected


if __name__ == "__main__":
    pytest.main([__file__, "-v"])
