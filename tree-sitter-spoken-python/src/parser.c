#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 72
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 65
#define ALIAS_COUNT 0
#define TOKEN_COUNT 39
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
  anon_sym_the = 22,
  aux_sym_the_assignment_token1 = 23,
  anon_sym_is = 24,
  anon_sym_let = 25,
  anon_sym_equal = 26,
  anon_sym_be = 27,
  anon_sym_increase = 28,
  anon_sym_decrease = 29,
  anon_sym_multiply = 30,
  anon_sym_divide = 31,
  anon_sym_by = 32,
  anon_sym_enchant = 33,
  anon_sym_string = 34,
  anon_sym_rejection = 35,
  anon_sym_math = 36,
  anon_sym_call = 37,
  sym_expression_line = 38,
  sym_program = 39,
  sym__statement = 40,
  sym_comment = 41,
  sym_aside_comment = 42,
  sym_as_an_aside_comment = 43,
  sym_literally = 44,
  sym_decorator = 45,
  sym_function_def = 46,
  sym_class_def = 47,
  sym_if_open = 48,
  sym_elif_open = 49,
  sym_else_if_open = 50,
  sym_else_open = 51,
  sym_for_open = 52,
  sym_while_open = 53,
  sym_with_open = 54,
  sym_try_open = 55,
  sym_except_open = 56,
  sym_finally_open = 57,
  sym_block_close = 58,
  sym_the_assignment = 59,
  sym_let_assignment = 60,
  sym_augmented_assign_sentence = 61,
  sym_enchantment = 62,
  sym_call_statement = 63,
  aux_sym_program_repeat1 = 64,
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
  [anon_sym_the] = "the",
  [aux_sym_the_assignment_token1] = "the_assignment_token1",
  [anon_sym_is] = "is",
  [anon_sym_let] = "let",
  [anon_sym_equal] = "equal",
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
  [sym_the_assignment] = "the_assignment",
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
  [anon_sym_the] = anon_sym_the,
  [aux_sym_the_assignment_token1] = aux_sym_the_assignment_token1,
  [anon_sym_is] = anon_sym_is,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_equal] = anon_sym_equal,
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
  [sym_the_assignment] = sym_the_assignment,
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
  [anon_sym_the] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_the_assignment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_is] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_equal] = {
    .visible = true,
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
  [sym_the_assignment] = {
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
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(117);
      ADVANCE_MAP(
        '\n', 118,
        '\r', 1,
        'a', 69,
        'b', 20,
        'c', 2,
        'd', 21,
        'e', 56,
        'f', 47,
        'i', 39,
        'l', 32,
        'm', 4,
        'o', 82,
        'r', 22,
        's', 100,
        't', 45,
        'w', 42,
      );
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(118);
      END_STATE();
    case 2:
      if (lookahead == 'a') ADVANCE(60);
      if (lookahead == 'l') ADVANCE(3);
      if (lookahead == 'o') ADVANCE(67);
      END_STATE();
    case 3:
      if (lookahead == 'a') ADVANCE(92);
      if (lookahead == 'o') ADVANCE(93);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(101);
      if (lookahead == 'u') ADVANCE(63);
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(58);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(102);
      END_STATE();
    case 7:
      if (lookahead == 'a') ADVANCE(64);
      END_STATE();
    case 8:
      if (lookahead == 'a') ADVANCE(94);
      END_STATE();
    case 9:
      if (lookahead == 'a') ADVANCE(77);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(65);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(95);
      END_STATE();
    case 12:
      if (lookahead == 'c') ADVANCE(78);
      END_STATE();
    case 13:
      if (lookahead == 'c') ADVANCE(46);
      END_STATE();
    case 14:
      if (lookahead == 'c') ADVANCE(90);
      END_STATE();
    case 15:
      if (lookahead == 'c') ADVANCE(31);
      END_STATE();
    case 16:
      if (lookahead == 'c') ADVANCE(105);
      END_STATE();
    case 17:
      if (lookahead == 'c') ADVANCE(107);
      END_STATE();
    case 18:
      if (lookahead == 'd') ADVANCE(25);
      END_STATE();
    case 19:
      if (lookahead == 'd') ADVANCE(28);
      END_STATE();
    case 20:
      if (lookahead == 'e') ADVANCE(244);
      if (lookahead == 'y') ADVANCE(253);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(12);
      if (lookahead == 'i') ADVANCE(109);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(55);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(237);
      END_STATE();
    case 24:
      if (lookahead == 'e') ADVANCE(225);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(206);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(235);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(229);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(251);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(247);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(245);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(84);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(96);
      if (lookahead == 'i') ADVANCE(106);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(70);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(76);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(89);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(8);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(17);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(11);
      END_STATE();
    case 39:
      if (lookahead == 'f') ADVANCE(221);
      if (lookahead == 'n') ADVANCE(14);
      if (lookahead == 's') ADVANCE(240);
      END_STATE();
    case 40:
      if (lookahead == 'f') ADVANCE(223);
      END_STATE();
    case 41:
      if (lookahead == 'g') ADVANCE(256);
      END_STATE();
    case 42:
      if (lookahead == 'h') ADVANCE(51);
      if (lookahead == 'i') ADVANCE(103);
      END_STATE();
    case 43:
      if (lookahead == 'h') ADVANCE(258);
      END_STATE();
    case 44:
      if (lookahead == 'h') ADVANCE(231);
      END_STATE();
    case 45:
      if (lookahead == 'h') ADVANCE(23);
      if (lookahead == 'r') ADVANCE(110);
      END_STATE();
    case 46:
      if (lookahead == 'h') ADVANCE(9);
      END_STATE();
    case 47:
      if (lookahead == 'i') ADVANCE(74);
      if (lookahead == 'o') ADVANCE(85);
      if (lookahead == 'u') ADVANCE(75);
      END_STATE();
    case 48:
      if (lookahead == 'i') ADVANCE(40);
      if (lookahead == 's') ADVANCE(24);
      END_STATE();
    case 49:
      if (lookahead == 'i') ADVANCE(79);
      END_STATE();
    case 50:
      if (lookahead == 'i') ADVANCE(83);
      END_STATE();
    case 51:
      if (lookahead == 'i') ADVANCE(66);
      END_STATE();
    case 52:
      if (lookahead == 'i') ADVANCE(71);
      END_STATE();
    case 53:
      if (lookahead == 'i') ADVANCE(19);
      END_STATE();
    case 54:
      if (lookahead == 'i') ADVANCE(81);
      END_STATE();
    case 55:
      if (lookahead == 'j') ADVANCE(37);
      END_STATE();
    case 56:
      if (lookahead == 'l') ADVANCE(48);
      if (lookahead == 'n') ADVANCE(13);
      if (lookahead == 'q') ADVANCE(108);
      if (lookahead == 'x') ADVANCE(15);
      END_STATE();
    case 57:
      if (lookahead == 'l') ADVANCE(259);
      END_STATE();
    case 58:
      if (lookahead == 'l') ADVANCE(243);
      END_STATE();
    case 59:
      if (lookahead == 'l') ADVANCE(111);
      END_STATE();
    case 60:
      if (lookahead == 'l') ADVANCE(57);
      END_STATE();
    case 61:
      if (lookahead == 'l') ADVANCE(112);
      END_STATE();
    case 62:
      if (lookahead == 'l') ADVANCE(113);
      END_STATE();
    case 63:
      if (lookahead == 'l') ADVANCE(104);
      END_STATE();
    case 64:
      if (lookahead == 'l') ADVANCE(59);
      END_STATE();
    case 65:
      if (lookahead == 'l') ADVANCE(62);
      END_STATE();
    case 66:
      if (lookahead == 'l') ADVANCE(27);
      END_STATE();
    case 67:
      if (lookahead == 'm') ADVANCE(68);
      END_STATE();
    case 68:
      if (lookahead == 'm') ADVANCE(34);
      END_STATE();
    case 69:
      if (lookahead == 'n') ADVANCE(210);
      if (lookahead == 's') ADVANCE(208);
      END_STATE();
    case 70:
      if (lookahead == 'n') ADVANCE(215);
      END_STATE();
    case 71:
      if (lookahead == 'n') ADVANCE(41);
      END_STATE();
    case 72:
      if (lookahead == 'n') ADVANCE(217);
      END_STATE();
    case 73:
      if (lookahead == 'n') ADVANCE(257);
      END_STATE();
    case 74:
      if (lookahead == 'n') ADVANCE(7);
      END_STATE();
    case 75:
      if (lookahead == 'n') ADVANCE(16);
      END_STATE();
    case 76:
      if (lookahead == 'n') ADVANCE(98);
      END_STATE();
    case 77:
      if (lookahead == 'n') ADVANCE(99);
      END_STATE();
    case 78:
      if (lookahead == 'o') ADVANCE(88);
      if (lookahead == 'r') ADVANCE(36);
      END_STATE();
    case 79:
      if (lookahead == 'o') ADVANCE(72);
      END_STATE();
    case 80:
      if (lookahead == 'o') ADVANCE(86);
      END_STATE();
    case 81:
      if (lookahead == 'o') ADVANCE(73);
      END_STATE();
    case 82:
      if (lookahead == 'p') ADVANCE(33);
      END_STATE();
    case 83:
      if (lookahead == 'p') ADVANCE(61);
      END_STATE();
    case 84:
      if (lookahead == 'p') ADVANCE(97);
      END_STATE();
    case 85:
      if (lookahead == 'r') ADVANCE(227);
      END_STATE();
    case 86:
      if (lookahead == 'r') ADVANCE(213);
      END_STATE();
    case 87:
      if (lookahead == 'r') ADVANCE(52);
      END_STATE();
    case 88:
      if (lookahead == 'r') ADVANCE(6);
      END_STATE();
    case 89:
      if (lookahead == 'r') ADVANCE(10);
      END_STATE();
    case 90:
      if (lookahead == 'r') ADVANCE(38);
      END_STATE();
    case 91:
      if (lookahead == 's') ADVANCE(219);
      END_STATE();
    case 92:
      if (lookahead == 's') ADVANCE(91);
      END_STATE();
    case 93:
      if (lookahead == 's') ADVANCE(26);
      END_STATE();
    case 94:
      if (lookahead == 's') ADVANCE(29);
      END_STATE();
    case 95:
      if (lookahead == 's') ADVANCE(30);
      END_STATE();
    case 96:
      if (lookahead == 't') ADVANCE(241);
      END_STATE();
    case 97:
      if (lookahead == 't') ADVANCE(233);
      END_STATE();
    case 98:
      if (lookahead == 't') ADVANCE(119);
      END_STATE();
    case 99:
      if (lookahead == 't') ADVANCE(254);
      END_STATE();
    case 100:
      if (lookahead == 't') ADVANCE(87);
      END_STATE();
    case 101:
      if (lookahead == 't') ADVANCE(43);
      END_STATE();
    case 102:
      if (lookahead == 't') ADVANCE(80);
      END_STATE();
    case 103:
      if (lookahead == 't') ADVANCE(44);
      END_STATE();
    case 104:
      if (lookahead == 't') ADVANCE(50);
      END_STATE();
    case 105:
      if (lookahead == 't') ADVANCE(49);
      END_STATE();
    case 106:
      if (lookahead == 't') ADVANCE(35);
      END_STATE();
    case 107:
      if (lookahead == 't') ADVANCE(54);
      END_STATE();
    case 108:
      if (lookahead == 'u') ADVANCE(5);
      END_STATE();
    case 109:
      if (lookahead == 'v') ADVANCE(53);
      END_STATE();
    case 110:
      if (lookahead == 'y') ADVANCE(232);
      END_STATE();
    case 111:
      if (lookahead == 'y') ADVANCE(234);
      END_STATE();
    case 112:
      if (lookahead == 'y') ADVANCE(249);
      END_STATE();
    case 113:
      if (lookahead == 'y') ADVANCE(211);
      END_STATE();
    case 114:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(204);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 115:
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(115);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(239);
      END_STATE();
    case 116:
      if (eof) ADVANCE(117);
      ADVANCE_MAP(
        '\n', 118,
        '\r', 121,
        'a', 187,
        'c', 123,
        'd', 136,
        'e', 161,
        'f', 176,
        'i', 151,
        'l', 137,
        'm', 200,
        'o', 180,
        't', 155,
        'w', 153,
        '\t', 122,
        ' ', 122,
      );
      if (lookahead != 0) ADVANCE(205);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym__newline);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_comment);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '\n') ADVANCE(118);
      if (lookahead != 0) ADVANCE(205);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      ADVANCE_MAP(
        '\r', 121,
        'a', 187,
        'c', 123,
        'd', 136,
        'e', 161,
        'f', 176,
        'i', 151,
        'l', 137,
        'm', 200,
        'o', 180,
        't', 155,
        'w', 153,
        '\t', 122,
        ' ', 122,
      );
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(165);
      if (lookahead == 'l') ADVANCE(124);
      if (lookahead == 'o') ADVANCE(169);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(189);
      if (lookahead == 'o') ADVANCE(190);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(196);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(167);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(191);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(175);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(192);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'c') ADVANCE(177);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'c') ADVANCE(186);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'c') ADVANCE(154);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'c') ADVANCE(199);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'd') ADVANCE(140);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'd') ADVANCE(143);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(130);
      if (lookahead == 'i') ADVANCE(201);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(193);
      if (lookahead == 'i') ADVANCE(198);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(238);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(226);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(207);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(236);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(230);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(252);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(246);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(171);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(127);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(185);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(129);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'f') ADVANCE(222);
      if (lookahead == 'n') ADVANCE(131);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'f') ADVANCE(224);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'h') ADVANCE(159);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'h') ADVANCE(128);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'h') ADVANCE(138);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'i') ADVANCE(152);
      if (lookahead == 's') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'i') ADVANCE(178);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'i') ADVANCE(181);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'i') ADVANCE(168);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'i') ADVANCE(135);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(156);
      if (lookahead == 'n') ADVANCE(132);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(260);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(203);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(162);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(197);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(164);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'm') ADVANCE(170);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'm') ADVANCE(147);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(216);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(218);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(133);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(195);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'o') ADVANCE(182);
      if (lookahead == 'u') ADVANCE(173);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'o') ADVANCE(184);
      if (lookahead == 'r') ADVANCE(148);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'o') ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'o') ADVANCE(183);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'p') ADVANCE(146);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'p') ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(228);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(214);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(126);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(150);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(209);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(220);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(188);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(141);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(144);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(145);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(242);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(120);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(255);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(179);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(158);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(149);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(157);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'u') ADVANCE(166);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'v') ADVANCE(160);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'y') ADVANCE(250);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'y') ADVANCE(212);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(204);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(anon_sym_aside);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_aside);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(anon_sym_as);
      if (lookahead == 'i') ADVANCE(18);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_as);
      if (lookahead == 'i') ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(anon_sym_an);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(anon_sym_literally);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(anon_sym_literally);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(anon_sym_decorator);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(anon_sym_decorator);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(anon_sym_open);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(anon_sym_open);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(anon_sym_function);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(anon_sym_function);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(anon_sym_class);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(anon_sym_class);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(anon_sym_if);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(anon_sym_elif);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(anon_sym_elif);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(anon_sym_else);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(anon_sym_for);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(anon_sym_while);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(anon_sym_with);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(anon_sym_try);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(anon_sym_except);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(anon_sym_finally);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(anon_sym_close);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_the);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_the);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(aux_sym_the_assignment_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(239);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_is);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(anon_sym_let);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(anon_sym_equal);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(anon_sym_be);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(anon_sym_increase);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(anon_sym_increase);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(anon_sym_decrease);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(anon_sym_decrease);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(anon_sym_multiply);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(anon_sym_multiply);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(anon_sym_divide);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(anon_sym_divide);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(anon_sym_by);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(anon_sym_enchant);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(anon_sym_enchant);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(anon_sym_rejection);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(anon_sym_math);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(anon_sym_call);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(anon_sym_call);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(205);
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
  [4] = {.lex_state = 116, .external_lex_state = 1},
  [5] = {.lex_state = 116, .external_lex_state = 1},
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
  [33] = {.lex_state = 0, .external_lex_state = 1},
  [34] = {.lex_state = 0, .external_lex_state = 1},
  [35] = {.lex_state = 0, .external_lex_state = 1},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 114},
  [40] = {.lex_state = 114},
  [41] = {.lex_state = 114},
  [42] = {.lex_state = 114},
  [43] = {.lex_state = 114},
  [44] = {.lex_state = 114},
  [45] = {.lex_state = 114},
  [46] = {.lex_state = 114},
  [47] = {.lex_state = 114},
  [48] = {.lex_state = 114},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 114},
  [54] = {.lex_state = 114},
  [55] = {.lex_state = 114},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 115},
  [59] = {.lex_state = 115},
  [60] = {.lex_state = 115},
  [61] = {.lex_state = 114},
  [62] = {.lex_state = 114},
  [63] = {.lex_state = 114},
  [64] = {.lex_state = 114},
  [65] = {.lex_state = 114},
  [66] = {.lex_state = 114},
  [67] = {.lex_state = 114},
  [68] = {.lex_state = 114},
  [69] = {.lex_state = 114},
  [70] = {.lex_state = 114},
  [71] = {.lex_state = 114},
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
    [anon_sym_the] = ACTIONS(1),
    [anon_sym_is] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_equal] = ACTIONS(1),
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
    [sym_program] = STATE(51),
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
    [sym_the_assignment] = STATE(2),
    [sym_let_assignment] = STATE(2),
    [sym_augmented_assign_sentence] = STATE(2),
    [sym_enchantment] = STATE(2),
    [sym_call_statement] = STATE(2),
    [aux_sym_program_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym__newline] = ACTIONS(5),
    [anon_sym_comment] = ACTIONS(7),
    [anon_sym_aside] = ACTIONS(9),
    [anon_sym_as] = ACTIONS(11),
    [anon_sym_literally] = ACTIONS(13),
    [anon_sym_decorator] = ACTIONS(15),
    [anon_sym_open] = ACTIONS(17),
    [anon_sym_function] = ACTIONS(19),
    [anon_sym_class] = ACTIONS(21),
    [anon_sym_if] = ACTIONS(23),
    [anon_sym_elif] = ACTIONS(25),
    [anon_sym_else] = ACTIONS(27),
    [anon_sym_for] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_close] = ACTIONS(33),
    [anon_sym_the] = ACTIONS(35),
    [anon_sym_let] = ACTIONS(37),
    [anon_sym_increase] = ACTIONS(39),
    [anon_sym_decrease] = ACTIONS(39),
    [anon_sym_multiply] = ACTIONS(39),
    [anon_sym_divide] = ACTIONS(39),
    [anon_sym_enchant] = ACTIONS(41),
    [anon_sym_call] = ACTIONS(43),
    [sym_expression_line] = ACTIONS(5),
  },
  [2] = {
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
    [sym_the_assignment] = STATE(3),
    [sym_let_assignment] = STATE(3),
    [sym_augmented_assign_sentence] = STATE(3),
    [sym_enchantment] = STATE(3),
    [sym_call_statement] = STATE(3),
    [aux_sym_program_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(45),
    [sym__newline] = ACTIONS(47),
    [anon_sym_comment] = ACTIONS(7),
    [anon_sym_aside] = ACTIONS(9),
    [anon_sym_as] = ACTIONS(11),
    [anon_sym_literally] = ACTIONS(13),
    [anon_sym_decorator] = ACTIONS(15),
    [anon_sym_open] = ACTIONS(17),
    [anon_sym_function] = ACTIONS(19),
    [anon_sym_class] = ACTIONS(21),
    [anon_sym_if] = ACTIONS(23),
    [anon_sym_elif] = ACTIONS(25),
    [anon_sym_else] = ACTIONS(27),
    [anon_sym_for] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(31),
    [anon_sym_close] = ACTIONS(33),
    [anon_sym_the] = ACTIONS(35),
    [anon_sym_let] = ACTIONS(37),
    [anon_sym_increase] = ACTIONS(39),
    [anon_sym_decrease] = ACTIONS(39),
    [anon_sym_multiply] = ACTIONS(39),
    [anon_sym_divide] = ACTIONS(39),
    [anon_sym_enchant] = ACTIONS(41),
    [anon_sym_call] = ACTIONS(43),
    [sym_expression_line] = ACTIONS(47),
  },
  [3] = {
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
    [sym_the_assignment] = STATE(3),
    [sym_let_assignment] = STATE(3),
    [sym_augmented_assign_sentence] = STATE(3),
    [sym_enchantment] = STATE(3),
    [sym_call_statement] = STATE(3),
    [aux_sym_program_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(49),
    [sym__newline] = ACTIONS(51),
    [anon_sym_comment] = ACTIONS(54),
    [anon_sym_aside] = ACTIONS(57),
    [anon_sym_as] = ACTIONS(60),
    [anon_sym_literally] = ACTIONS(63),
    [anon_sym_decorator] = ACTIONS(66),
    [anon_sym_open] = ACTIONS(69),
    [anon_sym_function] = ACTIONS(72),
    [anon_sym_class] = ACTIONS(75),
    [anon_sym_if] = ACTIONS(78),
    [anon_sym_elif] = ACTIONS(81),
    [anon_sym_else] = ACTIONS(84),
    [anon_sym_for] = ACTIONS(87),
    [anon_sym_while] = ACTIONS(90),
    [anon_sym_close] = ACTIONS(93),
    [anon_sym_the] = ACTIONS(96),
    [anon_sym_let] = ACTIONS(99),
    [anon_sym_increase] = ACTIONS(102),
    [anon_sym_decrease] = ACTIONS(102),
    [anon_sym_multiply] = ACTIONS(102),
    [anon_sym_divide] = ACTIONS(102),
    [anon_sym_enchant] = ACTIONS(105),
    [anon_sym_call] = ACTIONS(108),
    [sym_expression_line] = ACTIONS(51),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(115), 1,
      aux_sym_comment_token1,
    ACTIONS(111), 2,
      sym_expression_line,
      ts_builtin_sym_end,
    ACTIONS(113), 23,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [33] = 3,
    ACTIONS(121), 1,
      aux_sym_comment_token1,
    ACTIONS(117), 2,
      sym_expression_line,
      ts_builtin_sym_end,
    ACTIONS(119), 23,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [66] = 2,
    ACTIONS(125), 1,
      anon_sym_as,
    ACTIONS(123), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [96] = 2,
    ACTIONS(129), 1,
      anon_sym_as,
    ACTIONS(127), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [126] = 2,
    ACTIONS(133), 1,
      anon_sym_as,
    ACTIONS(131), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [156] = 2,
    ACTIONS(137), 1,
      anon_sym_as,
    ACTIONS(135), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [186] = 2,
    ACTIONS(141), 1,
      anon_sym_as,
    ACTIONS(139), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [216] = 2,
    ACTIONS(145), 1,
      anon_sym_as,
    ACTIONS(143), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [246] = 2,
    ACTIONS(149), 1,
      anon_sym_as,
    ACTIONS(147), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [276] = 2,
    ACTIONS(153), 1,
      anon_sym_as,
    ACTIONS(151), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [306] = 3,
    ACTIONS(157), 1,
      anon_sym_as,
    ACTIONS(159), 1,
      anon_sym_if,
    ACTIONS(155), 23,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [338] = 2,
    ACTIONS(163), 1,
      anon_sym_as,
    ACTIONS(161), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [368] = 2,
    ACTIONS(167), 1,
      anon_sym_as,
    ACTIONS(165), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [398] = 2,
    ACTIONS(171), 1,
      anon_sym_as,
    ACTIONS(169), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [428] = 2,
    ACTIONS(175), 1,
      anon_sym_as,
    ACTIONS(173), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [458] = 2,
    ACTIONS(179), 1,
      anon_sym_as,
    ACTIONS(177), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [488] = 2,
    ACTIONS(183), 1,
      anon_sym_as,
    ACTIONS(181), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [518] = 2,
    ACTIONS(187), 1,
      anon_sym_as,
    ACTIONS(185), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [548] = 2,
    ACTIONS(191), 1,
      anon_sym_as,
    ACTIONS(189), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [578] = 2,
    ACTIONS(195), 1,
      anon_sym_as,
    ACTIONS(193), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [608] = 2,
    ACTIONS(199), 1,
      anon_sym_as,
    ACTIONS(197), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [638] = 2,
    ACTIONS(203), 1,
      anon_sym_as,
    ACTIONS(201), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [668] = 2,
    ACTIONS(207), 1,
      anon_sym_as,
    ACTIONS(205), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [698] = 2,
    ACTIONS(211), 1,
      anon_sym_as,
    ACTIONS(209), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [728] = 2,
    ACTIONS(215), 1,
      anon_sym_as,
    ACTIONS(213), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [758] = 2,
    ACTIONS(219), 1,
      anon_sym_as,
    ACTIONS(217), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [788] = 2,
    ACTIONS(223), 1,
      anon_sym_as,
    ACTIONS(221), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [818] = 2,
    ACTIONS(227), 1,
      anon_sym_as,
    ACTIONS(225), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [848] = 2,
    ACTIONS(231), 1,
      anon_sym_as,
    ACTIONS(229), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [878] = 2,
    ACTIONS(235), 1,
      anon_sym_as,
    ACTIONS(233), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [908] = 2,
    ACTIONS(239), 1,
      anon_sym_as,
    ACTIONS(237), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [938] = 2,
    ACTIONS(243), 1,
      anon_sym_as,
    ACTIONS(241), 24,
      sym_expression_line,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_function,
      anon_sym_class,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_while,
      anon_sym_close,
      anon_sym_the,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [968] = 11,
    ACTIONS(245), 1,
      anon_sym_function,
    ACTIONS(247), 1,
      anon_sym_class,
    ACTIONS(249), 1,
      anon_sym_if,
    ACTIONS(251), 1,
      anon_sym_elif,
    ACTIONS(253), 1,
      anon_sym_else,
    ACTIONS(255), 1,
      anon_sym_for,
    ACTIONS(257), 1,
      anon_sym_while,
    ACTIONS(259), 1,
      anon_sym_with,
    ACTIONS(261), 1,
      anon_sym_try,
    ACTIONS(263), 1,
      anon_sym_except,
    ACTIONS(265), 1,
      anon_sym_finally,
  [1002] = 1,
    ACTIONS(267), 3,
      anon_sym_string,
      anon_sym_rejection,
      anon_sym_math,
  [1008] = 1,
    ACTIONS(269), 2,
      anon_sym_equal,
      anon_sym_be,
  [1013] = 1,
    ACTIONS(271), 1,
      aux_sym_comment_token1,
  [1017] = 1,
    ACTIONS(273), 1,
      aux_sym_comment_token1,
  [1021] = 1,
    ACTIONS(275), 1,
      aux_sym_comment_token1,
  [1025] = 1,
    ACTIONS(277), 1,
      aux_sym_comment_token1,
  [1029] = 1,
    ACTIONS(279), 1,
      aux_sym_comment_token1,
  [1033] = 1,
    ACTIONS(281), 1,
      aux_sym_comment_token1,
  [1037] = 1,
    ACTIONS(283), 1,
      aux_sym_comment_token1,
  [1041] = 1,
    ACTIONS(285), 1,
      aux_sym_comment_token1,
  [1045] = 1,
    ACTIONS(287), 1,
      aux_sym_comment_token1,
  [1049] = 1,
    ACTIONS(289), 1,
      aux_sym_comment_token1,
  [1053] = 1,
    ACTIONS(291), 1,
      anon_sym_aside,
  [1057] = 1,
    ACTIONS(293), 1,
      anon_sym_by,
  [1061] = 1,
    ACTIONS(295), 1,
      ts_builtin_sym_end,
  [1065] = 1,
    ACTIONS(297), 1,
      anon_sym_an,
  [1069] = 1,
    ACTIONS(299), 1,
      aux_sym_comment_token1,
  [1073] = 1,
    ACTIONS(301), 1,
      aux_sym_comment_token1,
  [1077] = 1,
    ACTIONS(303), 1,
      aux_sym_comment_token1,
  [1081] = 1,
    ACTIONS(305), 1,
      anon_sym_with,
  [1085] = 1,
    ACTIONS(307), 1,
      anon_sym_is,
  [1089] = 1,
    ACTIONS(309), 1,
      aux_sym_the_assignment_token1,
  [1093] = 1,
    ACTIONS(311), 1,
      aux_sym_the_assignment_token1,
  [1097] = 1,
    ACTIONS(313), 1,
      aux_sym_the_assignment_token1,
  [1101] = 1,
    ACTIONS(315), 1,
      aux_sym_comment_token1,
  [1105] = 1,
    ACTIONS(317), 1,
      aux_sym_comment_token1,
  [1109] = 1,
    ACTIONS(319), 1,
      aux_sym_comment_token1,
  [1113] = 1,
    ACTIONS(321), 1,
      aux_sym_comment_token1,
  [1117] = 1,
    ACTIONS(323), 1,
      aux_sym_comment_token1,
  [1121] = 1,
    ACTIONS(325), 1,
      aux_sym_comment_token1,
  [1125] = 1,
    ACTIONS(327), 1,
      aux_sym_comment_token1,
  [1129] = 1,
    ACTIONS(329), 1,
      aux_sym_comment_token1,
  [1133] = 1,
    ACTIONS(331), 1,
      aux_sym_comment_token1,
  [1137] = 1,
    ACTIONS(333), 1,
      aux_sym_comment_token1,
  [1141] = 1,
    ACTIONS(335), 1,
      aux_sym_comment_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 33,
  [SMALL_STATE(6)] = 66,
  [SMALL_STATE(7)] = 96,
  [SMALL_STATE(8)] = 126,
  [SMALL_STATE(9)] = 156,
  [SMALL_STATE(10)] = 186,
  [SMALL_STATE(11)] = 216,
  [SMALL_STATE(12)] = 246,
  [SMALL_STATE(13)] = 276,
  [SMALL_STATE(14)] = 306,
  [SMALL_STATE(15)] = 338,
  [SMALL_STATE(16)] = 368,
  [SMALL_STATE(17)] = 398,
  [SMALL_STATE(18)] = 428,
  [SMALL_STATE(19)] = 458,
  [SMALL_STATE(20)] = 488,
  [SMALL_STATE(21)] = 518,
  [SMALL_STATE(22)] = 548,
  [SMALL_STATE(23)] = 578,
  [SMALL_STATE(24)] = 608,
  [SMALL_STATE(25)] = 638,
  [SMALL_STATE(26)] = 668,
  [SMALL_STATE(27)] = 698,
  [SMALL_STATE(28)] = 728,
  [SMALL_STATE(29)] = 758,
  [SMALL_STATE(30)] = 788,
  [SMALL_STATE(31)] = 818,
  [SMALL_STATE(32)] = 848,
  [SMALL_STATE(33)] = 878,
  [SMALL_STATE(34)] = 908,
  [SMALL_STATE(35)] = 938,
  [SMALL_STATE(36)] = 968,
  [SMALL_STATE(37)] = 1002,
  [SMALL_STATE(38)] = 1008,
  [SMALL_STATE(39)] = 1013,
  [SMALL_STATE(40)] = 1017,
  [SMALL_STATE(41)] = 1021,
  [SMALL_STATE(42)] = 1025,
  [SMALL_STATE(43)] = 1029,
  [SMALL_STATE(44)] = 1033,
  [SMALL_STATE(45)] = 1037,
  [SMALL_STATE(46)] = 1041,
  [SMALL_STATE(47)] = 1045,
  [SMALL_STATE(48)] = 1049,
  [SMALL_STATE(49)] = 1053,
  [SMALL_STATE(50)] = 1057,
  [SMALL_STATE(51)] = 1061,
  [SMALL_STATE(52)] = 1065,
  [SMALL_STATE(53)] = 1069,
  [SMALL_STATE(54)] = 1073,
  [SMALL_STATE(55)] = 1077,
  [SMALL_STATE(56)] = 1081,
  [SMALL_STATE(57)] = 1085,
  [SMALL_STATE(58)] = 1089,
  [SMALL_STATE(59)] = 1093,
  [SMALL_STATE(60)] = 1097,
  [SMALL_STATE(61)] = 1101,
  [SMALL_STATE(62)] = 1105,
  [SMALL_STATE(63)] = 1109,
  [SMALL_STATE(64)] = 1113,
  [SMALL_STATE(65)] = 1117,
  [SMALL_STATE(66)] = 1121,
  [SMALL_STATE(67)] = 1125,
  [SMALL_STATE(68)] = 1129,
  [SMALL_STATE(69)] = 1133,
  [SMALL_STATE(70)] = 1137,
  [SMALL_STATE(71)] = 1141,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1, 0, 0),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(71),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(42),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(52),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(40),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(55),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(70),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(69),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(68),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(67),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [87] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(62),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(60),
  [99] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(59),
  [102] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(58),
  [105] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [108] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(39),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_except_open, 2, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_except_open, 2, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_close, 1, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_close, 1, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_def, 3, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_class_def, 3, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_open, 3, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_open, 3, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_finally_open, 2, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_finally_open, 2, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enchantment, 4, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enchantment, 4, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_augmented_assign_sentence, 4, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_augmented_assign_sentence, 4, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_assignment, 4, 0, 0),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_assignment, 4, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_the_assignment, 4, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_the_assignment, 4, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_as_an_aside_comment, 4, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_as_an_aside_comment, 4, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_open, 1, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_open, 1, 0, 0),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_if_open, 3, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_if_open, 3, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_except_open, 3, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_except_open, 3, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_with_open, 3, 0, 0),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_with_open, 3, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_open, 3, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_open, 3, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_open, 3, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_for_open, 3, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_elif_open, 3, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elif_open, 3, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_def, 3, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_def, 3, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call_statement, 2, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call_statement, 2, 0, 0),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 2, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 2, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aside_comment, 2, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_aside_comment, 2, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_def, 2, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_def, 2, 0, 0),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literally, 2, 0, 0),
  [207] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literally, 2, 0, 0),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decorator, 2, 0, 0),
  [211] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decorator, 2, 0, 0),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_close, 2, 0, 0),
  [215] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_close, 2, 0, 0),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_open, 2, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_open, 2, 0, 0),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_open, 2, 0, 0),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_for_open, 2, 0, 0),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_elif_open, 2, 0, 0),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elif_open, 2, 0, 0),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_open, 2, 0, 0),
  [231] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_open, 2, 0, 0),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_open, 2, 0, 0),
  [235] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_open, 2, 0, 0),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_def, 2, 0, 0),
  [239] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_class_def, 2, 0, 0),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_try_open, 2, 0, 0),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_try_open, 2, 0, 0),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [295] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
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
