%{
#include <stdio.h>
//#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
//#include <stddef.h>
#include "ast.h"
#include "symboltable.h"
#include "c2py.h"

int yylex(void);
int yyerror(char *s);

struct AstNodeStatements *root;
struct List *actualList = NULL;

char * type_to_str(int type);
void scope_enter();
void scope_exit();

//struct SymTab *s = NULL; 

%}

/*%code requires {
    #include "ast.h"
    #include "symboltable.h"
}*/

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
%token ADD
%token SUB
%token MUL
%token DIV
%token EQ
%token EE
%token NE
%token GT
%token LT
%token GE
%token LE
%token AND
%token OR
%token NOT
%token LPAR
%token RPAR
%token LSBRA
%token RSBRA
%token LBRA
%token RBRA
%token SEMICOL
%token COMMA
%token ID
%token INT_VALUE
%token FLOAT_VALUE
%token CHAR_VALUE
%token MAIN


/* NON_TERMINAL TYPES */
%define api.value.type {union yystype}


%type <string> types SEMICOL COMMA ID INT_VALUE FLOAT_VALUE CHAR_VALUE EQ ADD SUB MUL DIV EE NE GT LT GE LE AND OR NOT RETURN LPAR RPAR LSBRA RSBRA LBRA RBRA MAIN
%type <statements> program statements 
%type <instruction> instruction 
%type <init> initialization
%type <assign> assignment
%type <operand> content
%type <expression> expression
%type <body> body
%type <functionDecl> functionDecl
%type <functionCall> functionCall
%type <functionParams> functionParams singleParam

%start program

%%

program:                                        {
                                                    scope_enter();
                                                }   
statements                                      {
                                                    root = $2;
                                                    scope_exit();
                                                };

statements: 
instruction statements                          {
                                                    $$ = malloc(sizeof(struct AstNodeStatements));
                                                    printf("AstNodeStatements allocated for 'instruction statements'\n");
                                                    $$->nodeType = STATEMENT_NODE;
                                                    $$->currentInstruction = $1;
                                                    $$->nextStatement = $2;
                                                }
|   instruction                                 {
                                                    $$ = malloc(sizeof(struct AstNodeStatements));
                                                    printf("AstNodeStatements allocated for 'instruction'\n");
                                                    $$->nodeType = STATEMENT_NODE;
                                                    $$->currentInstruction = $1;
                                                    $$->nextStatement = NULL;
                                                };

instruction:
assignment SEMICOL                              {
                                                    $$ = malloc(sizeof(struct AstNodeInstruction));
                                                    printf("AstNodeInstruction allocated for 'assignment SEMICOL'\n");
                                                    $$->nodeType = ASSIGN_NODE;
                                                    struct SymTab *s = findSym($1->variableName, actualList);
                                                    if((s->dataType != $1->variableType) || strcmp(type_to_str(s->dataType), "none") == 0) {
                                                        printf("Error\n");
                                                    } else {
                                                        $$->value.assign = $1;
                                                        s->valueOper = $1->assignValue;
                                                    }
                                                    
                                                }
| initialization SEMICOL                        {
                                                    $$ = malloc(sizeof(struct AstNodeInstruction));
                                                    struct SymTab *s = NULL;
                                                    for (struct AstNodeInit *init = $1; init != NULL; init = init->nextInit) {
                                                        s = findSym(init->assign->variableName, actualList);
                                                        if (s == NULL) {
                                                            printf("AstNodeInstruction allocated for 'initialization SEMICOL'\n");
                                                            $$->nodeType = INIT_NODE;
                                                            $$->value.init = $1;
                                                            s = createSym(init->assign->variableName, actualList, SYMBOL_VARIABLE, str_to_type($1), str_to_type($1), NULL, nullValue);
                                                        } else {
                                                            printf("Error: variable already declared.\n");
                                                        }
                                                    }
                                                }
