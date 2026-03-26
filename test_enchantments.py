"""Tests for Spoken Python enchantments."""
from spoken_python import transpile


# ─── Enchant with String ────────────────────────────────────────────────────

def test_enchant_string_simple():
    assert transpile("enchant with string hello variable name") == 'f"hello {name}"'


def test_enchant_string_multi_var():
    src = "enchant with string hello variable name you are variable age"
    assert transpile(src) == 'f"hello {name} you are {age}"'


def test_enchant_string_inline_var():
    src = "enchant with string item variable i of variable total"
    assert transpile(src) == 'f"item {i} of {total}"'


def test_enchant_string_with_assign():
    src = "greeting assign enchant with string hello variable name"
    assert transpile(src) == 'greeting = f"hello {name}"'


def test_enchant_string_var_shorthand():
    """'var' works as shorthand for 'variable'."""
    assert transpile("enchant with string hi var name") == 'f"hi {name}"'


# ─── Enchant with Math ──────────────────────────────────────────────────────

def test_enchant_math_mat_mul():
    assert transpile("enchant with math A mat mul B") == "A @ B"


def test_enchant_math_mat_mul_with_assign():
    assert transpile("C assign enchant with math A mat mul B") == "C = A @ B"


def test_enchant_math_dot():
    assert transpile("enchant with math A dot B") == "nope.dot(A, B)"


def test_enchant_math_transpose():
    assert transpile("enchant with math transpose of A") == "A.T"


def test_enchant_math_transpose_mat_mul():
    assert transpile("enchant with math transpose of A mat mul B") == "A.T @ B"


def test_enchant_math_chained_transpose():
    src = "enchant with math transpose of X mat mul transpose of Y"
    assert transpile(src) == "X.T @ Y.T"


def test_enchant_math_inverse():
    assert transpile("enchant with math inverse of A") == "nope.linalg.inv(A)"


def test_enchant_math_inverse_mat_mul():
    src = "enchant with math inverse of A mat mul B"
    assert transpile(src) == "nope.linalg.inv(A) @ B"


def test_enchant_math_determinant():
    assert transpile("enchant with math determinant of A") == "nope.linalg.det(A)"


def test_enchant_math_determinant_with_assign():
    src = "det assign enchant with math determinant of A"
    assert transpile(src) == "det = nope.linalg.det(A)"


def test_enchant_math_cross_product():
    assert transpile("enchant with math A cross product B") == "nope.cross(A, B)"


def test_enchant_math_element_wise_times():
    assert transpile("enchant with math A element wise times B") == "A * B"


def test_enchant_math_element_wise_plus():
    assert transpile("enchant with math A element wise plus B") == "A + B"


def test_enchant_math_element_wise_minus():
    assert transpile("enchant with math A element wise minus B") == "A - B"


def test_enchant_math_element_wise_divided_by():
    src = "enchant with math A element wise divided by B"
    assert transpile(src) == "A / B"


def test_enchant_math_compound_element_wise():
    src = "enchant with math A element wise times B element wise plus C"
    assert transpile(src) == "A * B + C"


if __name__ == "__main__":
    import sys
    sys.path.insert(0, '.')
    tests = [name for name, obj in list(globals().items()) if name.startswith('test_') and callable(obj)]
    passed = failed = 0
    for t in sorted(tests):
        try:
            globals()[t]()
            print(f'  PASS: {t}')
            passed += 1
        except Exception as e:
            print(f'  FAIL: {t}: {e}')
            failed += 1
    print(f'\n{passed} passed, {failed} failed')
