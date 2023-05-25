%{
#include <stdio.h> //printf, scanf, ecc
#include <math.h>
#include <ctype.h>
#include <string.h> //strcmp, strdup
#include <stdbool.h> //true, false
#include <stdlib.h> //atoi()
#include "ast.h"
#include "symboltable.h"
#include "c2py.h"

int yylex(void);
int yyerror(char *s);

FILE *fptr;

struct AstNodeStatements *root;
struct List *actualList = NULL;
char appoggio[100] = {};

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
%token REFOP
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

%type <string> types VOID INT FLOAT CHAR IF ELSE WHILE PRINTF SCANF RETURN MAIN REFOP ADD SUB MUL DIV EQ EE NE GT LT GE LE AND OR NOT LPAR RPAR LSBRA RSBRA LBRA RBRA SEMICOL COMMA INT_VALUE FLOAT_VALUE ID CHAR_VALUE STRING_VALUE
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

program:                                                {
                                                            beginScope();
                                                        }
statements                                              {
                                                            root = $2;
                                                            endScope();
                                                        };

statements:
instruction statements                                  {
                                                            $$ = malloc(sizeof(struct AstNodeStatements));
                                                            printf("AstNodeStatements allocated for 'instruction statements'\n");
                                                            $$->nodeType = STATEMENT_NODE;
                                                            $$->currentInstruction = $1;
                                                            $$->nextStatement = $2;
                                                        }
|   instruction                                         {
                                                            $$ = malloc(sizeof(struct AstNodeStatements));
                                                            printf("AstNodeStatements allocated for 'instruction'\n");
                                                            $$->nodeType = STATEMENT_NODE;
                                                            $$->currentInstruction = $1;
                                                            $$->nextStatement = NULL;
                                                        };

instruction:
functionDecl                                            {
                                                            $$ = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'functionDecl SEMICOL'\n");
                                                            $$->nodeType = FUNCTION_DECL_NODE;
                                                            $$->value.functionDecl = $1;
                                                        }
|   functionCall SEMICOL                                {
                                                            $$ = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'functionCall SEMICOL'\n");
                                                            $$->nodeType = FUNCTION_CALL_NODE;
                                                            $$->value.functionCall = $1;
                                                        }
|   initialization SEMICOL                              {
                                                            $$ = malloc(sizeof(struct AstNodeInstruction));
                                                            struct SymTab *s = NULL;
                                                            s = findSym($1->variableName, actualList);
                                                            if (s == NULL) {
                                                                if($1->dataType == DATA_TYPE_VOID) {
                                                                    printf("You cannot initialize a variable of type void\n");
                                                                } else {
                                                                    printf("AstNodeInstruction allocated for 'initialization SEMICOL'\n");
                                                                    $$->nodeType = INIT_NODE;
                                                                    $$->value.init = $1;
                                                                    s = createSym($1->variableName, actualList, SYMBOL_VARIABLE, $1->dataType, $1->dataType, NULL, NULL, NULL, nullValue);
                                                                }
                                                            } else {
                                                                printf("Error: variable already declared.\n");
                                                            }
                                                        }
|   assignment SEMICOL                                  {
                                                            $$ = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'assignment SEMICOL'\n");
                                                            $$->nodeType = ASSIGN_NODE;
                                                            $$->value.assign = $1;
                                                        }
|   arrayInit SEMICOL                                   {
                                                            struct SymTab *s = findSym($1->arrayDecl->arrayName, actualList);
                                                            if (s == NULL) {
                                                                $$ = malloc(sizeof(struct AstNodeInstruction));
                                                                printf("AstNodeInstruction allocated for 'arrayInit'\n");
                                                                $$->nodeType = ARRAY_INIT_NODE;
                                                                $$->value.arrayInit = $1;
                                                                s = createSym($1->arrayDecl->arrayName, actualList, SYMBOL_ARRAY, $1->arrayType, $1->arrayType, NULL, NULL, $1->arrayDecl->arrayLength, nullValue);
                                                                printf("Symbol created. symbolName %s\n",$1->arrayDecl->arrayName);
                                                            } else {
                                                                printf("Error: array %s already declared\n", $1->arrayDecl->arrayName);
                                                            }
                                                        }
|   arrayAssign SEMICOL                                 {
                                                            struct SymTab *s = findSym($1->arrayCall->arrayName, actualList);
                                                            if (s != NULL) {
                                                                if(s->dataType != $1->arrayType) {
                                                                    printf("Error: Array %s has been declared as a %s but type %s is assigned.\n", $1->arrayCall->arrayName, typeToString(s->dataType), typeToString($1->arrayType));
                                                                } else if(atoi(s->arrayLength) <= atoi($1->arrayCall->elementIndex->value.val)) {
                                                                    printf("OUT OF MEMORY: the length of %s is %s", s->symbolName, s->arrayLength);
                                                                }else {
                                                                    $$ = malloc(sizeof(struct AstNodeInstruction));
                                                                    printf("AstNodeInstruction allocated for 'arrayAssign'\n");
                                                                    $$->nodeType = ARRAY_ASSIGN_NODE;
                                                                    $$->value.arrayAssign = $1;
                                                                }
                                                            } else {
                                                                printf("Error: array %s not declared\n", $1->arrayCall->arrayName);
                                                            }
                                                        }
|   outputFunction SEMICOL                              {
                                                            $$ = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'outputFunction SEMICOL'\n");
                                                            $$->nodeType = OUTPUT_NODE;
                                                            $$->value.outputFunction = $1;
                                                        }
|   inputFunction SEMICOL                               {
                                                            $$ = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'inputFunction SEMICOL'\n");
                                                            $$->nodeType = INPUT_NODE;
                                                            $$->value.inputFunction = $1;
                                                        }
|   ifStatement                                         {
                                                            $$ = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'ifStatement'\n");
                                                            $$->nodeType = IF_NODE;
                                                            $$->value.ifStatement = $1;
                                                        }
|   elseifStatement                                     {
                                                            $$ = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'elseifStatement'\n");
                                                            $$->nodeType = ELSE_IF_NODE;
                                                            $$->value.elseifStatement = $1;
                                                        }
|   elseStatement                                       {
                                                            $$ = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'elseStatement'\n");
                                                            $$->nodeType = ELSE_NODE;
                                                            $$->value.elseStatement = $1;
                                                        }
|   whileLoop                                           {
                                                            $$ = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'whileLoop'\n");
                                                            $$->nodeType = WHILE_NODE;
                                                            $$->value.whileLoop = $1;
                                                        };                      

functionDecl:
types MAIN LPAR RPAR                                    {
                                                            beginScope();
                                                        }
body                                                    {
                                                            struct SymTab *s = NULL;
                                                            char *main = "main";
                                                            s = findSymtab(main, actualList);
                                                            if (s == NULL) {
                                                                $$ = malloc(sizeof(struct AstNodeFunctionDecl));
                                                                printf("AstNodeFunctionDecl allocated for 'types MAIN LPAR RPAR body'\n");
                                                                $$->functionName = $2;
                                                                $$->returnType = stringToType($1);
                                                                $$->functionParams = NULL;
                                                                $$->functiontBody = $6;
                                                                endScope();
                                                                struct SymTab *s = createSym($$->functionName, actualList, SYMBOL_FUNCTION, DATA_TYPE_NONE, $$->returnType, $$->functionName, NULL, NULL, nullValue);
                                                                printf("Function MAIN inserted in the symtab\n");
                                                            } else {
                                                                printf("Error: function MAIN already declared\n");
                                                                endScope();
                                                            } 
                                                        }
|   initialization LPAR RPAR                            {
                                                            beginScope();
                                                        }
    body                                                {
                                                            struct SymTab *s = NULL;
                                                            s = findSymtab($1->variableName, actualList);
                                                            if (s == NULL) { 
                                                                $$ = malloc(sizeof(struct AstNodeFunctionDecl));
                                                                printf("AstNodeFunctionDecl allocated for 'initialization LPAR RPAR body'\n");
                                                                $$->functionName = $1->variableName;
                                                                $$->returnType = $1->dataType;
                                                                printf("returnType assigned\n");
                                                                $$->functionParams = NULL;
                                                                $$->functiontBody = $5;
                                                                endScope();
                                                                struct SymTab *s = createSym($$->functionName, actualList, SYMBOL_FUNCTION, DATA_TYPE_NONE, $$->returnType, $$->functionName, NULL, NULL, nullValue);
                                                            } else {
                                                                printf("Error: function %s already declared \n",$1->variableName);
                                                                endScope();
                                                            } 
                                                        }
|   initialization LPAR                                 {   
                                                            beginScope();
                                                        }
    functionParams                                      {
                                                            for(int i=0; i<sizeof(appoggio);i++) {
                                                                appoggio[i] = '\0';
                                                            }
                                                            for(struct AstNodeFunctionParams *p = $4; p != NULL; p = p->nextParams) {
                                                                struct SymTab *s = createSym(p->initParam->variableName, actualList, SYMBOL_FUNCTION, p->initParam->dataType, DATA_TYPE_NONE, $1->variableName, NULL, NULL, nullValue);
                                                                strcat(appoggio,typeToString(p->initParam->dataType));
                                                            } 
                                                            printf("Parameters of the declared function: %s \n",appoggio);
                                                        }
    RPAR body                                           {
                                                            struct SymTab *s = NULL;
                                                            s = findSymtab($1->variableName, actualList);
                                                            if (s == NULL) { 
                                                                $$ = malloc(sizeof(struct AstNodeFunctionDecl));
                                                                printf("AstNodeFunctionDecl allocated for 'initialization LPAR functionParams RPAR body'\n");
                                                                $$->functionName = $1->variableName;
                                                                $$->returnType = $1->dataType;
                                                                $$->functionParams = $4;
                                                                $$->functiontBody = $7; 
                                                                endScope();
                                                                struct SymTab *q = createSym($$->functionName, actualList, SYMBOL_FUNCTION, DATA_TYPE_NONE, $$->returnType, $$->functionName, appoggio, NULL, nullValue);
                                                            } else {
                                                                printf("Error: function %s already declared \n",$1->variableName);
                                                                endScope();
                                                            }
                                                        };

functionCall:
ID LPAR RPAR                                            {
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
|   ID LPAR functionParams RPAR                         {
                                                            $$ = malloc(sizeof(struct AstNodeFunctionCall));
                                                            printf("AstNodeFunctionCall allocated for 'ID LPAR functionParams RPAR'\n");
                                                            char calledParameters[100] = {};
                                                            struct SymTab *s = findSymtab($1, actualList);
                                                            if (s != NULL) {
                                                                for(struct AstNodeFunctionParams *q = $3; q != NULL; q = q->nextParams) {
                                                                    strcat(calledParameters,typeToString(q->callParams->valueType));
                                                                }
                                                                printf("Parameters of the declared function: %s \n", s->funcParameters);
                                                                printf("Parameters of the called function: %s \n", calledParameters);
                                                                int boolean = strcmp(s->funcParameters,calledParameters);
                                                                if (boolean == 0) {
                                                                    printf("The parameters are correct\n");
                                                                    $$->functionName = $1;
                                                                    $$->returnType = s->returnType;
                                                                    $$->functionParams = $3;
                                                                } else {
                                                                    printf("The parameters in the function call are incorrect\n");
                                                                }
                                                            } else {
                                                                printf("Error: function %s not declared\n", $1);
                                                            }
                                                        };

functionParams:
types ID                                                {
                                                            $$ = malloc(sizeof(struct AstNodeFunctionParams));
                                                            printf("AstNodeFunctionParams allocated for 'types ID'\n");
                                                            $$->nextParams = NULL;
                                                            $$->callParams = NULL;
                                                            $$->initParam = malloc(sizeof(struct AstNodeInit));
                                                            $$->initParam->dataType = stringToType($1);
                                                            $$->initParam->variableName = $2;
                                                        }
|   content                                             {
                                                            $$ = malloc(sizeof(struct AstNodeFunctionParams));
                                                            printf("AstNodeFunctionParams allocated for 'content'\n");
                                                            $$->nextParams = NULL;
                                                            $$->callParams = $1;
                                                            $$->initParam = NULL;
                                                        }
|   types ID COMMA functionParams                       {
                                                            $$ = malloc(sizeof(struct AstNodeFunctionParams));
                                                            printf("AstNodeFunctionParams allocated for 'types ID COMMA functionParams'\n");
                                                            $$->nextParams = $4;
                                                            $$->callParams = NULL;
                                                            $$->initParam = malloc(sizeof(struct AstNodeInit));
                                                            $$->initParam->dataType = stringToType($1);
                                                            $$->initParam->variableName = $2;
                                                        }
|   content COMMA functionParams                        {
                                                            $$ = malloc(sizeof(struct AstNodeFunctionParams));
                                                            printf("AstNodeFunctionParams allocated for 'content COMMA functionParams'\n");
                                                            $$->nextParams = $3;
                                                            $$->callParams = $1;
                                                            $$->initParam = NULL;
                                                        };

ifStatement:
IF LPAR expression RPAR                                 {
                                                            beginScope();
                                                        }
body                                                    {
                                                            $$ = malloc(sizeof(struct AstNodeIf));
                                                            printf("AstNodeIf allocated for 'IF LPAR expression RPAR body'\n");
                                                            $$->ifCondition = $3;
                                                            $$->ifBody = $6;
                                                            endScope();
                                                        };

elseifStatement:
ELSE IF LPAR expression RPAR                            {
                                                            beginScope();
                                                        }
body                                                    {
                                                            $$ = malloc(sizeof(struct AstNodeElseIf));
                                                            printf("AstNodeElseIf allocated for 'ELSE IF LPAR expression RPAR body'\n");
                                                            $$->elseifCondition = $4;
                                                            $$->elseifBody = $7;
                                                            endScope();
                                                        };

elseStatement:
ELSE                                                    {
                                                            beginScope();
                                                        }
body                                                    {
                                                            $$ = malloc(sizeof(struct AstNodeElse));
                                                            printf("AstNodeElse allocated for 'ELSE body'\n");
                                                            $$->elseBody = $3;
                                                            endScope();
                                                        };

whileLoop:
WHILE LPAR expression RPAR                              {
                                                            beginScope();
                                                        }
body                                                    {
                                                            $$ = malloc(sizeof(struct AstNodeWhile));
                                                            printf("AstNodeWhile allocated for 'WHILE LPAR expression RPAR body'\n");
                                                            $$->whileCondition = $3;
                                                            $$->whileBody = $6;
                                                            endScope();
                                                        };

body:
LBRA statements RBRA                                    {
                                                            $$ = malloc(sizeof(struct AstNodeBody));
                                                            printf("AstNodeBody allocated for 'LBRA statements RBRA'\n");
                                                            $$->bodyStatements = $2;
                                                            $$->returnValue = NULL;
                                                        }
|   LBRA statements RETURN content SEMICOL RBRA         {
                                                            $$ = malloc(sizeof(struct AstNodeBody));
                                                            printf("AstNodeBody allocated for 'LBRA statements RETURN content SEMICOL RBRA'\n");
                                                            $$->bodyStatements = $2;
                                                            $$->returnValue = $4;
                                                        }
|   LBRA RETURN content SEMICOL RBRA                    {
                                                            $$=malloc(sizeof(struct AstNodeBody));
                                                            printf("AstNodeBody allocated for 'LBRA RETURN content SEMICOL RBRA'\n");
                                                            $$->bodyStatements = NULL;
                                                            $$->returnValue = $3;
                                                        };

arrayInit:
types arrayDecl                                         {
                                                            //int myArray[]; Error: array size missing in ‘myArray’ !!!
                                                            //int myArray[3]; Corretct
                                                            if($2->arrayLength == NULL) {
                                                                printf("Error: array size missing in %s \n", $2->arrayName);
                                                            } else {
                                                                $$=malloc(sizeof(struct AstNodeArrayInit));
                                                                printf("AstNodeArrayInit allocated for 'types arrayDecl'\n");
                                                                $$->arrayType = stringToType($1);
                                                                $$->arrayDecl = $2;
                                                                $$->elements = NULL;
                                                                $$->arrayDecl->arrayType = stringToType($1);
                                                            }
                                                        }
|   types arrayDecl EQ LBRA RBRA                        {
                                                            //int myArray[] = {};
                                                            //int myArray[3] = {};
                                                            $$=malloc(sizeof(struct AstNodeArrayInit));
                                                            printf("AstNodeArrayInit allocated for 'types arrayDecl EQ LBRA RBRA'\n");
                                                            $$->arrayType = stringToType($1);
                                                            $$->arrayDecl = $2;
                                                            $$->elements = NULL;
                                                            $$->arrayDecl->arrayType = stringToType($1);
                                                        }
|    types arrayDecl EQ arrayElements                   {
                                                            //int myArray[] = 24; Error: invalid initializer !!!
                                                            //int myArray[3] = 24; Error: invalid initializer !!!
                                                            printf("Error: invalid initializer of %s\n", $2->arrayName);
                                                        }
|   types arrayDecl EQ LBRA arrayElements RBRA          {
                                                            //int myArray[] = {24, 27, 29};
                                                            //int myArray[3] = {24, 27, 29};
                                                            $$=malloc(sizeof(struct AstNodeArrayInit));
                                                            printf("AstNodeArrayInit allocated for 'types arrayDecl EQ LBRA arrayElements RBRA'\n");
                                                            $$->arrayType = stringToType($1);
                                                            $$->arrayDecl = $2;
                                                            $$->elements = $5;
                                                            $$->arrayDecl->arrayType = stringToType($1);
                                                            int ele = 0;
                                                            for(struct AstNodeArrayElements *q = $5; q != NULL; q = q->nextElement) {
                                                                ele++;
                                                            }
                                                            char ch[3];
                                                            sprintf(ch,"%d",ele);
                                                            printf("Number of elements in the array %s\n",ch);
                                                            $$->arrayDecl->arrayLength = ch;
                                                        };

arrayAssign:
arrayCall EQ LBRA RBRA                                  {
                                                            // myArray[] = {}; Syntax Error
                                                            // myArray[3] = {}; Syntax Error
                                                            printf("Syntax Error!!!\n");
                                                        }
|   arrayCall EQ arrayElements                          {
                                                            // myArray[] = 24; Synrtax Error
                                                            // myArray[2] = 24; Corret
                                                            if($1->elementIndex == NULL) {
                                                                printf("Syntax Error!!!\n");
                                                            } else {
                                                                $$=malloc(sizeof(struct AstNodeArrayAssign));
                                                                printf("AstNodeArrayAssign allocated for 'arrayCall EQ arrayElements'\n");
                                                                $$->arrayType = $3->element->valueType;
                                                                $$->arrayCall = $1;
                                                                $$->elements = $3;
                                                                $$->arrayCall->arrayType = $3->element->valueType;
                                                            }
                                                        }
|   arrayCall EQ LBRA arrayElements RBRA                {
                                                            //myArray[] = {24, 27, 29}; Syntax Error
                                                            //myArray[3] = {24, 27, 29}; Syntax Error
                                                            printf("Syntax Error!!!\n");
                                                        };

arrayDecl:
ID LSBRA RSBRA                                          {
                                                            $$=malloc(sizeof(struct AstNodeArrayDecl));
                                                            printf("AstNodeArrayDecl allocated for 'ID LSBRA RSBRA'\n");
                                                            $$->arrayName = $1;
                                                            $$->arrayLength = NULL;
                                                        }
|   ID LSBRA INT_VALUE RSBRA                            {
                                                            $$=malloc(sizeof(struct AstNodeArrayDecl));
                                                            printf("AstNodeArrayDecl allocated for 'ID LSBRA INT_VALUE RSBRA'\n");
                                                            $$->arrayName = $1;
                                                            $$->arrayLength = $3;
                                                        };

arrayCall:
ID LSBRA RSBRA                                          {
                                                            $$=malloc(sizeof(struct AstNodeArrayCall));
                                                            printf("AstNodeArrayCall allocated for 'ID LSBRA RSBRA'\n");
                                                            $$->arrayName = $1;
                                                            $$->elementIndex = NULL;
                                                        }
|   ID LSBRA content RSBRA                              {
                                                            $$=malloc(sizeof(struct AstNodeArrayCall));
                                                            printf("AstNodeArrayCall allocated for 'ID LSBRA content RSBRA'\n");
                                                            $$->arrayName = $1;
                                                            $$->elementIndex = $3;
                                                            if($$->elementIndex->contentType != CONTENT_TYPE_ID || $$->elementIndex->contentType != CONTENT_TYPE_INT_NUMBER) {
                                                                printf("Error: invalid array index type\n");
                                                            }
                                                        };

arrayElements:
content                                                 {
                                                            $$ = malloc(sizeof(struct AstNodeArrayElements)); // 4 -> single element in array
                                                            if($1->contentType == CONTENT_TYPE_EXPRESSION) {
                                                                printf("AstNodeArrayElements allocated for 'content': %s %s %s\n", $1->value.expression->leftOper->value.val, $1->value.expression->op, $1->value.expression->rightOper->value.val);
                                                            } else {
                                                                printf("AstNodeArrayElements allocated for 'content': %s\n", $1->value.val);
                                                            }
                                                            $$->element = $1;
                                                            $$->nextElement = NULL;
                                                        }
|   content COMMA arrayElements                         {
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
PRINTF LPAR STRING_VALUE RPAR                           {
                                                            $$ = malloc(sizeof(struct AstNodeFunctionOutput));
                                                            printf("AstNodeFunctionOutput allocated for 'PRINTF LPAR STRING_VALUE RPAR'\n");
                                                            $$->string = $3;
                                                            $$->outputElements = NULL;
                                                        }
|   PRINTF LPAR STRING_VALUE COMMA outputElements RPAR  {
                                                            $$ = malloc(sizeof(struct AstNodeFunctionOutput));
                                                            printf("AstNodeFunctionOutput allocated for 'PRINTF LPAR STRING_VALUE RPAR COMMA outputElements'\n");
                                                            $$->string = $3;
                                                            $$->outputElements = $5;
                                                        };

inputFunction:
SCANF LPAR STRING_VALUE RPAR                            {
                                                            $$ = malloc(sizeof(struct AstNodeFunctionInput));
                                                            printf("AstNodeFunctionInput allocated for 'SCANF LPAR STRING_VALUE RPAR'\n");
                                                            $$->string = $3;
                                                            $$->inputElements = NULL;
                                                        }
|   SCANF LPAR STRING_VALUE COMMA inputElements RPAR    {
                                                            $$ = malloc(sizeof(struct AstNodeFunctionInput));
                                                            printf("AstNodeFunctionInput allocated for 'SCANF LPAR STRING_VALUE RPAR COMMA inputElements'\n");
                                                            $$->string = $3;
                                                            $$->inputElements = $5;
                                                        };

outputElements:
content                                                 {
                                                            $$ = malloc(sizeof(struct AstNodeOutputElements));
                                                            printf("AstNodeOutputElements allocated for 'content'\n");
                                                            $$->element = $1;
                                                            $$->nextElement = NULL;
                                                        }
|   content COMMA outputElements                        {
                                                            $$ = malloc(sizeof(struct AstNodeOutputElements));
                                                            printf("AstNodeOutputElements allocated for 'content COMMA outputElements'\n");
                                                            $$->element = $1;
                                                            $$->nextElement = $3;
                                                        };

inputElements:
REFOP content                                           {
                                                            $$ = malloc(sizeof(struct AstNodeInputElements));
                                                            printf("AstNodeInputElements allocated for 'content'\n");
                                                            $$->element = $2;
                                                            $$->nextElement = NULL;
                                                        }
|   REFOP content COMMA inputElements                   {
                                                            $$ = malloc(sizeof(struct AstNodeInputElements));
                                                            printf("AstNodeInputElements allocated for 'content COMMA inputElements'\n");
                                                            $$->element = $2;
                                                            $$->nextElement = $4;
                                                        };

initialization:
types ID                                                {
                                                            $$ = malloc(sizeof(struct AstNodeInit));
                                                            printf("AstNodeInit allocated for 'types ID'\n");
                                                            $$->variableName = $2;
                                                            $$->dataType = stringToType($1);
                                                        };

assignment:
types ID EQ content                                     {
                                                            struct SymTab *s = NULL;
                                                            s = findSym($2, actualList);
                                                            if (s != NULL) {
                                                                printf("Error: variable %s already declared\n", $2);
                                                            } else if ((stringToType($1) != $4->valueType) || strcmp(typeToString($4->valueType), "Type none") == 0) {
                                                                printf("Error: Cannot assign type %s to type %s \n", typeToString($4->valueType), $1);
                                                            } else if(stringToType($1) == DATA_TYPE_VOID) {
                                                                printf("You cannot assign a variable of type void\n");
                                                            } else {
                                                                s = createSym($2, actualList, SYMBOL_VARIABLE, stringToType($1), stringToType($1), NULL, NULL, NULL, $4->value);
                                                                $$ = malloc(sizeof(struct AstNodeAssign));
                                                                printf("AstNodeAssign allocated for 'types ID EQ content'\n");
                                                                $$->variableName = $2;
                                                                $$->variableType = stringToType($1);
                                                                $$->assignValue = $4->value;
                                                                $$->assignType = $4->contentType;
                                                                //printf("'types ID EQ content': the variable %s has not already been declared and then I create the symbol table for this variable\n", $2);
                                                            }
                                                        }
|   ID EQ content                                       {
                                                            $$ = malloc(sizeof(struct AstNodeAssign));
                                                            printf("AstNodeAssign allocated for 'ID EQ content'\n");
                                                            struct SymTab *s = NULL;
                                                            s = findSymtab($1, actualList); 
                                                            if (s == NULL) {
                                                                printf("Error: variable %s not declared\n", $1);
                                                            } else {
                                                                if (s->dataType != $3->valueType) {
                                                                    printf("Error: cannot asign type %s to type %s\n", typeToString($3->valueType), typeToString(s->dataType));
                                                                } else {
                                                                    $$->variableName = $1;
                                                                    $$->variableType = $3->valueType;
                                                                    $$->assignValue = $3->value;
                                                                    $$->assignType = $3->contentType;
                                                                }
                                                            }
                                                        };

expression:
content ADD content                                     {
                                                            $$ = malloc(sizeof(struct AstNodeExpression));
                                                            printf("AstNodeExpression allocated for 'content ADD content'\n");
                                                            $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->leftOper = $1;
                                                            $$->op = $2;
                                                            $$->rightOper = $3;
                                                            $$->exprType = $1->valueType;
                                                            if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                printf("Error: cannot add variables of type char\n");
                                                            } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot add variables of type void\n");
                                                            } else if ($1->valueType != $3->valueType) {
                                                                printf("Error: cannot add variables of different types\n");
                                                            } else {
                                                                printf("Expression of type Sum\n");
                                                            }
                                                        }
|   content SUB content                                 {
                                                            $$ = malloc(sizeof(struct AstNodeExpression));
                                                            printf("AstNodeExpression allocated for 'content SUB content'\n");
                                                            $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->leftOper = $1;
                                                            $$->op = $2;
                                                            $$->rightOper = $3;
                                                            $$->exprType = $1->valueType;
                                                            if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                printf("Error: cannot subtract variables of type char\n");
                                                            } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot subtract variables of type void\n");
                                                            } else if ($1->valueType != $3->valueType) {
                                                                printf("Error: cannot subtract variables of different types\n");
                                                            } else {
                                                                printf("Expression of type Subtraction\n");
                                                            }
                                                        }
