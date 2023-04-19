#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int counter = 0;
FILE *fptr;

void printCounter(int counter);
char* DataType(enum DataType dataType);
char* NodeType(enum NodeType nodeType);
void translate(struct AstNodeStatements *root);
void translateInitialization(struct AstNodeInit *init);
void translateAssignment(struct AstNodeAssign *assign);
void translateOperand(struct AstNodeOperand *operand);
void translateExpression(struct AstNodeExpression *expression);
void translateArrayInitialization(struct AstNodeArrayInit *arrayInit);
void translateArrayAssignment(struct AstNodeArrayAssign *arrayAssign);
void translateArrayElements(struct AstNodeArrayElements *arrayElements);
void translateFunctionDeclaration(struct AstNodeFunctionDecl *functionDecl);
void translateFunctionCall(struct AstNodeFunctionCall *functionCall);
void translateFunctionParams(struct AstNodeFunctionParams *functionParams);
void translateIf(struct AstNodeIf *ifStatement);
void translateElseIf(struct AstNodeElseIf *elseifStatement);
void translateElse(struct AstNodeElse *elseStatement);
void translateWhile(struct AstNodeWhile *whileLoop);
void translateBody(struct AstNodeBody *body);
void translateFunctionOutput(struct AstNodeFunctionOutput *outputFunction);
void translateFunctionInput(struct AstNodeFunctionInput *inputFunction);
void translateOutputElements(struct AstNodeOutputElements *outputElements);
void translateInputElements(struct AstNodeInputElements *inputElements);

// Function to print indentation in .py file
void printCounter(int counter) {
    for (int i = 0; i<counter; i++) {
        fprintf(fptr, "\t", counter);
    }
}

// Function to translate the C Data Type into Python Data Type
char* DataType(enum DataType dataType) {
    switch (dataType) {
        case DATA_TYPE_VOID:
            return "None";
            break;
        case DATA_TYPE_INT:
            return "int";
            break;
        case DATA_TYPE_FLOAT:
            return "float";
            break;
        case DATA_TYPE_CHAR:
            return "str";
            break;
        default :
            return "unknown";
            break;
    } 
}

// Function to convert the Node Type
char* NodeType(enum NodeType nodeType) {
    switch(nodeType) {
        case STATEMENT_NODE:
            return "STATEMENT_NODE";
            break;
        case INIT_NODE:
            return "INIT_NODE";
            break;
        case ASSIGN_NODE:
            return "ASSIGN_NODE";
            break;
        case EXPRESSION_NODE:
            return "EXPRESSION_NODE";
            break;
        case ARRAY_INIT_NODE:
            return "ARRAY_INIT_NODE";
            break;
        case ARRAY_ASSIGN_NODE:
            return "ARRAY_ASSIGN_NODE";
            break;
        case FUNCTION_DECL_NODE:
            return "FUNCTION_DECL_NODE";
            break;
        case FUNCTION_CALL_NODE:
            return "FUNCTION_CALL_NODE";
            break;
        case IF_NODE:
            return "IF_NODE";
            break;
        case ELSE_IF_NODE:
            return "ELSE_IF_NODE";
            break;
        case ELSE_NODE:
            return "ELSE_NODE";
            break;
        case WHILE_NODE:
            return "WHILE_NODE";
            break;
        case OUTPUT_NODE:
            return "OUTPUT_NODE";
            break;
        case INPUT_NODE:
            return "INPUT_NODE";
            break;
        default:
            return "Unknown Node";
            break;
    }
}

