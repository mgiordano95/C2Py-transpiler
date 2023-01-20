# C2Py Transpiler TODO.md

- [x] Understand lexer
- [x] Understand parser
- [x] Understand symtab
- [ ] Study [uthash](https://troydhanson.github.io/uthash/) library 

## Task

- [x] Import utash header file
- [ ] Create Abstract Syntax Tree (ast.h)
    - [x] Add struct AST_NODE_INIT
    - [x] Add struct AST_NODE_ASSIGN
    - [x] Add struct AST_NODE_EXPRESSION
    - [x] Add struct AST_NODE_OPERAND
    - [x] Add struct AST_NODE_FUNCTION_DECL
    - [x] Add struct AST_NODE_FUNCTION_CALL
    - [x] Add struct AST_NODE_FUNCTION_PARAMS
    - [x] Add struct AST_NODE_BODY
    - [ ] Add struct AST_NODE_ARRAY_INIT
    - [ ] Add struct AST_NODE_ARRAY_ASSIGN
    - [ ] Add struct AST_NODE_IF
    - [ ] Add struct AST_NODE_ELSE
    - [ ] Add struct AST_NODE_ELSE_IF
    - [ ] Add struct AST_NODE_WHILE
    - [ ] Add struct AST_NODE_CONDITION
- [ ] Create Symbol Table (symtab.h)
- [ ] Create parser.y