|   functionDecl                         {
                                                    $$ = malloc(sizeof(struct AstNodeInstruction));
                                                    printf("AstNodeInstruction allocated for 'functionDecl SEMICOL'\n");
                                                    $$->nodeType = FUNCTION_DECL_NODE;
                                                    $$->value.functionDecl = $1;
                                                    struct SymTab *s = NULL;
                                                    s = findSymtab($1->functionName, actualList);
                                                    if (s == NULL) {
                                                        struct SymTab *s = createSym($1->functionName, actualList, SYMBOL_FUNCTION, DATA_TYPE_NONE, $1->returnType, NULL, nullValue);
                                                        printf("Funzione inserita nella symtab \n");
                                                    } else {
                                                         printf("Error: function %s already declared \n", $1->functionName);
                                                    }
                                                }
|   functionCall SEMICOL                        {
                                                    $$ = malloc(sizeof(struct AstNodeInstruction));
                                                    printf("AstNodeInstruction allocated for 'functionCall SEMICOL'\n");
                                                    $$->nodeType = FUNCTION_CALL_NODE;
                                                    $$->value.functionCall = $1;
                                                };

functionDecl:
types MAIN LPAR RPAR body                       {
                                                    scope_enter();
                                                    $$ = malloc(sizeof(struct AstNodeFunctionDecl));
                                                    printf("Entered in main \n");
                                                    $$->functionName = "main";
                                                    $$->returnType = str_to_type($1);
                                                    $$->functionParams = NULL;
                                                    $$->functiontBody = $5;
                                                    scope_exit();
                                                }
|   initialization LPAR RPAR body               {
                                                    scope_enter();
                                                    $$ = malloc(sizeof(struct AstNodeFunctionDecl));
                                                    printf("AstNodeFunctionDecl allocated for 'initialization LPAR RPAR body'\n");
                                                    $$->functionName = $1->assign->variableName;
                                                    $$->returnType = $1->dataType;
                                                    printf("returnType assigned\n");
                                                    $$->functionParams = NULL;
                                                    $$->functiontBody = $4;
                                                    scope_exit();
                                                }
|   initialization LPAR functionParams RPAR body    {
                                                        scope_enter();
                                                        for(struct AstNodeFunctionParams *p = $3; p != NULL; p = p->nextParams) {
                                                            struct symtab *s = createSym(p->initParam->assign->variableName, actualList, SYMBOL_FUNCTION, p->initParam->dataType, DATA_TYPE_NONE, $1->assign->variableName, p->initParam->assign->assignValue);
                                                            printf("Inserito parametro della funzione nella symtab \n");
                                                        }
                                                        $$ = malloc(sizeof(struct AstNodeFunctionDecl));
                                                        printf("AstNodeFunctionDecl allocated function with parameters \n");
                                                        $$->functionName = $1->assign->variableName;
                                                        $$->returnType = $1->dataType;
                                                        printf("returnType assigned\n");
                                                        $$->functionParams = $3;
                                                        $$->functiontBody = $5;
                                                        scope_exit();
                                                    };


functionCall:
ID LPAR RPAR                                    {
                                                    $$ = malloc(sizeof(struct AstNodeFunctionCall));
                                                    printf("AstNodeFunctionCall allocated for 'ID LPRA RPAR'\n");
                                                    $$->functionName = $1;
                                                    $$->returnType = DATA_TYPE_INT;
                                                    $$->functionParams = NULL; 
                                                }

functionParams:
types ID                                        {
                                                    $$ = malloc(sizeof(struct AstNodeFunctionParams));
                                                    $$->nextParams = NULL;
                                                    $$->callParams = NULL;
                                                    $$->initParam = malloc(sizeof(struct AstNodeInit));
                                                    $$->initParam->dataType = str_to_type($1);
                                                    $$->initParam->nextInit = NULL;
                                                    $$->initParam->assign = malloc(sizeof(struct AstNodeAssign));
                                                    $$->initParam->assign->variableName = $2;
                                                    $$->initParam->assign->variableType = str_to_type($1);
                                                    $$->initParam->assign->assignValue.val = NULL;
                                                    $$->initParam->assign->assignType = CONTENT_TYPE_ID;
                                                }
