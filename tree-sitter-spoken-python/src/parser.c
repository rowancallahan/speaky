#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 64
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 61
#define ALIAS_COUNT 0
#define TOKEN_COUNT 36
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym__newline = 1,
  anon_sym_comment = 2,
  aux_sym_comment_token1 = 3,
  anon_sym_aside = 4,
  anon_sym_as = 5,
  anon_sym_an = 6,
  anon_sym_literally = 7,
  anon_sym_decorator = 8,
  anon_sym_open = 9,
  anon_sym_function = 10,
  anon_sym_class = 11,
  anon_sym_if = 12,
  anon_sym_elif = 13,
  anon_sym_else = 14,
  anon_sym_for = 15,
  anon_sym_while = 16,
  anon_sym_with = 17,
  anon_sym_try = 18,
  anon_sym_except = 19,
  anon_sym_finally = 20,
  anon_sym_close = 21,
  anon_sym_let = 22,
  aux_sym_let_assignment_token1 = 23,
  anon_sym_be = 24,
  anon_sym_increase = 25,
  anon_sym_decrease = 26,
  anon_sym_multiply = 27,
  anon_sym_divide = 28,
  anon_sym_by = 29,
  anon_sym_enchant = 30,
  anon_sym_string = 31,
  anon_sym_rejection = 32,
  anon_sym_math = 33,
  anon_sym_call = 34,
  sym_expression_line = 35,
  sym_program = 36,
  sym__statement = 37,
  sym_comment = 38,
  sym_aside_comment = 39,
  sym_as_an_aside_comment = 40,
  sym_literally = 41,
  sym_decorator = 42,
  sym_function_def = 43,
  sym_class_def = 44,
  sym_if_open = 45,
  sym_elif_open = 46,
  sym_else_if_open = 47,
  sym_else_open = 48,
  sym_for_open = 49,
  sym_while_open = 50,
  sym_with_open = 51,
  sym_try_open = 52,
  sym_except_open = 53,
  sym_finally_open = 54,
  sym_block_close = 55,
  sym_let_assignment = 56,
  sym_augmented_assign_sentence = 57,
  sym_enchantment = 58,
  sym_call_statement = 59,
  aux_sym_program_repeat1 = 60,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__newline] = "_newline",
  [anon_sym_comment] = "comment",
  [aux_sym_comment_token1] = "comment_token1",
  [anon_sym_aside] = "aside",
  [anon_sym_as] = "as",
  [anon_sym_an] = "an",
  [anon_sym_literally] = "literally",
  [anon_sym_decorator] = "decorator",
  [anon_sym_open] = "open",
  [anon_sym_function] = "function",
  [anon_sym_class] = "class",
  [anon_sym_if] = "if",
  [anon_sym_elif] = "elif",
  [anon_sym_else] = "else",
  [anon_sym_for] = "for",
  [anon_sym_while] = "while",
  [anon_sym_with] = "with",
  [anon_sym_try] = "try",
  [anon_sym_except] = "except",
  [anon_sym_finally] = "finally",
  [anon_sym_close] = "close",
  [anon_sym_let] = "let",
  [aux_sym_let_assignment_token1] = "let_assignment_token1",
  [anon_sym_be] = "be",
  [anon_sym_increase] = "increase",
  [anon_sym_decrease] = "decrease",
  [anon_sym_multiply] = "multiply",
  [anon_sym_divide] = "divide",
  [anon_sym_by] = "by",
  [anon_sym_enchant] = "enchant",
  [anon_sym_string] = "string",
  [anon_sym_rejection] = "rejection",
  [anon_sym_math] = "math",
  [anon_sym_call] = "call",
  [sym_expression_line] = "expression_line",
  [sym_program] = "program",
  [sym__statement] = "_statement",
  [sym_comment] = "comment",
  [sym_aside_comment] = "aside_comment",
  [sym_as_an_aside_comment] = "as_an_aside_comment",
  [sym_literally] = "literally",
  [sym_decorator] = "decorator",
  [sym_function_def] = "function_def",
  [sym_class_def] = "class_def",
  [sym_if_open] = "if_open",
  [sym_elif_open] = "elif_open",
  [sym_else_if_open] = "else_if_open",
  [sym_else_open] = "else_open",
  [sym_for_open] = "for_open",
  [sym_while_open] = "while_open",
  [sym_with_open] = "with_open",
  [sym_try_open] = "try_open",
  [sym_except_open] = "except_open",
  [sym_finally_open] = "finally_open",
  [sym_block_close] = "block_close",
  [sym_let_assignment] = "let_assignment",
  [sym_augmented_assign_sentence] = "augmented_assign_sentence",
  [sym_enchantment] = "enchantment",
  [sym_call_statement] = "call_statement",
  [aux_sym_program_repeat1] = "program_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__newline] = sym__newline,
  [anon_sym_comment] = anon_sym_comment,
  [aux_sym_comment_token1] = aux_sym_comment_token1,
  [anon_sym_aside] = anon_sym_aside,
  [anon_sym_as] = anon_sym_as,
  [anon_sym_an] = anon_sym_an,
  [anon_sym_literally] = anon_sym_literally,
  [anon_sym_decorator] = anon_sym_decorator,
  [anon_sym_open] = anon_sym_open,
  [anon_sym_function] = anon_sym_function,
  [anon_sym_class] = anon_sym_class,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_elif] = anon_sym_elif,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_for] = anon_sym_for,
  [anon_sym_while] = anon_sym_while,
  [anon_sym_with] = anon_sym_with,
  [anon_sym_try] = anon_sym_try,
  [anon_sym_except] = anon_sym_except,
  [anon_sym_finally] = anon_sym_finally,
  [anon_sym_close] = anon_sym_close,
  [anon_sym_let] = anon_sym_let,
  [aux_sym_let_assignment_token1] = aux_sym_let_assignment_token1,
  [anon_sym_be] = anon_sym_be,
  [anon_sym_increase] = anon_sym_increase,
  [anon_sym_decrease] = anon_sym_decrease,
  [anon_sym_multiply] = anon_sym_multiply,
  [anon_sym_divide] = anon_sym_divide,
  [anon_sym_by] = anon_sym_by,
  [anon_sym_enchant] = anon_sym_enchant,
  [anon_sym_string] = anon_sym_string,
  [anon_sym_rejection] = anon_sym_rejection,
  [anon_sym_math] = anon_sym_math,
  [anon_sym_call] = anon_sym_call,
  [sym_expression_line] = sym_expression_line,
  [sym_program] = sym_program,
  [sym__statement] = sym__statement,
  [sym_comment] = sym_comment,
  [sym_aside_comment] = sym_aside_comment,
  [sym_as_an_aside_comment] = sym_as_an_aside_comment,
  [sym_literally] = sym_literally,
  [sym_decorator] = sym_decorator,
  [sym_function_def] = sym_function_def,
  [sym_class_def] = sym_class_def,
  [sym_if_open] = sym_if_open,
  [sym_elif_open] = sym_elif_open,
  [sym_else_if_open] = sym_else_if_open,
  [sym_else_open] = sym_else_open,
  [sym_for_open] = sym_for_open,
  [sym_while_open] = sym_while_open,
  [sym_with_open] = sym_with_open,
  [sym_try_open] = sym_try_open,
  [sym_except_open] = sym_except_open,
  [sym_finally_open] = sym_finally_open,
  [sym_block_close] = sym_block_close,
  [sym_let_assignment] = sym_let_assignment,
  [sym_augmented_assign_sentence] = sym_augmented_assign_sentence,
  [sym_enchantment] = sym_enchantment,
  [sym_call_statement] = sym_call_statement,
  [aux_sym_program_repeat1] = aux_sym_program_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym__newline] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_comment] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_aside] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_as] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_an] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_literally] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_decorator] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_open] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_function] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_class] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_elif] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_for] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_while] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_with] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_try] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_except] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_finally] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_close] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_let_assignment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_be] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_increase] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_decrease] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_multiply] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_divide] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_by] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_enchant] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_string] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rejection] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_math] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_call] = {
    .visible = true,
    .named = false,
  },
  [sym_expression_line] = {
    .visible = true,
    .named = true,
  },
  [sym_program] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_aside_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_as_an_aside_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_literally] = {
    .visible = true,
    .named = true,
  },
  [sym_decorator] = {
    .visible = true,
    .named = true,
  },
  [sym_function_def] = {
    .visible = true,
    .named = true,
  },
  [sym_class_def] = {
    .visible = true,
    .named = true,
  },
  [sym_if_open] = {
    .visible = true,
    .named = true,
  },
  [sym_elif_open] = {
    .visible = true,
    .named = true,
  },
  [sym_else_if_open] = {
    .visible = true,
    .named = true,
  },
  [sym_else_open] = {
    .visible = true,
    .named = true,
  },
  [sym_for_open] = {
    .visible = true,
    .named = true,
  },
  [sym_while_open] = {
    .visible = true,
    .named = true,
  },
  [sym_with_open] = {
    .visible = true,
    .named = true,
  },
  [sym_try_open] = {
    .visible = true,
    .named = true,
  },
  [sym_except_open] = {
    .visible = true,
    .named = true,
  },
  [sym_finally_open] = {
    .visible = true,
    .named = true,
  },
  [sym_block_close] = {
    .visible = true,
    .named = true,
  },
  [sym_let_assignment] = {
    .visible = true,
    .named = true,
  },
  [sym_augmented_assign_sentence] = {
    .visible = true,
    .named = true,
  },
  [sym_enchantment] = {
    .visible = true,
    .named = true,
  },
  [sym_call_statement] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_program_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(113);
      ADVANCE_MAP(
        '\n', 114,
        '\r', 1,
        'a', 65,
        'b', 19,
        'c', 2,
        'd', 20,
        'e', 53,
        'f', 44,
        'i', 37,
        'l', 30,
        'm', 4,
        'o', 78,
        'r', 21,
        's', 99,
        't', 81,
        'w', 40,
      );
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(114);
      END_STATE();
    case 2:
      if (lookahead == 'a') ADVANCE(56);
      if (lookahead == 'l') ADVANCE(3);
      if (lookahead == 'o') ADVANCE(63);
      END_STATE();
    case 3:
      if (lookahead == 'a') ADVANCE(89);
      if (lookahead == 'o') ADVANCE(90);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(97);
      if (lookahead == 'u') ADVANCE(60);
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(98);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(59);
      END_STATE();
    case 7:
      if (lookahead == 'a') ADVANCE(91);
      END_STATE();
    case 8:
      if (lookahead == 'a') ADVANCE(73);
      END_STATE();
    case 9:
      if (lookahead == 'a') ADVANCE(61);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(92);
      END_STATE();
    case 11:
      if (lookahead == 'c') ADVANCE(74);
      END_STATE();
    case 12:
      if (lookahead == 'c') ADVANCE(43);
      END_STATE();
    case 13:
      if (lookahead == 'c') ADVANCE(29);
      END_STATE();
    case 14:
      if (lookahead == 'c') ADVANCE(87);
      END_STATE();
    case 15:
      if (lookahead == 'c') ADVANCE(103);
      END_STATE();
    case 16:
      if (lookahead == 'c') ADVANCE(104);
      END_STATE();
    case 17:
      if (lookahead == 'd') ADVANCE(23);
      END_STATE();
    case 18:
      if (lookahead == 'd') ADVANCE(26);
      END_STATE();
    case 19:
      if (lookahead == 'e') ADVANCE(224);
      if (lookahead == 'y') ADVANCE(233);
      END_STATE();
    case 20:
      if (lookahead == 'e') ADVANCE(11);
      if (lookahead == 'i') ADVANCE(105);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(52);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(209);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(192);
      END_STATE();
    case 24:
      if (lookahead == 'e') ADVANCE(219);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(213);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(231);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(227);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(225);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(80);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(93);
      if (lookahead == 'i') ADVANCE(102);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(67);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(7);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(72);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(86);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(10);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(16);
      END_STATE();
    case 37:
      if (lookahead == 'f') ADVANCE(205);
      if (lookahead == 'n') ADVANCE(14);
      END_STATE();
    case 38:
      if (lookahead == 'f') ADVANCE(207);
      END_STATE();
    case 39:
      if (lookahead == 'g') ADVANCE(236);
      END_STATE();
    case 40:
      if (lookahead == 'h') ADVANCE(48);
      if (lookahead == 'i') ADVANCE(100);
      END_STATE();
    case 41:
      if (lookahead == 'h') ADVANCE(238);
      END_STATE();
    case 42:
      if (lookahead == 'h') ADVANCE(215);
      END_STATE();
    case 43:
      if (lookahead == 'h') ADVANCE(8);
      END_STATE();
    case 44:
      if (lookahead == 'i') ADVANCE(66);
      if (lookahead == 'o') ADVANCE(82);
      if (lookahead == 'u') ADVANCE(71);
      END_STATE();
    case 45:
      if (lookahead == 'i') ADVANCE(38);
      if (lookahead == 's') ADVANCE(22);
      END_STATE();
    case 46:
      if (lookahead == 'i') ADVANCE(75);
      END_STATE();
    case 47:
      if (lookahead == 'i') ADVANCE(79);
      END_STATE();
    case 48:
      if (lookahead == 'i') ADVANCE(62);
      END_STATE();
    case 49:
      if (lookahead == 'i') ADVANCE(68);
      END_STATE();
    case 50:
      if (lookahead == 'i') ADVANCE(18);
      END_STATE();
    case 51:
      if (lookahead == 'i') ADVANCE(77);
      END_STATE();
    case 52:
      if (lookahead == 'j') ADVANCE(36);
      END_STATE();
    case 53:
      if (lookahead == 'l') ADVANCE(45);
      if (lookahead == 'n') ADVANCE(12);
      if (lookahead == 'x') ADVANCE(13);
      END_STATE();
    case 54:
      if (lookahead == 'l') ADVANCE(239);
      END_STATE();
    case 55:
      if (lookahead == 'l') ADVANCE(107);
      END_STATE();
    case 56:
      if (lookahead == 'l') ADVANCE(54);
      END_STATE();
    case 57:
      if (lookahead == 'l') ADVANCE(108);
      END_STATE();
    case 58:
      if (lookahead == 'l') ADVANCE(109);
      END_STATE();
    case 59:
      if (lookahead == 'l') ADVANCE(55);
      END_STATE();
    case 60:
      if (lookahead == 'l') ADVANCE(101);
      END_STATE();
    case 61:
      if (lookahead == 'l') ADVANCE(58);
      END_STATE();
    case 62:
      if (lookahead == 'l') ADVANCE(25);
      END_STATE();
    case 63:
      if (lookahead == 'm') ADVANCE(64);
      END_STATE();
    case 64:
      if (lookahead == 'm') ADVANCE(33);
      END_STATE();
    case 65:
      if (lookahead == 'n') ADVANCE(196);
      if (lookahead == 's') ADVANCE(194);
      END_STATE();
    case 66:
      if (lookahead == 'n') ADVANCE(6);
      END_STATE();
    case 67:
      if (lookahead == 'n') ADVANCE(201);
      END_STATE();
    case 68:
      if (lookahead == 'n') ADVANCE(39);
      END_STATE();
    case 69:
      if (lookahead == 'n') ADVANCE(203);
      END_STATE();
    case 70:
      if (lookahead == 'n') ADVANCE(237);
      END_STATE();
    case 71:
      if (lookahead == 'n') ADVANCE(15);
      END_STATE();
    case 72:
      if (lookahead == 'n') ADVANCE(95);
      END_STATE();
    case 73:
      if (lookahead == 'n') ADVANCE(96);
      END_STATE();
    case 74:
      if (lookahead == 'o') ADVANCE(85);
      if (lookahead == 'r') ADVANCE(32);
      END_STATE();
    case 75:
      if (lookahead == 'o') ADVANCE(69);
      END_STATE();
    case 76:
      if (lookahead == 'o') ADVANCE(83);
      END_STATE();
    case 77:
      if (lookahead == 'o') ADVANCE(70);
      END_STATE();
    case 78:
      if (lookahead == 'p') ADVANCE(31);
      END_STATE();
    case 79:
      if (lookahead == 'p') ADVANCE(57);
      END_STATE();
    case 80:
      if (lookahead == 'p') ADVANCE(94);
      END_STATE();
    case 81:
      if (lookahead == 'r') ADVANCE(106);
      END_STATE();
    case 82:
      if (lookahead == 'r') ADVANCE(211);
      END_STATE();
    case 83:
      if (lookahead == 'r') ADVANCE(199);
      END_STATE();
    case 84:
      if (lookahead == 'r') ADVANCE(49);
      END_STATE();
    case 85:
      if (lookahead == 'r') ADVANCE(5);
      END_STATE();
    case 86:
      if (lookahead == 'r') ADVANCE(9);
      END_STATE();
    case 87:
      if (lookahead == 'r') ADVANCE(35);
      END_STATE();
    case 88:
      if (lookahead == 's') ADVANCE(204);
      END_STATE();
    case 89:
      if (lookahead == 's') ADVANCE(88);
      END_STATE();
    case 90:
      if (lookahead == 's') ADVANCE(24);
      END_STATE();
    case 91:
      if (lookahead == 's') ADVANCE(27);
      END_STATE();
    case 92:
      if (lookahead == 's') ADVANCE(28);
      END_STATE();
    case 93:
      if (lookahead == 't') ADVANCE(221);
      END_STATE();
    case 94:
      if (lookahead == 't') ADVANCE(217);
      END_STATE();
    case 95:
      if (lookahead == 't') ADVANCE(115);
      END_STATE();
    case 96:
      if (lookahead == 't') ADVANCE(234);
      END_STATE();
    case 97:
      if (lookahead == 't') ADVANCE(41);
      END_STATE();
    case 98:
      if (lookahead == 't') ADVANCE(76);
      END_STATE();
    case 99:
      if (lookahead == 't') ADVANCE(84);
      END_STATE();
    case 100:
      if (lookahead == 't') ADVANCE(42);
      END_STATE();
    case 101:
      if (lookahead == 't') ADVANCE(47);
      END_STATE();
    case 102:
      if (lookahead == 't') ADVANCE(34);
      END_STATE();
    case 103:
      if (lookahead == 't') ADVANCE(46);
      END_STATE();
    case 104:
      if (lookahead == 't') ADVANCE(51);
      END_STATE();
    case 105:
      if (lookahead == 'v') ADVANCE(50);
      END_STATE();
    case 106:
      if (lookahead == 'y') ADVANCE(216);
      END_STATE();
    case 107:
      if (lookahead == 'y') ADVANCE(218);
      END_STATE();
    case 108:
      if (lookahead == 'y') ADVANCE(229);
      END_STATE();
    case 109:
      if (lookahead == 'y') ADVANCE(197);
      END_STATE();
    case 110:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(190);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 111:
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(111);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(223);
      END_STATE();
    case 112:
      if (eof) ADVANCE(113);
      ADVANCE_MAP(
        '\n', 114,
        '\r', 117,
        'a', 176,
        'c', 119,
        'd', 130,
        'e', 152,
        'f', 165,
        'i', 144,
        'l', 131,
        'm', 186,
        'o', 169,
        'w', 146,
        '\t', 118,
        ' ', 118,
      );
      if (lookahead != 0) ADVANCE(191);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym__newline);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_comment);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '\n') ADVANCE(114);
      if (lookahead != 0) ADVANCE(191);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      ADVANCE_MAP(
        '\r', 117,
        'a', 176,
        'c', 119,
        'd', 130,
        'e', 152,
        'f', 165,
        'i', 144,
        'l', 131,
        'm', 186,
        'o', 169,
        'w', 146,
        '\t', 118,
        ' ', 118,
      );
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(156);
      if (lookahead == 'l') ADVANCE(166);
      if (lookahead == 'o') ADVANCE(160);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(185);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(158);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(178);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(164);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(179);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'c') ADVANCE(167);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'c') ADVANCE(147);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'c') ADVANCE(175);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'd') ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'd') ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(125);
      if (lookahead == 'i') ADVANCE(187);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(180);
      if (lookahead == 'i') ADVANCE(183);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(162);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(210);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(193);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(220);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(214);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(232);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(228);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(226);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(122);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(124);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'f') ADVANCE(206);
      if (lookahead == 'n') ADVANCE(127);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'f') ADVANCE(208);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'h') ADVANCE(150);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'h') ADVANCE(123);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'i') ADVANCE(145);
      if (lookahead == 's') ADVANCE(133);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'i') ADVANCE(170);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'i') ADVANCE(159);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'i') ADVANCE(129);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(148);
      if (lookahead == 'n') ADVANCE(126);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(240);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(188);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(189);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(184);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(155);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'm') ADVANCE(161);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'm') ADVANCE(140);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(181);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(182);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'o') ADVANCE(171);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'o') ADVANCE(177);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'o') ADVANCE(173);
      if (lookahead == 'r') ADVANCE(141);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'o') ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'p') ADVANCE(132);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'p') ADVANCE(154);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(212);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(200);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(120);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(121);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(143);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(195);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(135);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(138);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(222);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(116);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(235);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(149);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(168);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'u') ADVANCE(157);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'v') ADVANCE(151);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'y') ADVANCE(230);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'y') ADVANCE(198);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(190);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(anon_sym_aside);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(anon_sym_aside);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(anon_sym_as);
      if (lookahead == 'i') ADVANCE(17);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(anon_sym_as);
      if (lookahead == 'i') ADVANCE(128);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(anon_sym_an);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(anon_sym_literally);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(anon_sym_literally);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(anon_sym_decorator);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(anon_sym_decorator);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(anon_sym_open);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(anon_sym_open);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(anon_sym_function);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(anon_sym_class);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(anon_sym_if);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_elif);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(anon_sym_elif);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(anon_sym_else);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(anon_sym_for);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(anon_sym_while);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(anon_sym_with);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(anon_sym_try);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(anon_sym_except);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(anon_sym_finally);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(anon_sym_close);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(anon_sym_let);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(aux_sym_let_assignment_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(223);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(anon_sym_be);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(anon_sym_increase);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(anon_sym_increase);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(anon_sym_decrease);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(anon_sym_decrease);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(anon_sym_multiply);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(anon_sym_multiply);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(anon_sym_divide);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(anon_sym_divide);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(anon_sym_by);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(anon_sym_enchant);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(anon_sym_enchant);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_rejection);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_math);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_call);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_call);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(191);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0, .external_lex_state = 1},
  [2] = {.lex_state = 0, .external_lex_state = 1},
  [3] = {.lex_state = 0, .external_lex_state = 1},
  [4] = {.lex_state = 112, .external_lex_state = 1},
  [5] = {.lex_state = 112, .external_lex_state = 1},
  [6] = {.lex_state = 0, .external_lex_state = 1},
  [7] = {.lex_state = 0, .external_lex_state = 1},
  [8] = {.lex_state = 0, .external_lex_state = 1},
  [9] = {.lex_state = 0, .external_lex_state = 1},
  [10] = {.lex_state = 0, .external_lex_state = 1},
  [11] = {.lex_state = 0, .external_lex_state = 1},
  [12] = {.lex_state = 0, .external_lex_state = 1},
  [13] = {.lex_state = 0, .external_lex_state = 1},
  [14] = {.lex_state = 0, .external_lex_state = 1},
  [15] = {.lex_state = 0, .external_lex_state = 1},
  [16] = {.lex_state = 0, .external_lex_state = 1},
  [17] = {.lex_state = 0, .external_lex_state = 1},
  [18] = {.lex_state = 0, .external_lex_state = 1},
  [19] = {.lex_state = 0, .external_lex_state = 1},
  [20] = {.lex_state = 0, .external_lex_state = 1},
  [21] = {.lex_state = 0, .external_lex_state = 1},
  [22] = {.lex_state = 0, .external_lex_state = 1},
  [23] = {.lex_state = 0, .external_lex_state = 1},
  [24] = {.lex_state = 0, .external_lex_state = 1},
  [25] = {.lex_state = 0, .external_lex_state = 1},
  [26] = {.lex_state = 0, .external_lex_state = 1},
  [27] = {.lex_state = 0, .external_lex_state = 1},
  [28] = {.lex_state = 0, .external_lex_state = 1},
  [29] = {.lex_state = 0, .external_lex_state = 1},
  [30] = {.lex_state = 0, .external_lex_state = 1},
  [31] = {.lex_state = 0, .external_lex_state = 1},
  [32] = {.lex_state = 0, .external_lex_state = 1},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 110},
  [37] = {.lex_state = 110},
  [38] = {.lex_state = 110},
  [39] = {.lex_state = 110},
  [40] = {.lex_state = 110},
  [41] = {.lex_state = 110},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 110},
  [45] = {.lex_state = 110},
  [46] = {.lex_state = 110},
  [47] = {.lex_state = 110},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 110},
  [51] = {.lex_state = 111},
  [52] = {.lex_state = 111},
  [53] = {.lex_state = 110},
  [54] = {.lex_state = 110},
  [55] = {.lex_state = 110},
  [56] = {.lex_state = 110},
  [57] = {.lex_state = 110},
  [58] = {.lex_state = 110},
  [59] = {.lex_state = 110},
  [60] = {.lex_state = 110},
  [61] = {.lex_state = 110},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 110},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym__newline] = ACTIONS(1),
    [anon_sym_comment] = ACTIONS(1),
    [anon_sym_aside] = ACTIONS(1),
    [anon_sym_as] = ACTIONS(1),
    [anon_sym_an] = ACTIONS(1),
    [anon_sym_literally] = ACTIONS(1),
    [anon_sym_decorator] = ACTIONS(1),
    [anon_sym_open] = ACTIONS(1),
    [anon_sym_function] = ACTIONS(1),
    [anon_sym_class] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_elif] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_for] = ACTIONS(1),
    [anon_sym_while] = ACTIONS(1),
    [anon_sym_with] = ACTIONS(1),
    [anon_sym_try] = ACTIONS(1),
    [anon_sym_except] = ACTIONS(1),
    [anon_sym_finally] = ACTIONS(1),
    [anon_sym_close] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_be] = ACTIONS(1),
    [anon_sym_increase] = ACTIONS(1),
    [anon_sym_decrease] = ACTIONS(1),
    [anon_sym_multiply] = ACTIONS(1),
    [anon_sym_divide] = ACTIONS(1),
    [anon_sym_by] = ACTIONS(1),
    [anon_sym_enchant] = ACTIONS(1),
    [anon_sym_string] = ACTIONS(1),
    [anon_sym_rejection] = ACTIONS(1),
    [anon_sym_math] = ACTIONS(1),
    [anon_sym_call] = ACTIONS(1),
    [sym_expression_line] = ACTIONS(1),
  },
  [1] = {
    [sym_program] = STATE(49),
    [sym__statement] = STATE(3),
    [sym_comment] = STATE(3),
    [sym_aside_comment] = STATE(3),
    [sym_as_an_aside_comment] = STATE(3),
    [sym_literally] = STATE(3),
    [sym_decorator] = STATE(3),
    [sym_function_def] = STATE(3),
    [sym_class_def] = STATE(3),
    [sym_if_open] = STATE(3),
    [sym_elif_open] = STATE(3),
    [sym_else_if_open] = STATE(3),
    [sym_else_open] = STATE(3),
    [sym_for_open] = STATE(3),
    [sym_while_open] = STATE(3),
    [sym_with_open] = STATE(3),
    [sym_try_open] = STATE(3),
    [sym_except_open] = STATE(3),
    [sym_finally_open] = STATE(3),
    [sym_block_close] = STATE(3),
    [sym_let_assignment] = STATE(3),
    [sym_augmented_assign_sentence] = STATE(3),
    [sym_enchantment] = STATE(3),
    [sym_call_statement] = STATE(3),
    [aux_sym_program_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym__newline] = ACTIONS(5),
    [anon_sym_comment] = ACTIONS(7),
    [anon_sym_aside] = ACTIONS(9),
    [anon_sym_as] = ACTIONS(11),
    [anon_sym_literally] = ACTIONS(13),
    [anon_sym_decorator] = ACTIONS(15),
    [anon_sym_open] = ACTIONS(17),
    [anon_sym_if] = ACTIONS(19),
    [anon_sym_elif] = ACTIONS(21),
    [anon_sym_else] = ACTIONS(23),
    [anon_sym_for] = ACTIONS(25),
    [anon_sym_while] = ACTIONS(27),
    [anon_sym_close] = ACTIONS(29),
    [anon_sym_let] = ACTIONS(31),
    [anon_sym_increase] = ACTIONS(33),
    [anon_sym_decrease] = ACTIONS(33),
    [anon_sym_multiply] = ACTIONS(33),
    [anon_sym_divide] = ACTIONS(33),
    [anon_sym_enchant] = ACTIONS(35),
    [anon_sym_call] = ACTIONS(37),
    [sym_expression_line] = ACTIONS(5),
  },
  [2] = {
    [sym__statement] = STATE(2),
    [sym_comment] = STATE(2),
    [sym_aside_comment] = STATE(2),
    [sym_as_an_aside_comment] = STATE(2),
    [sym_literally] = STATE(2),
    [sym_decorator] = STATE(2),
    [sym_function_def] = STATE(2),
    [sym_class_def] = STATE(2),
    [sym_if_open] = STATE(2),
    [sym_elif_open] = STATE(2),
    [sym_else_if_open] = STATE(2),
    [sym_else_open] = STATE(2),
    [sym_for_open] = STATE(2),
    [sym_while_open] = STATE(2),
    [sym_with_open] = STATE(2),
    [sym_try_open] = STATE(2),
    [sym_except_open] = STATE(2),
    [sym_finally_open] = STATE(2),
    [sym_block_close] = STATE(2),
    [sym_let_assignment] = STATE(2),
    [sym_augmented_assign_sentence] = STATE(2),
    [sym_enchantment] = STATE(2),
    [sym_call_statement] = STATE(2),
    [aux_sym_program_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(39),
    [sym__newline] = ACTIONS(41),
    [anon_sym_comment] = ACTIONS(44),
    [anon_sym_aside] = ACTIONS(47),
    [anon_sym_as] = ACTIONS(50),
    [anon_sym_literally] = ACTIONS(53),
    [anon_sym_decorator] = ACTIONS(56),
    [anon_sym_open] = ACTIONS(59),
    [anon_sym_if] = ACTIONS(62),
    [anon_sym_elif] = ACTIONS(65),
    [anon_sym_else] = ACTIONS(68),
    [anon_sym_for] = ACTIONS(71),
    [anon_sym_while] = ACTIONS(74),
    [anon_sym_close] = ACTIONS(77),
    [anon_sym_let] = ACTIONS(80),
    [anon_sym_increase] = ACTIONS(83),
    [anon_sym_decrease] = ACTIONS(83),
    [anon_sym_multiply] = ACTIONS(83),
    [anon_sym_divide] = ACTIONS(83),
    [anon_sym_enchant] = ACTIONS(86),
    [anon_sym_call] = ACTIONS(89),
    [sym_expression_line] = ACTIONS(41),
  },
  [3] = {
    [sym__statement] = STATE(2),
    [sym_comment] = STATE(2),
    [sym_aside_comment] = STATE(2),
    [sym_as_an_aside_comment] = STATE(2),
    [sym_literally] = STATE(2),
    [sym_decorator] = STATE(2),
    [sym_function_def] = STATE(2),
    [sym_class_def] = STATE(2),
    [sym_if_open] = STATE(2),
    [sym_elif_open] = STATE(2),
    [sym_else_if_open] = STATE(2),
    [sym_else_open] = STATE(2),
    [sym_for_open] = STATE(2),
    [sym_while_open] = STATE(2),
    [sym_with_open] = STATE(2),
    [sym_try_open] = STATE(2),
    [sym_except_open] = STATE(2),
    [sym_finally_open] = STATE(2),
    [sym_block_close] = STATE(2),
    [sym_let_assignment] = STATE(2),
    [sym_augmented_assign_sentence] = STATE(2),
    [sym_enchantment] = STATE(2),
    [sym_call_statement] = STATE(2),
    [aux_sym_program_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(92),
    [sym__newline] = ACTIONS(94),
    [anon_sym_comment] = ACTIONS(7),
    [anon_sym_aside] = ACTIONS(9),
    [anon_sym_as] = ACTIONS(11),
    [anon_sym_literally] = ACTIONS(13),
    [anon_sym_decorator] = ACTIONS(15),
    [anon_sym_open] = ACTIONS(17),
    [anon_sym_if] = ACTIONS(19),
    [anon_sym_elif] = ACTIONS(21),
    [anon_sym_else] = ACTIONS(23),
    [anon_sym_for] = ACTIONS(25),
    [anon_sym_while] = ACTIONS(27),
    [anon_sym_close] = ACTIONS(29),
    [anon_sym_let] = ACTIONS(31),
    [anon_sym_increase] = ACTIONS(33),
    [anon_sym_decrease] = ACTIONS(33),
    [anon_sym_multiply] = ACTIONS(33),
    [anon_sym_divide] = ACTIONS(33),
    [anon_sym_enchant] = ACTIONS(35),
    [anon_sym_call] = ACTIONS(37),
    [sym_expression_line] = ACTIONS(94),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(100), 1,
      aux_sym_comment_token1,
    ACTIONS(96), 2,
      sym_expression_line,
      ts_builtin_sym_end,
    ACTIONS(98), 20,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [30] = 3,
    ACTIONS(106), 1,
      aux_sym_comment_token1,
    ACTIONS(102), 2,
      sym_expression_line,
      ts_builtin_sym_end,
    ACTIONS(104), 20,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [60] = 2,
    ACTIONS(110), 1,
      anon_sym_as,
    ACTIONS(108), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [87] = 2,
    ACTIONS(114), 1,
      anon_sym_as,
    ACTIONS(112), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [114] = 2,
    ACTIONS(118), 1,
      anon_sym_as,
    ACTIONS(116), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [141] = 2,
    ACTIONS(122), 1,
      anon_sym_as,
    ACTIONS(120), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [168] = 2,
    ACTIONS(126), 1,
      anon_sym_as,
    ACTIONS(124), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [195] = 2,
    ACTIONS(130), 1,
      anon_sym_as,
    ACTIONS(128), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [222] = 3,
    ACTIONS(134), 1,
      anon_sym_as,
    ACTIONS(136), 1,
      anon_sym_if,
    ACTIONS(132), 20,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [251] = 2,
    ACTIONS(140), 1,
      anon_sym_as,
    ACTIONS(138), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [278] = 2,
    ACTIONS(144), 1,
      anon_sym_as,
    ACTIONS(142), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [305] = 2,
    ACTIONS(148), 1,
      anon_sym_as,
    ACTIONS(146), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [332] = 2,
    ACTIONS(152), 1,
      anon_sym_as,
    ACTIONS(150), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [359] = 2,
    ACTIONS(156), 1,
      anon_sym_as,
    ACTIONS(154), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [386] = 2,
    ACTIONS(160), 1,
      anon_sym_as,
    ACTIONS(158), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [413] = 2,
    ACTIONS(164), 1,
      anon_sym_as,
    ACTIONS(162), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [440] = 2,
    ACTIONS(168), 1,
      anon_sym_as,
    ACTIONS(166), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [467] = 2,
    ACTIONS(172), 1,
      anon_sym_as,
    ACTIONS(170), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [494] = 2,
    ACTIONS(176), 1,
      anon_sym_as,
    ACTIONS(174), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [521] = 2,
    ACTIONS(180), 1,
      anon_sym_as,
    ACTIONS(178), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [548] = 2,
    ACTIONS(184), 1,
      anon_sym_as,
    ACTIONS(182), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [575] = 2,
    ACTIONS(188), 1,
      anon_sym_as,
    ACTIONS(186), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [602] = 2,
    ACTIONS(192), 1,
      anon_sym_as,
    ACTIONS(190), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [629] = 2,
    ACTIONS(196), 1,
      anon_sym_as,
    ACTIONS(194), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [656] = 2,
    ACTIONS(200), 1,
      anon_sym_as,
    ACTIONS(198), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [683] = 2,
    ACTIONS(204), 1,
      anon_sym_as,
    ACTIONS(202), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [710] = 2,
    ACTIONS(208), 1,
      anon_sym_as,
    ACTIONS(206), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [737] = 2,
    ACTIONS(212), 1,
      anon_sym_as,
    ACTIONS(210), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [764] = 2,
    ACTIONS(216), 1,
      anon_sym_as,
    ACTIONS(214), 21,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [791] = 11,
    ACTIONS(218), 1,
      anon_sym_function,
    ACTIONS(220), 1,
      anon_sym_class,
    ACTIONS(222), 1,
      anon_sym_if,
    ACTIONS(224), 1,
      anon_sym_elif,
    ACTIONS(226), 1,
      anon_sym_else,
    ACTIONS(228), 1,
      anon_sym_for,
    ACTIONS(230), 1,
      anon_sym_while,
    ACTIONS(232), 1,
      anon_sym_with,
    ACTIONS(234), 1,
      anon_sym_try,
    ACTIONS(236), 1,
      anon_sym_except,
    ACTIONS(238), 1,
      anon_sym_finally,
  [825] = 1,
    ACTIONS(240), 3,
      anon_sym_string,
      anon_sym_rejection,
      anon_sym_math,
  [831] = 1,
    ACTIONS(242), 1,
      anon_sym_with,
  [835] = 1,
    ACTIONS(244), 1,
      aux_sym_comment_token1,
  [839] = 1,
    ACTIONS(246), 1,
      aux_sym_comment_token1,
  [843] = 1,
    ACTIONS(248), 1,
      aux_sym_comment_token1,
  [847] = 1,
    ACTIONS(250), 1,
      aux_sym_comment_token1,
  [851] = 1,
    ACTIONS(252), 1,
      aux_sym_comment_token1,
  [855] = 1,
    ACTIONS(254), 1,
      aux_sym_comment_token1,
  [859] = 1,
    ACTIONS(256), 1,
      anon_sym_be,
  [863] = 1,
    ACTIONS(258), 1,
      anon_sym_by,
  [867] = 1,
    ACTIONS(260), 1,
      aux_sym_comment_token1,
  [871] = 1,
    ACTIONS(262), 1,
      aux_sym_comment_token1,
  [875] = 1,
    ACTIONS(264), 1,
      aux_sym_comment_token1,
  [879] = 1,
    ACTIONS(266), 1,
      aux_sym_comment_token1,
  [883] = 1,
    ACTIONS(268), 1,
      anon_sym_aside,
  [887] = 1,
    ACTIONS(270), 1,
      ts_builtin_sym_end,
  [891] = 1,
    ACTIONS(272), 1,
      aux_sym_comment_token1,
  [895] = 1,
    ACTIONS(274), 1,
      aux_sym_let_assignment_token1,
  [899] = 1,
    ACTIONS(276), 1,
      aux_sym_let_assignment_token1,
  [903] = 1,
    ACTIONS(278), 1,
      aux_sym_comment_token1,
  [907] = 1,
    ACTIONS(280), 1,
      aux_sym_comment_token1,
  [911] = 1,
    ACTIONS(282), 1,
      aux_sym_comment_token1,
  [915] = 1,
    ACTIONS(284), 1,
      aux_sym_comment_token1,
  [919] = 1,
    ACTIONS(286), 1,
      aux_sym_comment_token1,
  [923] = 1,
    ACTIONS(288), 1,
      aux_sym_comment_token1,
  [927] = 1,
    ACTIONS(290), 1,
      aux_sym_comment_token1,
  [931] = 1,
    ACTIONS(292), 1,
      aux_sym_comment_token1,
  [935] = 1,
    ACTIONS(294), 1,
      aux_sym_comment_token1,
  [939] = 1,
    ACTIONS(296), 1,
      anon_sym_an,
  [943] = 1,
    ACTIONS(298), 1,
      aux_sym_comment_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 30,
  [SMALL_STATE(6)] = 60,
  [SMALL_STATE(7)] = 87,
  [SMALL_STATE(8)] = 114,
  [SMALL_STATE(9)] = 141,
  [SMALL_STATE(10)] = 168,
  [SMALL_STATE(11)] = 195,
  [SMALL_STATE(12)] = 222,
  [SMALL_STATE(13)] = 251,
  [SMALL_STATE(14)] = 278,
  [SMALL_STATE(15)] = 305,
  [SMALL_STATE(16)] = 332,
  [SMALL_STATE(17)] = 359,
  [SMALL_STATE(18)] = 386,
  [SMALL_STATE(19)] = 413,
  [SMALL_STATE(20)] = 440,
  [SMALL_STATE(21)] = 467,
  [SMALL_STATE(22)] = 494,
  [SMALL_STATE(23)] = 521,
  [SMALL_STATE(24)] = 548,
  [SMALL_STATE(25)] = 575,
  [SMALL_STATE(26)] = 602,
  [SMALL_STATE(27)] = 629,
  [SMALL_STATE(28)] = 656,
  [SMALL_STATE(29)] = 683,
  [SMALL_STATE(30)] = 710,
  [SMALL_STATE(31)] = 737,
  [SMALL_STATE(32)] = 764,
  [SMALL_STATE(33)] = 791,
  [SMALL_STATE(34)] = 825,
  [SMALL_STATE(35)] = 831,
  [SMALL_STATE(36)] = 835,
  [SMALL_STATE(37)] = 839,
  [SMALL_STATE(38)] = 843,
  [SMALL_STATE(39)] = 847,
  [SMALL_STATE(40)] = 851,
  [SMALL_STATE(41)] = 855,
  [SMALL_STATE(42)] = 859,
  [SMALL_STATE(43)] = 863,
  [SMALL_STATE(44)] = 867,
  [SMALL_STATE(45)] = 871,
  [SMALL_STATE(46)] = 875,
  [SMALL_STATE(47)] = 879,
  [SMALL_STATE(48)] = 883,
  [SMALL_STATE(49)] = 887,
  [SMALL_STATE(50)] = 891,
  [SMALL_STATE(51)] = 895,
  [SMALL_STATE(52)] = 899,
  [SMALL_STATE(53)] = 903,
  [SMALL_STATE(54)] = 907,
  [SMALL_STATE(55)] = 911,
  [SMALL_STATE(56)] = 915,
  [SMALL_STATE(57)] = 919,
  [SMALL_STATE(58)] = 923,
  [SMALL_STATE(59)] = 927,
  [SMALL_STATE(60)] = 931,
  [SMALL_STATE(61)] = 935,
  [SMALL_STATE(62)] = 939,
  [SMALL_STATE(63)] = 943,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [44] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(62),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(60),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(55),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(54),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(53),
  [77] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(52),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(51),
  [86] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(35),
  [89] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(50),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1, 0, 0),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_except_open, 2, 0, 0),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_except_open, 2, 0, 0),
  [100] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_close, 1, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_close, 1, 0, 0),
  [106] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_except_open, 3, 0, 0),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_except_open, 3, 0, 0),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aside_comment, 2, 0, 0),
  [114] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_aside_comment, 2, 0, 0),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_if_open, 3, 0, 0),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_if_open, 3, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_augmented_assign_sentence, 4, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_augmented_assign_sentence, 4, 0, 0),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_finally_open, 2, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_finally_open, 2, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_with_open, 3, 0, 0),
  [130] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_with_open, 3, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_open, 1, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_open, 1, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_open, 3, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_open, 3, 0, 0),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_open, 3, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_for_open, 3, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_elif_open, 3, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elif_open, 3, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_open, 3, 0, 0),
  [152] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_open, 3, 0, 0),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_def, 3, 0, 0),
  [156] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_class_def, 3, 0, 0),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_def, 3, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_def, 3, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enchantment, 4, 0, 0),
  [164] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enchantment, 4, 0, 0),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 2, 0, 0),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 2, 0, 0),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_as_an_aside_comment, 4, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_as_an_aside_comment, 4, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_assignment, 4, 0, 0),
  [176] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_assignment, 4, 0, 0),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literally, 2, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literally, 2, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decorator, 2, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decorator, 2, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call_statement, 2, 0, 0),
  [188] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call_statement, 2, 0, 0),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_try_open, 2, 0, 0),
  [192] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_try_open, 2, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_close, 2, 0, 0),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_close, 2, 0, 0),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_open, 2, 0, 0),
  [200] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_open, 2, 0, 0),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_open, 2, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_open, 2, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_open, 2, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_for_open, 2, 0, 0),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_elif_open, 2, 0, 0),
  [212] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elif_open, 2, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_open, 2, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_open, 2, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [270] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token_expression_line = 0,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_expression_line] = sym_expression_line,
};

static const bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_expression_line] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_spoken_python_external_scanner_create(void);
void tree_sitter_spoken_python_external_scanner_destroy(void *);
bool tree_sitter_spoken_python_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_spoken_python_external_scanner_serialize(void *, char *);
void tree_sitter_spoken_python_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_spoken_python(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_spoken_python_external_scanner_create,
      tree_sitter_spoken_python_external_scanner_destroy,
      tree_sitter_spoken_python_external_scanner_scan,
      tree_sitter_spoken_python_external_scanner_serialize,
      tree_sitter_spoken_python_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
