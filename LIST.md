# lexer.l

## To Do:

- Improve token detection of multi-line comments, single-line comments and strings
- Add token to detect the # symbol (library)

# parser.y

## To Do:

- Line 135 Check:
    - Old: `s = createSym(init->assign->variableName, actualList, SYMBOL_VARIABLE, str_to_type($1), str_to_type($1), NULL, nullValue);` or 
    - `s = createSym(init->assign->variableName, actualList, SYMBOL_VARIABLE, str_to_type($1->dataType), str_to_type($1->dataType), NULL, nullValue);` or 
    - `s = createSym(init->assign->variableName, actualList, SYMBOL_VARIABLE, $1->dataType, $1->dataType, NULL, nullValue);`
- Line 198 Check:
    - Old: `$$->returnType = str_to_type($1);` or
    - `$$->returnType = $1;`


# Array

## To Do:
- Line 183 (arrayInit SEMICOL)
    - [ ] Implement findSym e createSym ("Error: array already declared.\n")
- Line 189 (arrayAssign SEMICOL)
    - [ ] Implement findSym ("Error: array not declared.")
    - [ ] 

- Line 407 (types ID LSBRA RSBRA) `int myArray[];`
    - [x] Implement "Error: array size missing in ‘myArray’"
- Line 410 (types ID LSBRA INT_VALUE RSBRA) `int myArray[4];`
    - 
- Line 424 (types ID LSBRA RSBRA EQ LBRA RBRA) `int myArray[] = {};`
    - [x] Learn more about this syntax
    - [ ] Check if the arrayType is int or float, else print "Error"
- Line 433 (types ID LSBRA INT_VALUE RSBRA EQ arrayElements) `int myArray[2] = 24;`
    - [x] Implement "Error: invalid initializer"
- Line 436 (types ID LSBRA RSBRA EQ LBRA arrayElements RBRA) `int myArray[] = {24, 27, 29};`
    - 
- Line 445 (types ID LSBRA INT_VALUE RSBRA EQ LBRA arrayElements RBRA) `int myArray[3] = {24, 27, 29};`
    - 
- Line 454 (ID LSBRA RSBRA EQ LBRA RBRA) `myArray[] = {};`
    - [x] Implement "Syntax Error" 
- Line 457 (ID LSBRA INT_VALUE RSBRA EQ arrayElements) `myArray[2] = 24;`:
    - 
- Line 466 (ID LSBRA RSBRA EQ LBRA arrayElements RBRA) `myArray[] = {24, 27, 29};` 
    - 
- Line 428 (ID LSBRA INT_VALUE RSBRA EQ LBRA arrayElements RBRA) `myArray[3] = {24, 27, 29};` 
    - 