| content                                       {
                                                    $$ = malloc(sizeof(struct AstNodeFunctionParams));
                                                    $$->nextParams = NULL;
                                                    $$->callParams = $1;
                                                    $$->initParam = NULL;
                                                }
| types ID COMMA functionParams                 {
                                                    $$ = malloc(sizeof(struct AstNodeFunctionParams));
                                                    $$->nextParams = $4;
                                                    $$->callParams = NULL;
                                                    $$->initParam = malloc(sizeof(struct AstNodeInit));
                                                    $$->initParam->dataType = str_to_type($1);
                                                    $$->initParam->nextInit = NULL;
                                                    $$->initParam->assign = malloc(sizeof(struct AstNodeAssign));
                                                    $$->initParam->assign->variableName = $2;
                                                    $$->initParam->assign->variableType = str_to_type($1);
                                                    $$->initParam->assign->assignValue.val = NULL;
                                                    $$->initParam->assign->assignType = CONTENT_TYPE_ID;
                                                }
| content COMMA functionParams                  {
                                                    $$ = malloc(sizeof(struct AstNodeFunctionParams));
                                                    $$->nextParams = $3;
                                                    $$->callParams = $1;
                                                    $$->initParam = NULL;
                                                };




body:
LBRA statements RBRA                            {
                                                    $$ = malloc(sizeof(struct AstNodeBody));
                                                    printf("AstNodeBody allocated for 'LBRA statements RBRA'\n");
                                                    $$->bodyStatements = $2;
                                                    $$->returnValue = NULL;
                                                }
| LBRA statements RETURN content SEMICOL RBRA   {
                                                    $$ = malloc(sizeof(struct AstNodeBody));
                                                    printf("AstNodeBody allocated for 'LBRA statements RETURN content SEMICOL RBRA'\n");
                                                    $$->bodyStatements = $2;
                                                    $$->returnValue = $4;
                                                };


initialization:
types ID                                        {
                                                    $$ = malloc(sizeof(struct AstNodeInit));
                                                    printf("AstNodeInit allocated for 'types ID'\n");
                                                    $$->dataType = str_to_type($1);
                                                    $$->nextInit = NULL;
                                                    $$->assign = malloc(sizeof(struct AstNodeAssign));
                                                    printf("AstNodeAssign allocated for 'types ID'\n");
                                                    $$->assign->variableName = $2;
                                                    $$->assign->variableType = str_to_type($1);
                                                    $$->assign->assignValue.val = NULL;   
                                                    $$->assign->assignType = CONTENT_TYPE_ID;  
                                                };

