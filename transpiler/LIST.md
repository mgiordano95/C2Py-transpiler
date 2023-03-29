# lexer.l

## To Do:

- Migliorare il riconoscimento dei commenti multi-line, commenti single-line e delle stringhe.

# Array

## To Do:

- Inserire symbol table
- Eliminare la produzione 'types ID LSBRA RSBRA' di arrayInit poichè è un errore sintattico dato che non è possibile inizializzare un array senza dimensione:
    - Syntax Error: int myArray[];
    - Correct Syntax: int myArray[3];
    - Correct Syntax: int myArray[] = {};
- Line 363: Studiare il caso int myArray[] = {}; (types ID LSBRA RSBRA EQ LBRA RBRA)
- Eliminare la produzione 'types ID LSBRA INT_VALUE RSBRA EQ content' di arrayAssign poichè è un errore dato che non è possibile inizializzare un array come int myArray[2] = 24;
- Line 382: Nella produzione "types ID LSBRA RSBRA EQ LBRA arrayElements RBRA " di arrayAssign calcolare l'arrayLength in base al numero di elementi
- Line 427: Eliminare la produzione 'ID LSBRA INT_VALUE RSBRA EQ LBRA arrayElements RBRA' 
