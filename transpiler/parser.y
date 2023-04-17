%{
#include <stdio.h> //printf, scanf, ecc
#include <math.h>
#include <ctype.h>
#include <string.h> //strcmp, strdup
#include <stdbool.h> //true, false
#include "ast.h"
#include "symboltable.h"

int yylex(void);
int yyerror(char *s);

struct AstNodeStatements *root;
struct List *actualList = NULL;
int counter; 

char *typeToString(int);
int stringToType(char*);

void beginScope();
void endScope();

%}


%token VOID
%token INT
%token FLOAT
%token CHAR
%token IF
%token ELSE
%token WHILE
%token PRINTF
%token SCANF
%token RETURN
%token MAIN
%left ADD
%right SUB
%left MUL
%left DIV
%left EQ
%left EE
%left NE
%left GT
%left LT
%left GE
%left LE
%left AND
%left OR
%left NOT
%token LPAR
%token RPAR
%token LSBRA
%token RSBRA
%token LBRA
%token RBRA
%token SEMICOL
%token COMMA
%token INT_VALUE
%token FLOAT_VALUE
%token ID
%token CHAR_VALUE
%token STRING_VALUE
%token UNKNOWN

%define api.value.type {union yystype}

%type <string> types VOID INT FLOAT CHAR IF ELSE WHILE PRINTF SCANF RETURN MAIN ADD SUB MUL DIV EQ EE NE GT LT GE LE AND OR NOT LPAR RPAR LSBRA RSBRA LBRA RBRA SEMICOL COMMA INT_VALUE FLOAT_VALUE ID CHAR_VALUE STRING_VALUE
%type <statements> program statements
%type <instruction> instruction
%type <init> initialization
%type <assign> assignment
%type <operand> content
%type <expression> expression
%type <body> body
%type <functionDecl> functionDecl
%type <functionCall> functionCall
%type <functionParams> functionParams
%type <ifStatement> ifStatement
%type <elseifStatement> elseifStatement
%type <elseStatement> elseStatement
%type <whileLoop>   whileLoop
%type <arrayInit> arrayInit
%type <arrayAssign> arrayAssign
%type <arrayDecl> arrayDecl
%type <arrayCall> arrayCall
%type <arrayElements> arrayElements
%type <outputFunction> outputFunction
%type <inputFunction> inputFunction
%type <outputElements> outputElements
%type <inputElements> inputElements

%start program

%%

program:                                                    {
                                                                beginScope();
                                                            }
statements                                                  {
                                                                root = $2;
                                                                endScope();
                                                            };

statements:
instruction statements                                      {
                                                                $$ = malloc(sizeof(struct AstNodeStatements));
                                                                printf("AstNodeStatements allocated for 'instruction statements'\n");
                                                                $$->nodeType = STATEMENT_NODE;
                                                                $$->currentInstruction = $1;
                                                                $$->nextStatement = $2;
                                                            }
|   instruction                                             {
                                                                $$ = malloc(sizeof(struct AstNodeStatements));
                                                                printf("AstNodeStatements allocated for 'instruction'\n");
                                                                $$->nodeType = STATEMENT_NODE;
                                                                $$->currentInstruction = $1;
                                                                $$->nextStatement = NULL;
                                                            };

instruction:
assignment SEMICOL                                          {
                                                                $$ = malloc(sizeof(struct AstNodeInstruction));
                                                                printf("AstNodeInstruction allocated for 'assignment SEMICOL'\n");
                                                                $$->nodeType = ASSIGN_NODE;
                                                                struct SymTab *s = findSym($1->variableName, actualList);
                                                                if((s->dataType != $1->variableType) || strcmp(typeToString(s->dataType), "none") == 0) {
                                                                    printf("Error\n");
                                                                } else {
                                                                    $$->value.assign = $1;
                                                                    s->valueOper = $1->assignValue;
                                                                }
                                                            }
| initialization SEMICOL                                    {
                                                                $$ = malloc(sizeof(struct AstNodeInstruction));
                                                                struct SymTab *s = NULL;
                                                                for (struct AstNodeInit *init = $1; init != NULL; init = init->nextInit) {
                                                                    s = findSym(init->assign->variableName, actualList);
                                                                    if (s == NULL) {
                                                                        printf("AstNodeInstruction allocated for 'initialization SEMICOL'\n");
                                                                        $$->nodeType = INIT_NODE;
                                                                        $$->value.init = $1;
                                                                        s = createSym(init->assign->variableName, actualList, SYMBOL_VARIABLE, $1->dataType, $1->dataType, NULL, NULL, nullValue);
                                                                    } else {
                                                                        printf("Error: variable already declared.\n");
                                                                    }
                                                                }
                                                            }
|   functionDecl                                            {
                                                                $$ = malloc(sizeof(struct AstNodeInstruction));
                                                                printf("AstNodeInstruction allocated for 'functionDecl SEMICOL'\n");
                                                                $$->nodeType = FUNCTION_DECL_NODE;
                                                                $$->value.functionDecl = $1;
                                                            }
|   functionCall SEMICOL                                    {
                                                                $$ = malloc(sizeof(struct AstNodeInstruction));
                                                                printf("AstNodeInstruction allocated for 'functionCall SEMICOL'\n");
                                                                $$->nodeType = FUNCTION_CALL_NODE;
                                                                $$->value.functionCall = $1;
                                                            }
|   ifStatement                                             {
                                                                $$ = malloc(sizeof(struct AstNodeInstruction));
                                                                printf("AstNodeInstruction allocated for 'ifStatement'\n");
                                                                $$->nodeType = IF_NODE;
                                                                $$->value.ifStatement = $1;
                                                            }
|   elseifStatement                                         {
                                                                $$ = malloc(sizeof(struct AstNodeInstruction));
                                                                printf("AstNodeInstruction allocated for 'elseifStatement'\n");
                                                                $$->nodeType = ELSE_IF_NODE;
                                                                $$->value.elseifStatement = $1;
                                                            }
