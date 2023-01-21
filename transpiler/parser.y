%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

int yylex(void);
int yyparse(void);
int yyerror(char *st);
int error_num = 0;

%}

%union  {
    char *str;
    int num;
}

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

%type<AST_NODE_INSTRUCTION> statements

%%

  program:   { scope_enter(); }    statements    { root = $2; scope_exit(); };
  types:
              INT       { $$ = DATA_TYPE_INT; }
          |   FLOAT     { $$ = DATA_TYPE_INT; }
          |   CHAR      { $$ = DATA_TYPE_CHAR; }

%%


int yylex (void) {
  int c;
  while ((c = getchar ()) == ' ' || c == '\t' || c == '\n');
  if (c == '.' || isdigit (c)) {
    ungetc (c, stdin);
    scanf ("%lf", &yylval);
    return VAL;
  }
  if (c == EOF)
    return 0;
  return c;
}

int yyerror(char *st) { printf("\n\n\t***Error: %s***\n\t***Line: %d***\n\n\n",st,yylineno); error_num++;}


int main {
    yyparse();
}

//Conversione type to string
char * type_to_str(int type) {
    switch (type) {
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
        break;
        default:
            return "Type not defined";
        break;
    }
}

// Conversione string to type
int str_to_type (int type) {
    if      (strcmp(type_to_str(type), "void") == 0)  	{ return DATA_TYPE_VOID; }         
    else if (strcmp(type_to_str(type), "int") == 0)  	{ return DATA_TYPE_INT; }
    else if (strcmp(type_to_str(type), "float") == 0)   { return DATA_TYPE_FLOAT; }
    else if (strcmp(type_to_str(type), "char") == 0)    { return DATA_TYPE_CHAR; }
    else                                                { return DATA_TYPE_NONE; }
}