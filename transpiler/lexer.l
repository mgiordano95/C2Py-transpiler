

%x  MLCOMMENT
%x  SLCOMMENT
%x  QUOTE

%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "parser.tab.h"
%}


delim           [ \t]
ws              {delim}+
digit           [0-9]
letter          [a-zA-Z]
int_value       ([+]?[0]+|([-+]?[0]+?[1-9][0-9]*))       
float_value     [-+]?([0-9]*\.?[0-9]+|[0-9]+\.)(E[+-]?{digit}+)?
char_value      {letter}|{digit}
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

"+"         {printf("keyword '+' detected\n"); return(ADD);}
"-"         {printf("keyword '-' detected\n"); return(SUB);}
"*"         {printf("keyword '*' detected\n"); return(MUL);}
"/"         {printf("keyword '/' detected\n"); return(DIV);}

"="         {printf("keyword '=' detected\n"); return(EQ);}

"=="        {printf("keyword '==' detected\n"); return(EE);}
"!="        {printf("keyword '!=' detected\n"); return(NE);}
">"         {printf("keyword '>' detected\n"); return(GT);}
"<"         {printf("keyword '<' detected\n"); return(LT);}
">="        {printf("keyword '>=' detected\n"); return(GE);}
"<="        {printf("keyword '<=' detected\n"); return(LE);}

"&&"        {printf("keyword '&&' detected\n"); return(AND);}
"||"        {printf("keyword '||' detected\n"); return(OR);}
"!"         {printf("keyword '!' detected\n"); return(NOT);}

"("         {printf("keyword '(' detexted\n"); return(LPAR);}
")"         {printf("keyword ')' detexted\n"); return(RPAR);}
"["         {printf("keyword '[' detexted\n"); return(LSBRA);}
"]"         {printf("keyword ']' detexted\n"); return(RSBRA);}
"{"         {printf("keyword '{' detexted\n"); return(LBRA);}
"}"         {printf("keyword '}' detexted\n"); return(RBRA);}

";"         {printf("Found semicolon\n"); return(SEMICOL);}
","         {printf("Found comma\n"); return(COMMA);}

{delim}             {printf("Found DELIM\n");}
{ws}                {printf("Found WHITE SPACE\n");}
{id}                {printf("Found ID\n"); return(ID);}
{int_value}         {printf("Found INTEGER NUMBER\n"); return(INT_VALUE);}
{float_value}       {printf("Found FLOAT NUMBER\n"); return(FLOAT_VALUE);}
{char_value}        {printf("Found CHAR\n"); return(CHAR_VALUE);}
{digit}             {printf("Found DIGIT\n");}

[ \t\n\f]           { }

%%