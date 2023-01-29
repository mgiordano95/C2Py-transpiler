

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

"/*"                        BEGIN(MLCOMMENT);   printf("found ML comment");
<MLCOMMENT>[^*\n]*          { } /* se non trovi asterisco vai avanti  */
<MLCOMMENT>"*"+[^*/n]*      { } /*  asterischi senza lo slash   */
<MLCOMMENT>\n               { } /* se vado a capo */
<MLCOMMENT>"*"+"/"          BEGIN(INITIAL);     printf("end of ML comment");

"//" 						BEGIN(SLCOMMENT);   printf("found SL comment");
<SLCOMMENT>[^\n]* 			/* tutto tranne a capo */
<SLCOMMENT>\n 				BEGIN(INITIAL);     printf("end of SL comment");

\"\"                        {printf("found quotes "); }

\"                          BEGIN(QUOTE); printf("found quote");
<QUOTE>([^"\\\n]|\\.)*      { printf("stringa accettata"); }
<QUOTE>\"                   BEGIN(INITIAL); printf("end quote");
<QUOTE>\n |  
<QUOTE><<EOF>>              {printf("errore");}     




"void"      {printf("keyword 'VOID' detected"); return(VOID);}
"int"       {printf("keyword 'INT' detected"); return(INT); }
"float"     {printf("keyword 'FLOAT' detected"); return(FLOAT);}
"char"      {printf("keyword 'CHAR' detected"); return(CHAR);}
"if"        {printf("keyword 'IF' detected"); return(IF);}
"else"      {printf("keyword 'ELSE' detected"); return(ELSE);}
"while"     {printf("keyword 'WHILE' detected"); return(WHILE);}
"printf"    {printf("keyword 'PRINTF' detected"); return(PRINTF);}
"scanf"     {printf("keyword 'SCANF' detected"); return(SCANF);}
"return"    {printf("keyword 'RETURN' detected"); return(RETURN);}

"+"         {printf("keyword '+' detected"); return(ADD);}
"-"         {printf("keyword '-' detected"); return(SUB);}
"*"         {printf("keyword '*' detected"); return(MUL);}
"/"         {printf("keyword '/' detected"); return(DIV);}

"="         {printf("keyword '=' detected"); return(EQ);}

"=="        {printf("keyword '==' detected"); return(EE);}
"!="        {printf("keyword '!=' detected"); return(NE);}
">"         {printf("keyword '>' detected"); return(GT);}
"<"         {printf("keyword '<' detected"); return(LT);}
">="        {printf("keyword '>=' detected"); return(GE);}
"<="        {printf("keyword '<=' detected"); return(LE);}

"&&"        {printf("keyword '&&' detected"); return(AND);}
"||"        {printf("keyword '||' detected"); return(OR);}
"!"         {printf("keyword '!' detected"); return(NOT);}

"("         {printf("keyword '(' detexted"); return(LPAR);}
")"         {printf("keyword ')' detexted"); return(RPAR);}
"["         {printf("keyword '[' detexted"); return(LSBRA);}
"]"         {printf("keyword ']' detexted"); return(RSBRA);}
"{"         {printf("keyword '{' detexted"); return(LBRA);}
"}"         {printf("keyword '}' detexted"); return(RBRA);}

";"         {printf("Found semicolon"); return(SEMICOL);}
","         {printf("Found comma"); return(COMMA);}


{delim}             {printf("Found DELIM");}
{ws}                {printf("Found WHITE SPACE");}
{digit}             {printf("Found DIGIT");}
{int_value}         {printf("Found INTEGER NUMBER"); return(INT_VALUE);}
{float_value}       {printf("Found FLOAT NUMBER"); return(FLOAT_VALUE);}
{id}                {printf("Found ID"); return(ID);}    
{char_value}        {printf("Found CHAR"); return(CHAR_VALUE);}
     

[ \t\n\f]           { }

%%