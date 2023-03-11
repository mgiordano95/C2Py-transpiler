# C2Py Transpiler TODO.md

## Task

### Todo

- [ ] Create translate.h

### In Progress

- [ ] :computer: Create Abstract Syntax Tree (ast.h)
    - [x] Add struct AstNodeStatements
    - [x] Add struct AstNodeInstruction
    - [x] Add struct AstNodeInit
    - [x] Add struct AstNodeAssign
    - [x] Add struct AstNodeExpression
    - [x] Add struct AstNodeOperand
    - [ ] :computer: Add struct AstNodeArrayInit (to test)
    - [ ] :computer: Add struct AstNodeArrayAssign (to test)
    - [ ] :computer: Add struct AstNodeArrayElements (to test)
    - [x] Add struct AstNodeFunctionDecl
    - [x] Add struct AstNodeFunctionCall
    - [x] Add struct AstNodeFunctionParams
    - [x] Add struct AstNodeBody
    - [x] Add struct AstNodeIf
    - [x] Add struct AstNodeElseIf
    - [x] Add struct AstNodeElse
    - [x] Add struct AstNodeWhile
- [ ] :computer: Create parser.y
    - [x] Implement statements
    - [ ] :computer: Implement instruction
    - [ ] :computer: Implement initialization
    - [ ] :computer: Implement assignment
    - [ ] :computer: Implement expression
    - [x] Implement content
    - [ ] Implement arrayInit
    - [ ] Implement arrayAssign
    - [ ] Implement arrayElements
    - [ ] :computer: Implement functionDecl
    - [ ] :computer: Implement functionCall
    - [ ] Implement functionParams
    - [x] Implement body
    - [ ] Implement if
    - [ ] Implement elseif
    - [ ] Implement else
    - [ ] Implement while


### Done ✓
- [x] Understand lexer
- [x] Understand parser
- [x] Study [uthash](https://troydhanson.github.io/uthash/) library 
- [x] Import utash header file
- [x] Understand symtab
- [x] Create Symbol Table (symtab.h)