# Spoken Python Roadmap

## Vision

A family of spoken programming dialects optimized for voice dictation:
1. **Spoken Python** — general purpose programming via voice
2. **Spoken APL** (future) — mathematical/array programming via voice, leveraging APL's concise semantics

The shared design constraint: every keyword must be a **common English word** that modern speech-to-text engines (Whisper, Deepgram, AssemblyAI) transcribe with near-perfect accuracy. No jargon, no abbreviations, no ambiguous homophones.

---

## Phase 1: Core Language (v0.1) ✅ DONE

- [x] Block delimiters: `open function` / `close function`, `open if` / `close if`, etc.
- [x] Operator mappings: `assign`, `equals`, `greater than`, `plus`, `times`, etc.
- [x] String literals: `string literal hello world` → `"hello world"`
- [x] Function calls: `call print with x` → `print(x)`
- [x] Method calls: `call x dot append with 5` → `x.append(5)`
- [x] Comments, decorators, indexing, slicing, list literals
- [x] Nested block tracking with correct indentation
- [x] CLI tool: `python spoken_python.py input.spk`
- [x] Test suite (21 tests passing)

## Phase 2: Expression Parser (v0.2)

**The big problem:** v0.1 treats each space-separated token as an argument. `call foo with n minus 1` becomes `foo(n, -, 1)` instead of `foo(n - 1)`. Need a real expression parser.

- [ ] Implement a recursive descent parser for expressions
- [ ] Distinguish between argument boundaries and operators within expressions
- [ ] Support parenthesized subexpressions: `open paren x plus y close paren times z`
- [ ] Handle operator precedence
- [ ] Support chained method calls: `call x dot strip dot split`
- [ ] Inline conditionals: `x if y else z`

**Design decision:** Use `comma` as the explicit argument separator:
```
call foo with n minus 1 comma y plus 2
```
→ `foo(n - 1, y + 2)`

## Phase 3: Speech-to-Text Integration (v0.3)

- [ ] Pipe Whisper/Deepgram output directly into the preprocessor
- [ ] Fuzzy matching for common transcription errors:
  - "define" → `open function` (common mistranscription)
  - "print" sometimes becomes "prince" — handle it
- [ ] Punctuation normalization (STT sometimes inserts periods, commas)
- [ ] Homophone disambiguation: "for/four", "two/to/too", "or/ore"
- [ ] Confidence-based ambiguity flagging (if STT gives alternatives, pick the one that parses)
- [ ] Real-time mode: process line-by-line as speech comes in

## Phase 4: Advanced Python Features (v0.4)

- [ ] List comprehensions: `list comprehension x times 2 for x in range 10 if x greater than 3`
- [ ] Dictionary comprehensions
- [ ] Generator expressions
- [ ] Lambda: `lambda x comma y colon x plus y`
- [ ] Type hints: `open function foo parameters x type int returns int`
- [ ] Async/await: `open async function fetch parameters url`
- [ ] Context managers (`open with`)
- [ ] Multiple assignment: `x comma y assign 1 comma 2`
- [ ] Unpacking: `star args`, `double star kwargs`

## Phase 5: Tooling (v0.5)

- [ ] VS Code extension: live preview of Python output
- [ ] Syntax highlighting for .spk files
- [ ] Error messages that reference Spoken Python line numbers
- [ ] Auto-formatter: normalize spoken python to canonical form
- [ ] Round-trip: Python → Spoken Python (for reading code aloud)
- [ ] REPL mode: speak a line, see Python, execute

## Phase 6: Spoken APL (v1.0+)

A second dialect optimized for math and array programming.

**Why APL?** APL operators map beautifully to English words:
- `⍳` (iota) → `sequence of` (generates 1..n)
- `⍴` (rho) → `reshape` (reshape array)
- `+/` (plus reduce) → `sum of`
- `×/` (times reduce) → `product of`
- `⌈` (ceiling) → `max of` / `ceiling of`
- `⌊` (floor) → `min of` / `floor of`
- `∘.×` (outer product) → `outer product times`

APL's tacit/point-free style means **fewer variable names to speak**, which makes it faster to dictate than Python for mathematical work.

**Target use case:** Data analysis, matrix operations, mathematical exploration — all via voice.

---

## Design Principles for All Dialects

### STT-Friendly Vocabulary
Every keyword must be:
1. **A common English word** — high recognition accuracy across all STT engines
2. **Phonetically distinct** — no near-homophones with other keywords
3. **Multi-syllable when possible** — harder to confuse than monosyllables
4. **Not a common filler word** — avoid "um", "like", "so" which STT may insert

### Known Risky Words (track misrecognition rates)
| Word | Risk | Mitigation |
|---|---|---|
| `for` | Confused with "four" | Context: only valid after `open` |
| `or` | Confused with "ore" | Low-risk in boolean context |
| `in` | Common filler | Context: only valid after `for X` |
| `not` | Confused with "knot" | Low-risk |
| `pass` | Confused with "past" | Low-risk — unique in context |

### The 95% Rule
If a keyword is correctly transcribed 95%+ of the time by Whisper on clear speech, it's acceptable. Below that, find an alternative.

---

## Architecture

```
[Speech] → [STT Engine] → [Transcript] → [Spoken Python Preprocessor] → [Python AST] → [Execute]
                                              ↓
                                    [Fuzzy Error Recovery]
                                    [Ambiguity Resolution]
```

The preprocessor is deterministic. All intelligence/ML lives in the STT layer and the optional fuzzy recovery layer. This separation of concerns means:
- The grammar can be formally verified
- The preprocessor can be tested without audio
- STT engines can be swapped freely
