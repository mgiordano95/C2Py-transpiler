%option yylineno
%option noyywrap

%x  MLCOMMENT
%x  SLCOMMENT
%x  QUOTE

%{
    #include <stdlib.h>
    #include <stdio.h>
%}


delim           [ \t]
ws              {delim}+
digit           [0-9]
int_number      ([+]?[0]+|([-+]?[0]+?[1-9][0-9]*))       
float_number    [-+]?([0-9]*\.?[0-9]+|[0-9]+\.)(E[+-]?{digit}+)?
letter          [a-zA-Z]
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

\"                          { BEGIN QUOTE; }
<QUOTE>([^"\\\n]|\\.)*      { printf("stringa accettata"); }
<QUOTE>\"                   { BEGIN INITIAL; }
<QUOTE>\n |  
<QUOTE><<EOF>>              {printf("errore");}     




"int"       {printf("keyword 'INT' detected"); }
"float"     {printf("keyword 'FLOAT' detected"); }
"void"      {printf("keyword 'VOID' detected"); }
"char"      {printf("keyword 'CHAR' detected"); }
"if"        {printf("keyword 'IF' detected"); }
"else"      {printf("keyword 'ELSE' detected"); }
"for"       {printf("keyword 'FOR' detected"); }
"printf"    {printf("keyword 'PRINTF' detected"); }
"scanf"     {printf("keyword 'SCANF' detected"); }
"return"    {printf("keyword 'RETURN' detected"); }

"+"        {printf("keyword '+' detected"); }
"-"        {printf("keyword '-' detected"); }
"*"        {printf("keyword '*' detected"); }
"/"        {printf("keyword '/' detected"); }
"="        {printf("keyword '=' detected"); }

"<"        {printf("keyword '<' detected"); }
">"        {printf("keyword '>' detected"); }
"=="       {printf("keyword '==' detected"); }
"<="       {printf("keyword '<=' detected"); }
">="       {printf("keyword '>=' detected"); }
"!="       {printf("keyword '!=' detected"); }

"!"       {printf("keyword '!' detected"); }
"&&"       {printf("keyword '&&' detected"); }
"||"       {printf("keyword '||' detected"); }

"(" |
")" |
"[" |
"]" |
"{" |
"}"         {printf("Found brackets");}

";"         {printf("Found semicolon");}
","         {printf("Found colon");}


{delim}             {printf("Found DELIM");}
{ws}                {printf("Found WHITE SPACE");}
{digit}             {printf("Found DIGIT");}
{int_number}        {printf("Found INTEGER NUMBER");}
{float_number}      {printf("Found FLOAT NUMBER");}
{letter}            {printf("Found LETTER\n");}
{id}                {printf("Found ID");}         
      


%%

main() {
    yylex();
    printf("stringa di prova");
    system("PAUSE");
    return 0;
}