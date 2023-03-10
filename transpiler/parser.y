%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ast.h"
#include "symboltable.h"

int yyerror(char *s);
int yylex(void);

struct AstNodeStatements *root;
struct List *actualList = NULL;  

%}

%code requires{
    #include "ast.h"
}

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
%token LPAR RPAR LSBRA RSBRA LBRA RBRA
%token SEMICOL
%token COMMA 
%token INT_VALUE 
%token FLOAT_VALUE
%token CHAR_VALUE
%token ID 


/* NON_TERMINAL TYPES */
%define api.value.type {union yystype}

%type <string> types ID SEMICOL INT_VALUE FLOAT_VALUE CHAR_VALUE EQ ADD SUB MUL DIV EE NE GT LT GE LE AND OR NOT RETURN LBRA RBRA LPAR RPAR
%type <statements> program statements 
%type <instruction> instruction 
%type <init> initialization
%type <assign> assignment
%type <operand> content
%type <expression> expression
%type <body> body
%type <functionDecl> functionDecl
%type <functionCall> functionCall

        
%start program

%%

program:    
statements                      { root = $1; };

statements: 
instruction statements          {   
                                    $$ = malloc(sizeof(struct AstNodeStatements));
                                    $$->nodeType = STATEMENT_NODE;
                                    $$->currentInstruction = $1;
                                    $$->nextStatement = $2;
                                }
|   instruction                 {
                                    $$ = malloc(sizeof(struct AstNodeStatements));
                                    $$->nodeType = STATEMENT_NODE;
                                    $$->currentInstruction = $1;
                                    $$->nextStatement = NULL;
                                };

instruction:
initialization SEMICOL          {
                                    $$ = malloc(sizeof(struct AstNodeInstruction));
                                    $$->nodeType = INIT_NODE;
                                    $$->value.init = $1;
                                }
|   assignment SEMICOL          {
                                    $$ = malloc(sizeof(struct AstNodeInstruction));
                                    $$->nodeType = ASSIGN_NODE;
                                    $$->value.assign = $1;
                                }
|   functionDecl SEMICOL        {
                                    $$ = malloc(sizeof(struct AstNodeInstruction));
                                    $$->nodeType = FUNCTION_DECL_NODE;
                                    $$->value.functionDecl = $1;
                                }
|   functionCall SEMICOL        {
                                    $$ = malloc(sizeof(struct AstNodeInstruction));
                                    $$->nodeType = FUNCTION_CALL_NODE;
                                    $$->value.functionCall = $1;
                                };

functionDecl:
initialization LPAR RPAR body   {
                                    $$ = malloc(sizeof(struct AstNodeFunctionDecl));
                                    printf("Nodo functionDecl dichiarato \n");
                                    $$->functionName = $1->assign->variableName;
                                    $$->returnType = $1->dataType;
                                    printf("Assegnato returnType \n");
                                    $$->functionParams = NULL;
                                    $$->functiontBody = $4;
                                    printf("Montato function body \n");
                                };

functionCall:
ID LPAR RPAR                    {
                                    $$ = malloc(sizeof(struct AstNodeFunctionCall));
                                    printf("Nodo Function Call \n");
                                    $$->functionName = $1;
                                    $$->returnType = DATA_TYPE_INT;
                                    $$->functionParams = NULL; 
                                }

body:
LBRA statements RBRA                            {
                                                    $$ = malloc(sizeof(struct AstNodeBody));
                                                    printf("Espando Body \n");
                                                    $$->bodyStatements = $2;
                                                    $$->returnValue = NULL;
                                                }
| LBRA statements RETURN content SEMICOL RBRA   {
                                                    $$ = malloc(sizeof(struct AstNodeBody));
                                                    $$->bodyStatements = $2;
                                                    $$->returnValue = $4;
                                                };

initialization:
types ID                        {
                                    $$ = malloc(sizeof(struct AstNodeInit));
                                    printf("AstNodeInit allocated\n");
                                    $$->dataType = str_to_type($1);
                                    $$->assign = malloc(sizeof(struct AstNodeAssign));
                                    printf("AstNodeAssign allocated\n");
                                    $$->assign->variableName = $2;
                                    $$->assign->variableType = str_to_type($1);
                                    printf("assegnato variable type\n");
                                    $$->assign->assignValue.val = NULL;   
                                    $$->assign->assignType = CONTENT_TYPE_ID;  
                                };

assignment:                     
types ID EQ content             {   
                                    struct SymTab *s = NULL;  //sar?? diverso da NULL solo se trova il simbolo
                                    s = findSymtab(actualList, $2);  //controlla se il simbolo ?? stato gi?? dichiarato
                                    if (s==NULL) {
                                        s = createSym($2, actualList, SYMBOL_VARIABLE, str_to_type($1), str_to_type($1), null, $4->value );
                                    }
                                    $$ = malloc(sizeof(struct AstNodeAssign));
                                    printf("AstNodeAssign allocated\n");
                                    $$->variableName = $2;
                                    $$->variableType = str_to_type($1);
                                    $$->assignValue.val = $4->value.val; 
                                    $$->assignType = $4->contentType;
                                }
