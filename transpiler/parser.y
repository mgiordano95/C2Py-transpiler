%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ast.h"

int yyerror(char *s);
int yylex();


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

%type<statements> statements

%%

  program:   { printf("ciao"); }    statements    { printf("ciao"); };
  statements:   {printf("ciao");}
%%

int yyerror(char *s) {
    printf("%s\n", s);
}

int main(void) {
    return yyparse();
}