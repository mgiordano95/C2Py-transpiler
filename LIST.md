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

- Line 337 (types ID LSBRA RSBRA) `int myArray[];`
    - Delete production or Implement "Error: array size missing in ‘myArray’"
- Line 350 (types ID LSBRA content RSBRA) `int myArray[4];`
    - Implement Symbol Table
- Line 364 (types ID LSBRA RSBRA EQ LBRA RBRA) `int myArray[] = {};`
    - Learn more about this syntax
    - Implement Symbol Table
    - Check that the array has not already been initialized
- Line 373 (types ID LSBRA content RSBRA EQ arrayElements) `int myArray[2] = 24;`
    - Delete production or Implement "Error: invalid initializer"
- Line 383 (types ID LSBRA RSBRA EQ LBRA arrayElements RBRA) `int myArray[] = {24, 27, 29};`
    - Implement Symbol Table
    - Check that the array has not already been initialized
    - Compute arrayLength as # of elements
- Line 392 (types ID LSBRA INT_VALUE RSBRA EQ LBRA arrayElements RBRA) `int myArray[3] = {24, 27, 29};`
    - Implement Symbol Table
    - Check that the array has not already been initialized
    - Check that the # of elements is not greater than arrayLength
- Line 401 (ID LSBRA RSBRA EQ LBRA RBRA) `myArray[] = {};`
    - Delete production or Implement "Syntax Error" 
- Line 410 (ID LSBRA content RSBRA EQ arrayElements) `myArray[2] = 24;`:
    - Implement symbol table
    - Check that the array has been initialized
- Line 419 (ID LSBRA RSBRA EQ LBRA arrayElements RBRA) `myArray[] = {24, 27, 29};` 
    - Delete production or Implement "Syntax Error"
- Line 428 (ID LSBRA content RSBRA EQ LBRA arrayElements RBRA) `myArray[3] = {24, 27, 29};` 
    - Delete production or Implement "Syntax Error"