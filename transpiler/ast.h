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
    CONTENT_TYPE_STRING,
    CONTENT_TYPE_FLOAT_NUMBER,
    CONTENT_TYPE_INT_NUMBER,
    CONTENT_TYPE_EXPRESSION,
    CONTENT_TYPE_FUNCTION,
};

enum Access_Type {
    ACCESS_TYPE_VAR,
    ACCESS_TYPE_ASSIGN,
    ACCESS_TYPE_FUNCTION,
};

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
    struct AST_NODE_INIT            *init;
    struct AST_NODE_ASSIGN          *assign;

    struct AST_Node_Declare_Params  *declare_params;
    struct AST_Node_Params          *params;
    struct AST_Node_Instruction     *instruction;
    struct AST_Node_Expression      *expression;
    struct AST_Node_Statements      *statements;
    struct AST_Node_Value           *value;
    struct AST_Node_Variable        *variable;
    struct AST_Node_FunctionCall    *functionCall;
    struct AST_Node_FunctionDef     *functionDef;
    struct AST_Node_If              *ifNode;
    struct AST_Node_Else            *elseNode;
    struct AST_Node_Else_If         *elseIfNode;
    struct AST_Node_For             *forNode;
    struct AST_Node_Operand         *operand;
    struct AST_Node_Return          *returnNode;
    struct AST_Node_Input           *inputNode;
    struct AST_Node_Output          *outputNode;
    struct AST_NODE_BODY            *bodyNode;
};

/*--------------- Other Types ---------------*/
typedef union Value_after_eq {
    char *val;
    /* struct AST_Node_Expression *expr;
    struct AST_Node_FunctionCall *funca; */ 
};

static union Value_sym null_value;

struct AST_NODE_ARRAY {
    char *variable_name;
    int *length;

};


/*--------------- Node Initialization ---------------*/

struct AST_NODE_INIT {
    enum Data_Type data_type; 
    struct AST_NODE_ASSIGN *assign;
    struct AST_NODE_INIT *next_init;
};

struct AST_NODE_ASSIGN {
    char *variable_name;
    enum Data_Type value_type; //value_type serve per il check del type del Content/ID
    union Value_after_eq assign_value; //Value
    enum Content_Type assign_type; //assign_type è il tipo di ciò che c'è dopo l'uguale
};



#endif