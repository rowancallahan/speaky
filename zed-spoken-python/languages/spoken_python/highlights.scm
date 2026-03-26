; Spoken Python highlight queries for Zed
; Since our tree-sitter grammar has the raw_line issue,
; we use textmate-style regex patterns via Zed's built-in support.
; This file uses simple keyword matching.

; Block keywords
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
"try" @keyword.exception
"except" @keyword.exception
"finally" @keyword.exception
"as" @keyword
"inherits" @keyword
"parameters" @keyword
"with" @keyword

; Assignment keywords
"let" @keyword
"be" @keyword
"assign" @keyword.operator
"increase" @keyword
"decrease" @keyword
"multiply" @keyword
"divide" @keyword
"by" @keyword

; Call/access
"call" @keyword
"dot" @punctuation.delimiter

; Special
"literally" @keyword.special
"enchant" @keyword.special
"comment" @comment
"aside" @comment
"decorator" @keyword

; Identifiers and literals
(identifier) @variable
(comment text: _ @comment)
(literally code: _ @embedded)
(function_def name: (identifier) @function.definition)
(class_def name: (identifier) @type.definition)
(param_list (identifier) @variable.parameter)
(call_statement function: (dotted_name) @function.call)
(enchantment type: _ @type)
(block_close kind: _ @keyword)
