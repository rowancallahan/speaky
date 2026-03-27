; Spoken Python syntax highlighting for Zed
; Only highlight node types and keywords that exist as terminals

; Node-level
(comment) @comment
(aside_comment) @comment
(as_an_aside_comment) @comment
(literally) @embedded
(function_def) @function
(class_def) @type
(enchantment) @string
(call_statement) @function
(let_assignment) @variable
(block_close) @keyword

; Keywords that are actual terminals in the grammar
"function" @keyword
"class" @keyword
"if" @keyword
"else" @keyword
"elif" @keyword
"for" @keyword
"while" @keyword
"close" @keyword
"open" @keyword
"let" @keyword
"call" @keyword
"with" @keyword
"literally" @keyword
"enchant" @keyword
"decorator" @keyword
"increase" @keyword
"decrease" @keyword
"multiply" @keyword
"divide" @keyword
"by" @keyword
"try" @keyword
"except" @keyword
"finally" @keyword
"equal" @keyword
"be" @keyword

; Enchantment types
"string" @type
"math" @type
"rejection" @type