|   content MUL content                                 {
                                                            $$ = malloc(sizeof(struct AstNodeExpression));
                                                            printf("AstNodeExpression allocated for 'content MUL content'\n");
                                                            $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->leftOper = $1;
                                                            $$->op = $2;
                                                            $$->rightOper = $3;
                                                            $$->exprType = $1->valueType;
                                                            if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                printf("Error: cannot multiply variables of type char\n");
                                                            } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot multiply variables of type void\n");
                                                            } else if ($1->valueType != $3->valueType) {
                                                                printf("Error: cannot multiply variables of different types\n");
                                                            } else {
                                                                printf("Expression of type Multiplication\n");
                                                            }
                                                        }
|   content DIV content                                 {
                                                            $$ = malloc(sizeof(struct AstNodeExpression));
                                                            printf("AstNodeExpression allocated for 'content DIV content'\n");
                                                            $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->leftOper = $1;
                                                            $$->op = $2;
                                                            $$->rightOper = $3;
                                                            $$->exprType = DATA_TYPE_FLOAT; //forziamo il tipo a Float essendo una divisione
                                                            if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                printf("Error: cannot divide variables of type char\n");
                                                            } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot divide variables of type void\n");
                                                            } else if ($1->valueType != $3->valueType) {
                                                                printf("Error: cannot divide variables of different types\n");
                                                            } else {
                                                                printf("Expression of type Division\n");
                                                            }
                                                        } 