assignment:                     
ID EQ ID                                        {
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
|   types ID EQ content                         {
                                                    struct SymTab *s = NULL;  //sarà diverso da NULL solo se trova il simbolo
                                                    s = findSym($2, actualList);  //controlla se il simbolo è stato già dichiarato
                                                    if (s==NULL) {
                                                        s = createSym($2, actualList, SYMBOL_VARIABLE, str_to_type($1), str_to_type($1), NULL, $4->value);
                                                        printf("types ID EQ content non esiste dollaro2 nella symtab e la creo\n");
                                                    } else {
                                                        printf("\n Errore: variabile %s gia' dichiarata \n", $2);
                                                    }
                                                    if ((str_to_type($1) != $4->valueType)) {
                                                        //printf("Errore: impossibile assegnare un tipo %s ad un tipo %s \n", type_to_str($4->valueType), type_to_str($1));
                                                    } else {
                                                    $$ = malloc(sizeof(struct AstNodeAssign));
                                                    printf("AstNodeAssign allocated for 'types ID EQ content'\n");
                                                    $$->variableName = $2;
                                                    $$->variableType = str_to_type($1);
                                                    $$->assignValue.val = $4->value.val; 
                                                    $$->assignType = $4->contentType;
                                                    }
                                                }
|   ID EQ content                               {
                                                    $$ = malloc(sizeof(struct AstNodeAssign)); //inserire qui la verifica che int a sia stato dichiarato prima di fare a = qualcosa
                                                    printf("AstNodeAssign allocated for 'ID EQ content'\n");
                                                    $$->variableName = $1;
                                                    $$->variableType = $3->valueType;
                                                    $$->assignValue = $3->value;   //forse va- assignValue.val ma fors no perche- anche $3 e' generico
                                                    $$->assignType = $3->contentType;
                                                };

expression:
content ADD content                             {
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
|   content SUB content                         {
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
|   content MUL content                         {
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
|   content DIV content                         {
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
|   content EE content                          {
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
|   content NE content                          {
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
|   content GT content                          {
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
|   content LT content                          {
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
|   content GE content                          {
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
|   content LE content                          {
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
|   content AND content                         {
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
|   content OR content                          {
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
|   NOT content                                 {
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
ID                                              {
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
|   INT_VALUE                                   {       
                                                    $$ = malloc(sizeof(struct AstNodeOperand));
                                                    printf("AstNodeOperand allocated for 'INT_VALUE'\n");
                                                    $$->value.val = $1;
                                                    $$->valueType = DATA_TYPE_INT; 
                                                    $$->contentType = CONTENT_TYPE_INT_NUMBER;
                                                }
|   FLOAT_VALUE                                 {
                                                    $$ = malloc(sizeof(struct AstNodeOperand));
                                                    printf("AstNodeOperand allocated for 'FLOAT_VALUE'\n");
                                                    $$->value.val = $1;
                                                    $$->valueType = DATA_TYPE_FLOAT; 
                                                    $$->contentType = CONTENT_TYPE_FLOAT_NUMBER;
                                                }
|   CHAR_VALUE                                  {
                                                    $$ = malloc(sizeof(struct AstNodeOperand));
                                                    printf("AstNodeOperand allocated for 'CHAR_VALUE'\n");
                                                    $$->value.val = $1;
                                                    $$->valueType = DATA_TYPE_CHAR;  
                                                    $$->contentType = CONTENT_TYPE_CHAR;
                                                }
|   expression                                  {
                                                    $$ = malloc(sizeof(struct AstNodeOperand));
                                                    printf("AstNodeOperand allocated for 'expression'\n");
                                                    $$->value.expression = $1;
                                                    $$->valueType = $1->exprType;  
                                                    $$->contentType = CONTENT_TYPE_EXPRESSION;
                                                };

types:
    VOID                                        {
                                                    $$ = DATA_TYPE_VOID;
                                                    printf("Defined 'type: VOID'\n");
                                                }
|   INT                                         {
                                                    $$ = DATA_TYPE_INT;
                                                    printf("Defined 'type: INT'\n");
                                                }
|   FLOAT                                       {
                                                    $$ = DATA_TYPE_FLOAT;
                                                    printf("Defined 'type: FLOAT'\n");
                                                }
|   CHAR                                        {
                                                    $$ = DATA_TYPE_CHAR;
                                                    printf("Defined 'type: CHAR'\n");
                                                };

%%

int main() {
    yyparse();

    counter = 0;
    //return yyparse();
}

int yyerror(char *s) {
    printf("%s\n", s);
}

void scope_enter() {
    actualList = createList(counter, actualList);
    counter++;
}

void scope_exit() {
    deleteList(actualList);
    counter--;
}

char * type_to_str(int type) {
    switch(type) {
        case DATA_TYPE_NONE:
            return "none";
        break;
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
            return "Type not defined";
        break;
    }
}

int str_to_type(int type) {
    if (strcmp(type_to_str(type), "void") == 0) { 
        return DATA_TYPE_VOID; 
    } else if (strcmp(type_to_str(type), "int") == 0) { 
        return DATA_TYPE_INT; 
    } else if (strcmp(type_to_str(type), "float") == 0) {
        return DATA_TYPE_FLOAT;
    } else if (strcmp(type_to_str(type), "char") == 0) { 
        return DATA_TYPE_CHAR;
    } else {
        return DATA_TYPE_NONE; 
    }
}