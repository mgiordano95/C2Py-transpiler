%option yylineno
%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include "parser.tab.h"
    #include "ast.h"
%}


delim           [ \t]
ws              {delim}+
digit           [0-9]
letter          [a-zA-Z]
int_value       ([+]?[0]+|([-+]?[0]+?[1-9][0-9]*))       
float_value     [-+]?([0-9]*\.?[0-9]+|[0-9]+\.)(E[+-]?{digit}+)?
char_value      (\')({letter}|{digit})(\')
id              {letter}({letter}|{digit})*
string_value    \"[^\"]*\"

%x MLCOMMENT
%x SLCOMMENT
%x LIBRARY

%%

"/*"                        BEGIN(MLCOMMENT);   printf("found MULTI-LINE comment\n");
<MLCOMMENT>[^*\n]*          /* se non trovi asterisco vai avanti  */
<MLCOMMENT>"*"+[^*/n]*      /*  asterischi senza lo slash   */
<MLCOMMENT>\n               /* se vado a capo */
<MLCOMMENT>"*"+"/"          BEGIN(INITIAL);     printf("end of MULTI-LINE comment\n");

"//" 						BEGIN(SLCOMMENT);   printf("found SINGLE-LINE comment\n");
<SLCOMMENT>[^\n]* 			/* tutto tranne a capo */
<SLCOMMENT>\n 				BEGIN(INITIAL);     printf("end of SINGLE-LINE comment\n");

"#include"                  BEGIN(LIBRARY);     printf("found #include<library>\n");
<LIBRARY>^.*
<LIBRARY>[^\n]*
<LIBRARY>\n                 BEGIN(INITIAL);     printf("end of #include<library>\n");

"void"      {yylval.string=strdup(yytext); printf("keyword 'VOID' detected\n"); return(VOID);}
"int"       {yylval.string=strdup(yytext); printf("keyword 'INT' detected\n"); return(INT); }
"float"     {yylval.string=strdup(yytext); printf("keyword 'FLOAT' detected\n"); return(FLOAT);}
"char"      {yylval.string=strdup(yytext); printf("keyword 'CHAR' detected\n"); return(CHAR);}

"if"        {yylval.string=strdup(yytext); printf("keyword 'IF' detected\n"); return(IF);}
"else"      {yylval.string=strdup(yytext); printf("keyword 'ELSE' detected\n"); return(ELSE);}
"while"     {yylval.string=strdup(yytext); printf("keyword 'WHILE' detected\n"); return(WHILE);}
"printf"    {yylval.string=strdup(yytext); printf("keyword 'PRINTF' detected\n"); return(PRINTF);}
"scanf"     {yylval.string=strdup(yytext); printf("keyword 'SCANF' detected\n"); return(SCANF);}
"return"    {yylval.string=strdup(yytext); printf("keyword 'RETURN' detected\n"); return(RETURN);}
"main"      {yylval.string=strdup(yytext); printf("keyword 'MAIN' detected\n"); return(MAIN);}

"&"         {yylval.string=strdup(yytext); printf("Keywork '&' detected\n"); return(REFOP);}

"+"         {yylval.string=strdup(yytext); printf("keyword '+' detected\n"); return(ADD);}
"-"         {yylval.string=strdup(yytext); printf("keyword '-' detected\n"); return(SUB);}
"*"         {yylval.string=strdup(yytext); printf("keyword '*' detected\n"); return(MUL);}
"/"         {yylval.string=strdup(yytext); printf("keyword '/' detected\n"); return(DIV);}

"="         {yylval.string=strdup(yytext); printf("keyword '=' detected\n"); return(EQ);}

"=="        {yylval.string=strdup(yytext); printf("keyword '==' detected\n"); return(EE);}
"!="        {yylval.string=strdup(yytext); printf("keyword '!=' detected\n"); return(NE);}
">"         {yylval.string=strdup(yytext); printf("keyword '>' detected\n"); return(GT);}
"<"         {yylval.string=strdup(yytext); printf("keyword '<' detected\n"); return(LT);}
">="        {yylval.string=strdup(yytext); printf("keyword '>=' detected\n"); return(GE);}
"<="        {yylval.string=strdup(yytext); printf("keyword '<=' detected\n"); return(LE);}

"&&"        {yylval.string=strdup(yytext); printf("keyword '&&' detected\n"); return(AND);}
"||"        {yylval.string=strdup(yytext); printf("keyword '||' detected\n"); return(OR);}
"!"         {yylval.string=strdup(yytext); printf("keyword '!' detected\n"); return(NOT);}

"("         {yylval.string=strdup(yytext); printf("keyword '(' detected\n"); return(LPAR);}
")"         {yylval.string=strdup(yytext); printf("keyword ')' detected\n"); return(RPAR);}
"["         {yylval.string=strdup(yytext); printf("keyword '[' detected\n"); return(LSBRA);}
"]"         {yylval.string=strdup(yytext); printf("keyword ']' detected\n"); return(RSBRA);}
"{"         {yylval.string=strdup(yytext); printf("keyword '{' detected\n"); return(LBRA);}
"}"         {yylval.string=strdup(yytext); printf("keyword '}' detected\n"); return(RBRA);}

";"         {yylval.string=strdup(yytext); printf("Found SEMICOLON\n"); return(SEMICOL);}
","         {yylval.string=strdup(yytext); printf("Found COMMA\n"); return(COMMA);}

"\n"        {}

{delim}             {printf("Found DELIM\n");}
{ws}                {printf("Found WHITE SPACE\n");}
{int_value}         {yylval.string=strdup(yytext); printf("Found INTEGER NUMBER\n"); return(INT_VALUE);}
{float_value}       {yylval.string=strdup(yytext); printf("Found FLOAT NUMBER\n"); return(FLOAT_VALUE);}
{id}                {yylval.string=strdup(yytext); printf("Found ID\n"); return(ID);}
{char_value}        {yylval.string=strdup(yytext); printf("Found CHAR\n"); return(CHAR_VALUE);}
{string_value}      {yylval.string=strdup(yytext); printf("Found STRING\n"); return(STRING_VALUE);}
.                   {printf("Unknown character\n"); return(UNKNOWN);}

%%