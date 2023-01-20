/*--------------- Abstrac Syntax Tree ---------------*/
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

enum Access_Type {
    ACCESS_TYPE_VAR,
    ACCESS_TYPE_ASSIGN,
    ACCESS_TYPE_FUNCTION,
};


//TO-DO: da scrivere dopo il Node_type, serve per la traduzione
enum Node_Type {
    INIT_NODE,
    ASSIGN_NODE,
    EXPR_NODE,
    FUNC_DEF_NODE,
    FUN_CALL_NODE,
    STATEMENT_NODE,
    ARRAY_NODE,
    IF_NODE,
    ELSE_NODE,
    IF_ELSE_NODE,
    FOR_NODE,
    INPUT_NODE,
    OUTPUT_NODE,
    
};

union yystype {
    char *string;
    struct AST_NODE_INIT                *init;
    struct AST_NODE_ASSIGN              *assign;
    struct AST_NODE_EXPRESSION          *expression;
    struct AST_NODE_OPERAND             *operand;
    struct AST_NODE_FUNCTION_DECL       *functionDecl;
    struct AST_NODE_FUNCTION_CALL       *functionCall;
    struct AST_NODE_FUNCTION_PARAMS     *functionParams;
    struct AST_NODE_BODY                *body;
    /* struct AST_NODE_FUNCTION_INPUT      *inputFunction;
    struct AST_NODE_FUNCTION_OUTPUT     *outputFunction; */






    struct AST_Node_Declare_Params  *declare_params;
    
    struct AST_Node_Instruction     *instruction;
    
    struct AST_Node_Statements      *statements;
    struct AST_Node_Value           *value;
    struct AST_Node_Variable        *variable;
    struct AST_Node_If              *ifNode;
    struct AST_Node_Else            *elseNode;
    struct AST_Node_Else_If         *elseIfNode;
    struct AST_Node_For             *forNode;
    
};

/*--------------- Other Types ---------------*/
typedef union Value_oper {
    char *val;
    struct AST_NODE_EXPRESSION *expression;
    struct AST_NODE_FUNCTION_CALL *funtionCall;
};

static union Value_sym null_value;


/*--------------- Node Initialization ---------------*/

//int a = 3;
struct AST_NODE_INIT {
    enum Data_Type data_type; 
    struct AST_NODE_ASSIGN *assign;
    struct AST_NODE_INIT *next_init;
};

//a = 5;
struct AST_NODE_ASSIGN {
    char *variable_name;
    enum Data_Type value_type; //value_type serve per il check del type del Content/ID
    union Value_oper assign_value; //Value
    enum Content_Type assign_type; //assign_type è il tipo di ciò che c'è dopo l'uguale
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
    enum Data_Type expr_type;
    char *op; // op è $2 e può essere +, -, *, /, >, < ...
    struct AST_NODE_OPERAND *left_oper;
    struct AST_NODE_OPERAND *right_oper; 
};

/* NODE OEPRAND:
a = int myFunc() -> myFunc = content_type, a = value_type
*/
struct AST_NODE_OPERAND {
    enum Data_Type value_type;
    union Value_oper value;
    enum Content_Type content_type; //content_type è il tipo di value
}; 

struct AST_NODE_FUNCTION_DECL {
    char *function_name;
    enum Data_Type return_type; //tipo restituito dalla funzione
    struct AST_NODE_FUNCTION_PARAMS *function_params;
    struct AST_NODE_BODY *function_body;
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

/* struct AST_NODE_FUNCTION_INPUT {
    struct AST_NODE_FUNCTION_CALL *input_function;
};

struct AST_NODE_FUNCTION_OUTPUT {
    struct AST_NODE_FUNCTION_CALL *output_function;
}; */




#endif