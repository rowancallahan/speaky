#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 78
#define LARGE_STATE_COUNT 5
#define SYMBOL_COUNT 70
#define ALIAS_COUNT 0
#define TOKEN_COUNT 41
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 16
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 20

enum ts_symbol_identifiers {
  sym__newline = 1,
  sym__indent = 2,
  anon_sym_comment = 3,
  aux_sym_comment_token1 = 4,
  anon_sym_aside = 5,
  anon_sym_as = 6,
  anon_sym_an = 7,
  anon_sym_literally = 8,
  anon_sym_decorator = 9,
  anon_sym_open = 10,
  anon_sym_function = 11,
  anon_sym_with = 12,
  anon_sym_parameters = 13,
  anon_sym_and = 14,
  anon_sym_class = 15,
  anon_sym_inherits = 16,
  anon_sym_if = 17,
  anon_sym_elif = 18,
  anon_sym_else = 19,
  anon_sym_for = 20,
  anon_sym_in = 21,
  anon_sym_while = 22,
  anon_sym_try = 23,
  anon_sym_except = 24,
  anon_sym_finally = 25,
  anon_sym_close = 26,
  anon_sym_let = 27,
  anon_sym_be = 28,
  anon_sym_increase = 29,
  anon_sym_decrease = 30,
  anon_sym_multiply = 31,
  anon_sym_divide = 32,
  anon_sym_by = 33,
  anon_sym_enchant = 34,
  anon_sym_string = 35,
  anon_sym_rejection = 36,
  anon_sym_math = 37,
  anon_sym_call = 38,
  anon_sym_dot = 39,
  sym_identifier = 40,
  sym_program = 41,
  sym__statement = 42,
  sym_comment = 43,
  sym_aside_comment = 44,
  sym_as_an_aside_comment = 45,
  sym_literally = 46,
  sym_decorator = 47,
  sym_function_def = 48,
  sym_param_list = 49,
  sym_class_def = 50,
  sym_if_open = 51,
  sym_elif_open = 52,
  sym_else_open = 53,
  sym_for_open = 54,
  sym_while_open = 55,
  sym_with_open = 56,
  sym_try_open = 57,
  sym_except_open = 58,
  sym_finally_open = 59,
  sym_block_close = 60,
  sym_let_assignment = 61,
  sym_augmented_assign_sentence = 62,
  sym_enchantment = 63,
  sym_call_statement = 64,
  sym_dotted_name = 65,
  sym_raw_line = 66,
  aux_sym_program_repeat1 = 67,
  aux_sym_param_list_repeat1 = 68,
  aux_sym_dotted_name_repeat1 = 69,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__newline] = "_newline",
  [sym__indent] = "_indent",
  [anon_sym_comment] = "comment",
  [aux_sym_comment_token1] = "comment_token1",
  [anon_sym_aside] = "aside",
  [anon_sym_as] = "as",
  [anon_sym_an] = "an",
  [anon_sym_literally] = "literally",
  [anon_sym_decorator] = "decorator",
  [anon_sym_open] = "open",
  [anon_sym_function] = "function",
  [anon_sym_with] = "with",
  [anon_sym_parameters] = "parameters",
  [anon_sym_and] = "and",
  [anon_sym_class] = "class",
  [anon_sym_inherits] = "inherits",
  [anon_sym_if] = "if",
  [anon_sym_elif] = "elif",
  [anon_sym_else] = "else",
  [anon_sym_for] = "for",
  [anon_sym_in] = "in",
  [anon_sym_while] = "while",
  [anon_sym_try] = "try",
  [anon_sym_except] = "except",
  [anon_sym_finally] = "finally",
  [anon_sym_close] = "close",
  [anon_sym_let] = "let",
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
  [anon_sym_dot] = "dot",
  [sym_identifier] = "identifier",
  [sym_program] = "program",
  [sym__statement] = "_statement",
  [sym_comment] = "comment",
  [sym_aside_comment] = "aside_comment",
  [sym_as_an_aside_comment] = "as_an_aside_comment",
  [sym_literally] = "literally",
  [sym_decorator] = "decorator",
  [sym_function_def] = "function_def",
  [sym_param_list] = "param_list",
  [sym_class_def] = "class_def",
  [sym_if_open] = "if_open",
  [sym_elif_open] = "elif_open",
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
  [sym_dotted_name] = "dotted_name",
  [sym_raw_line] = "raw_line",
  [aux_sym_program_repeat1] = "program_repeat1",
  [aux_sym_param_list_repeat1] = "param_list_repeat1",
  [aux_sym_dotted_name_repeat1] = "dotted_name_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__newline] = sym__newline,
  [sym__indent] = sym__indent,
  [anon_sym_comment] = anon_sym_comment,
  [aux_sym_comment_token1] = aux_sym_comment_token1,
  [anon_sym_aside] = anon_sym_aside,
  [anon_sym_as] = anon_sym_as,
  [anon_sym_an] = anon_sym_an,
  [anon_sym_literally] = anon_sym_literally,
  [anon_sym_decorator] = anon_sym_decorator,
  [anon_sym_open] = anon_sym_open,
  [anon_sym_function] = anon_sym_function,
  [anon_sym_with] = anon_sym_with,
  [anon_sym_parameters] = anon_sym_parameters,
  [anon_sym_and] = anon_sym_and,
  [anon_sym_class] = anon_sym_class,
  [anon_sym_inherits] = anon_sym_inherits,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_elif] = anon_sym_elif,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_for] = anon_sym_for,
  [anon_sym_in] = anon_sym_in,
  [anon_sym_while] = anon_sym_while,
  [anon_sym_try] = anon_sym_try,
  [anon_sym_except] = anon_sym_except,
  [anon_sym_finally] = anon_sym_finally,
  [anon_sym_close] = anon_sym_close,
  [anon_sym_let] = anon_sym_let,
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
  [anon_sym_dot] = anon_sym_dot,
  [sym_identifier] = sym_identifier,
  [sym_program] = sym_program,
  [sym__statement] = sym__statement,
  [sym_comment] = sym_comment,
  [sym_aside_comment] = sym_aside_comment,
  [sym_as_an_aside_comment] = sym_as_an_aside_comment,
  [sym_literally] = sym_literally,
  [sym_decorator] = sym_decorator,
  [sym_function_def] = sym_function_def,
  [sym_param_list] = sym_param_list,
  [sym_class_def] = sym_class_def,
  [sym_if_open] = sym_if_open,
  [sym_elif_open] = sym_elif_open,
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
  [sym_dotted_name] = sym_dotted_name,
  [sym_raw_line] = sym_raw_line,
  [aux_sym_program_repeat1] = aux_sym_program_repeat1,
  [aux_sym_param_list_repeat1] = aux_sym_param_list_repeat1,
  [aux_sym_dotted_name_repeat1] = aux_sym_dotted_name_repeat1,
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
  [sym__indent] = {
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
  [anon_sym_with] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_parameters] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_and] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_class] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_inherits] = {
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
  [anon_sym_in] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_while] = {
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
  [anon_sym_dot] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
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
  [sym_param_list] = {
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
  [sym_dotted_name] = {
    .visible = true,
    .named = true,
  },
  [sym_raw_line] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_program_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_param_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_dotted_name_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_args = 1,
  field_body = 2,
  field_code = 3,
  field_condition = 4,
  field_expr = 5,
  field_function = 6,
  field_iterable = 7,
  field_kind = 8,
  field_name = 9,
  field_op = 10,
  field_params = 11,
  field_parent = 12,
  field_text = 13,
  field_type = 14,
  field_value = 15,
  field_var = 16,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_args] = "args",
  [field_body] = "body",
  [field_code] = "code",
  [field_condition] = "condition",
  [field_expr] = "expr",
  [field_function] = "function",
  [field_iterable] = "iterable",
  [field_kind] = "kind",
  [field_name] = "name",
  [field_op] = "op",
  [field_params] = "params",
  [field_parent] = "parent",
  [field_text] = "text",
  [field_type] = "type",
  [field_value] = "value",
  [field_var] = "var",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 1},
  [6] = {.index = 5, .length = 1},
  [7] = {.index = 6, .length = 1},
  [8] = {.index = 7, .length = 1},
  [9] = {.index = 8, .length = 1},
  [10] = {.index = 9, .length = 2},
  [11] = {.index = 11, .length = 1},
  [12] = {.index = 12, .length = 2},
  [13] = {.index = 14, .length = 3},
  [14] = {.index = 17, .length = 2},
  [15] = {.index = 19, .length = 2},
  [16] = {.index = 21, .length = 2},
  [17] = {.index = 23, .length = 2},
  [18] = {.index = 25, .length = 2},
  [19] = {.index = 27, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_text, 1},
  [1] =
    {field_code, 1},
  [2] =
    {field_name, 1},
  [3] =
    {field_kind, 1},
  [4] =
    {field_function, 1},
  [5] =
    {field_name, 2},
  [6] =
    {field_expr, 2},
  [7] =
    {field_condition, 2},
  [8] =
    {field_type, 2},
  [9] =
    {field_kind, 1},
    {field_name, 2},
  [11] =
    {field_text, 3},
  [12] =
    {field_value, 3},
    {field_var, 1},
  [14] =
    {field_op, 0},
    {field_value, 3},
    {field_var, 1},
  [17] =
    {field_body, 3},
    {field_type, 2},
  [19] =
    {field_args, 3},
    {field_function, 1},
  [21] =
    {field_name, 2},
    {field_params, 4},
  [23] =
    {field_name, 2},
    {field_parent, 4},
  [25] =
    {field_iterable, 4},
    {field_var, 2},
  [27] =
    {field_name, 2},
    {field_params, 5},
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
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(126);
      ADVANCE_MAP(
        '\n', 127,
        '\r', 1,
        'a', 68,
        'b', 21,
        'c', 2,
        'd', 22,
        'e', 55,
        'f', 46,
        'i', 39,
        'l', 31,
        'm', 7,
        'o', 82,
        'p', 5,
        'r', 23,
        's', 106,
        't', 85,
        'w', 42,
      );
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(127);
      END_STATE();
    case 2:
      if (lookahead == 'a') ADVANCE(58);
      if (lookahead == 'l') ADVANCE(3);
      if (lookahead == 'o') ADVANCE(65);
      END_STATE();
    case 3:
      if (lookahead == 'a') ADVANCE(95);
      if (lookahead == 'o') ADVANCE(96);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        'a', 247,
        'c', 134,
        'd', 161,
        'e', 218,
        'i', 220,
        'l', 162,
        'm', 273,
        'o', 232,
        '\t', 133,
        ' ', 133,
      );
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(88);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(66);
      END_STATE();
    case 7:
      if (lookahead == 'a') ADVANCE(103);
      if (lookahead == 'u') ADVANCE(62);
      END_STATE();
    case 8:
      if (lookahead == 'a') ADVANCE(73);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(8);
      END_STATE();
    case 9:
      if (lookahead == 'a') ADVANCE(104);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(61);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(97);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(77);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(63);
      END_STATE();
    case 14:
      if (lookahead == 'c') ADVANCE(78);
      END_STATE();
    case 15:
      if (lookahead == 'c') ADVANCE(45);
      END_STATE();
    case 16:
      if (lookahead == 'c') ADVANCE(30);
      END_STATE();
    case 17:
      if (lookahead == 'c') ADVANCE(109);
      END_STATE();
    case 18:
      if (lookahead == 'c') ADVANCE(111);
      END_STATE();
    case 19:
      if (lookahead == 'd') ADVANCE(25);
      END_STATE();
    case 20:
      if (lookahead == 'd') ADVANCE(28);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(325);
      if (lookahead == 'y') ADVANCE(337);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(14);
      if (lookahead == 'i') ADVANCE(112);
      if (lookahead == 'o') ADVANCE(98);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(54);
      END_STATE();
    case 24:
      if (lookahead == 'e') ADVANCE(312);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(284);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(319);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(315);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(334);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(328);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(84);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(99);
      if (lookahead == 'i') ADVANCE(108);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(69);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(76);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(11);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(92);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(90);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(110);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(18);
      END_STATE();
    case 39:
      if (lookahead == 'f') ADVANCE(310);
      if (lookahead == 'n') ADVANCE(314);
      END_STATE();
    case 40:
      if (lookahead == 'f') ADVANCE(311);
      END_STATE();
    case 41:
      if (lookahead == 'g') ADVANCE(341);
      END_STATE();
    case 42:
      if (lookahead == 'h') ADVANCE(50);
      if (lookahead == 'i') ADVANCE(105);
      END_STATE();
    case 43:
      if (lookahead == 'h') ADVANCE(343);
      END_STATE();
    case 44:
      if (lookahead == 'h') ADVANCE(302);
      END_STATE();
    case 45:
      if (lookahead == 'h') ADVANCE(12);
      END_STATE();
    case 46:
      if (lookahead == 'i') ADVANCE(74);
      if (lookahead == 'o') ADVANCE(86);
      if (lookahead == 'u') ADVANCE(75);
      END_STATE();
    case 47:
      if (lookahead == 'i') ADVANCE(40);
      if (lookahead == 's') ADVANCE(24);
      END_STATE();
    case 48:
      if (lookahead == 'i') ADVANCE(79);
      END_STATE();
    case 49:
      if (lookahead == 'i') ADVANCE(83);
      END_STATE();
    case 50:
      if (lookahead == 'i') ADVANCE(64);
      END_STATE();
    case 51:
      if (lookahead == 'i') ADVANCE(70);
      END_STATE();
    case 52:
      if (lookahead == 'i') ADVANCE(20);
      END_STATE();
    case 53:
      if (lookahead == 'i') ADVANCE(81);
      END_STATE();
    case 54:
      if (lookahead == 'j') ADVANCE(38);
      END_STATE();
    case 55:
      if (lookahead == 'l') ADVANCE(47);
      if (lookahead == 'n') ADVANCE(15);
      if (lookahead == 'x') ADVANCE(16);
      END_STATE();
    case 56:
      if (lookahead == 'l') ADVANCE(344);
      END_STATE();
    case 57:
      if (lookahead == 'l') ADVANCE(114);
      END_STATE();
    case 58:
      if (lookahead == 'l') ADVANCE(56);
      END_STATE();
    case 59:
      if (lookahead == 'l') ADVANCE(115);
      END_STATE();
    case 60:
      if (lookahead == 'l') ADVANCE(116);
      END_STATE();
    case 61:
      if (lookahead == 'l') ADVANCE(57);
      END_STATE();
    case 62:
      if (lookahead == 'l') ADVANCE(107);
      END_STATE();
    case 63:
      if (lookahead == 'l') ADVANCE(60);
      END_STATE();
    case 64:
      if (lookahead == 'l') ADVANCE(27);
      END_STATE();
    case 65:
      if (lookahead == 'm') ADVANCE(67);
      END_STATE();
    case 66:
      if (lookahead == 'm') ADVANCE(37);
      END_STATE();
    case 67:
      if (lookahead == 'm') ADVANCE(33);
      END_STATE();
    case 68:
      if (lookahead == 'n') ADVANCE(291);
      if (lookahead == 's') ADVANCE(287);
      END_STATE();
    case 69:
      if (lookahead == 'n') ADVANCE(298);
      END_STATE();
    case 70:
      if (lookahead == 'n') ADVANCE(41);
      END_STATE();
    case 71:
      if (lookahead == 'n') ADVANCE(301);
      END_STATE();
    case 72:
      if (lookahead == 'n') ADVANCE(342);
      END_STATE();
    case 73:
      if (lookahead == 'n') ADVANCE(290);
      END_STATE();
    case 74:
      if (lookahead == 'n') ADVANCE(10);
      END_STATE();
    case 75:
      if (lookahead == 'n') ADVANCE(17);
      END_STATE();
    case 76:
      if (lookahead == 'n') ADVANCE(101);
      END_STATE();
    case 77:
      if (lookahead == 'n') ADVANCE(102);
      END_STATE();
    case 78:
      if (lookahead == 'o') ADVANCE(91);
      if (lookahead == 'r') ADVANCE(34);
      END_STATE();
    case 79:
      if (lookahead == 'o') ADVANCE(71);
      END_STATE();
    case 80:
      if (lookahead == 'o') ADVANCE(87);
      END_STATE();
    case 81:
      if (lookahead == 'o') ADVANCE(72);
      END_STATE();
    case 82:
      if (lookahead == 'p') ADVANCE(32);
      END_STATE();
    case 83:
      if (lookahead == 'p') ADVANCE(59);
      END_STATE();
    case 84:
      if (lookahead == 'p') ADVANCE(100);
      END_STATE();
    case 85:
      if (lookahead == 'r') ADVANCE(113);
      END_STATE();
    case 86:
      if (lookahead == 'r') ADVANCE(313);
      END_STATE();
    case 87:
      if (lookahead == 'r') ADVANCE(295);
      END_STATE();
    case 88:
      if (lookahead == 'r') ADVANCE(6);
      END_STATE();
    case 89:
      if (lookahead == 'r') ADVANCE(51);
      END_STATE();
    case 90:
      if (lookahead == 'r') ADVANCE(94);
      END_STATE();
    case 91:
      if (lookahead == 'r') ADVANCE(9);
      END_STATE();
    case 92:
      if (lookahead == 'r') ADVANCE(13);
      END_STATE();
    case 93:
      if (lookahead == 's') ADVANCE(308);
      END_STATE();
    case 94:
      if (lookahead == 's') ADVANCE(304);
      END_STATE();
    case 95:
      if (lookahead == 's') ADVANCE(93);
      END_STATE();
    case 96:
      if (lookahead == 's') ADVANCE(26);
      END_STATE();
    case 97:
      if (lookahead == 's') ADVANCE(29);
      END_STATE();
    case 98:
      if (lookahead == 't') ADVANCE(347);
      END_STATE();
    case 99:
      if (lookahead == 't') ADVANCE(322);
      END_STATE();
    case 100:
      if (lookahead == 't') ADVANCE(317);
      END_STATE();
    case 101:
      if (lookahead == 't') ADVANCE(129);
      END_STATE();
    case 102:
      if (lookahead == 't') ADVANCE(338);
      END_STATE();
    case 103:
      if (lookahead == 't') ADVANCE(43);
      END_STATE();
    case 104:
      if (lookahead == 't') ADVANCE(80);
      END_STATE();
    case 105:
      if (lookahead == 't') ADVANCE(44);
      END_STATE();
    case 106:
      if (lookahead == 't') ADVANCE(89);
      END_STATE();
    case 107:
      if (lookahead == 't') ADVANCE(49);
      END_STATE();
    case 108:
      if (lookahead == 't') ADVANCE(35);
      END_STATE();
    case 109:
      if (lookahead == 't') ADVANCE(48);
      END_STATE();
    case 110:
      if (lookahead == 't') ADVANCE(36);
      END_STATE();
    case 111:
      if (lookahead == 't') ADVANCE(53);
      END_STATE();
    case 112:
      if (lookahead == 'v') ADVANCE(52);
      END_STATE();
    case 113:
      if (lookahead == 'y') ADVANCE(316);
      END_STATE();
    case 114:
      if (lookahead == 'y') ADVANCE(318);
      END_STATE();
    case 115:
      if (lookahead == 'y') ADVANCE(331);
      END_STATE();
    case 116:
      if (lookahead == 'y') ADVANCE(292);
      END_STATE();
    case 117:
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(117);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(349);
      END_STATE();
    case 118:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(281);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 119:
      if (eof) ADVANCE(126);
      ADVANCE_MAP(
        '\n', 127,
        '\r', 132,
        'a', 247,
        'c', 134,
        'd', 161,
        'e', 218,
        'i', 217,
        'l', 162,
        'm', 273,
        'o', 232,
        '\t', 128,
        ' ', 128,
      );
      if (lookahead != 0) ADVANCE(283);
      END_STATE();
    case 120:
      if (eof) ADVANCE(126);
      ADVANCE_MAP(
        '\n', 127,
        '\r', 132,
        'a', 247,
        'c', 134,
        'd', 161,
        'e', 218,
        'i', 220,
        'l', 162,
        'm', 273,
        'o', 232,
        'p', 147,
        'w', 193,
        '\t', 128,
        ' ', 128,
      );
      if (lookahead != 0) ADVANCE(283);
      END_STATE();
    case 121:
      if (eof) ADVANCE(126);
      ADVANCE_MAP(
        '\n', 127,
        '\r', 132,
        'a', 247,
        'c', 134,
        'd', 161,
        'e', 218,
        'i', 220,
        'l', 162,
        'm', 273,
        'o', 232,
        'w', 193,
        '\t', 128,
        ' ', 128,
      );
      if (lookahead != 0) ADVANCE(283);
      END_STATE();
    case 122:
      if (eof) ADVANCE(126);
      ADVANCE_MAP(
        '\n', 127,
        '\r', 132,
        'a', 247,
        'c', 134,
        'd', 161,
        'e', 218,
        'i', 220,
        'l', 162,
        'm', 273,
        'o', 232,
        '\t', 128,
        ' ', 128,
      );
      if (lookahead != 0) ADVANCE(283);
      END_STATE();
    case 123:
      if (eof) ADVANCE(126);
      ADVANCE_MAP(
        '\n', 127,
        '\r', 132,
        'a', 247,
        'c', 134,
        'd', 160,
        'e', 218,
        'i', 220,
        'l', 162,
        'm', 273,
        'o', 232,
        'w', 193,
        '\t', 128,
        ' ', 128,
      );
      if (lookahead != 0) ADVANCE(283);
      END_STATE();
    case 124:
      if (eof) ADVANCE(126);
      ADVANCE_MAP(
        '\n', 127,
        '\r', 132,
        'a', 215,
        'c', 135,
        'd', 168,
        'e', 219,
        'i', 221,
        'l', 169,
        'm', 274,
        'o', 233,
        '\t', 128,
        ' ', 128,
      );
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0) ADVANCE(283);
      END_STATE();
    case 125:
      if (eof) ADVANCE(126);
      ADVANCE_MAP(
        '\n', 127,
        '\r', 132,
        'a', 248,
        'c', 135,
        'd', 168,
        'e', 219,
        'i', 221,
        'l', 169,
        'm', 274,
        'o', 233,
        '\t', 128,
        ' ', 128,
      );
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0) ADVANCE(283);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym__newline);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym__indent);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(128);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_comment);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_comment);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '\n') ADVANCE(127);
      if (lookahead != 0) ADVANCE(283);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      ADVANCE_MAP(
        'a', 247,
        'c', 134,
        'd', 161,
        'e', 218,
        'i', 220,
        'l', 162,
        'm', 273,
        'o', 232,
        '\t', 133,
        ' ', 133,
      );
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(203);
      if (lookahead == 'l') ADVANCE(227);
      if (lookahead == 'o') ADVANCE(209);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(205);
      if (lookahead == 'l') ADVANCE(226);
      if (lookahead == 'o') ADVANCE(210);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(211);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(264);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(268);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(207);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(208);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(254);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(253);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(224);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(225);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(256);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(255);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'a') ADVANCE(243);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'c') ADVANCE(228);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'c') ADVANCE(188);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'c') ADVANCE(245);
      if (lookahead == 'h') ADVANCE(182);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'c') ADVANCE(245);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'c') ADVANCE(229);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'c') ADVANCE(190);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'c') ADVANCE(246);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'd') ADVANCE(307);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'd') ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'd') ADVANCE(170);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'd') ADVANCE(165);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'd') ADVANCE(172);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(148);
      if (lookahead == 'i') ADVANCE(275);
      if (lookahead == 'o') ADVANCE(260);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(148);
      if (lookahead == 'i') ADVANCE(275);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(257);
      if (lookahead == 'i') ADVANCE(265);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(286);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(321);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(336);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(330);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(327);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(152);
      if (lookahead == 'i') ADVANCE(276);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(261);
      if (lookahead == 'i') ADVANCE(269);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(285);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(320);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(335);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(329);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(326);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(214);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(216);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(222);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(223);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(141);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(240);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(244);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(241);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(242);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(272);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(146);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'e') ADVANCE(145);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'h') ADVANCE(143);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'h') ADVANCE(303);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'h') ADVANCE(144);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'i') ADVANCE(234);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'i') ADVANCE(235);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'i') ADVANCE(267);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'i') ADVANCE(271);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'i') ADVANCE(158);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'i') ADVANCE(159);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(346);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(277);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(345);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(279);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(280);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(197);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(266);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(199);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(270);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(201);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'l') ADVANCE(202);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'm') ADVANCE(212);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'm') ADVANCE(213);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'm') ADVANCE(185);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'm') ADVANCE(177);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'm') ADVANCE(179);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(300);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(155);
      if (lookahead == 's') ADVANCE(289);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(299);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(150);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(149);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(153);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(151);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(154);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(258);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(262);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(259);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'n') ADVANCE(263);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'o') ADVANCE(252);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'o') ADVANCE(251);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'o') ADVANCE(238);
      if (lookahead == 'r') ADVANCE(178);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'o') ADVANCE(239);
      if (lookahead == 'r') ADVANCE(180);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'o') ADVANCE(236);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'o') ADVANCE(237);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'p') ADVANCE(175);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'p') ADVANCE(176);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'p') ADVANCE(198);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'p') ADVANCE(200);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(297);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(296);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(138);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(249);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(140);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(186);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'r') ADVANCE(187);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(288);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(289);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(305);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(309);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(164);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(171);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(166);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(173);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(167);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 's') ADVANCE(174);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(324);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(131);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(340);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(348);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(323);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(130);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(339);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(230);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(183);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(191);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(189);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(231);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(184);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(192);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(250);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 't') ADVANCE(181);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'u') ADVANCE(204);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'u') ADVANCE(206);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'v') ADVANCE(195);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'v') ADVANCE(196);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'y') ADVANCE(333);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'y') ADVANCE(294);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'y') ADVANCE(332);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == 'y') ADVANCE(293);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(281);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(anon_sym_aside);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(anon_sym_aside);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(anon_sym_aside);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(anon_sym_as);
      if (lookahead == 'i') ADVANCE(19);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(anon_sym_as);
      if (lookahead == 'i') ADVANCE(156);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(anon_sym_as);
      if (lookahead == 'i') ADVANCE(157);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(anon_sym_an);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(anon_sym_an);
      if (lookahead == 'd') ADVANCE(306);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(anon_sym_literally);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(anon_sym_literally);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(anon_sym_literally);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(anon_sym_decorator);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(anon_sym_decorator);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(anon_sym_decorator);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(anon_sym_open);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(anon_sym_open);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(anon_sym_open);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(anon_sym_function);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(anon_sym_with);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(anon_sym_with);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(anon_sym_parameters);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(anon_sym_parameters);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(anon_sym_and);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(anon_sym_class);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(anon_sym_inherits);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(anon_sym_elif);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(anon_sym_try);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(anon_sym_except);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(anon_sym_finally);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(anon_sym_close);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(anon_sym_close);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(anon_sym_let);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(anon_sym_let);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(anon_sym_be);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(anon_sym_increase);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(anon_sym_increase);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(anon_sym_decrease);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(anon_sym_decrease);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(anon_sym_decrease);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(anon_sym_multiply);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(anon_sym_multiply);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(anon_sym_multiply);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(anon_sym_divide);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(anon_sym_divide);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(anon_sym_divide);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(anon_sym_by);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(anon_sym_enchant);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(anon_sym_enchant);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(anon_sym_enchant);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(anon_sym_rejection);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(anon_sym_math);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(anon_sym_call);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(anon_sym_call);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(anon_sym_call);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(anon_sym_dot);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(anon_sym_dot);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(283);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(349);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 122},
  [2] = {.lex_state = 122},
  [3] = {.lex_state = 122},
  [4] = {.lex_state = 4},
  [5] = {.lex_state = 123},
  [6] = {.lex_state = 124},
  [7] = {.lex_state = 124},
  [8] = {.lex_state = 124},
  [9] = {.lex_state = 123},
  [10] = {.lex_state = 123},
  [11] = {.lex_state = 124},
  [12] = {.lex_state = 123},
  [13] = {.lex_state = 120},
  [14] = {.lex_state = 119},
  [15] = {.lex_state = 125},
  [16] = {.lex_state = 121},
  [17] = {.lex_state = 122},
  [18] = {.lex_state = 122},
  [19] = {.lex_state = 122},
  [20] = {.lex_state = 122},
  [21] = {.lex_state = 122},
  [22] = {.lex_state = 122},
  [23] = {.lex_state = 122},
  [24] = {.lex_state = 122},
  [25] = {.lex_state = 122},
  [26] = {.lex_state = 122},
  [27] = {.lex_state = 122},
  [28] = {.lex_state = 122},
  [29] = {.lex_state = 122},
  [30] = {.lex_state = 122},
  [31] = {.lex_state = 122},
  [32] = {.lex_state = 122},
  [33] = {.lex_state = 122},
  [34] = {.lex_state = 122},
  [35] = {.lex_state = 122},
  [36] = {.lex_state = 122},
  [37] = {.lex_state = 122},
  [38] = {.lex_state = 122},
  [39] = {.lex_state = 122},
  [40] = {.lex_state = 122},
  [41] = {.lex_state = 122},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 117},
  [46] = {.lex_state = 117},
  [47] = {.lex_state = 117},
  [48] = {.lex_state = 117},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 118},
  [53] = {.lex_state = 118},
  [54] = {.lex_state = 118},
  [55] = {.lex_state = 118},
  [56] = {.lex_state = 117},
  [57] = {.lex_state = 118},
  [58] = {.lex_state = 117},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 117},
  [61] = {.lex_state = 118},
  [62] = {.lex_state = 118},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 118},
  [65] = {.lex_state = 118},
  [66] = {.lex_state = 117},
  [67] = {.lex_state = 117},
  [68] = {.lex_state = 118},
  [69] = {.lex_state = 118},
  [70] = {.lex_state = 118},
  [71] = {.lex_state = 117},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 117},
  [75] = {.lex_state = 8},
  [76] = {.lex_state = 118},
  [77] = {.lex_state = 117},
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
    [anon_sym_with] = ACTIONS(1),
    [anon_sym_parameters] = ACTIONS(1),
    [anon_sym_and] = ACTIONS(1),
    [anon_sym_class] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_elif] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_for] = ACTIONS(1),
    [anon_sym_in] = ACTIONS(1),
    [anon_sym_while] = ACTIONS(1),
    [anon_sym_try] = ACTIONS(1),
    [anon_sym_except] = ACTIONS(1),
    [anon_sym_finally] = ACTIONS(1),
    [anon_sym_close] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_be] = ACTIONS(1),
    [anon_sym_decrease] = ACTIONS(1),
    [anon_sym_multiply] = ACTIONS(1),
    [anon_sym_divide] = ACTIONS(1),
    [anon_sym_by] = ACTIONS(1),
    [anon_sym_enchant] = ACTIONS(1),
    [anon_sym_string] = ACTIONS(1),
    [anon_sym_rejection] = ACTIONS(1),
    [anon_sym_math] = ACTIONS(1),
    [anon_sym_call] = ACTIONS(1),
    [anon_sym_dot] = ACTIONS(1),
  },
  [1] = {
    [sym_program] = STATE(73),
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
    [sym_raw_line] = STATE(3),
    [aux_sym_program_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym__newline] = ACTIONS(5),
    [sym__indent] = ACTIONS(7),
    [anon_sym_comment] = ACTIONS(9),
    [aux_sym_comment_token1] = ACTIONS(11),
    [anon_sym_aside] = ACTIONS(13),
    [anon_sym_as] = ACTIONS(15),
    [anon_sym_literally] = ACTIONS(17),
    [anon_sym_decorator] = ACTIONS(19),
    [anon_sym_open] = ACTIONS(21),
    [anon_sym_close] = ACTIONS(23),
    [anon_sym_let] = ACTIONS(25),
    [anon_sym_increase] = ACTIONS(27),
    [anon_sym_decrease] = ACTIONS(27),
    [anon_sym_multiply] = ACTIONS(27),
    [anon_sym_divide] = ACTIONS(27),
    [anon_sym_enchant] = ACTIONS(29),
    [anon_sym_call] = ACTIONS(31),
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
    [sym_raw_line] = STATE(2),
    [aux_sym_program_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(33),
    [sym__newline] = ACTIONS(35),
    [sym__indent] = ACTIONS(38),
    [anon_sym_comment] = ACTIONS(41),
    [aux_sym_comment_token1] = ACTIONS(44),
    [anon_sym_aside] = ACTIONS(47),
    [anon_sym_as] = ACTIONS(50),
    [anon_sym_literally] = ACTIONS(53),
    [anon_sym_decorator] = ACTIONS(56),
    [anon_sym_open] = ACTIONS(59),
    [anon_sym_close] = ACTIONS(62),
    [anon_sym_let] = ACTIONS(65),
    [anon_sym_increase] = ACTIONS(68),
    [anon_sym_decrease] = ACTIONS(68),
    [anon_sym_multiply] = ACTIONS(68),
    [anon_sym_divide] = ACTIONS(68),
    [anon_sym_enchant] = ACTIONS(71),
    [anon_sym_call] = ACTIONS(74),
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
    [sym_raw_line] = STATE(2),
    [aux_sym_program_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(77),
    [sym__newline] = ACTIONS(79),
    [sym__indent] = ACTIONS(7),
    [anon_sym_comment] = ACTIONS(9),
    [aux_sym_comment_token1] = ACTIONS(11),
    [anon_sym_aside] = ACTIONS(13),
    [anon_sym_as] = ACTIONS(15),
    [anon_sym_literally] = ACTIONS(17),
    [anon_sym_decorator] = ACTIONS(19),
    [anon_sym_open] = ACTIONS(21),
    [anon_sym_close] = ACTIONS(23),
    [anon_sym_let] = ACTIONS(25),
    [anon_sym_increase] = ACTIONS(27),
    [anon_sym_decrease] = ACTIONS(27),
    [anon_sym_multiply] = ACTIONS(27),
    [anon_sym_divide] = ACTIONS(27),
    [anon_sym_enchant] = ACTIONS(29),
    [anon_sym_call] = ACTIONS(31),
  },
  [4] = {
    [sym_comment] = STATE(21),
    [sym_aside_comment] = STATE(21),
    [sym_as_an_aside_comment] = STATE(21),
    [sym_literally] = STATE(21),
    [sym_decorator] = STATE(21),
    [sym_function_def] = STATE(21),
    [sym_class_def] = STATE(21),
    [sym_if_open] = STATE(21),
    [sym_elif_open] = STATE(21),
    [sym_else_open] = STATE(21),
    [sym_for_open] = STATE(21),
    [sym_while_open] = STATE(21),
    [sym_with_open] = STATE(21),
    [sym_try_open] = STATE(21),
    [sym_except_open] = STATE(21),
    [sym_finally_open] = STATE(21),
    [sym_block_close] = STATE(21),
    [sym_let_assignment] = STATE(21),
    [sym_augmented_assign_sentence] = STATE(21),
    [sym_enchantment] = STATE(21),
    [sym_call_statement] = STATE(21),
    [sym_raw_line] = STATE(21),
    [anon_sym_comment] = ACTIONS(9),
    [aux_sym_comment_token1] = ACTIONS(11),
    [anon_sym_aside] = ACTIONS(13),
    [anon_sym_as] = ACTIONS(15),
    [anon_sym_literally] = ACTIONS(17),
    [anon_sym_decorator] = ACTIONS(19),
    [anon_sym_open] = ACTIONS(21),
    [anon_sym_close] = ACTIONS(23),
    [anon_sym_let] = ACTIONS(25),
    [anon_sym_increase] = ACTIONS(27),
    [anon_sym_decrease] = ACTIONS(27),
    [anon_sym_multiply] = ACTIONS(27),
    [anon_sym_divide] = ACTIONS(27),
    [anon_sym_enchant] = ACTIONS(29),
    [anon_sym_call] = ACTIONS(31),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(81), 1,
      ts_builtin_sym_end,
    ACTIONS(85), 1,
      anon_sym_dot,
    STATE(10), 1,
      aux_sym_dotted_name_repeat1,
    ACTIONS(83), 18,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_with,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [30] = 5,
    ACTIONS(87), 1,
      ts_builtin_sym_end,
    ACTIONS(91), 1,
      anon_sym_and,
    ACTIONS(94), 1,
      sym_identifier,
    STATE(6), 1,
      aux_sym_param_list_repeat1,
    ACTIONS(89), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [62] = 5,
    ACTIONS(97), 1,
      ts_builtin_sym_end,
    ACTIONS(101), 1,
      anon_sym_and,
    ACTIONS(103), 1,
      sym_identifier,
    STATE(6), 1,
      aux_sym_param_list_repeat1,
    ACTIONS(99), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [94] = 5,
    ACTIONS(101), 1,
      anon_sym_and,
    ACTIONS(105), 1,
      ts_builtin_sym_end,
    ACTIONS(109), 1,
      sym_identifier,
    STATE(7), 1,
      aux_sym_param_list_repeat1,
    ACTIONS(107), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [126] = 4,
    ACTIONS(111), 1,
      ts_builtin_sym_end,
    ACTIONS(115), 1,
      anon_sym_dot,
    STATE(9), 1,
      aux_sym_dotted_name_repeat1,
    ACTIONS(113), 18,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_with,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [156] = 4,
    ACTIONS(85), 1,
      anon_sym_dot,
    ACTIONS(118), 1,
      ts_builtin_sym_end,
    STATE(9), 1,
      aux_sym_dotted_name_repeat1,
    ACTIONS(120), 18,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_with,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [186] = 2,
    ACTIONS(87), 1,
      ts_builtin_sym_end,
    ACTIONS(89), 19,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_and,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
      sym_identifier,
  [211] = 2,
    ACTIONS(111), 1,
      ts_builtin_sym_end,
    ACTIONS(113), 19,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_with,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
      anon_sym_dot,
  [236] = 4,
    ACTIONS(122), 1,
      ts_builtin_sym_end,
    ACTIONS(126), 1,
      anon_sym_with,
    ACTIONS(128), 1,
      anon_sym_parameters,
    ACTIONS(124), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [265] = 3,
    ACTIONS(130), 1,
      ts_builtin_sym_end,
    ACTIONS(134), 1,
      anon_sym_inherits,
    ACTIONS(132), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [291] = 3,
    ACTIONS(136), 1,
      ts_builtin_sym_end,
    ACTIONS(140), 1,
      sym_identifier,
    ACTIONS(138), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [317] = 3,
    ACTIONS(142), 1,
      ts_builtin_sym_end,
    ACTIONS(146), 1,
      anon_sym_with,
    ACTIONS(144), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [343] = 2,
    ACTIONS(148), 1,
      ts_builtin_sym_end,
    ACTIONS(150), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [366] = 2,
    ACTIONS(152), 1,
      ts_builtin_sym_end,
    ACTIONS(154), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [389] = 2,
    ACTIONS(156), 1,
      ts_builtin_sym_end,
    ACTIONS(158), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [412] = 2,
    ACTIONS(160), 1,
      ts_builtin_sym_end,
    ACTIONS(162), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [435] = 2,
    ACTIONS(164), 1,
      ts_builtin_sym_end,
    ACTIONS(166), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [458] = 2,
    ACTIONS(168), 1,
      ts_builtin_sym_end,
    ACTIONS(170), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [481] = 2,
    ACTIONS(172), 1,
      ts_builtin_sym_end,
    ACTIONS(174), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [504] = 2,
    ACTIONS(176), 1,
      ts_builtin_sym_end,
    ACTIONS(178), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [527] = 2,
    ACTIONS(180), 1,
      ts_builtin_sym_end,
    ACTIONS(182), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [550] = 2,
    ACTIONS(184), 1,
      ts_builtin_sym_end,
    ACTIONS(186), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [573] = 2,
    ACTIONS(188), 1,
      ts_builtin_sym_end,
    ACTIONS(190), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [596] = 2,
    ACTIONS(192), 1,
      ts_builtin_sym_end,
    ACTIONS(194), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [619] = 2,
    ACTIONS(196), 1,
      ts_builtin_sym_end,
    ACTIONS(198), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [642] = 2,
    ACTIONS(200), 1,
      ts_builtin_sym_end,
    ACTIONS(202), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [665] = 2,
    ACTIONS(204), 1,
      ts_builtin_sym_end,
    ACTIONS(206), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [688] = 2,
    ACTIONS(208), 1,
      ts_builtin_sym_end,
    ACTIONS(210), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [711] = 2,
    ACTIONS(212), 1,
      ts_builtin_sym_end,
    ACTIONS(214), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [734] = 2,
    ACTIONS(216), 1,
      ts_builtin_sym_end,
    ACTIONS(218), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [757] = 3,
    ACTIONS(220), 1,
      ts_builtin_sym_end,
    ACTIONS(224), 1,
      aux_sym_comment_token1,
    ACTIONS(222), 16,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [782] = 2,
    ACTIONS(227), 1,
      ts_builtin_sym_end,
    ACTIONS(229), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [805] = 2,
    ACTIONS(231), 1,
      ts_builtin_sym_end,
    ACTIONS(233), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [828] = 2,
    ACTIONS(235), 1,
      ts_builtin_sym_end,
    ACTIONS(237), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [851] = 2,
    ACTIONS(239), 1,
      ts_builtin_sym_end,
    ACTIONS(241), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [874] = 2,
    ACTIONS(243), 1,
      ts_builtin_sym_end,
    ACTIONS(245), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [897] = 2,
    ACTIONS(247), 1,
      ts_builtin_sym_end,
    ACTIONS(249), 17,
      sym__newline,
      sym__indent,
      anon_sym_comment,
      aux_sym_comment_token1,
      anon_sym_aside,
      anon_sym_as,
      anon_sym_literally,
      anon_sym_decorator,
      anon_sym_open,
      anon_sym_close,
      anon_sym_let,
      anon_sym_increase,
      anon_sym_decrease,
      anon_sym_multiply,
      anon_sym_divide,
      anon_sym_enchant,
      anon_sym_call,
  [920] = 11,
    ACTIONS(251), 1,
      anon_sym_function,
    ACTIONS(253), 1,
      anon_sym_with,
    ACTIONS(255), 1,
      anon_sym_class,
    ACTIONS(257), 1,
      anon_sym_if,
    ACTIONS(259), 1,
      anon_sym_elif,
    ACTIONS(261), 1,
      anon_sym_else,
    ACTIONS(263), 1,
      anon_sym_for,
    ACTIONS(265), 1,
      anon_sym_while,
    ACTIONS(267), 1,
      anon_sym_try,
    ACTIONS(269), 1,
      anon_sym_except,
    ACTIONS(271), 1,
      anon_sym_finally,
  [954] = 1,
    ACTIONS(273), 7,
      anon_sym_function,
      anon_sym_with,
      anon_sym_class,
      anon_sym_if,
      anon_sym_for,
      anon_sym_while,
      anon_sym_try,
  [964] = 1,
    ACTIONS(275), 3,
      anon_sym_string,
      anon_sym_rejection,
      anon_sym_math,
  [970] = 2,
    ACTIONS(277), 1,
      sym_identifier,
    STATE(27), 1,
      sym_param_list,
  [977] = 2,
    ACTIONS(279), 1,
      sym_identifier,
    STATE(16), 1,
      sym_dotted_name,
  [984] = 2,
    ACTIONS(277), 1,
      sym_identifier,
    STATE(20), 1,
      sym_param_list,
  [991] = 1,
    ACTIONS(281), 1,
      sym_identifier,
  [995] = 1,
    ACTIONS(283), 1,
      anon_sym_with,
  [999] = 1,
    ACTIONS(285), 1,
      anon_sym_by,
  [1003] = 1,
    ACTIONS(287), 1,
      anon_sym_be,
  [1007] = 1,
    ACTIONS(289), 1,
      aux_sym_comment_token1,
  [1011] = 1,
    ACTIONS(291), 1,
      aux_sym_comment_token1,
  [1015] = 1,
    ACTIONS(293), 1,
      aux_sym_comment_token1,
  [1019] = 1,
    ACTIONS(295), 1,
      aux_sym_comment_token1,
  [1023] = 1,
    ACTIONS(297), 1,
      sym_identifier,
  [1027] = 1,
    ACTIONS(299), 1,
      aux_sym_comment_token1,
  [1031] = 1,
    ACTIONS(301), 1,
      sym_identifier,
  [1035] = 1,
    ACTIONS(303), 1,
      anon_sym_parameters,
  [1039] = 1,
    ACTIONS(305), 1,
      sym_identifier,
  [1043] = 1,
    ACTIONS(307), 1,
      aux_sym_comment_token1,
  [1047] = 1,
    ACTIONS(309), 1,
      aux_sym_comment_token1,
  [1051] = 1,
    ACTIONS(311), 1,
      anon_sym_in,
  [1055] = 1,
    ACTIONS(313), 1,
      aux_sym_comment_token1,
  [1059] = 1,
    ACTIONS(315), 1,
      aux_sym_comment_token1,
  [1063] = 1,
    ACTIONS(317), 1,
      sym_identifier,
  [1067] = 1,
    ACTIONS(319), 1,
      sym_identifier,
  [1071] = 1,
    ACTIONS(321), 1,
      aux_sym_comment_token1,
  [1075] = 1,
    ACTIONS(323), 1,
      aux_sym_comment_token1,
  [1079] = 1,
    ACTIONS(325), 1,
      aux_sym_comment_token1,
  [1083] = 1,
    ACTIONS(327), 1,
      sym_identifier,
  [1087] = 1,
    ACTIONS(329), 1,
      anon_sym_aside,
  [1091] = 1,
    ACTIONS(331), 1,
      ts_builtin_sym_end,
  [1095] = 1,
    ACTIONS(333), 1,
      sym_identifier,
  [1099] = 1,
    ACTIONS(335), 1,
      anon_sym_an,
  [1103] = 1,
    ACTIONS(337), 1,
      aux_sym_comment_token1,
  [1107] = 1,
    ACTIONS(339), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(5)] = 0,
  [SMALL_STATE(6)] = 30,
  [SMALL_STATE(7)] = 62,
  [SMALL_STATE(8)] = 94,
  [SMALL_STATE(9)] = 126,
  [SMALL_STATE(10)] = 156,
  [SMALL_STATE(11)] = 186,
  [SMALL_STATE(12)] = 211,
  [SMALL_STATE(13)] = 236,
  [SMALL_STATE(14)] = 265,
  [SMALL_STATE(15)] = 291,
  [SMALL_STATE(16)] = 317,
  [SMALL_STATE(17)] = 343,
  [SMALL_STATE(18)] = 366,
  [SMALL_STATE(19)] = 389,
  [SMALL_STATE(20)] = 412,
  [SMALL_STATE(21)] = 435,
  [SMALL_STATE(22)] = 458,
  [SMALL_STATE(23)] = 481,
  [SMALL_STATE(24)] = 504,
  [SMALL_STATE(25)] = 527,
  [SMALL_STATE(26)] = 550,
  [SMALL_STATE(27)] = 573,
  [SMALL_STATE(28)] = 596,
  [SMALL_STATE(29)] = 619,
  [SMALL_STATE(30)] = 642,
  [SMALL_STATE(31)] = 665,
  [SMALL_STATE(32)] = 688,
  [SMALL_STATE(33)] = 711,
  [SMALL_STATE(34)] = 734,
  [SMALL_STATE(35)] = 757,
  [SMALL_STATE(36)] = 782,
  [SMALL_STATE(37)] = 805,
  [SMALL_STATE(38)] = 828,
  [SMALL_STATE(39)] = 851,
  [SMALL_STATE(40)] = 874,
  [SMALL_STATE(41)] = 897,
  [SMALL_STATE(42)] = 920,
  [SMALL_STATE(43)] = 954,
  [SMALL_STATE(44)] = 964,
  [SMALL_STATE(45)] = 970,
  [SMALL_STATE(46)] = 977,
  [SMALL_STATE(47)] = 984,
  [SMALL_STATE(48)] = 991,
  [SMALL_STATE(49)] = 995,
  [SMALL_STATE(50)] = 999,
  [SMALL_STATE(51)] = 1003,
  [SMALL_STATE(52)] = 1007,
  [SMALL_STATE(53)] = 1011,
  [SMALL_STATE(54)] = 1015,
  [SMALL_STATE(55)] = 1019,
  [SMALL_STATE(56)] = 1023,
  [SMALL_STATE(57)] = 1027,
  [SMALL_STATE(58)] = 1031,
  [SMALL_STATE(59)] = 1035,
  [SMALL_STATE(60)] = 1039,
  [SMALL_STATE(61)] = 1043,
  [SMALL_STATE(62)] = 1047,
  [SMALL_STATE(63)] = 1051,
  [SMALL_STATE(64)] = 1055,
  [SMALL_STATE(65)] = 1059,
  [SMALL_STATE(66)] = 1063,
  [SMALL_STATE(67)] = 1067,
  [SMALL_STATE(68)] = 1071,
  [SMALL_STATE(69)] = 1075,
  [SMALL_STATE(70)] = 1079,
  [SMALL_STATE(71)] = 1083,
  [SMALL_STATE(72)] = 1087,
  [SMALL_STATE(73)] = 1091,
  [SMALL_STATE(74)] = 1095,
  [SMALL_STATE(75)] = 1099,
  [SMALL_STATE(76)] = 1103,
  [SMALL_STATE(77)] = 1107,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(76),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(77),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(68),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(76),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(69),
  [56] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(66),
  [59] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(42),
  [62] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(43),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(77),
  [68] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(60),
  [71] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(49),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(46),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dotted_name, 1, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dotted_name, 1, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_param_list_repeat1, 2, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_param_list_repeat1, 2, 0, 0),
  [91] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_param_list_repeat1, 2, 0, 0), SHIFT_REPEAT(74),
  [94] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_param_list_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param_list, 2, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_param_list, 2, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param_list, 1, 0, 0),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_param_list, 1, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dotted_name_repeat1, 2, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dotted_name_repeat1, 2, 0, 0),
  [115] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dotted_name_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dotted_name, 2, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dotted_name, 2, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_def, 3, 0, 6),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_def, 3, 0, 6),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [128] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_def, 3, 0, 6),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_class_def, 3, 0, 6),
  [134] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_close, 2, 0, 4),
  [138] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_close, 2, 0, 4),
  [140] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call_statement, 2, 0, 5),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call_statement, 2, 0, 5),
  [146] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aside_comment, 2, 0, 1),
  [150] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_aside_comment, 2, 0, 1),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_augmented_assign_sentence, 4, 0, 13),
  [154] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_augmented_assign_sentence, 4, 0, 13),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_raw_line, 1, 0, 0),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_raw_line, 1, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_def, 6, 0, 19),
  [162] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_def, 6, 0, 19),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 2, 0, 0),
  [166] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statement, 2, 0, 0),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 2, 0, 1),
  [170] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 2, 0, 1),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_open, 5, 0, 18),
  [174] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_for_open, 5, 0, 18),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literally, 2, 0, 2),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literally, 2, 0, 2),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decorator, 2, 0, 3),
  [182] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decorator, 2, 0, 3),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_def, 5, 0, 17),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_class_def, 5, 0, 17),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_def, 5, 0, 16),
  [190] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_def, 5, 0, 16),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call_statement, 4, 0, 15),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call_statement, 4, 0, 15),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enchantment, 4, 0, 14),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enchantment, 4, 0, 14),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_assignment, 4, 0, 12),
  [202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_assignment, 4, 0, 12),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_open, 2, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_open, 2, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_as_an_aside_comment, 4, 0, 11),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_as_an_aside_comment, 4, 0, 11),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_close, 3, 0, 10),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_close, 3, 0, 10),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_try_open, 2, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_try_open, 2, 0, 0),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_except_open, 2, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_except_open, 2, 0, 0),
  [224] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_except_open, 2, 0, 0), SHIFT(37),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_finally_open, 2, 0, 0),
  [229] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_finally_open, 2, 0, 0),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_except_open, 3, 0, 9),
  [233] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_except_open, 3, 0, 9),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_open, 3, 0, 8),
  [237] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_open, 3, 0, 8),
  [239] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_elif_open, 3, 0, 8),
  [241] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elif_open, 3, 0, 8),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_open, 3, 0, 8),
  [245] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_open, 3, 0, 8),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_with_open, 3, 0, 7),
  [249] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_with_open, 3, 0, 7),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [331] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
};

#ifdef __cplusplus
extern "C" {
#endif
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
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
