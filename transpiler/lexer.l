%x  MLCOMMENT
%x  SLCOMMENT
%x  QUOTE

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



%%

"/*"                        BEGIN(MLCOMMENT);   printf("found ML comment\n");
<MLCOMMENT>[^*\n]*          { } /* se non trovi asterisco vai avanti  */
<MLCOMMENT>"*"+[^*/n]*      { } /*  asterischi senza lo slash   */
<MLCOMMENT>\n               { } /* se vado a capo */
<MLCOMMENT>"*"+"/"          BEGIN(INITIAL);     printf("end of ML comment\n");

"//" 						BEGIN(SLCOMMENT);   printf("found SL comment\n");
<SLCOMMENT>[^\n]* 			/* tutto tranne a capo */
<SLCOMMENT>\n 				BEGIN(INITIAL);     printf("end of SL comment\n");

\"\"                        {printf("found quotes "); }

\"                          BEGIN(QUOTE); printf("found quote\n");
<QUOTE>([^"\\\n]|\\.)*      { printf("stringa accettata\n"); }
<QUOTE>\"                   BEGIN(INITIAL); printf("end quote\n");
<QUOTE>\n |  
<QUOTE><<EOF>>              {printf("errore\n");}


"void"      {printf("keyword 'VOID' detected\n"); return(VOID);}
"int"       {printf("keyword 'INT' detected\n"); return(INT); }
"float"     {printf("keyword 'FLOAT' detected\n"); return(FLOAT);}
"char"      {printf("keyword 'CHAR' detected\n"); return(CHAR);}

"if"        {printf("keyword 'IF' detected\n"); return(IF);}
"else"      {printf("keyword 'ELSE' detected\n"); return(ELSE);}
"while"     {printf("keyword 'WHILE' detected\n"); return(WHILE);}
"printf"    {printf("keyword 'PRINTF' detected\n"); return(PRINTF);}
"scanf"     {printf("keyword 'SCANF' detected\n"); return(SCANF);}
"return"    {printf("keyword 'RETURN' detected\n"); return(RETURN);}
"main"      {printf("keyword 'MAIN' detected\n"); return(MAIN);}

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

"("         {yylval.string=strdup(yytext); printf("keyword '(' detexted\n"); return(LPAR);}
")"         {yylval.string=strdup(yytext); printf("keyword ')' detexted\n"); return(RPAR);}
"["         {yylval.string=strdup(yytext); printf("keyword '[' detexted\n"); return(LSBRA);}
"]"         {yylval.string=strdup(yytext); printf("keyword ']' detexted\n"); return(RSBRA);}
"{"         {yylval.string=strdup(yytext); printf("keyword '{' detexted\n"); return(LBRA);}
"}"         {yylval.string=strdup(yytext); printf("keyword '}' detexted\n"); return(RBRA);}

";"         {yylval.string=strdup(yytext); printf("Found semicolon\n"); return(SEMICOL);}
","         {yylval.string=strdup(yytext); printf("Found comma\n"); return(COMMA);}

{delim}             {printf("Found DELIM\n");}
{ws}                {printf("Found WHITE SPACE\n");}
{int_value}         {yylval.string=strdup(yytext); printf("Found INTEGER NUMBER\n"); return(INT_VALUE);}
{float_value}       {yylval.string=strdup(yytext); printf("Found FLOAT NUMBER\n"); return(FLOAT_VALUE);}
{id}                {yylval.string=strdup(yytext); printf("Found ID\n"); return(ID);}
{char_value}        {yylval.string=strdup(yytext); printf("Found CHAR\n"); return(CHAR_VALUE);}

.                   {printf("Unknown character\n"); return(UNKNOWN)}

%%