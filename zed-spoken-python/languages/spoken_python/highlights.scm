; Spoken Python highlight queries for Zed

; Keywords
"open" @keyword
"close" @keyword
"comment" @comment
"aside" @comment
"as" @comment
"an" @comment
"literally" @keyword.special
"decorator" @keyword
"let" @keyword
"be" @keyword
"increase" @keyword
"decrease" @keyword
"multiply" @keyword
"divide" @keyword
"by" @keyword
"call" @keyword
"enchant" @keyword.special
"with" @keyword
"if" @keyword.conditional
"elif" @keyword.conditional
"else" @keyword.conditional
"for" @keyword.repeat
"while" @keyword.repeat
"in" @keyword
"try" @keyword.exception
"except" @keyword.exception
"finally" @keyword.exception
"function" @keyword
"class" @keyword
"parameters" @keyword
"inherits" @keyword

; Enchantment types
"string" @type
"math" @type
"rejection" @type

; Block kinds in close
"function" @keyword
"class" @keyword

; Node-level highlights
(comment) @comment
(aside_comment) @comment
(as_an_aside_comment) @comment
(literally) @embedded
(enchantment) @string
(function_def) @function
(class_def) @type.definition
(let_assignment) @variable
(block_close) @keyword
(expression_line) @variable
