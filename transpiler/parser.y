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

%type<string> types
%type<statements> program statements 
%type<instruction> instruction 
%type<init> initialization
%type<assign> assignment
%type<expression> expression
%type<operand>
%type<functionDecl> function_decl
%type<funcionCall> function_call
%type<functionParams>
%type<body> body

%start program

%%

    program:    statements

    statements: 
                instruction statements          {   
                                                    $$ = malloc(sizeof(struct AST_Node_Statements));
                                                    $->n_type = STATEMENT_NODE;
                                                    $$->left = $1;
                                                    $$->right = $2;
                                                }
            |   instruction                     {

                                                };


    instruction:
                initialization SEMICOL          {
                                                }
            |   assignment SEMICOL              {
                                                }
            |   function_decl                   {

                                                }
            |   function_call SEMICOL           {

                                                };


                                                

    


%%

int yyerror(char *s) {
    printf("%s\n", s);
}

int main(void) {
    return yyparse();
}