|   elseStatement                                           {
                                                                $$ = malloc(sizeof(struct AstNodeInstruction));
                                                                printf("AstNodeInstruction allocated for 'elseStatement'\n");
                                                                $$->nodeType = ELSE_NODE;
                                                                $$->value.elseStatement = $1;
                                                            }
|   whileLoop                                               {
                                                                $$ = malloc(sizeof(struct AstNodeInstruction));
                                                                printf("AstNodeInstruction allocated for 'whileLoop'\n");
                                                                $$->nodeType = WHILE_NODE;
                                                                $$->value.whileLoop = $1;
                                                            }                       
|   arrayInit SEMICOL                                       {
                                                                $$ = malloc(sizeof(struct AstNodeInstruction));
                                                                printf("AstNodeInstruction allocated for 'arrayInit'\n");
                                                                $$->nodeType = ARRAY_INIT_NODE;
                                                                $$->value.arrayInit = $1;
                                                            }
|   arrayAssign SEMICOL                                     {
                                                                $$ = malloc(sizeof(struct AstNodeInstruction));
                                                                printf("AstNodeInstruction allocated for 'arrayAssign'\n");
                                                                $$->nodeType = ARRAY_ASSIGN_NODE;
                                                                $$->value.arrayAssign = $1;
                                                            }
|   outputFunction SEMICOL                                  {
                                                                $$ = malloc(sizeof(struct AstNodeInstruction));
                                                                printf("AstNodeInstruction allocated for 'outputFunction SEMICOL'\n");
                                                                $$->nodeType = OUTPUT_NODE;
                                                                $$->value.outputFunction = $1;
                                                            }
|   inputFunction SEMICOL                                   {
                                                                $$ = malloc(sizeof(struct AstNodeInstruction));
                                                                printf("AstNodeInstruction allocated for 'inputFunction SEMICOL'\n");
                                                                $$->nodeType = INPUT_NODE;
                                                                $$->value.inputFunction = $1;
                                                            };

functionDecl:
types MAIN LPAR RPAR body                                   {
                                                                struct SymTab *s = NULL;
                                                                char *main = "main";
                                                                s = findSymtab(main, actualList);
                                                                if (s == NULL) {
                                                                beginScope();
                                                                $$ = malloc(sizeof(struct AstNodeFunctionDecl));
                                                                printf("AstNodeFunctionDecl allocated for 'types MAIN LPAR RPAR body'\n");
                                                                $$->functionName = "main";
                                                                $$->returnType = stringToType($1);
                                                                $$->functionParams = NULL;
                                                                $$->functiontBody = $5;
                                                                endScope();
                                                                struct SymTab *s = createSym($$->functionName, actualList, SYMBOL_FUNCTION, DATA_TYPE_NONE, $$->returnType, $$->functionName, NULL, nullValue);
                                                                printf("Funzione main inserita nella symtab \n");
                                                                } else {
                                                                    printf("Error: function MAIN already declared \n");
                                                                }
                                                            }
|   initialization LPAR RPAR body                           {
                                                                struct SymTab *s = NULL;
                                                                s = findSymtab($1->assign->variableName, actualList);
                                                                if (s == NULL) {
                                                                beginScope();
                                                                $$ = malloc(sizeof(struct AstNodeFunctionDecl));
                                                                printf("AstNodeFunctionDecl allocated for 'initialization LPAR RPAR body'\n");
                                                                $$->functionName = $1->assign->variableName;
                                                                $$->returnType = $1->dataType;
                                                                printf("returnType assigned\n");
                                                                $$->functionParams = NULL;
                                                                $$->functiontBody = $4;
                                                                endScope();
                                                                struct SymTab *s = createSym($$->functionName, actualList, SYMBOL_FUNCTION, DATA_TYPE_NONE, $$->returnType, $$->functionName, NULL, nullValue);
                                                                printf("Funzione inserita nella symtab \n");
                                                            } else {
                                                                    printf("Error: function %s already declared \n",$1->assign->variableName);
                                                                }
                                                            }
|   initialization LPAR functionParams RPAR body            {
                                                                struct SymTab *s = NULL;
                                                                s = findSymtab($1->assign->variableName, actualList);
                                                                if (s == NULL) {
                                                                beginScope();
                                                                char appoggio[100] = {};
                                                                for(struct AstNodeFunctionParams *p = $3; p != NULL; p = p->nextParams) {
                                                                    printf("Sono entrato nel ciclo for \n \n");
                                                                    struct SymTab *s = createSym(p->initParam->assign->variableName, actualList, SYMBOL_FUNCTION, p->initParam->dataType, DATA_TYPE_NONE, $1->assign->variableName, NULL, p->initParam->assign->assignValue);
                                                                    printf("Aggiunto parametro alla symbol table\n");
                                                                    strcat(appoggio,typeToString(p->initParam->dataType));
                                                                }
                                                                printf("Appoggio alla fine vale: %s \n \n",appoggio);
                                                                $$ = malloc(sizeof(struct AstNodeFunctionDecl));
                                                                printf("AstNodeFunctionDecl allocated for 'initialization LPAR functionParams RPAR body'\n");
                                                                $$->functionName = $1->assign->variableName;
                                                                $$->returnType = $1->dataType;
                                                                $$->functionParams = $3;
                                                                $$->functiontBody = $5;
                                                                endScope();
                                                                    printf("Sto per entrare in symtab \n");
                                                                    struct SymTab *s = createSym($$->functionName, actualList, SYMBOL_FUNCTION, DATA_TYPE_NONE, $$->returnType, $$->functionName, appoggio, nullValue);
                                                                    printf("Funzione inserita nella symtab \n");
                                                                } else {
                                                                    printf("Error: function %s already declared \n",$1->assign->variableName);
                                                                }
                                                            };

