; Spoken Python syntax highlighting queries

; ── Keywords ──────────────────────────────────────────────
"open" @keyword
"close" @keyword
"function" @keyword
"class" @keyword
"if" @keyword.conditional
"elif" @keyword.conditional
"else" @keyword.conditional
"for" @keyword.repeat
"while" @keyword.repeat
"in" @keyword
"with" @keyword
"try" @keyword.exception
"except" @keyword.exception
"finally" @keyword.exception
"as" @keyword
"inherits" @keyword
"parameters" @keyword
"and" @keyword
"let" @keyword
"be" @keyword
"assign" @keyword.operator
"increase" @keyword
"decrease" @keyword
"multiply" @keyword
"divide" @keyword
"by" @keyword
"call" @keyword
"dot" @punctuation.delimiter
"literally" @keyword.special
"enchant" @keyword.special
"comment" @keyword.comment
"aside" @keyword.comment
"decorator" @keyword

; ── Block close kinds ─────────────────────────────────────
(block_close
  kind: _ @keyword)

; ── Comments ──────────────────────────────────────────────
(comment
  text: _ @comment)
(aside_comment
  text: _ @comment)
(as_an_aside_comment
  text: _ @comment)

; ── Literally (passthrough) ───────────────────────────────
(literally
  code: _ @embedded)

; ── Functions ─────────────────────────────────────────────
(function_def
  name: (identifier) @function.definition)
(param_list
  (identifier) @variable.parameter)

; ── Classes ───────────────────────────────────────────────
(class_def
  name: (identifier) @type.definition)
(class_def
  parent: (identifier) @type)

; ── Decorators ────────────────────────────────────────────
(decorator
  name: (identifier) @attribute)

; ── Assignments ───────────────────────────────────────────
(let_assignment
  var: (identifier) @variable)
(augmented_assign_sentence
  var: (identifier) @variable)

; ── Calls ─────────────────────────────────────────────────
(call_statement
  function: (dotted_name) @function.call)

; ── Enchantments ──────────────────────────────────────────
(enchantment
  type: _ @type)
(enchantment
  body: _ @string)

; ── Identifiers ───────────────────────────────────────────
(identifier) @variable