|   types ID EQ expression      {   
                                    $$ = malloc(sizeof(struct AstNodeAssign));
                                    printf("AstNodeAssign allocated\n");
                                    $$->variableName = $2;
                                    $$->variableType = str_to_type($1);
                                    $$->assignValue.expression = $4;
                                    $$->assignType = CONTENT_TYPE_EXPRESSION;
                                    if ($$->variableType != $$->assignValue.expression->exprType) {
                                        printf("Impossibile assegnare espressione a tipo diverso \n");
                                    }
                                }; 

expression:
content ADD content             {
                                    $$ = malloc(sizeof(struct AstNodeExpression));
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
|   content SUB content         {
                                    $$ = malloc(sizeof(struct AstNodeExpression));
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
|   content MUL content         {
                                    $$ = malloc(sizeof(struct AstNodeExpression));
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
|   content DIV content         {
                                    $$ = malloc(sizeof(struct AstNodeExpression));
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
|   content EE content          {
                                    $$ = malloc(sizeof(struct AstNodeExpression));
                                    $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                    $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                    $$->leftOper = $1;
                                    $$->op = $2;
                                    $$->rightOper = $3;
                                    $$->exprType = DATA_TYPE_INT;
                                    printf("Expression di tipo Equal to \n");
                                }
|   content NE content          {
                                    $$ = malloc(sizeof(struct AstNodeExpression));
                                    $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                    $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                    $$->leftOper = $1;
                                    $$->op = $2;
                                    $$->rightOper = $3;
                                    $$->exprType = DATA_TYPE_INT;
                                    printf("Expression di tipo Not Equal \n");
                                }
|   content GT content          {
                                    $$ = malloc(sizeof(struct AstNodeExpression));
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
|   content LT content          {
                                    $$ = malloc(sizeof(struct AstNodeExpression));
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
|   content GE content          {
                                    $$ = malloc(sizeof(struct AstNodeExpression));
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
|   content LE content          {
                                    $$ = malloc(sizeof(struct AstNodeExpression));
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
|   content AND content         {
                                    $$ = malloc(sizeof(struct AstNodeExpression));
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
|   content OR content          {
                                    $$ = malloc(sizeof(struct AstNodeExpression));
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
|   NOT content                 {
                                    $$ = malloc(sizeof(struct AstNodeExpression));
                                    $$->leftOper = malloc(sizeof(struct AstNodeOperand));
                                    $$->rightOper = malloc(sizeof(struct AstNodeOperand));
                                    $$->op = $1;
                                    $$->leftOper = $2;
                                    $$->rightOper = NULL;
                                    $$->exprType = DATA_TYPE_INT;
                                    if  ($1->valueType == DATA_TYPE_CHAR || $3->valueType == DATA_TYPE_CHAR) {
                                        printf("\n Errore! Impossibile confrontare variabili di tipo char");
                                    } else if  ($1->valueType == DATA_TYPE_VOID || $3->valueType == DATA_TYPE_VOID) { 
                                        printf("\n Errore! Impossibile confrontare variabili di tipo void");
                                    } else {
                                        printf("Expression di tipo NOT \n");
                                    }
                                }; 

content:
ID                              {
                                    $$ = malloc(sizeof(struct AstNodeOperand)); 
                                    printf("Ci troviamo nel caso in cui abbiamo int a = b\n");
                                    struct SymTab *s = findSymtab(actualTable, $1);
                                    if(s==NULL) { $$->}
                                    $$->value.val = $1;
                                    $$->valueType = DATA_TYPE_VOID;
                                    $$->contentType = CONTENT_TYPE_ID;
                                }
|   INT_VALUE                   {       
                                    $$ = malloc(sizeof(struct AstNodeOperand));
                                    printf("Il tipo e' int\n");
                                    $$->value.val = $1;
                                    $$->valueType = DATA_TYPE_INT; 
                                    $$->contentType = CONTENT_TYPE_INT_NUMBER;
                                }
|   FLOAT_VALUE                 {
                                    $$ = malloc(sizeof(struct AstNodeOperand));
                                    printf("Il tipo e' float\n");
                                    $$->value.val = $1;
                                    $$->valueType = DATA_TYPE_FLOAT; 
                                    $$->contentType = CONTENT_TYPE_FLOAT_NUMBER;
                                }
|   CHAR_VALUE                  {
                                    $$ = malloc(sizeof(struct AstNodeOperand));
                                    printf("Il tipo e' char\n");
                                    $$->value.val = $1;
                                    $$->valueType = DATA_TYPE_CHAR;  
                                    $$->contentType = CONTENT_TYPE_CHAR;
                                };

types:
    VOID                        {
                                    $$ = DATA_TYPE_VOID;
                                }
|   INT                         {
                                    $$ = DATA_TYPE_INT;
                                }
|   FLOAT                       {
                                    $$ = DATA_TYPE_FLOAT;
                                }
|   CHAR                        {
                                    $$ = DATA_TYPE_CHAR;
                                };

%%

int yyerror(char *s) {
    printf("%s\n", s);
}

int main(void) {
    return yyparse();
}


char * type_to_str(int  type) {
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
            return "Type not defined";
        break;
    }
}


int str_to_type(int type) {
    if      (strcmp(type_to_str(type), "void") == 0)   { return DATA_TYPE_VOID; }
    else if (strcmp(type_to_str(type), "int") == 0)    { return DATA_TYPE_INT; }
    else if (strcmp(type_to_str(type), "float") == 0)  { return DATA_TYPE_FLOAT; }
    else if (strcmp(type_to_str(type), "char") == 0)   { return DATA_TYPE_CHAR; }
}