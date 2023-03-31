#ifndef AST_H
#define AST_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum SymbolType {
    SYMBOL_VARIABLE,
    SYMBOL_CONTENT,
    SYMBOL_FUNCTION,
    SYMBOL_PARAMETER,
};

enum DataType {
    DATA_TYPE_VOID,
    DATA_TYPE_INT,
    DATA_TYPE_FLOAT,
    DATA_TYPE_CHAR,
    DATA_TYPE_NONE,
};

enum ContentType {
    CONTENT_TYPE_ID,
    CONTENT_TYPE_INT_NUMBER,
    CONTENT_TYPE_FLOAT_NUMBER,
    CONTENT_TYPE_CHAR,
    CONTENT_TYPE_EXPRESSION,
    CONTENT_TYPE_FUNCTION,
};

enum NodeType {
    STATEMENT_NODE,
    INIT_NODE,
    ASSIGN_NODE,
    ARRAY_INIT_NODE,
    ARRAY_ASSIGN_NODE,
    FUNCTION_DECL_NODE,
    FUNCTION_CALL_NODE,
    IF_NODE,
    ELSE_IF_NODE,
    ELSE_NODE,
    WHILE_NODE,
};

union yystype {
    char *string;
    struct AstNodeStatements          *statements;
    struct AstNodeInstruction         *instruction;
    struct AstNodeInit                *init;
    struct AstNodeAssign              *assign;
    struct AstNodeExpression          *expression;
    struct AstNodeOperand             *operand;
    struct AstNodeArrayInit           *arrayInit;
    struct AstNodeArrayAssign         *arrayAssign;
    struct AstNodeArrayElements       *arrayElements;
    struct AstNodeFunctionDecl        *functionDecl;
    struct AstNodeFunctionCall        *functionCall;
    struct AstNodeFunctionParams      *functionParams;
    struct AstNodeBody                *body;
    struct AstNodeIf                  *ifStatement;
    struct AstNodeElseIf              *elseifStatement;
    struct AstNodeElse                *elseStatement;
    struct AstNodeWhile               *whileLoop;
    /* struct AstNodeFunctionInput       *inputFunction;
    struct AstNodeFunctionOutput      *outputFunction; */
    /* struct AstNodeValue               *value;
    struct AstNodeVariable            *variable; */
    
};

/*--------------- Other Types ---------------*/
typedef union ValueOper {
    char *val;
    struct AstNodeExpression *expression;
    struct AstNodeFunctionCall *funtionCall;
}ValueOper;

static union ValueOper nullValue;

struct AstNodeStatements {
    enum NodeType nodeType; //questa può essere uguale solo a NodeType.STATEMENT_NODE
    struct AstNodeInstruction *currentInstruction; //puntatore all'instruction corrente
    struct AstNodeStatements *nextStatement; //puntato allo statmenent successivo
};

struct AstNodeInstruction {
    enum NodeType nodeType; //tipo dell'instruction
    union yystype value; /*puntatore alla struct dell'instruction $1 -> value.init, $1 -> value.functionDecl
    usare gli stessi nomi dei puntatori definiti in camelCase a riga 55*/
};


/*--------------- Node Initialization ---------------*/

//int a = 3;
struct AstNodeInit {
    enum DataType dataType; 
    struct AstNodeAssign *assign;
    struct AstNodeInit *nextInit;  //serivra' per controllo che non siano state inizializzate 2 variabili 
    // con lo stesso nome
};

/*--------------- Node Assignment ---------------*/
//a = 5;
struct AstNodeAssign {
    char *variableName; 
    enum DataType variableType; //valueType serve per il check del type del Content/ID ed è il tipo prima di uguale
    union ValueOper assignValue; //Valore vero e proprio dopo uguale
    enum ContentType assignType; //Contenuto (int func expr) che c'è dopo l'uguale
    //int a -> CONTENT_TYPE_ID indica che e' solo un ID senza assegnazione
    //int main() -> CONTENT_TYPE_FUNCTION
};

