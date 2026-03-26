// Tree-sitter grammar for Spoken Python v0.2
// Line-based grammar: parses structure (blocks, assignments, comments)
// and captures expression content as raw text.
// This gives us syntax checking for structural correctness without
// needing to fully parse every expression.

module.exports = grammar({
  name: 'spoken_python',

  extras: $ => [/[ \t]/],

  conflicts: $ => [
    [$.except_open],
  ],

  rules: {
    program: $ => repeat(choice($._statement, $._newline)),

    _newline: _ => /\r?\n/,

    _statement: $ => seq(optional($._indent), choice(
      $.comment,
      $.aside_comment,
      $.as_an_aside_comment,
      $.literally,
      $.decorator,
      $.function_def,
      $.class_def,
      $.if_open,
      $.elif_open,
      $.else_open,
      $.for_open,
      $.while_open,
      $.with_open,
      $.try_open,
      $.except_open,
      $.finally_open,
      $.block_close,
      $.let_assignment,
      $.augmented_assign_sentence,
      $.enchantment,
      $.call_statement,
      $.expression_line,
    )),

    _indent: _ => /[ \t]+/,

    // Catch-all for lines that are valid expressions/passthrough
    // Must only match content NOT starting with a known keyword
    expression_line: _ => prec(-10, /[^\n]+/),

    // ── Comments ─────────────────────────────────────────

    comment: _ => seq('comment', field('text', /[^\n]+/)),
    aside_comment: _ => seq('aside', field('text', /[^\n]+/)),
    as_an_aside_comment: _ => seq('as', 'an', 'aside', field('text', /[^\n]+/)),

    // ── Literal passthrough ──────────────────────────────

    literally: _ => seq('literally', field('code', /[^\n]+/)),

    // ── Decorators ───────────────────────────────────────

    decorator: $ => seq('decorator', field('name', $.identifier)),

    // ── Function Definition ──────────────────────────────

    function_def: $ => seq(
      'open', 'function',
      field('name', $.identifier),
      optional(choice(
        seq('with', 'parameters', field('params', $.param_list)),
        seq('parameters', field('params', $.param_list)),
      )),
    ),

    param_list: $ => seq(
      $.identifier,
      repeat(seq(optional('and'), $.identifier)),
    ),

    // ── Class Definition ─────────────────────────────────

    class_def: $ => seq(
      'open', 'class',
      field('name', $.identifier),
      optional(seq('inherits', field('parent', $.identifier))),
    ),

    // ── Conditionals ─────────────────────────────────────

    if_open: _ => seq('open', 'if', field('condition', /[^\n]+/)),
    elif_open: _ => seq('open', 'elif', field('condition', /[^\n]+/)),
    else_open: _ => seq('open', 'else'),

    // ── Loops ────────────────────────────────────────────

    for_open: $ => seq(
      'open', 'for',
      field('var', $.identifier),
      'in',
      field('iterable', /[^\n]+/),
    ),
    while_open: _ => seq('open', 'while', field('condition', /[^\n]+/)),

    // ── Context Manager ──────────────────────────────────

    with_open: _ => seq('open', 'with', field('expr', /[^\n]+/)),

    // ── Exception Handling ───────────────────────────────

    try_open: _ => seq('open', 'try'),
    except_open: _ => seq('open', 'except', optional(field('type', /[^\n]+/))),
    finally_open: _ => seq('open', 'finally'),

    // ── Block Close ──────────────────────────────────────

    block_close: $ => seq(
      'close',
      field('kind', choice('function', 'class', 'if', 'for', 'while', 'with', 'try')),
      optional(field('name', $.identifier)),
    ),

    // ── Assignment ───────────────────────────────────────

    let_assignment: $ => seq(
      'let',
      field('var', $.identifier),
      'be',
      field('value', /[^\n]+/),
    ),

    // ── Augmented Assignment ─────────────────────────────

    augmented_assign_sentence: $ => seq(
      field('op', choice('increase', 'decrease', 'multiply', 'divide')),
      field('var', $.identifier),
      'by',
      field('value', /[^\n]+/),
    ),

    // ── Enchantments ─────────────────────────────────────

    enchantment: $ => seq(
      'enchant', 'with',
      field('type', choice('string', 'rejection', 'math')),
      field('body', /[^\n]+/),
    ),

    // ── Function Call ────────────────────────────────────

    call_statement: $ => seq(
      'call',
      field('function', $.dotted_name),
      optional(seq('with', field('args', /[^\n]+/))),
    ),

    dotted_name: $ => seq(
      $.identifier,
      repeat(seq('dot', $.identifier)),
    ),

    // ── Catch-all ────────────────────────────────────────

    raw_line: _ => prec(-10, /[^\n]+/),

    // ── Terminals ────────────────────────────────────────

    identifier: _ => /[a-zA-Z_][a-zA-Z0-9_.]+|[a-zA-Z_]/,
  },
});