|   content EE content                                  {
                                                            $$ = malloc(sizeof(struct AstNodeExpression));
                                                            printf("AstNodeExpression allocated for 'content EE content'\n");
                                                            $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->leftOper = $1;
                                                            $$->op = $2;
                                                            $$->rightOper = $3;
                                                            $$->exprType = DATA_TYPE_INT;
                                                            printf("Expression of type Equal to\n");
                                                        }
|   content NE content                                  {
                                                            $$ = malloc(sizeof(struct AstNodeExpression));
                                                            printf("AstNodeExpression allocated for 'content NE content'\n");
                                                            $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->leftOper = $1;
                                                            $$->op = $2;
                                                            $$->rightOper = $3;
                                                            $$->exprType = DATA_TYPE_INT;
                                                            printf("Expression of type Not Equal\n");
                                                        }
|   content GT content                                  {
                                                            $$ = malloc(sizeof(struct AstNodeExpression));
                                                            printf("AstNodeExpression allocated for 'content GT content'\n");
                                                            $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->leftOper = $1;
                                                            $$->op = $2;
                                                            $$->rightOper = $3;
                                                            $$->exprType = DATA_TYPE_INT;
                                                            if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                printf("Error: cannot compare variables of type char\n");
                                                            } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot compare variables of type void\n");
                                                            } else {
                                                                printf("Expression of type Greater than\n");
                                                            }
                                                        }
