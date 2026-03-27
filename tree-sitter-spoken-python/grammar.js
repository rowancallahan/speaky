// Tree-sitter grammar for Spoken Python v0.3
// Uses external scanner to prevent catch-all from eating keyword lines.

module.exports = grammar({
  name: 'spoken_python',

  extras: $ => [/[ \t]/],

  externals: $ => [
    $.expression_line,
  ],

  conflicts: $ => [
    [$.block_close],
    [$.except_open],
  ],

  rules: {
    program: $ => repeat(choice($._statement, $._newline)),

    _newline: _ => /\r?\n/,

    _statement: $ => choice(
      $.comment,
      $.aside_comment,
      $.as_an_aside_comment,
      $.literally,
      $.decorator,
      $.function_def,
      $.class_def,
      $.if_open,
      $.elif_open,
      $.else_if_open,
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
    ),

    comment: _ => seq('comment', /[^\n]+/),
    aside_comment: _ => seq('aside', /[^\n]+/),
    as_an_aside_comment: _ => seq('as', 'an', 'aside', /[^\n]+/),
    literally: _ => seq('literally', /[^\n]+/),
    decorator: _ => seq('decorator', /[^\n]+/),
    function_def: _ => seq(optional('open'), 'function', /[^\n]+/),
    class_def: _ => seq(optional('open'), 'class', /[^\n]+/),
    if_open: _ => seq(optional('open'), 'if', /[^\n]+/),
    elif_open: _ => seq(optional('open'), 'elif', /[^\n]+/),
    else_if_open: _ => prec(2, seq('else', 'if', /[^\n]+/)),
    else_open: _ => prec(1, seq(optional('open'), 'else')),
    for_open: _ => seq(optional('open'), 'for', /[^\n]+/),
    while_open: _ => seq(optional('open'), 'while', /[^\n]+/),
    with_open: _ => seq('open', 'with', /[^\n]+/),
    try_open: _ => seq('open', 'try'),
    except_open: _ => prec(3, seq('open', 'except', optional(/[^\n]+/))),
    finally_open: _ => seq('open', 'finally'),
    block_close: _ => prec(5, seq('close', optional(/[^\n]+/))),
    let_assignment: _ => seq('let', /[a-zA-Z_]\w*/, choice('equal', 'be'), /[^\n]+/),
    augmented_assign_sentence: _ => seq(
      choice('increase', 'decrease', 'multiply', 'divide'),
      /[a-zA-Z_]\w*/,
      'by',
      /[^\n]+/,
    ),
    enchantment: _ => seq(
      'enchant', 'with',
      choice('string', 'rejection', 'math'),
      /[^\n]+/,
    ),
    call_statement: _ => seq('call', /[^\n]+/),
  },
});
