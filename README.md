# Spoken Python (OralPython)

A dialect of English that deterministically transpiles to Python.

**The problem:** Python uses indentation for scope, which is impossible to dictate verbally. Existing voice-coding tools use AI/ML to interpret intent. Spoken Python instead defines a **formal grammar** — a subset of English with explicit block delimiters — that compiles predictably to valid Python.

**The principle:** Spoken Python IS Python, except where Python relies on things you can't say (whitespace, punctuation, symbols).

## Quick Example

**Spoken Python:**
```
open function greet parameters name
    greeting assign string literal hello concatenate name
    call print with greeting
close function greet

call greet with string literal world
```

**Compiles to:**
```python
def greet(name):
    greeting = "hello" + name
    print(greeting)

greet("world")
```

## Grammar Reference

See [GRAMMAR.md](GRAMMAR.md) for the full specification.

## Usage

```bash
python spoken_python.py input.spk           # outputs to stdout
python spoken_python.py input.spk -o out.py # outputs to file
```

## Roadmap

See [ROADMAP.md](ROADMAP.md) for the development plan.