functionCall:
ID LPAR RPAR                                                {
                                                                $$ = malloc(sizeof(struct AstNodeFunctionCall));
                                                                printf("AstNodeFunctionCall allocated for 'ID LPAR RPAR'\n");
                                                                struct SymTab *s = findSymtab($1, actualList);
                                                                if (s != NULL) {
                                                                    $$->functionName = $1;
                                                                    $$->returnType = s->returnType;
                                                                    $$->functionParams = NULL;
                                                                } else {
                                                                    printf("Error: function %s not declared\n", $1);
                                                                }
                                                            }
|   ID LPAR functionParams RPAR                             {
                                                                $$ = malloc(sizeof(struct AstNodeFunctionCall));
                                                                char confronto[100] = {};
                                                                printf("AstNodeFunctionCall allocated for 'ID LPAR functionParams RPAR'\n");
                                                                struct SymTab *s = findSymtab($1, actualList);
                                                                printf("Vedo se la funzione e' stata dichiarata \n");
                                                                if (s != NULL) {
                                                                    printf("Inizio a scorrere i parametri \n");
                                                                    for(struct AstNodeFunctionParams *q = $3; q != NULL; q = q->nextParams) {
                                                                    printf("Qui non so se arrivo \n");
                                                                    strcat(confronto,typeToString(q->callParams->valueType));
                                                                    printf("Fin qui se arrivo festeggio \n");
                                                                    }
                                                                    printf("Parametri della function Decl: %s \n \n",s->funcParameters);
                                                                    printf("Parametri della function Call: %s \n",confronto);
                                                                    int a = strcmp(s->funcParameters,confronto);
                                                                    if (a==0) {
                                                                    printf("I parametri sono corretti \n");
                                                                    $$->functionName = $1;
                                                                    $$->returnType = s->returnType;
                                                                    $$->functionParams = $3;
                                                                    } else {
                                                                        printf("Tipo dei parametri inserito non valido \n \n");
                                                                    }
                                                                } else {
                                                                    printf("Error: function %s not declared\n", $1);
                                                                }
                                                            };

functionParams:
types ID                                                    {
                                                                $$ = malloc(sizeof(struct AstNodeFunctionParams));
                                                                printf("AstNodeFunctionParams allocated for 'types ID'\n");
                                                                $$->nextParams = NULL;
                                                                $$->callParams = NULL;
                                                                $$->initParam = malloc(sizeof(struct AstNodeInit));
                                                                $$->initParam->dataType = stringToType($1);
                                                                $$->initParam->nextInit = NULL;
                                                                $$->initParam->assign = malloc(sizeof(struct AstNodeAssign));
                                                                $$->initParam->assign->variableName = $2;
                                                                $$->initParam->assign->variableType = stringToType($1);
                                                                $$->initParam->assign->assignValue.val = NULL;
                                                                $$->initParam->assign->assignType = CONTENT_TYPE_ID;
                                                            }
|   content                                                 {
                                                                $$ = malloc(sizeof(struct AstNodeFunctionParams));
                                                                printf("AstNodeFunctionParams allocated for 'content'\n");
                                                                $$->nextParams = NULL;
                                                                $$->callParams = $1;
                                                                $$->initParam = NULL;
                                                            }
|   types ID COMMA functionParams                           {
                                                                $$ = malloc(sizeof(struct AstNodeFunctionParams));
                                                                printf("AstNodeFunctionParams allocated for 'types ID COMMA functionParams'\n");
                                                                $$->nextParams = $4;
                                                                $$->callParams = NULL;
                                                                $$->initParam = malloc(sizeof(struct AstNodeInit));
                                                                $$->initParam->dataType = stringToType($1);
                                                                $$->initParam->nextInit = NULL;
                                                                $$->initParam->assign = malloc(sizeof(struct AstNodeAssign));
                                                                $$->initParam->assign->variableName = $2;
                                                                $$->initParam->assign->variableType = stringToType($1);
                                                                $$->initParam->assign->assignValue.val = NULL;
                                                                $$->initParam->assign->assignType = CONTENT_TYPE_ID;
                                                            }
|   content COMMA functionParams                            {
                                                                $$ = malloc(sizeof(struct AstNodeFunctionParams));
                                                                printf("AstNodeFunctionParams allocated for 'content COMMA functionParams'\n");
                                                                $$->nextParams = $3;
                                                                $$->callParams = $1;
                                                                $$->initParam = NULL;
                                                            };

body:
LBRA statements RBRA                                        {
                                                                $$ = malloc(sizeof(struct AstNodeBody));
                                                                printf("AstNodeBody allocated for 'LBRA statements RBRA'\n");
                                                                $$->bodyStatements = $2;
                                                                $$->returnValue = NULL;
                                                            }
| LBRA statements RETURN content SEMICOL RBRA               {
                                                                $$ = malloc(sizeof(struct AstNodeBody));
                                                                printf("AstNodeBody allocated for 'LBRA statements RETURN content SEMICOL RBRA'\n");
                                                                $$->bodyStatements = $2;
                                                                $$->returnValue = $4;
                                                            };

ifStatement:
IF LPAR expression RPAR body                                {
                                                                $$ = malloc(sizeof(struct AstNodeIf));
                                                                printf("AstNodeIf allocated for 'IF LPAR expression RPAR body'\n");
                                                                $$->ifCondition = $3;
                                                                $$->ifBody = $5;
                                                            };

elseifStatement:
ELSE IF LPAR expression RPAR body                           {
                                                                $$ = malloc(sizeof(struct AstNodeElseIf));
                                                                printf("AstNodeElseIf allocated for 'ELSE IF LPAR expression RPAR body'\n");
                                                                $$->elseifCondition = $4;
                                                                $$->elseifBody = $6;
                                                            };

elseStatement:
ELSE body                                                   {
                                                                $$ = malloc(sizeof(struct AstNodeElse));
                                                                printf("AstNodeElse allocated for 'ELSE body'\n");
                                                                $$->elseBody = $2;
                                                            };