void translate(struct AstNodeStatements *root) {
    if(root->currentInstruction == NULL && root->nextStatement == NULL) {
        //printf("End!!!");
    } else if(root->currentInstruction != NULL && root->nextStatement == NULL) {
        struct AstNodeInstruction *currentInstruction = root->currentInstruction;
        struct AstNodeStatements *nextStatement = NULL;
        switch(currentInstruction->nodeType) {
            case INIT_NODE:
                translateInitialization(currentInstruction->value.init);
                break;
            case ASSIGN_NODE:
                translateAssignment(currentInstruction->value.assign);
                break;
            case FUNCTION_DECL_NODE:
                translateFunctionDeclaration(currentInstruction->value.functionDecl);
                break;
            case FUNCTION_CALL_NODE:
                translateFunctionCall(currentInstruction->value.functionCall);
                break;
            case IF_NODE:
                translateIf(currentInstruction->value.ifStatement);
                break;
            case ELSE_IF_NODE:
                translateElseIf(currentInstruction->value.elseifStatement);
                break;
            case ELSE_NODE:
                translateElse(currentInstruction->value.elseStatement);
                break;
            case WHILE_NODE:
                translateWhile(currentInstruction->value.whileLoop);
                break;
            case ARRAY_INIT_NODE:
                translateArrayInitialization(currentInstruction->value.arrayInit);
                break;
            case ARRAY_ASSIGN_NODE:
                translateArrayAssignment(currentInstruction->value.arrayAssign);
                break;
            case OUTPUT_NODE:
                translateFunctionOutput(currentInstruction->value.outputFunction);
                break;
            case INPUT_NODE:
                translateFunctionInput(currentInstruction->value.inputFunction);
                break;
            default:
                printf("Unknown Node\n");
                break;
        }
    } else {
        struct AstNodeInstruction *currentInstruction = root->currentInstruction;
        struct AstNodeStatements *nextStatement = root->nextStatement;
        switch(currentInstruction->nodeType) {
            case INIT_NODE:
                translateInitialization(currentInstruction->value.init);
                break;
            case ASSIGN_NODE:
                translateAssignment(currentInstruction->value.assign);
                break;
            case FUNCTION_DECL_NODE:
                translateFunctionDeclaration(currentInstruction->value.functionDecl);
                break;
            case FUNCTION_CALL_NODE:
                translateFunctionCall(currentInstruction->value.functionCall);
                break;
            case IF_NODE:
                translateIf(currentInstruction->value.ifStatement);
                break;
            case ELSE_IF_NODE:
                translateElseIf(currentInstruction->value.elseifStatement);
                break;
            case ELSE_NODE:
                translateElse(currentInstruction->value.elseStatement);
                break;
            case WHILE_NODE:
                translateWhile(currentInstruction->value.whileLoop);
                break;
            case ARRAY_INIT_NODE:
                translateArrayInitialization(currentInstruction->value.arrayInit);
                break;
            case ARRAY_ASSIGN_NODE:
                translateArrayAssignment(currentInstruction->value.arrayAssign);
                break;
            case OUTPUT_NODE:
                translateFunctionOutput(currentInstruction->value.outputFunction);
                break;
            case INPUT_NODE:
                translateFunctionInput(currentInstruction->value.inputFunction);
                break;
            default:
                printf("Unknown Node\n");
                break;
        }
        translate(nextStatement);
    }
}

void translateInitialization(struct AstNodeInit *init) {
    printCounter(counter);
    fprintf(fptr, "%s = %s", init->assign->variableName, init->assign->assignValue.val);
    fprintf(fptr, "\n");
}

void translateAssignment(struct AstNodeAssign *assign) {
    printCounter(counter);
    fprintf(fptr, "%s = %s", assign->variableName, assign->assignValue.val);
}

void translateOperand(struct AstNodeOperand *operand) {
    printf("Hello!!!");
}

void translateExpression(struct AstNodeExpression *expression) {
    printf("Hello!!!");
}

void translateArrayInitialization(struct AstNodeArrayInit *arrayInit) {
    printf("Hello!!!");
}

void translateArrayAssignment(struct AstNodeArrayAssign *arrayAssign) {
    printf("Hello!!!");
}

void translateArrayElements(struct AstNodeArrayElements *arrayElements) {
    printf("Hello!!!");
}

void translateFunctionDeclaration(struct AstNodeFunctionDecl *functionDecl) {
    printf("Hello!!!");
}

void translateFunctionCall(struct AstNodeFunctionCall *functionCall) {
    printf("Hello!!!");
}

void translateFunctionParams(struct AstNodeFunctionParams *functionParams) {
    printf("Hello!!!");
}

void translateIf(struct AstNodeIf *ifStatement) {
    printf("Hello!!!");
}

void translateElseIf(struct AstNodeElseIf *elseifStatement) {
    printf("Hello!!!");
}

void translateElse(struct AstNodeElse *elseStatement) {
    printf("Hello!!!");
}

void translateWhile(struct AstNodeWhile *whileLoop) {
    printf("Hello!!!");
}

void translateBody(struct AstNodeBody *body) {
    printf("Hello!!!");
}

void translateFunctionOutput(struct AstNodeFunctionOutput *outputFunction) {
    printf("Hello!!!");
}

void translateFunctionInput(struct AstNodeFunctionInput *inputFunction) {
    printf("Hello!!!");
}

void translateOutputElements(struct AstNodeOutputElements *outputElements) {
    printf("Hello!!!");
}

void translateInputElements(struct AstNodeInputElements *inputElements) {
    printf("Hello!!!");
}