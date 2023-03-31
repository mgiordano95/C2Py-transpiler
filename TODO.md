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
    - [x] Add struct AstNodeArrayInit (` to test `)
    - [x] Add struct AstNodeArrayAssign (` to test `)
    - [x] Add struct AstNodeArrayElements (` to test `)
    - [x] Add struct AstNodeFunctionDecl
    - [x] Add struct AstNodeFunctionCall
    - [x] Add struct AstNodeFunctionParams
    - [x] Add struct AstNodeBody
    - [x] Add struct AstNodeIf
    - [x] Add struct AstNodeElseIf
    - [x] Add struct AstNodeElse
    - [x] Add struct AstNodeWhile
- [ ] Create Parser (parser.y)
    - [x] Implement statements
    - [x] Implement instruction (` to test `)
    - [x] Implement initialization (` to test `)
    - [x] Implement assignment (` to test `)
    - [x] Implement expression (` to test `)
    - [x] Implement content
    - [x] Implement arrayInit (` to test `)
    - [x] Implement arrayAssign (` to test `)
    - [x] Implement arrayElements (` to test `)
    - [x] Implement functionDecl (` to test `)
    - [x] Implement functionCall (` to test `)
    - [x] Implement functionParams (` to test `)
    - [x] Implement body (` to test `)
    - [x] Implement if (` to test `)
    - [x] Implement elseif (` to test `)
    - [x] Implement else (` to test `)
    - [x] Implement while (` to test `)
- [ ] Create Transpiler (c2py.h)

### Done ✓
- [x] Understand lexer
- [x] Understand parser
- [x] Study [uthash](https://troydhanson.github.io/uthash/) library 
- [x] Import utash header file
- [x] Understand symtab
- [x] Create Symbol Table (symtab.h)