# Spoken Python Grammar Specification v0.1

## Design Principles

1. **Minimal divergence:** If Python syntax is already speakable, keep it identical
2. **Explicit blocks:** Replace indentation with `open X` / `close X` pairs
3. **Deterministic:** Every Spoken Python input produces exactly one Python output
4. **Transcript-friendly:** Designed to survive speech-to-text transcription artifacts

## Block Delimiters

The core addition. Every Python block construct gets explicit open/close markers.

### Functions
```
open function <name> [parameters <param1> <param2> ...]
    <body>
close function <name>
```
→ Compiles to:
```python
def <name>(<param1>, <param2>):
    <body>
```

The name after `close function` is optional but recommended for readability:
```
close function          # also valid
close function greet    # preferred — helps match blocks
```

### Classes
```
open class <Name> [inherits <Parent>]
    <body>
close class <Name>
```
→
```python
class <Name>(<Parent>):
    <body>
```

### Conditionals
```
open if <condition>
    <body>
open elif <condition>
    <body>
open else
    <body>
close if
```
→
```python
if <condition>:
    <body>
elif <condition>:
    <body>
else:
    <body>
```

Note: `elif` and `else` implicitly close the previous branch. Only one `close if` needed at the end.

### Loops
```
open for <var> in <iterable>
    <body>
close for

open while <condition>
    <body>
close while
```

### With Statements
```
open with call open with string literal data.txt as f
    <body>
close with
```

### Try/Except
```
open try
    <body>
open except <ExceptionType> as <var>
    <body>
open finally
    <body>
close try
```

## Operators

### Comparison
| Spoken | Python |
|---|---|
| `equals` | `==` |
| `not equals` | `!=` |
| `greater than` | `>` |
| `less than` | `<` |
| `greater than or equal to` | `>=` |
| `less than or equal to` | `<=` |

### Assignment
| Spoken | Python |
|---|---|
| `assign` | `=` |
| `plus assign` | `+=` |
| `minus assign` | `-=` |
| `times assign` | `*=` |

### Arithmetic
| Spoken | Python |
|---|---|
| `plus` | `+` |
| `minus` | `-` |
| `times` | `*` |
| `divided by` | `/` |
| `integer divided by` | `//` |
| `modulo` | `%` |
| `to the power of` | `**` |

### Logical (unchanged from Python)
`and`, `or`, `not` — pass through as-is.

### String
| Spoken | Python |
|---|---|
| `concatenate` | `+` |

## Literals

### Strings
```
string literal hello world
```
→ `"hello world"`

The `string literal` prefix marks the start. The string continues until the next keyword or end of line.

### F-strings
```
f string literal hello open expression name close expression
```
→ `f"hello {name}"`

### Numbers
Numbers pass through unchanged: `42`, `3.14`, `-7`

### Booleans and None
`True`, `False`, `None` — unchanged.

### Lists
```
list of 1 2 3
```
→ `[1, 2, 3]`

### Dictionaries
```
dictionary of key string literal name value string literal Alice key string literal age value 30
```
→ `{"name": "Alice", "age": 30}`

## Function Calls
```
call <function> with <arg1> <arg2> ...
call print with string literal hello
call range with 0 10 2
```
→
```python
print("hello")
range(0, 10, 2)
```

For method calls:
```
call x dot append with 5
```
→ `x.append(5)`

For no-argument calls:
```
call foo
```
→ `foo()`

## Indexing and Slicing
```
index x at 0
slice x from 1 to 5
```
→ `x[0]`, `x[1:5]`

## Keywords That Pass Through Unchanged

These Python keywords are already speakable and need no translation:
- `return`, `yield`
- `import`, `from`, `as`
- `pass`, `break`, `continue`
- `global`, `nonlocal`
- `assert`, `raise`
- `del`
- `lambda`
- `in`, `is`, `not in`, `is not`
- `True`, `False`, `None`
- `and`, `or`, `not`

## Comments
```
comment this is a note
```
→ `# this is a note`

## Decorators
```
decorator staticmethod
open function my_method
    pass
close function
```
→
```python
@staticmethod
def my_method():
    pass
```

## Line Handling

Each line of Spoken Python maps to one line of Python. Blank lines pass through. The preprocessor:
1. Reads each line
2. Tracks indentation depth via open/close pairs
3. Applies keyword substitutions
4. Outputs indented Python

## Ambiguity Resolution

When a word could be a keyword or a variable name, context determines meaning:
- `assign` at the start of a line after a variable name → `=`
- `equals` between two expressions → `==`
- `open` at the start of a line → block opener
- `open` elsewhere → the variable/function named `open`

## Future Extensions (v0.2+)

- Multiline expressions
- List comprehensions: `list comprehension x for x in range 10 if x greater than 5`
- Type hints: `open function foo parameters x type int returns int`
- Async/await support
- Error recovery for common transcription mistakes
