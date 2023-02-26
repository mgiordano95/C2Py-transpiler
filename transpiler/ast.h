#ifndef AST_H
#define AST_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum Symbol_Type {
    SYMBOL_VARIABLE,
    SYMBOL_CONTENT,
    SYMBOL_FUNCTION,
    SYMBOL_PARAMETER,
};

enum Data_Type {
    DATA_TYPE_VOID,
    DATA_TYPE_INT,
    DATA_TYPE_FLOAT,
    DATA_TYPE_CHAR,
};

enum Content_Type {
    CONTENT_TYPE_ID,
    CONTENT_TYPE_INT_NUMBER,
    CONTENT_TYPE_FLOAT_NUMBER,
    CONTENT_TYPE_CHAR,
    CONTENT_TYPE_EXPRESSION,
    CONTENT_TYPE_FUNCTION,
};

//TO-DO: da scrivere dopo il Node_type, serve per la traduzione
enum Node_Type {
    INIT_NODE,
    ASSIGN_NODE,
    EXPRESSION_NODE,
    FUNCTION_DECL_NODE,
    FUNCTION_CALL_NODE,
    ARRAY_INIT_NODE,
    ARRAY_ASSIGN_NODE,
    IF_NODE,
    ELSE_NODE,
    ELSE_IF_NODE,
    WHILE_NODE,
    STATEMENT_NODE,
};

union yystype {
    char *string;
    struct AST_NODE_STATEMENTS          *statements;
    struct AST_NODE_INSTRUCTION         *instruction;
    struct AST_NODE_INIT                *init;
    struct AST_NODE_ASSIGN              *assign;
    struct AST_NODE_EXPRESSION          *expression;
    struct AST_NODE_OPERAND             *operand;
    struct AST_NODE_FUNCTION_DECL       *functionDecl;
    struct AST_NODE_FUNCTION_CALL       *functionCall;
    struct AST_NODE_FUNCTION_PARAMS     *functionParams;
    struct AST_NODE_BODY                *body;
    // struct AST_NODE_FUNCTION_INPUT   *inputFunction;
    // struct AST_NODE_FUNCTION_OUTPUT  *outputFunction;
    // struct AST_NODE_ARRAY_INIT       *arrayInit;
    // struct AST_NODE_ARRAY_ASSIGN     *arrayAssign;
    struct AST_NODE_IF                  *ifStatement;
    struct AST_NODE_ELSE_IF             *elseifStatement;
    struct AST_NODE_ELSE                *elseStatement;
    struct AST_NODE_WHILE               *whileLoop;
    struct AST_NODE_VALUE               *value;
    struct AST_NODE_VARIABLE            *variable;
    
};

/*--------------- Other Types ---------------*/
typedef union Value_oper {
    char *val;
    struct AST_NODE_EXPRESSION *expression;
    struct AST_NODE_FUNCTION_CALL *funtionCall;
}Value_oper;

static union Value_oper null_value;

struct AST_NODE_STATEMENTS {
    enum Node_Type node_type; //questa può essere uguale solo a Node_Type.STATEMENT_NODE
    struct AST_NODE_INSTRUCTION *current_instruction; //puntatore all'instruction corrente
    struct AST_NODE_STATEMENTS *next_statement; //puntato allo statmenent successivo
};

struct AST_NODE_INSTRUCTION {
    enum Node_Type node_type; //tipo dell'instruction
    union yystype value; /*puntatore alla struct dell'instruction $1 -> value.init, $1 -> value.functionDecl
    usare gli stessi nomi dei puntatori definiti in camelCase a riga 55*/
};


/*--------------- Node Initialization ---------------*/

//int a = 3;
struct AST_NODE_INIT {
    enum Data_Type data_type; 
    struct AST_NODE_ASSIGN *assign;
    // struct AST_NODE_INIT *next_init;  serivra' per controllo che non siano state inizializzate 2 variabili 
    // con lo stesso nome
};

//a = 5;
struct AST_NODE_ASSIGN {
    char *variable_name; 
    enum Data_Type variable_type; //value_type serve per il check del type del Content/ID ed è il tipo prima di uguale
    union Value_oper assign_value; //Valore vero e proprio dopo uguale
    enum Content_Type assign_type; //Contenuto (int func expr) che c'è dopo l'uguale
    //int a -> CONTENT_TYPE_ID indica che e' solo un ID senza assegnazione
    //int main() -> CONTENT_TYPE_FUNCTION
};

/* NODE EXPRESSION:
a+b
7-3
a*2
d/3
a + 5 > 6
i + 1 < 8
*/
struct AST_NODE_EXPRESSION {
    enum Data_Type expr_type;  //tipo dato restituito dall'espressione (void, int float, char)
    char *op; // op è $2 e può essere +, -, *, /, >, < ...
    struct AST_NODE_OPERAND *left_oper;
    struct AST_NODE_OPERAND *right_oper; 
};

/* NODE OEPRAND:
a = int myFunc() -> myFunc = content_type, a = value_type
*/
struct AST_NODE_OPERAND {
    union Value_oper value;             //valore reale restituito se int, void, char  o puntatore a func o a expr
    enum Data_Type value_type;          //tipo del valore restituito
    enum Content_Type content_type;   //è il tipo di operando func expr int che forse serve per la traduzione ma forse no
}; 

struct AST_NODE_FUNCTION_DECL {
    char *function_name;
    enum Data_Type return_type; //tipo restituito dalla funzione
    struct AST_NODE_FUNCTION_PARAMS *function_params;
    struct AST_NODE_BODY *function_body; //da scrivere
};

struct AST_NODE_FUNCTION_CALL {
    char *function_name;
    enum Data_Type return_type;
    struct AST_NODE_FUNCTION_PARAMS *function_params;
};

struct AST_NODE_FUNCTION_PARAMS {
    struct AST_NODE_INIT *init_param; //questo vale solo per la dichiarazione e va annullato nella chiamata 
    struct AST_NODE_OPERAND *call_params; //questo vale solo per la chiamata e va annullato nella dichiarazione 
    struct AST_NODE_FUNCTION_PARAMS *next_params; // questo vale sempre per puntare al parametro successivo (a, b, c), sia dichiarazione che chiamata
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

struct AST_NODE_BODY {
    struct AST_NODE_STATEMENTS *body_statements;
    struct AST_NODE_OPERAND *return_value;
};


/* struct AST_NODE_FUNCTION_INPUT {
    struct AST_NODE_FUNCTION_CALL *input_function;
};

struct AST_NODE_FUNCTION_OUTPUT {
    struct AST_NODE_FUNCTION_CALL *output_function;
}; */




#endif