whileLoop:
WHILE LPAR expression RPAR body                             {
                                                                $$ = malloc(sizeof(struct AstNodeWhile));
                                                                printf("AstNodeWhile allocated for 'WHILE LPAR expression RPAR body'\n");
                                                                $$->whileCondition = $3;
                                                                $$->whileBody = $5;
                                                            };

arrayInit:
types arrayDecl                                             {
                                                                //int myArray[]; Error: array size missing in ‘myArray’ !!!
                                                                //int myArray[3];
                                                                if($2->arrayLength == NULL) {
                                                                    printf("Error: array size missing in%s\n", $2->arrayName);
                                                                } else {
                                                                    $$=malloc(sizeof(struct AstNodeArrayInit));
                                                                $$->arrayType = stringToType($1);
                                                                $$->arrayDecl = $2;
                                                                $$->elements = NULL;
                                                                }
                                                            }
|   types arrayDecl EQ LBRA RBRA                {
                                                                //int myArray[] = {};
                                                                //int myArray[3] = {};
                                                                $$=malloc(sizeof(struct AstNodeArrayInit));
                                                                $$->arrayType = stringToType($1);
                                                                $$->arrayDecl = $2;
                                                                $$->elements = NULL;
                                                            }
|    types arrayDecl EQ arrayElements                       {
                                                                //int myArray[] = 24; Error: invalid initializer !!!
                                                                //int myArray[3] = 24; Error: invalid initializer !!!
                                                                printf("Error: invalid initializer of %s\n", $2->arrayName);
                                                            }
|   types arrayDecl EQ LBRA arrayElements RBRA              {
                                                                //int myArray[] = {24, 27, 29};
                                                                //int myArray[3] = {24, 27, 29};
                                                                $$=malloc(sizeof(struct AstNodeArrayInit));
                                                                $$->arrayType = stringToType($1);
                                                                $$->arrayDecl = $2;
                                                                $$->elements = $5;
                                                            };

arrayAssign:
arrayCall EQ LBRA RBRA                                  {
                                                                // myArray[] = {}; Syntax Error !!!
                                                                // myArray[3] = {}
                                                                printf("Syntax Error\n");
                                                            }
|   arrayCall EQ arrayElements                              {
                                                                // myArray[] = 24; Synrtax Error
                                                                // myArray[2] = 24; Corret
                                                                if($1->elementIndex == NULL) {
                                                                    printf("Syntax Error\n");
                                                                } else {
                                                                    $$=malloc(sizeof(struct AstNodeArrayAssign));
                                                                    $$->arrayType = $3->element->valueType;
                                                                    $$->arrayCall = $1;
                                                                    $$->elements = $3;
                                                                }
                                                                
                                                            }
|   arrayCall EQ LBRA arrayElements RBRA                    {
                                                                //myArray[] = {24, 27, 29}; Syntax Error
                                                                //myArray[3] = {24, 27, 29}; Syntax Error
                                                                printf("Syntax Error\n");
                                                            };

arrayDecl:
ID LSBRA RSBRA                                              {
                                                                $$=malloc(sizeof(struct AstNodeArrayDecl));
                                                                $$->arrayName = $1;
                                                                $$->arrayLength = NULL;
                                                            }
|   ID LSBRA INT_VALUE RSBRA                                    {
                                                                $$=malloc(sizeof(struct AstNodeArrayDecl));
                                                                $$->arrayName = $1;
                                                                $$->arrayLength = $3;
                                                            };

arrayCall:
ID LSBRA RSBRA                                              {
                                                                $$=malloc(sizeof(struct AstNodeArrayCall));
                                                                $$->arrayName = $1;
                                                                $$->elementIndex = NULL;
                                                            }
|   ID LSBRA content RSBRA                                    {
                                                                $$=malloc(sizeof(struct AstNodeArrayCall));
                                                                $$->arrayName = $1;
                                                                $$->elementIndex = $3;
                                                            };

/* arrayInit:
types ID LSBRA RSBRA                                        {
                                                                printf("Error: array size missing in %s\n", $2); //int myArray[]; Error: array size missing in ‘myArray’ !!!
                                                            }
|   types ID LSBRA INT_VALUE RSBRA                          {
                                                                $$ = malloc(sizeof(struct AstNodeArrayInit));
                                                                printf("AstNodeArrayInit allocated for 'types ID LSBRA INT_VALUE RSBRA'\n"); //int myArray[4];
                                                                $$->arrayType = stringToType($1);
                                                                $$->assignArray = malloc(sizeof(struct AstNodeArrayAssign));
                                                                printf("AstNodeArrayAssign allocated for 'types ID LSBRA INT_VALUE RSBRA'\n");
                                                                $$->assignArray->arrayType = stringToType($1);
                                                                $$->assignArray->arrayName = $2;
                                                                $$->assignArray->arrayLength = $4;
                                                                $$->assignArray->elementIndex = NULL;
                                                                $$->assignArray->elements = NULL;
                                                            }; */

