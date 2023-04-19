# C2Py Transpiler TODO.md

## Task

### Todo

- [ ]

### In Progress
- [x] Implement Lexer (lexer.l)
    - [ ] Implement string detection with %d %s %c
    - [ ] Improve token detection of multi-line comments, single-line comments and strings
    - [ ] Add token to detect the # symbol (include library)
- [ ] Create Abstract Syntax Tree (ast.h)
    - [x] Add struct AstNodeStatements
    - [x] Add struct AstNodeInstruction
    - [x] Add struct AstNodeInit
    - [x] Add struct AstNodeAssign
    - [x] Add struct AstNodeExpression
    - [x] Add struct AstNodeOperand
    - [x] Add struct AstNodeArrayDecl
    - [x] Add struct AstNodeArrayCall
    - [x] Add struct AstNodeArrayInit
    - [x] Add struct AstNodeArrayAssign
    - [x] Add struct AstNodeArrayElements
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
    - [x] Implement arrayDecl (` to test `)
    - [x] Implement arrayCall (` to test `)
    - [x] Implement arrayInit (` to test `)
        - [x] Implement findSym e createSym with ("Error: array already declared.\n")
    - [x] Implement arrayAssign (` to test `)
        - [x] Implement findSym with ("Error: array not declared.")
    - [x] Implement arrayElements (` to test `)
    - [x] Implement functionDecl (` to test `)
    - [x] Implement functionCall (` to test `)
    - [x] Implement functionParams (` to test `)
    - [x] Implement body (` to test `)
    - [x] Implement if (` to test `)
    - [x] Implement elseif (` to test `)
    - [x] Implement else (` to test `)
    - [x] Implement while (` to test `)
    - [x] Implement outputFunction (` to test `)
    - [x] Implement inputFunction (` to test `)
    - [x] Implement outputelements (` to test `)
    - [x] Implement inputElements (` to test `)
- [ ] Create Transpiler (c2py.h)
    - [x] translateInitialization(struct AstNodeInit *init); (` to test `)
    - [ ] translateAssignment(struct AstNodeAssign *assign);
    - [ ] translateOperand(struct AstNodeOperand *operand);
    - [ ] translateExpression(struct AstNodeExpression *expression);
    - [ ] translateArrayInitialization(struct AstNodeArrayInit *arrayInit);
    - [ ] translateArrayAssignment(struct AstNodeArrayAssign *arrayAssign);
    - [ ] translateArrayElements(struct AstNodeArrayElements *arrayElements);
    - [ ] translateFunctionDeclaration(struct AstNodeFunctionDecl *functionDecl);
    - [ ] translateFunctionCall(struct AstNodeFunctionCall *functionCall);
    - [ ] translateFunctionParams(struct AstNodeFunctionParams *functionParams);
    - [ ] translateIf(struct AstNodeIf *ifStatement);
    - [ ] translateElseIf(struct AstNodeElseIf *elseifStatement);
    - [ ] translateElse(struct AstNodeElse *elseStatement);
    - [ ] translateWhile(struct AstNodeWhile *whileLoop);
    - [ ] translateBody(struct AstNodeBody *body);
    - [ ] translateFunctionOutput(struct AstNodeFunctionOutput *outputFunction);
    - [ ] translateFunctionInput(struct AstNodeFunctionInput *inputFunction);
    - [ ] translateOutputElements(struct AstNodeOutputElements *outputElements);
    - [ ] translateInputElements(struct AstNodeInputElements *inputElements);

### Done ✓
- [x] Understand lexer
- [x] Understand parser
- [x] Study [uthash](https://troydhanson.github.io/uthash/) library 
- [x] Import utash header file
- [x] Understand symtab
- [x] Create Symbol Table (symboltable.h)