|   content LT content                                  {
                                                            $$ = malloc(sizeof(struct AstNodeExpression));
                                                            printf("AstNodeExpression allocated for 'content LT content'\n");
                                                            $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->leftOper = $1;
                                                            $$->op = $2;
                                                            $$->rightOper = $3;
                                                            $$->exprType = DATA_TYPE_INT;
                                                            if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                printf("Error: cannot compare variables of type char\n");
                                                            } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot compare variables of type void\n");
                                                            } else {
                                                                printf("Expression of type Less than\n");
                                                            }
                                                        }
|   content GE content                                  {
                                                            $$ = malloc(sizeof(struct AstNodeExpression));
                                                            printf("AstNodeExpression allocated for 'content GE content'\n");
                                                            $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->leftOper = $1;
                                                            $$->op = $2;
                                                            $$->rightOper = $3;
                                                            $$->exprType = DATA_TYPE_INT;
                                                            if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                printf("Error: cannot compare variables of type char\n");
                                                            } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot compare variables of type void\n");
                                                            } else {
                                                                printf("Expression of type Greater than or equal to\n");
                                                            }
                                                        }
|   content LE content                                  {
                                                            $$ = malloc(sizeof(struct AstNodeExpression));
                                                            printf("AstNodeExpression allocated for 'content LE content'\n");
                                                            $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->leftOper = $1;
                                                            $$->op = $2;
                                                            $$->rightOper = $3;
                                                            $$->exprType = DATA_TYPE_INT;
                                                            if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                printf("Error: cannot compare variables of type char\n");
                                                            } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot compare variables of type void\n");
                                                            } else {
                                                                printf("Expression of type Less than or equal to\n");
                                                            }
                                                        }