/* arrayAssign:                                        
types ID LSBRA RSBRA EQ LBRA RBRA                           {
                                                                $$ = malloc(sizeof(struct AstNodeArrayAssign));
                                                                printf("AstNodeArrayAssign allocated for 'types ID LSBRA RSBRA EQ LBRA RBRA'\n"); //int myArray[] = {};
                                                                $$->arrayType = stringToType($1);
                                                                $$->arrayName = $2;
                                                                $$->arrayLength = NULL;
                                                                $$->elementIndex = NULL;
                                                                $$->elements = NULL; //Outuput: array[0]: 0, array[1]: memoryAddress
                                                            }
|   types ID LSBRA INT_VALUE RSBRA EQ arrayElements           {
                                                                printf("Error: invalid initializer of %s\n", $2); //int myArray[2] = 24; Error: invalid initializer !!!
                                                            }
|   types ID LSBRA RSBRA EQ LBRA arrayElements RBRA         {
                                                                $$ = malloc(sizeof(struct AstNodeArrayAssign));
                                                                printf("AstNodeArrayAssign allocated for 'types ID LSBRA RSBRA EQ LBRA arrayElements RBRA'\n"); 
                                                                $$->arrayType = stringToType($1);
                                                                $$->arrayName = $2;
                                                                $$->arrayLength = NULL; //TODO: compute arrayLength as # of elements (ciclare su arrayElements per calcolare il numero di elementi)
                                                                $$->elementIndex = NULL;
                                                                $$->elements = $7; 
                                                            }
|   types ID LSBRA INT_VALUE RSBRA EQ LBRA arrayElements RBRA {
                                                                $$ = malloc(sizeof(struct AstNodeArrayAssign));
                                                                printf("AstNodeArrayAssign allocated for 'types ID LSBRA INT_VALUE RSBRA EQ LBRA arrayElements RBRA'\n"); //int myArray[3] = {24, 27, 29};
                                                                $$->arrayType = stringToType($1);
                                                                $$->arrayName = $2;
                                                                $$->arrayLength = $4;
                                                                $$->elementIndex = NULL;
                                                                $$->elements = $8; //TODO (ciclare su arrayElements e controllare che nella graffa ci sono 3 elementi e verificare il tipo)
                                                            }
|   ID LSBRA RSBRA EQ LBRA RBRA                             {
                                                                printf("Error: invalid initializer of %s\n", $2); // myArray[] = {}; Syntax Error !!!
                                                            }
|   ID LSBRA INT_VALUE RSBRA EQ arrayElements                 {
                                                                $$ = malloc(sizeof(struct AstNodeArrayAssign));
                                                                printf("AstNodeArrayAssign allocated for 'ID LSBRA content RSBRA EQ arrayElements'\n"); // myArray[2] = 24;
                                                                $$->arrayType = $6->element->valueType;
                                                                $$->arrayName = $1;
                                                                $$->arrayLength = NULL;
                                                                $$->elementIndex = $3;
                                                                $$->elements = $6;
                                                            }
|   ID LSBRA RSBRA EQ LBRA arrayElements RBRA               {
                                                                $$ = malloc(sizeof(struct AstNodeArrayAssign));
                                                                printf("AstNodeArrayAssign allocated for 'ID LSBRA RSBRA EQ LBRA arrayElements RBRA'\n"); //myArray[] = {24, 27, 29};
                                                                $$->arrayType = $6->element->valueType; //TODO: accedere ai tipi di element e non di content, tipo $7->element->valueType
                                                                $$->arrayName = $1;
                                                                $$->arrayLength = NULL; //TODO: compute arrayLength as # of elements
                                                                $$->elementIndex = NULL;
                                                                $$->elements = $6;
                                                            }
|   ID LSBRA INT_VALUE RSBRA EQ LBRA arrayElements RBRA       {
                                                                $$ = malloc(sizeof(struct AstNodeArrayAssign));
                                                                printf("AstNodeArrayAssign allocated for 'ID LSBRA content RSBRA EQ LBRA arrayElements RBRA'\n"); //myArray[3] = {24, 27, 29};
                                                                $$->arrayType = $7->element->valueType; //TO-DO: accedere ai tipi di element e non di content, tipo $7->element->valueType
                                                                $$->arrayName = $1;
                                                                $$->arrayLength = $3;
                                                                $$->elementIndex = NULL;
                                                                $$->elements = $7;
                                                            }; */

arrayElements:
content                                                     {
                                                                $$ = malloc(sizeof(struct AstNodeArrayElements)); // 4 -> single element in array
                                                                if($1->contentType == CONTENT_TYPE_EXPRESSION) {
                                                                    printf("AstNodeArrayElements allocated for 'content': %s %s %s\n", $1->value.expression->leftOper->value.val, $1->value.expression->op, $1->value.expression->rightOper->value.val);
                                                                } else {
                                                                    printf("AstNodeArrayElements allocated for 'content': %s\n", $1->value.val);
                                                                }
                                                                $$->element = $1;
                                                                $$->nextElement = NULL;
                                                            }
|   content COMMA arrayElements                             {
                                                                $$ = malloc(sizeof(struct AstNodeArrayElements)); // 4, 5, 6 -> multiple elements in array
                                                                if($1->contentType == CONTENT_TYPE_EXPRESSION) {
                                                                    printf("AstNodeArrayElements allocated for 'content COMMA arrayElements': %s %s %s\n", $1->value.expression->leftOper->value.val, $1->value.expression->op, $1->value.expression->rightOper->value.val);
                                                                } else {
                                                                    printf("AstNodeArrayElements allocated for 'content COMMA arrayElements': %s\n", $1->value.val);
                                                                }
                                                                $$->element = $1;
                                                                $$->nextElement = $3;
                                                            };

outputFunction:
PRINTF LPAR STRING_VALUE RPAR                               {
                                                                $$ = malloc(sizeof(struct AstNodeFunctionOutput));
                                                                printf("AstNodeFunctionOutput allocated for 'PRINTF LPAR STRING_VALUE RPAR'\n");
                                                                $$->string = $3;
                                                                $$->outputElements = NULL;
                                                            }
|   PRINTF LPAR STRING_VALUE COMMA outputElements RPAR      {
                                                                $$ = malloc(sizeof(struct AstNodeFunctionOutput));
                                                                printf("AstNodeFunctionOutput allocated for 'PRINTF LPAR STRING_VALUE RPAR COMMA outputElements'\n");
                                                                $$->string = $3;
                                                                $$->outputElements = $5;
                                                            };

inputFunction:
SCANF LPAR STRING_VALUE RPAR                                {
                                                                $$ = malloc(sizeof(struct AstNodeFunctionInput));
                                                                printf("AstNodeFunctionInput allocated for 'SCANF LPAR STRING_VALUE RPAR'\n");
                                                                $$->string = $3;
                                                                $$->inputElements = NULL;
                                                            }
