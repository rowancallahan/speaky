# Session Summary — 2026-03-26

## What Was Built

### Spoken Python v0.1 → v0.2
A formal English dialect that deterministically transpiles to Python. Not AI-based — it's a compiler.

### Core Architecture (transpiler.py)
- **Tokenizer** → **Parser** → **Code Generator** pipeline (AST-based)
- No regex in parsing — word-by-word scanning throughout
- `spoken_python.py` CLI delegates to `transpiler.py`

### Grammar Features

**Block delimiters** (replaces Python indentation):
- `open function greet with parameters name and age` → `def greet(name, age):`
- `close function greet` → dedent
- Same for `class`, `if/elif/else`, `for`, `while`, `with`, `try/except/finally`

**Natural assignment**:
- `let x be 5` → `x = 5`
- `x assign 5` → `x = 5` (terse form)
- `increase x by 1` → `x += 1`
- `decrease x by 2` → `x -= 2`

**Natural comparison**:
- `x is equal to 5` → `x == 5`
- `x is greater than 3` → `x > 3`
- `x is not equal to 0` → `x != 0`

**Parentheses and tuples**:
- `open paren X and Y close paren` → `(X, Y)` — tuple
- `open paren close paren` → `()` — empty tuple
- `open paren X close paren` → `(X,)` — single-element tuple
- `group X plus Y end group` → `(X + Y)` — grouping (not tuple)

**Logical operators** (distinguished from tuple `and`):
- `logical and` → `and`
- `logical or` → `or`
- `logical not` → `not`
- Plain `and` inside `open paren` = tuple separator

**Comments**:
- `comment X` → `# X`
- `as an aside X` → `# X`
- `aside X` → `# X`

**Escape hatch**:
- `literally <raw python>` → passes through unchanged

**STT mode** (`--stt` flag):
- Periods become line breaks: `let x be 5. let y be 10.` → two lines
- Preserves decimal numbers like `3.14`

### Enchantments

**`enchant with string`** — f-string builder:
- `enchant with string hello variable name` → `f"hello {name}"`

**`enchant with math`** — numpy matrix ops (uses `nope` as numpy alias):
- `A mat mul B` → `A @ B`
- `A dot B` → `nope.dot(A, B)`
- `transpose of A` → `A.T`
- `inverse of A` → `nope.linalg.inv(A)`
- `determinant of A` → `nope.linalg.det(A)`
- `A cross product B` → `nope.cross(A, B)`
- `A element wise times B` → `A * B`

**`enchant with rejection`** — regex builder (basic, kept simple for now)

### Tests
- `test_spoken_python.py` — 21 core tests
- `test_enchantments.py` — 21 enchantment tests
- All passing

### Formal Grammar
- `grammar.bnf` — full BNF specification
- `tree-sitter-spoken-python/grammar.js` — tree-sitter grammar (needs update for latest features)

### Micrograd Stress Test
Translated Karpathy's micrograd engine.py (autograd/backprop) to Spoken Python:
- **79% spoken syntax**, 21% `literally` passthrough
- `examples/micrograd.spk` — the spoken version

## Known Gaps (Phase 2 Priorities)

1. **Expression parser** — The biggest gap. `call X with A B else C` can't distinguish call args from ternary `else`. Need explicit `comma` separator or a real recursive descent parser.
2. **Default parameters** — `open function foo with parameters x and y defaults to 5` not implemented
3. **Empty collections** — `empty list` → `[]`, `empty dict` → `{}`
4. **Ternary inside expressions** — Works as passthrough but breaks when mixed with `call`
5. **Tree-sitter grammar needs update** — Missing: parens/tuples, `literally`, `as an aside`, `logical and/or/not`

## Design Decisions Made

- `and` = tuple/param separator, `logical and` = boolean operator
- `open paren / close paren` for tuples, `group / end group` for grouping
- `nope` as numpy alias (speakable, user handles `import numpy as nope`)
- `literally` escape hatch for complex Python that can't be spoken yet
- `as an aside` for comments (natural for dictation)
- Sentence-form functions: `open function greet with parameters name and age`
- STT mode strips periods as sentence boundaries

## Files

```
oralpython/
├── spoken_python.py       # CLI + delegates to transpiler
├── transpiler.py          # AST pipeline: tokenizer → parser → codegen
├── grammar.bnf            # Formal BNF grammar
├── GRAMMAR.md             # Human-readable grammar reference
├── ROADMAP.md             # 6-phase development plan
├── README.md              # Project overview
├── test_spoken_python.py  # 21 core tests
├── test_enchantments.py   # 21 enchantment tests
├── examples/
│   ├── hello.spk
│   ├── fizzbuzz.spk
│   ├── enchantments.spk
│   ├── natural.spk
│   ├── stt_raw.spk
│   └── micrograd.spk     # Karpathy micrograd in Spoken Python
└── tree-sitter-spoken-python/
    ├── grammar.js         # Tree-sitter grammar
    └── package.json
```

## Next Steps

1. Phase 2 expression parser (recursive descent, `comma` as arg separator)
2. Update tree-sitter grammar + Zed extension for syntax checking
3. Default parameters, empty collections
4. Reduce micrograd `literally` usage from 21% → ~5%
5. Spoken APL dialect for math (future)