|   content AND content                                 {
                                                            $$ = malloc(sizeof(struct AstNodeExpression));
                                                            printf("AstNodeExpression allocated for 'content AND content'\n");
                                                            $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->leftOper = $1;
                                                            $$->op = $2;
                                                            $$->rightOper = $3;
                                                            $$->exprType = DATA_TYPE_INT;
                                                            if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                printf("Error: cannot compare variables of type char\n");
                                                            } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot compare variables of type void\n");
                                                            } else {
                                                                printf("Expression of type AND\n");
                                                            }
                                                        }
|   content OR content                                  {
                                                            $$ = malloc(sizeof(struct AstNodeExpression));
                                                            printf("AstNodeExpression allocated for 'content OR content'\n");
                                                            $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->leftOper = $1;
                                                            $$->op = $2;
                                                            $$->rightOper = $3;
                                                            $$->exprType = DATA_TYPE_INT;
                                                            if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                                                printf("Error: cannot compare variables of type char\n");
                                                            } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot compare variables of type void\n");
                                                            } else {
                                                                printf("Expression of type OR\n");
                                                            }
                                                        }
|   NOT content                                         {
                                                            $$ = malloc(sizeof(struct AstNodeExpression));
                                                            printf("AstNodeExpression allocated for 'NOT content'\n");
                                                            $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                            $$->op = $1;
                                                            $$->leftOper = $2;
                                                            $$->rightOper = NULL;
                                                            $$->exprType = DATA_TYPE_INT;
                                                            if  ($2->valueType == DATA_TYPE_CHAR) {
                                                                printf("Error: cannot compare variables of type char\n");
                                                            } else if  ($2->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot compare variables of type void\n");
                                                            } else {
                                                                printf("Expression of type NOT\n");
                                                            }
                                                        };

