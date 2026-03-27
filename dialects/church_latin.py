"""
Church Latin Spoken Python — Dialect Map

"Amen" closes all blocks. Code as liturgy.

Example:
    functio fizzbuzz cum parametris n
        pro i in voca range cum n
            si i modulo 15 aequalis 0
                scribe cum verbum FizzBuzz
            aliter
                scribe cum i
            amen si
        amen pro
    amen functio
"""

DIALECT_NAME = "Church Latin"
DIALECT_ID = "church_latin"

# Maps Church Latin words → English Spoken Python words
# Only non-English words need mapping; English words pass through unchanged
KEYWORD_MAP = {
    # Block structure
    "functio": "function",
    "amen": "close",
    "classis": "class",
    "hereditat": "inherits",

    # Parameters
    "cum": "with",
    "parametris": "parameters",
    "et": "and",

    # Assignment
    "est": "is",
    # "the" stays as "the" — or use Latin article-free style

    # Conditionals
    "si": "if",
    "aliter": "else",
    "aliter si": "else if",

    # Loops
    "pro": "for",
    "dum": "while",
    "in": "in",

    # Calls
    "voca": "call",
    "scribe": "print",

    # Control flow
    "redde": "return",
    "transeat": "pass",
    "frange": "break",
    "perge": "continue",

    # Comparison
    "aequalis": "equal to",
    "non aequalis": "not equal to",
    "maior quam": "greater than",
    "minor quam": "less than",
    "maior vel aequalis": "greater or equal to",
    "minor vel aequalis": "less or equal to",

    # Logical
    "logice et": "logical and",
    "logice vel": "logical or",
    "non": "logical not",

    # Literals
    "verbum": "string literal",
    "verum": "True",
    "falsum": "False",
    "nihil": "None",

    # Collections
    "vacuus index": "empty list",
    "vacuus lexicon": "empty dict",
    "vacuus par": "empty tuple",
    "vacuus grex": "empty set",
    "vacuus verbum": "empty string",
    "index de": "list of",

    # Comments
    "nota": "comment",
    "notandum": "as an aside",

    # Enchantments
    "incanta cum": "enchant with",
    "variabilis": "variable",

    # Escape hatch
    "ad litteram": "literally",

    # Other
    "importa": "import",
    "ex": "from",
    "ornamentum": "decorator",
    "punctum": "dot",
    "modulo": "modulo",
}

# Multi-word keys sorted longest first for greedy matching
MULTI_WORD_KEYS = sorted(
    [(k, v) for k, v in KEYWORD_MAP.items() if " " in k],
    key=lambda x: len(x[0]),
    reverse=True,
)

SINGLE_WORD_KEYS = {k: v for k, v in KEYWORD_MAP.items() if " " not in k}
