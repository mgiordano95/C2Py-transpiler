%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyparse(void);
int yyerror(char *st);
int error_num = 0;

%}

%union {
    char *str;
    int num;
}

%token INT FLOAT VOID CHAR
%token IF ELSE FOR RETURN
%token<str> ID SCANF PRINTF
%left NOT AND OR
%left ADD SUB MUL DIV EQ
%left LT GT EE LE GE NE

%%

//qui vanno le definizioni della grammatica

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