content:
ID                                                      {
                                                            $$ = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'ID'\n"); //Ci troviamo nel caso in cui abbiamo int a = b
                                                            struct SymTab *s = findSymtab($1,actualList);
                                                            if(s == NULL) {
                                                                printf("Error: The variable %s does not exist\n", $1);
                                                            } else {
                                                                $$->value.val = $1;
                                                                $$->valueType = s->dataType;
                                                                $$->contentType = CONTENT_TYPE_ID;
                                                            }
                                                        }
|   INT_VALUE                                           {
                                                            $$ = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'INT_VALUE'\n");
                                                            $$->value.val = $1;
                                                            $$->valueType = DATA_TYPE_INT;
                                                            $$->contentType = CONTENT_TYPE_INT_NUMBER;
                                                        }
|   FLOAT_VALUE                                         {
                                                            $$ = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'FLOAT_VALUE'\n");
                                                            $$->value.val = $1;
                                                            $$->valueType = DATA_TYPE_FLOAT;
                                                            $$->contentType = CONTENT_TYPE_FLOAT_NUMBER;
                                                        }
|   CHAR_VALUE                                          {
                                                            $$ = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'CHAR_VALUE'\n");
                                                            $$->value.val = $1;
                                                            $$->valueType = DATA_TYPE_CHAR;
                                                            $$->contentType = CONTENT_TYPE_CHAR;
                                                        }