/*--------------- Node Expression ---------------*/
/* 
a+b
7-3
a*2
d/3
a + 5 > 6
i + 1 < 8
*/
struct AstNodeExpression {
    enum DataType exprType;  //tipo dato restituito dall'espressione (void, int float, char)
    char *op; // op è $2 e può essere +, -, *, /, >, < ...
    struct AstNodeOperand *leftOper;
    struct AstNodeOperand *rightOper; 
};

/*--------------- Node Operand ---------------*/
/*
a = int myFunc() -> myFunc = contentType, a = valueType
*/
struct AstNodeOperand {
    union ValueOper value;             //valore reale restituito se int, void, char  o puntatore a func o a expr
    enum DataType valueType;          //tipo del valore restituito
    enum ContentType contentType;   //è il tipo di operando func expr int che forse serve per la traduzione ma forse no
}; 

/*--------------- Node Array Init ---------------*/
struct AstNodeArrayInit {
    enum DataType arrayType; 
    struct AstNodeArrayAssign *assignArray;
};

/*--------------- Node Array Assign ---------------*/
struct AstNodeArrayAssign {
    char *arrayName;
    enum DataType arrayType;
    //char *elementIndex;
    //char *arrayLength;
    struct AstNodeOperand *elementIndex; //only for array assignment
    struct AstNodeOperand *arrayLength; //only for array declaration
    struct AstNodeArrayElements *elements;
};

/*--------------- Node Array Assign ---------------*/
struct AstNodeArrayElements {
    struct AstNodeOperand *element;
    struct AstNodeArrayElements *nextElement;
};

/*--------------- Node Function Declaration ---------------*/
struct AstNodeFunctionDecl {
    char *functionName;
    enum DataType returnType; //tipo restituito dalla funzione
    struct AstNodeFunctionParams *functionParams;
    struct AstNodeBody *functiontBody; //da scrivere
};

/*--------------- Node Function Call ---------------*/
struct AstNodeFunctionCall {
    char *functionName;
    enum DataType returnType;
    struct AstNodeFunctionParams *functionParams;
};

/*--------------- Node Function Parameters ---------------*/
struct AstNodeFunctionParams {
    struct AstNodeInit *initParam; //questo vale solo per la dichiarazione e va annullato nella chiamata 
    struct AstNodeOperand *callParams; //questo vale solo per la chiamata e va annullato nella dichiarazione 
    struct AstNodeFunctionParams *nextParams; // questo vale sempre per puntare al parametro successivo (a, b, c), sia dichiarazione che chiamata
    /* Gestione di più parametri:
    multi_fun_param:
                fun_param                           {
                                                        $1->next_param = NULL;
                                                        $$ = $1;
                                                        }
                |   fun_param COMMA  multi_fun_param    {
                                                        $1->next_param = $3;
                                                        $$ = $1;
                                                        };
    */
};

struct AstNodeBody {
    struct AstNodeStatements *bodyStatements;
    struct AstNodeOperand *returnValue;
};

/*--------------- Node If ---------------*/
struct AstNodeIf {
    struct AstNodeExpression *ifCondition;
    struct AstNodeBody *ifBody;

};

/*--------------- Node Elseif ---------------*/
struct AstNodeElseIf {
    struct AstNodeExpression *elseifCondition;
    struct AstNodeBody *elseifBody;
};

/*--------------- Node Else ---------------*/
struct AstNodeElse {
    struct AstNodeBody *elseBody;
};

/*--------------- Node While ---------------*/
struct AstNodeWhile {
    struct AstNodeExpression *whileCondition;
    struct AstNodeBody *whileBody;
};


/* struct AstNodeFunctionInput {
    struct AstNodeFunctionCall *input_function;
};

struct AstNodeFunctionOutput {
    struct AstNodeFunctionCall *output_function;
}; */




#endif