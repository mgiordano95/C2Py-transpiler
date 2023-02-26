%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ast.h"

int yyerror(char *s);
int yylex(void);

struct AST_NODE_STATEMENTS *root;

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

%type <string> types ID SEMICOL INT_VALUE FLOAT_VALUE CHAR_VALUE EQ ADD
%type <statements> program statements 
%type <instruction> instruction 
%type <init> initialization
%type <assign> assignment
%type <operand> content
%type <expression> expression


%start program

%%

program:    
statements                      { root = $1; };

statements: 
instruction statements          {   
                                    $$ = malloc(sizeof(struct AST_NODE_STATEMENTS));
                                    $$->node_type = STATEMENT_NODE;
                                    $$->current_instruction = $1;
                                    $$->next_statement = $2;
                                }
|   instruction                 {
                                    $$ = malloc(sizeof(struct AST_NODE_STATEMENTS));
                                    $$->node_type = STATEMENT_NODE;
                                    $$->current_instruction = $1;
                                    $$->next_statement = NULL;
                                };


instruction:
initialization SEMICOL          {
                                    $$ = malloc(sizeof(struct AST_NODE_INSTRUCTION));
                                    $$->node_type = INIT_NODE;
                                    $$->value.init = $1;
                                }
|   assignment SEMICOL          {
                                    $$ = malloc(sizeof(struct AST_NODE_INSTRUCTION));
                                    $$->node_type = ASSIGN_NODE;
                                    $$->value.assign = $1;
                                };

initialization:
types ID                        {
                                    $$ = malloc(sizeof(struct AST_NODE_INIT)); printf("AST_NODE_INIT allocated\n");
                                    $$->data_type = str_to_type($1);
                                    $$->assign = malloc(sizeof(struct AST_NODE_ASSIGN)); printf("AST_NODE_ASSIGN allocated\n");
                                    $$->assign->variable_name = $2;
                                    $$->assign->variable_type = str_to_type($1); printf("assegnato variable type\n");
                                    $$->assign->assign_value.val = NULL;   
                                    $$->assign->assign_type = CONTENT_TYPE_ID;  
                                };

assignment:                     
types ID EQ content             {   
                                    $$ = malloc(sizeof(struct AST_NODE_ASSIGN)); printf("AST_NODE_ASSIGN allocated\n");
                                    $$->variable_name = $2;
                                    $$->variable_type = str_to_type($1);
                                    $$->assign_value.val = $4->value.val; 
                                    $$->assign_type = $4->content_type;
                                }
|   types ID EQ expression      {   
                                    $$ = malloc(sizeof(struct AST_NODE_ASSIGN)); printf("AST_NODE_ASSIGN allocated\n");
                                    $$->variable_name = $2;
                                    $$->variable_type = str_to_type($1);
                                    $$->assign_value.expression = $4;
                                    $$->assign_type = CONTENT_TYPE_EXPRESSION;
                                    if ($$->variable_type != $$->assign_value.expression->expr_type)
                                        { printf("Impossibile assegnare espressione a tipo diverso \n"); }
                                };  

    
expression:
content ADD content             {
                                    $$ = malloc(sizeof(struct AST_NODE_EXPRESSION));
                                    $$->left_oper = malloc(sizeof(struct AST_NODE_OPERAND));
                                    $$->right_oper = malloc(sizeof(struct AST_NODE_OPERAND)); 
                                    $$->left_oper = $1;   
                                    $$->op = $2;  
                                    $$->left_oper = $3; 
                                    $$->expr_type = $1->value_type;    
                                    if  ($1->value_type == DATA_TYPE_CHAR || $3->value_type == DATA_TYPE_CHAR)
                                        { printf("\n Errore! Impossibile sommare tipi char"); }
                                    else if  ($1->value_type == DATA_TYPE_VOID || $3->value_type == DATA_TYPE_VOID)
                                        { printf("\n Errore! Impossibile sommare tipi void"); }  
                                    else if ($1->value_type != $3->value_type)
                                        { printf("\n Errore! Impossibile sommare tipi diversi"); }   
                                    else 
                                        {
                                            printf("Expression di tipo somma \n");
                                        }                
                                };

content:
ID                              {
                                    $$ = malloc(sizeof(struct AST_NODE_OPERAND)); printf("Ci troviamo nel caso in cui abbiamo int a = b\n");
                                    $$->value.val = $1;
                                    $$->value_type = DATA_TYPE_VOID;
                                    $$->content_type = CONTENT_TYPE_ID;
                                }
|   INT_VALUE                   {       
                                    $$ = malloc(sizeof(struct AST_NODE_OPERAND)); printf("Il tipo e' int\n");
                                    $$->value.val = $1;
                                    $$->value_type = DATA_TYPE_INT; 
                                    $$->content_type = CONTENT_TYPE_INT_NUMBER;
                                }
|   FLOAT_VALUE                 {
                                    $$ = malloc(sizeof(struct AST_NODE_OPERAND)); printf("Il tipo e' float\n");
                                    $$->value.val = $1;
                                    $$->value_type = DATA_TYPE_FLOAT; 
                                    $$->content_type = CONTENT_TYPE_FLOAT_NUMBER;
                                }
|   CHAR_VALUE                  {
                                    $$ = malloc(sizeof(struct AST_NODE_OPERAND)); printf("Il tipo e' char\n");
                                    $$->value.val = $1;
                                    $$->value_type = DATA_TYPE_CHAR;  
                                    $$->content_type = CONTENT_TYPE_CHAR;
                                };

types:
    VOID                        {$$ = DATA_TYPE_VOID; }
|   INT                         {$$ = DATA_TYPE_INT; }
|   FLOAT                       {$$ = DATA_TYPE_FLOAT; }
|   CHAR                        {$$ = DATA_TYPE_CHAR; };

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