|   expression                                          {
                                                            $$ = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'expression'\n");
                                                            $$->value.expression = $1;
                                                            $$->valueType = $1->exprType;
                                                            $$->contentType = CONTENT_TYPE_EXPRESSION;
                                                        }
|   functionCall                                        {
                                                            $$ = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'functionCall'\n");
                                                            $$->value.funtionCall = $1;
                                                            $$->valueType = $1->returnType;
                                                            $$->contentType = CONTENT_TYPE_FUNCTION;
                                                        }
|   arrayCall                                           {
                                                            $$ = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'arrayCall'\n");
                                                            struct SymTab *s = findSymtab($1->arrayName,actualList);
                                                            if (s != NULL) {
                                                                $$->value.arrayCall = $1;
                                                                $$->valueType = s->dataType;
                                                                $$->contentType = CONTENT_TYPE_ARRAY;
                                                            }
                                                        };

types:
VOID                                                    {
                                                            printf("Defined 'type: VOID'\n");
                                                        }
|   INT                                                 {
                                                            printf("Defined 'type: INT'\n");
                                                        }
|   FLOAT                                               {
                                                            printf("Defined 'type: FLOAT'\n");
                                                        }
|   CHAR                                                {
                                                            printf("Defined 'type: CHAR'\n");
                                                        };

%%

int main() {
    yyparse();
    nullValue.val = NULL;
    counter = 0;
    fptr = fopen("test.py", "w");
    translate(root);
    fclose(fptr);
    printf("Translation completed!\n");
    
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
        case DATA_TYPE_NONE:
            return "Type none";
        default:
            return "Type not defined";
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