|   SCANF LPAR STRING_VALUE COMMA inputElements RPAR        {
                                                                $$ = malloc(sizeof(struct AstNodeFunctionInput));
                                                                printf("AstNodeFunctionInput allocated for 'SCANF LPAR STRING_VALUE RPAR COMMA inputElements'\n");
                                                                $$->string = $3;
                                                                $$->inputElements = $5;
                                                            };

outputElements:
content                                                     {
                                                                $$ = malloc(sizeof(struct AstNodeOutputElements));
                                                                printf("AstNodeOutputElements allocated for 'content'\n");
                                                                $$->element = $1;
                                                                $$->nextElement = NULL;
                                                            }
|   content COMMA outputElements                            {
                                                                $$ = malloc(sizeof(struct AstNodeOutputElements));
                                                                printf("AstNodeOutputElements allocated for 'content COMMA outputElements'\n");
                                                                $$->element = $1;
                                                                $$->nextElement = $3;
                                                            };

inputElements:
content                                                     {
                                                                $$ = malloc(sizeof(struct AstNodeInputElements));
                                                                printf("AstNodeInputElements allocated for 'content'\n");
                                                                $$->element = $1;
                                                                $$->nextElement = NULL;
                                                            }
|   content COMMA inputElements                             {
                                                                $$ = malloc(sizeof(struct AstNodeInputElements));
                                                                printf("AstNodeInputElements allocated for 'content COMMA inputElements'\n");
                                                                $$->element = $1;
                                                                $$->nextElement = $3;
                                                            };

initialization:
types ID                                                    {
                                                                $$ = malloc(sizeof(struct AstNodeInit));
                                                                printf("AstNodeInit allocated for 'types ID'\n");
                                                                $$->dataType = stringToType($1);
                                                                $$->nextInit = NULL;
                                                                $$->assign = malloc(sizeof(struct AstNodeAssign));
                                                                printf("AstNodeAssign allocated for 'types ID'\n");
                                                                $$->assign->variableName = $2;
                                                                $$->assign->variableType = stringToType($1);
                                                                $$->assign->assignValue.val = NULL;
                                                                $$->assign->assignType = CONTENT_TYPE_ID;
                                                            };

assignment:
ID EQ ID                                                    {
                                                                $$ = malloc(sizeof(struct AstNodeAssign));
                                                                printf("AstNodeAssign allocated for 'ID EQ ID'\n");
                                                                $$->variableName = $1;
                                                                $$->assignType = CONTENT_TYPE_ID;
                                                                $$->assignValue.val = $3;
                                                                struct SymTab *s = findSym($3, actualList);
                                                                if (s == NULL) {
                                                                    $$->variableType = DATA_TYPE_NONE;
                                                                    printf("ID EQ ID non esiste dollaro3 nella symtab\n");
                                                                } else {
                                                                    $$->variableType = s->dataType;
                                                                    printf("ID EQ ID esiste dollaro3 nella symtab\n");
                                                                }
                                                            }
|   types ID EQ content                                     {
                                                                struct SymTab *s = NULL;  //sarà diverso da NULL solo se trova il simbolo
                                                                s = findSym($2, actualList);  //controlla se il simbolo è stato già dichiarato
                                                                if (s==NULL) {
                                                                    s = createSym($2, actualList, SYMBOL_VARIABLE, stringToType($1), stringToType($1), NULL, NULL, $4->value);
                                                                    printf("'types ID EQ content': the variable %s has not already been declared and then I create the symbol table for this variable\n", $2);
                                                                } else {
                                                                    printf("Error: variable %s already declared\n", $2);
                                                                }
                                                                if ((stringToType($1) != $4->valueType)) {
                                                                    printf("Error: Cannot assign type %s to type %s \n", typeToString($4->valueType), $1);
                                                                } else {
                                                                    $$ = malloc(sizeof(struct AstNodeAssign));
                                                                    printf("AstNodeAssign allocated for 'types ID EQ content'\n");
                                                                    $$->variableName = $2;
                                                                    $$->variableType = stringToType($1);
                                                                    $$->assignValue.val = $4->value.val;
                                                                    $$->assignType = $4->contentType;
                                                                }
                                                            }
|   ID EQ content                                           {
                                                                $$ = malloc(sizeof(struct AstNodeAssign)); //inserire qui la verifica che int a sia stato dichiarato prima di fare a = qualcosa
                                                                printf("AstNodeAssign allocated for 'ID EQ content'\n");
                                                                $$->variableName = $1;
                                                                $$->variableType = $3->valueType;
                                                                $$->assignValue = $3->value;   //forse va- assignValue.val ma fors no perche- anche $3 e' generico
                                                                $$->assignType = $3->contentType;
                                                            };

expression:
content ADD content                                         {
                                                                $$ = malloc(sizeof(struct AstNodeExpression));
                                                                printf("AstNodeExpression allocated for 'content ADD content'\n");
                                                                $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->leftOper = $1;
                                                                $$->op = $2;
                                                                $$->rightOper = $3;
                                                                $$->exprType = $1->valueType;
                                                                if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                    printf("\n Errore! Impossibile sommare variabili di tipo char");
                                                                } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                    printf("\n Errore! Impossibile sommare variabili di tipo void");
                                                                } else if ($1->valueType != $3->valueType) {
                                                                    printf("\n Errore! Impossibile sommare variabili di tipi diversi");
                                                                } else {
                                                                    printf("Expression di tipo somma \n");
                                                                }
                                                            }
|   content SUB content                                     {
                                                                $$ = malloc(sizeof(struct AstNodeExpression));
                                                                printf("AstNodeExpression allocated for 'content SUB content'\n");
                                                                $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->leftOper = $1;
                                                                $$->op = $2;
                                                                $$->rightOper = $3;
                                                                $$->exprType = $1->valueType;
                                                                if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                    printf("\n Errore! Impossibile sottrarre variabili di tipo char");
                                                                } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                    printf("\n Errore! Impossibile sottrare variabili di tipo void");
                                                                } else if ($1->valueType != $3->valueType) {
                                                                    printf("\n Errore! Impossibile sottrarre variabili di tipi diversi");
                                                                } else {
                                                                    printf("Expression di tipo sottrazione \n");
                                                                }
                                                            }
