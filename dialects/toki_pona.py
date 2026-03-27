"""
Toki Pona Spoken Python — Dialect Map

Minimal language, minimal code. Numbers stay in English.
"pini" (finish/end) closes all blocks.

Example:
    pali fizzbuzz kepeken n
        pro i insa call range kepeken n
            la i modulo 15 sama 0
                toki kepeken nimi FizzBuzz
            ante
                toki kepeken i
            pini la
        pini pro
    pini pali

Word choice notes:
- Toki Pona has ~130 words so collisions are inevitable
- We disambiguate by using different words or multi-word phrases
- "insa" (inside) = in, "lon" (exist) = True
- "ala" alone = False, "ala li" = not equal (multi-word avoids collision)
"""

DIALECT_NAME = "Toki Pona"
DIALECT_ID = "toki_pona"

# Maps Toki Pona words → English Spoken Python words
KEYWORD_MAP = {
    # Block structure
    "pali": "function",
    "pini": "close",
    "kulupu": "class",
    "tan": "inherits",

    # Parameters
    "kepeken": "with",
    "ijo": "parameters",
    "en": "and",

    # Assignment — "X li Y" means "X is Y"
    "li": "is",

    # Conditionals
    "la": "if",
    "ante": "else",
    "ante la": "else if",

    # Loops
    "pro": "for",
    "insa": "in",           # "inside" = in (avoids lon collision)
    "awen": "while",

    # Calls — "call" stays as English, or use "o" (imperative marker)
    "o": "call",

    # Control flow
    "pana": "return",
    "pakala": "break",
    "tawa": "continue",

    # Comparison
    "sama": "equal to",
    "sama ala": "not equal to",
    "suli": "greater than",
    "lili": "less than",
    "suli sama": "greater or equal to",
    "lili sama": "less or equal to",

    # Logical
    "en lon": "logical and",
    "anu": "logical or",
    "ala lon": "logical not",

    # Booleans / None (distinct from operators)
    "lon": "True",
    "ala": "False",
    "weka": "None",

    # Literals
    "nimi": "string literal",
    "toki": "print",

    # Collections
    "weka kulupu": "empty list",
    "weka lipu": "empty dict",
    "weka tu": "empty tuple",
    "weka kulupu wan": "empty set",
    "weka nimi": "empty string",
    "kulupu pi": "list of",

    # Comments
    "toki lili": "comment",
    "toki insa": "as an aside",

    # Enchantments
    "pali suli kepeken": "enchant with",
    "ijo nimi": "variable",

    # Escape hatch
    "toki sama": "literally",

    # Other
    "kama": "import",
    "kama tan": "from",
    "sitelen": "decorator",
    "nanpa": "dot",
    "modulo": "modulo",
}

# Multi-word keys sorted longest first for greedy matching
MULTI_WORD_KEYS = sorted(
    [(k, v) for k, v in KEYWORD_MAP.items() if " " in k],
    key=lambda x: len(x[0]),
    reverse=True,
)

SINGLE_WORD_KEYS = {k: v for k, v in KEYWORD_MAP.items() if " " not in k}
