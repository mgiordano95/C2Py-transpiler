# C2Py Transpiler TODO.md

## Task

### Todo

- [ ] Create translate.h

### In Progress

- [ ] Create Abstract Syntax Tree (ast.h)
    - [x] Add struct AstNodeStatements
    - [x] Add struct AstNodeInstruction
    - [x] Add struct AstNodeInit
    - [x] Add struct AstNodeAssign
    - [x] Add struct AstNodeExpression
    - [x] Add struct AstNodeOperand
    - [x] Add struct AstNodeArrayInit (<span style="color:red">to test</span>)
    - [x] Add struct AstNodeArrayAssign (<span style="color:red">to test</span>)
    - [x] Add struct AstNodeArrayElements (<span style="color:red">to test</span>)
    - [x] Add struct AstNodeFunctionDecl
    - [x] Add struct AstNodeFunctionCall
    - [x] Add struct AstNodeFunctionParams
    - [x] Add struct AstNodeBody
    - [x] Add struct AstNodeIf
    - [x] Add struct AstNodeElseIf
    - [x] Add struct AstNodeElse
    - [x] Add struct AstNodeWhile
- [ ] Create parser.y
    - [x] Implement statements
    - [x] Implement instruction (<span style="color:red">to test</span>)
    - [x] Implement initialization (<span style="color:red">to test</span>)
    - [x] Implement assignment (<span style="color:red">to test</span>)
    - [x] Implement expression (<span style="color:red">to test</span>)
    - [x] Implement content
    - [x] Implement arrayInit (<span style="color:red">to test</span>)
    - [x] Implement arrayAssign (<span style="color:red">to test</span>)
    - [x] Implement arrayElements (<span style="color:red">to test</span>)
    - [x] Implement functionDecl (<span style="color:red">to test</span>)
    - [x] Implement functionCall (<span style="color:red">to test</span>)
    - [x] Implement functionParams (<span style="color:red">to test</span>)
    - [x] Implement body (<span style="color:red">to test</span>)
    - [x] Implement if (<span style="color:red">to test</span>)
    - [x] Implement elseif (<span style="color:red">to test</span>)
    - [x] Implement else (<span style="color:red">to test</span>)
    - [ ] Implement while


### Done ✓
- [x] Understand lexer
- [x] Understand parser
- [x] Study [uthash](https://troydhanson.github.io/uthash/) library 
- [x] Import utash header file
- [x] Understand symtab
- [x] Create Symbol Table (symtab.h)