|   content MUL content                                     {
                                                                $$ = malloc(sizeof(struct AstNodeExpression));
                                                                printf("AstNodeExpression allocated for 'content MUL content'\n");
                                                                $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->leftOper = $1;
                                                                $$->op = $2;
                                                                $$->rightOper = $3;
                                                                $$->exprType = $1->valueType;
                                                                if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                    printf("\n Errore! Impossibile moltiplicare variabili di tipo char");
                                                                } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                    printf("\n Errore! Impossibile moltiplicare variabili di tipo void");
                                                                } else if ($1->valueType != $3->valueType) {
                                                                    printf("\n Errore! Impossibile moltiplicare variabili di tipi diversi");
                                                                } else {
                                                                    printf("Expression di tipo moltiplicazione \n");
                                                                }
                                                            }
|   content DIV content                                     {
                                                                $$ = malloc(sizeof(struct AstNodeExpression));
                                                                printf("AstNodeExpression allocated for 'content DIV content'\n");
                                                                $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->leftOper = $1;
                                                                $$->op = $2;
                                                                $$->rightOper = $3;
                                                                $$->exprType = DATA_TYPE_FLOAT; //forziamo il tipo a Float essendo una divisione
                                                                if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                    printf("\n Errore! Impossibile dividere variabili di tipo char");
                                                                } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                    printf("\n Errore! Impossibile dividere variabili di tipo void");
                                                                } else if ($1->valueType != $3->valueType) {
                                                                    printf("\n Errore! Impossibile dividere variabili di tipi diversi");
                                                                } else {
                                                                    printf("Expression di tipo divisione \n");
                                                                }
                                                            } 
|   content EE content                                      {
                                                                $$ = malloc(sizeof(struct AstNodeExpression));
                                                                printf("AstNodeExpression allocated for 'content EE content'\n");
                                                                $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->leftOper = $1;
                                                                $$->op = $2;
                                                                $$->rightOper = $3;
                                                                $$->exprType = DATA_TYPE_INT;
                                                                printf("Expression di tipo Equal to \n");
                                                            }
|   content NE content                                      {
                                                                $$ = malloc(sizeof(struct AstNodeExpression));
                                                                printf("AstNodeExpression allocated for 'content NE content'\n");
                                                                $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->leftOper = $1;
                                                                $$->op = $2;
                                                                $$->rightOper = $3;
                                                                $$->exprType = DATA_TYPE_INT;
                                                                printf("Expression di tipo Not Equal \n");
                                                            }
|   content GT content                                      {
                                                                $$ = malloc(sizeof(struct AstNodeExpression));
                                                                printf("AstNodeExpression allocated for 'content GT content'\n");
                                                                $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->leftOper = $1;
                                                                $$->op = $2;
                                                                $$->rightOper = $3;
                                                                $$->exprType = DATA_TYPE_INT;
                                                                if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                    printf("\n Errore! Impossibile confrontare variabili di tipo char");
                                                                } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                    printf("\n Errore! Impossibile confrontare variabili di tipo void");
                                                                } else {
                                                                    printf("Expression di tipo Greater than \n");
                                                                }
                                                            }
|   content LT content                                      {
                                                                $$ = malloc(sizeof(struct AstNodeExpression));
                                                                printf("AstNodeExpression allocated for 'content LT content'\n");
                                                                $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->leftOper = $1;
                                                                $$->op = $2;
                                                                $$->rightOper = $3;
                                                                $$->exprType = DATA_TYPE_INT;
                                                                if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                    printf("\n Errore! Impossibile confrontare variabili di tipo char");
                                                                } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                    printf("\n Errore! Impossibile confrontare variabili di tipo void");
                                                                } else {
                                                                    printf("Expression di tipo Less than \n");
                                                                }
                                                            }
|   content GE content                                      {
                                                                $$ = malloc(sizeof(struct AstNodeExpression));
                                                                printf("AstNodeExpression allocated for 'content GE content'\n");
                                                                $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->leftOper = $1;
                                                                $$->op = $2;
                                                                $$->rightOper = $3;
                                                                $$->exprType = DATA_TYPE_INT;
                                                                if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                    printf("\n Errore! Impossibile confrontare variabili di tipo char");
                                                                } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                    printf("\n Errore! Impossibile confrontare variabili di tipo void");
                                                                } else {
                                                                    printf("Expression di tipo Greater than or equal to \n");
                                                                }
                                                            }
|   content LE content                                      {
                                                                $$ = malloc(sizeof(struct AstNodeExpression));
                                                                printf("AstNodeExpression allocated for 'content LE content'\n");
                                                                $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->leftOper = $1;
                                                                $$->op = $2;
                                                                $$->rightOper = $3;
                                                                $$->exprType = DATA_TYPE_INT;
                                                                if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                    printf("\n Errore! Impossibile confrontare variabili di tipo char");
                                                                } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                    printf("\n Errore! Impossibile confrontare variabili di tipo void");
                                                                } else {
                                                                    printf("Expression di tipo Less than or equal to \n");
                                                                }
                                                            }
|   content AND content                                     {
                                                                $$ = malloc(sizeof(struct AstNodeExpression));
                                                                printf("AstNodeExpression allocated for 'content AND content'\n");
                                                                $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->leftOper = $1;
                                                                $$->op = $2;
                                                                $$->rightOper = $3;
                                                                $$->exprType = DATA_TYPE_INT;
                                                                if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                    printf("\n Errore! Impossibile confrontare variabili di tipo char");
                                                                } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                    printf("\n Errore! Impossibile confrontare variabili di tipo void");
                                                                } else {
                                                                    printf("Expression di tipo AND \n");
                                                                }
                                                            }
