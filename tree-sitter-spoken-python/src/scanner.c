#include "tree_sitter/parser.h"
#include <string.h>
#include <ctype.h>

// External scanner for Spoken Python
// Handles EXPRESSION_LINE — matches an entire line only when
// it does NOT start with a known keyword.

enum TokenType {
    EXPRESSION_LINE,
};

// Keywords that start structured statements
static const char *KEYWORDS[] = {
    "open", "close", "comment", "aside", "as",
    "literally", "decorator", "let",
    "increase", "decrease", "multiply", "divide",
    "enchant", "call", "if", "else", "for", "while",
    NULL,
};

void *tree_sitter_spoken_python_external_scanner_create(void) { return NULL; }
void tree_sitter_spoken_python_external_scanner_destroy(void *p) {}
unsigned tree_sitter_spoken_python_external_scanner_serialize(void *p, char *buf) { return 0; }
void tree_sitter_spoken_python_external_scanner_deserialize(void *p, const char *buf, unsigned len) {}

bool tree_sitter_spoken_python_external_scanner_scan(
    void *payload,
    TSLexer *lexer,
    const bool *valid_symbols
) {
    if (!valid_symbols[EXPRESSION_LINE]) return false;

    // We must be at the beginning of a line (after optional whitespace).
    // Skip whitespace.
    while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
        lexer->advance(lexer, true);  // skip as whitespace
    }

    // At newline or EOF? No match.
    if (lexer->lookahead == '\n' || lexer->lookahead == '\r' || lexer->eof(lexer)) {
        return false;
    }

    // Read the first word to check if it's a keyword
    char word[32];
    int len = 0;
    // Peek without committing — use mark_end to checkpoint
    lexer->mark_end(lexer);

    while (len < 31 && isalpha(lexer->lookahead)) {
        word[len++] = (char)lexer->lookahead;
        lexer->advance(lexer, false);
    }
    word[len] = '\0';

    // Check if first word is a keyword followed by space/newline/EOF
    if (len > 0) {
        bool after_word_ok = (lexer->lookahead == ' ' || lexer->lookahead == '\t' ||
                              lexer->lookahead == '\n' || lexer->lookahead == '\r' ||
                              lexer->eof(lexer));
        if (after_word_ok) {
            for (const char **kw = KEYWORDS; *kw != NULL; kw++) {
                if (strcmp(word, *kw) == 0) {
                    // Keyword found — do NOT match as expression_line
                    return false;
                }
            }
        }
    }

    // Not a keyword line. Consume everything up to newline.
    while (lexer->lookahead != '\n' && lexer->lookahead != '\r' && !lexer->eof(lexer)) {
        lexer->advance(lexer, false);
    }

    lexer->mark_end(lexer);
    lexer->result_symbol = EXPRESSION_LINE;
    return true;
}
