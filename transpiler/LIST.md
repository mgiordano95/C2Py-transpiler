# lexer.l

## To Do:

- Improve token detection of multi-line comments, single-line comments and strings
- Add token to detect the # symbol (library)

# Array

## To Do:

- Line 336 (types ID LSBRA RSBRA) `int myArray[];`
    - Delete production or Implement "Error: array size missing in ‘myArray’"
- Line 349 (types ID LSBRA INT_VALUE RSBRA) `int myArray[4];`
    - Implement Symbol Table
- Line 362 (types ID LSBRA RSBRA EQ LBRA RBRA) `int myArray[] = {};`
    - Learn more about this syntax
    - Implement Symbol Table
    - Check that the array has not already been initialized
- Line 372 (types ID LSBRA INT_VALUE RSBRA EQ content) `int myArray[2] = 24;`
    - Delete production or Implement "Error: invalid initializer"
- Line 382 (types ID LSBRA RSBRA EQ LBRA arrayElements RBRA) `int myArray[] = {24, 27, 29};`
    - Implement Symbol Table
    - Check that the array has not already been initialized
    - Compute arrayLength as # of elements
- Line 391 (types ID LSBRA INT_VALUE RSBRA EQ LBRA arrayElements RBRA) `int myArray[3] = {24, 27, 29};`
    - Implement Symbol Table
    - Check that the array has not already been initialized
    - Check that the # of elements is not greater than arrayLength
- Line 400 (ID LSBRA RSBRA EQ LBRA RBRA) `myArray[] = {};`
    - Delete production or Implement "Syntax Error" 
- Line 409 (ID LSBRA INT_VALUE RSBRA EQ content) `myArray[2] = 24;`:
    - Implement symbol table
    - Check that the array has been initialized
- Line 418 (ID LSBRA RSBRA EQ LBRA arrayElements RBRA) `myArray[] = {24, 27, 29};` 
    - Delete production or Implement "Syntax Error"
- Line 427 (ID LSBRA INT_VALUE RSBRA EQ LBRA arrayElements RBRA) `myArray[3] = {24, 27, 29};` 
    - Delete production or Implement "Syntax Error"