|   content OR content                                      {
                                                                $$ = malloc(sizeof(struct AstNodeExpression));
                                                                printf("AstNodeExpression allocated for 'content OR content'\n");
                                                                $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->leftOper = $1;
                                                                $$->op = $2;
                                                                $$->rightOper = $3;
                                                                $$->exprType = DATA_TYPE_INT;
                                                                if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                    printf("\n Errore! Impossibile confrontare variabili di tipo char");
                                                                } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                    printf("\n Errore! Impossibile confrontare variabili di tipo void");
                                                                } else {
                                                                    printf("Expression di tipo OR \n");
                                                                }
                                                            }
|   NOT content                                             {
                                                                $$ = malloc(sizeof(struct AstNodeExpression));
                                                                printf("AstNodeExpression allocated for 'NOT content'\n");
                                                                $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                                $$->op = $1;
                                                                $$->leftOper = $2;
                                                                $$->rightOper = NULL;
                                                                $$->exprType = DATA_TYPE_INT;
                                                                if  ($2->valueType == DATA_TYPE_CHAR) {
                                                                    printf("\n Errore! Impossibile confrontare variabili di tipo char");
                                                                } else if  ($2->valueType == DATA_TYPE_VOID) {
                                                                    printf("\n Errore! Impossibile confrontare variabili di tipo void");
                                                                } else {
                                                                    printf("Expression di tipo NOT \n");
                                                                }
                                                            };

content:
ID                                                          {
                                                                $$ = malloc(sizeof(struct AstNodeOperand));
                                                                printf("AstNodeOperand allocated for 'ID'\n"); //Ci troviamo nel caso in cui abbiamo int a = b
                                                                struct SymTab *s = findSymtab($1,actualList);
                                                                if(s == NULL) {
                                                                    $$->valueType = DATA_TYPE_NONE;
                                                                } else {
                                                                    $$->value.val = $1;
                                                                    $$->valueType = s->dataType;
                                                                    $$->contentType = CONTENT_TYPE_ID;
                                                                }
                                                            }
|   INT_VALUE                                               {
                                                                $$ = malloc(sizeof(struct AstNodeOperand));
                                                                printf("AstNodeOperand allocated for 'INT_VALUE'\n");
                                                                $$->value.val = $1;
                                                                $$->valueType = DATA_TYPE_INT;
                                                                $$->contentType = CONTENT_TYPE_INT_NUMBER;
                                                            }
|   FLOAT_VALUE                                             {
                                                                $$ = malloc(sizeof(struct AstNodeOperand));
                                                                printf("AstNodeOperand allocated for 'FLOAT_VALUE'\n");
                                                                $$->value.val = $1;
                                                                $$->valueType = DATA_TYPE_FLOAT;
                                                                $$->contentType = CONTENT_TYPE_FLOAT_NUMBER;
                                                            }
|   CHAR_VALUE                                              {
                                                                $$ = malloc(sizeof(struct AstNodeOperand));
                                                                printf("AstNodeOperand allocated for 'CHAR_VALUE'\n");
                                                                $$->value.val = $1;
                                                                $$->valueType = DATA_TYPE_CHAR;
                                                                $$->contentType = CONTENT_TYPE_CHAR;
                                                            }
|   expression                                              {
                                                                $$ = malloc(sizeof(struct AstNodeOperand));
                                                                printf("AstNodeOperand allocated for 'expression'\n");
                                                                $$->value.expression = $1;
                                                                $$->valueType = $1->exprType;
                                                                $$->contentType = CONTENT_TYPE_EXPRESSION;
                                                            }
|   functionCall                                            {
                                                                $$ = malloc(sizeof(struct AstNodeOperand));
                                                                printf("AstNodeOperand allocated for 'functionCall'\n");
                                                                $$->value.funtionCall = $1;
                                                                $$->valueType = $1->returnType;
                                                                $$->contentType = CONTENT_TYPE_FUNCTION;
                                                            };

types:
VOID                                                        {
                                                                printf("Defined 'type: VOID'\n");
                                                            }
|   INT                                                     {
                                                                printf("Defined 'type: INT'\n");
                                                            }
|   FLOAT                                                   {
                                                                printf("Defined 'type: FLOAT'\n");
                                                            }
|   CHAR                                                    {
                                                                printf("Defined 'type: CHAR'\n");
                                                            };

%%

int main() {
    yyparse();
    nullValue.val = NULL;
    counter = 0;
    
    return 0;
}

int yyerror(char *s) {
    printf("%s\n", s);
}

void beginScope() {
    actualList = createList(counter, actualList);
    counter++;
}

void endScope() {
    deleteList(actualList);
    counter--;
}

char *typeToString(int type) {
    switch(type) {
        case DATA_TYPE_VOID:
            return "void";
        break;
        case DATA_TYPE_INT:
            return "int";
        break;
        case DATA_TYPE_FLOAT:
            return "float";
        break;
        case DATA_TYPE_CHAR:
            return "char";
        break;
        default:
            return "NULL";
        break;
    }
}

int stringToType(char *type) {
    if (strcmp(type, "void") == 0) {
        return DATA_TYPE_VOID;
    } else if (strcmp(type, "int") == 0) {
        return DATA_TYPE_INT;
    } else if (strcmp(type, "float") == 0) {
        return DATA_TYPE_FLOAT;
    } else if (strcmp(type, "char") == 0) {
        return DATA_TYPE_CHAR;
    } else {
        return DATA_TYPE_NONE;
    }
}

/* int compareStrings(char *one, char *two) {
    while (*one == *two) {
    printf("Le stringhe sono uguali \n");
    if ( *one == '\0' || *two == '\0' ) {
        printf("Nooooo "); break;
    }
    one++; two++; 
    }
    if( *one == '\0' && *two == '\0' )
    printf("Le stringhe sono le stesse \n");
    else
    printf("Le stringhe non sono affatto le stesse \n");
} */

