%option yylineno
%option noyywrap

%x  MLCOMMENT
%x  SLCOMMENT

%{
    #include <stdlib.h>
    #include <stdio.h>
%}


delim           [ \t]
ws              {delim}+
digit           [0-9]
int_number      [0]+|-?[0]+[1-9][0-9]*     
float_number    [-+]?([0-9]*\.?[0-9]+|[0-9]+\.)(E[+-]?{digit}+)?
letter          [a-zA-Z]
id              {letter}({letter}|{digit})*


%%

"/*"                        BEGIN(MLCOMMENT);
<MLCOMMENT>[^*\n]*          { } /* se non trovi asterisco vai avanti  */
<MLCOMMENT>"*"+[^*/n]*      { } /*  asterischi senza lo slash   */
<MLCOMMENT>\n               { } /* se vado a capo */
<MLCOMMENT>"*"+"/"          BEGIN(INITIAL);

"//" 						BEGIN(SLCOMMENT);
<SLCOMMENT>[^\n]* 			/* tutto tranne a capo */
<SLCOMMENT>\n 				BEGIN(INITIAL);



"int"       {printf("keyword 'INT' detected"); return(INT); }
"float"     {printf("keyword 'FLOAT' detected"); return(FLOAT);}
"void"      {printf("keyword 'VOID' detected"); return(VOID);}
"char"      {printf("keyword 'CHAR' detected"); return(CHAR);}
"if"        {printf("keyword 'IF' detected"); return(IF);}
"else"      {printf("keyword 'ELSE' detected"); return(ELSE);}
"for"       {printf("keyword 'FOR' detected"); return(FOR);}
"printf"    {printf("keyword 'PRINTF' detected"); return(PRINTF);}
"scanf"     {printf("keyword 'SCANF' detected"); return(SCANF);}
"return"    {printf("keyword 'RETURN' detected"); return(RETURN);}

"+"        {printf("keyword '+' detected"); return(ADD);}
"-"        {printf("keyword '-' detected"); return(SUB);}
"*"        {printf("keyword '*' detected"); return(MUL);}
"/"        {printf("keyword '/' detected"); return(DIV);}
"="        {printf("keyword '=' detected"); return(EQ);}

"<"        {printf("keyword '<' detected"); return(LT);}
">"        {printf("keyword '>' detected"); return(GT);}
"=="       {printf("keyword '==' detected"); return(EE);}
"<="       {printf("keyword '<=' detected"); return(LE);}
">="       {printf("keyword '>=' detected"); return(GE);}
"!="       {printf("keyword '!=' detected"); return(NE);}

"!"       {printf("keyword '!' detected"); return(NOT);}
"&&"       {printf("keyword '&&' detected"); return(AND);}
"||"       {printf("keyword '||' detected"); return(OR);}


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