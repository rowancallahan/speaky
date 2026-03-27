"""
Dialect Preprocessor

Translates dialect keywords → English Spoken Python keywords,
then passes through the normal transpiler pipeline.

Usage:
    from dialects.preprocessor import translate_dialect
    english_source = translate_dialect(latin_source, "church_latin")
"""

from importlib import import_module


def load_dialect(dialect_id: str):
    """Load a dialect module by ID."""
    mod = import_module(f"dialects.{dialect_id}")
    return mod.MULTI_WORD_KEYS, mod.SINGLE_WORD_KEYS


def translate_line(line: str, multi_word_keys, single_word_keys) -> str:
    """Translate a single line from dialect → English Spoken Python."""
    # Preserve leading whitespace
    stripped = line.lstrip()
    indent = line[:len(line) - len(stripped)]

    if not stripped:
        return line

    # First pass: multi-word replacements (longest first)
    result = stripped.lower()
    for dialect_phrase, english_phrase in multi_word_keys:
        result = result.replace(dialect_phrase, english_phrase)

    # Second pass: single-word replacements (word boundary aware)
    words = result.split()
    translated = []
    for word in words:
        translated.append(single_word_keys.get(word, word))

    return indent + " ".join(translated)


def translate_dialect(source: str, dialect_id: str) -> str:
    """Translate full source from dialect → English Spoken Python."""
    multi, single = load_dialect(dialect_id)
    lines = source.split("\n")
    return "\n".join(translate_line(line, multi, single) for line in lines)
