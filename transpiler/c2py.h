#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int counter = 0;
FILE *fptr;

void printCounter(int counter);
char* DataType(enum DataType dataType);
char* NodeType(enum NodeType nodeType);
void translate(struct AstNodeStatements *root);
void translateInitialization(struct AstNodeInit *init);
void translateAssignment(struct AstNodeAssign *assign);
void translateOperand(union ValueOper value, int contentType);
void translateExpression(struct AstNodeExpression *expression);
void translateArrayDecleration(struct AstNodeArrayDecl *arrayDecl);
void translateArrayCall(struct AstNodeArrayCall *arrayCall);
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
        fprintf(fptr, "\t");
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
        default:
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
                printCounter(counter);
                translateInitialization(currentInstruction->value.init);
                break;
            case ASSIGN_NODE:
                printCounter(counter);
                translateAssignment(currentInstruction->value.assign);
                break;
            case FUNCTION_DECL_NODE:
                printCounter(counter);
                translateFunctionDeclaration(currentInstruction->value.functionDecl);
                break;
            case FUNCTION_CALL_NODE:
                printCounter(counter);
                translateFunctionCall(currentInstruction->value.functionCall);
                break;
            case IF_NODE:
                printCounter(counter);
                translateIf(currentInstruction->value.ifStatement);
                break;
            case ELSE_IF_NODE:
                translateElseIf(currentInstruction->value.elseifStatement);
                break;
            case ELSE_NODE:
                printCounter(counter);
                translateElse(currentInstruction->value.elseStatement);
                break;
            case WHILE_NODE:
                printCounter(counter);
                translateWhile(currentInstruction->value.whileLoop);
                break;
            case ARRAY_INIT_NODE:
                printCounter(counter);
                translateArrayInitialization(currentInstruction->value.arrayInit);
                break;
            case ARRAY_ASSIGN_NODE:
                printCounter(counter);
                translateArrayAssignment(currentInstruction->value.arrayAssign);
                break;
            case OUTPUT_NODE:
                printCounter(counter);
                translateFunctionOutput(currentInstruction->value.outputFunction);
                break;
            case INPUT_NODE:
                printCounter(counter);
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
                printCounter(counter);
                translateInitialization(currentInstruction->value.init);
                break;
            case ASSIGN_NODE:
                printCounter(counter);
                translateAssignment(currentInstruction->value.assign);
                break;
            case FUNCTION_DECL_NODE:
                printCounter(counter);
                translateFunctionDeclaration(currentInstruction->value.functionDecl);
                break;
            case FUNCTION_CALL_NODE:
                printCounter(counter);
                translateFunctionCall(currentInstruction->value.functionCall);
                break;
            case IF_NODE:
                printCounter(counter);
                translateIf(currentInstruction->value.ifStatement);
                break;
            case ELSE_IF_NODE:
                printCounter(counter);
                translateElseIf(currentInstruction->value.elseifStatement);
                break;
            case ELSE_NODE:
                printCounter(counter);
                translateElse(currentInstruction->value.elseStatement);
                break;
            case WHILE_NODE:
                printCounter(counter);
                translateWhile(currentInstruction->value.whileLoop);
                break;
            case ARRAY_INIT_NODE:
                printCounter(counter);
                translateArrayInitialization(currentInstruction->value.arrayInit);
                break;
            case ARRAY_ASSIGN_NODE:
                printCounter(counter);
                translateArrayAssignment(currentInstruction->value.arrayAssign);
                break;
            case OUTPUT_NODE:
                printCounter(counter);
                translateFunctionOutput(currentInstruction->value.outputFunction);
                break;
            case INPUT_NODE:
                printCounter(counter);
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
    fprintf(fptr, "%s = None", init->variableName);
    fprintf(fptr, "\n");
}

void translateAssignment(struct AstNodeAssign *assign) {
    if (assign->assignType == CONTENT_TYPE_EXPRESSION) {
        fprintf(fptr, "%s = ", assign->variableName);
        translateExpression(assign->assignValue.expression);
    } else if (assign->assignType == CONTENT_TYPE_FUNCTION) {
        fprintf(fptr, "%s = ", assign->variableName);
        translateFunctionCall(assign->assignValue.funtionCall);
    } else if (assign->assignType == CONTENT_TYPE_ARRAY) {
        fprintf(fptr, "%s = ", assign->variableName);
        translateArrayCall(assign->assignValue.arrayCall);
    } else {
        fprintf(fptr, "%s = %s", assign->variableName, assign->assignValue.val);
    }
    fprintf(fptr, "\n");
}

void translateOperand(union ValueOper value, int contentType) {
    switch(contentType) {
        case CONTENT_TYPE_ID:
            fprintf(fptr, "%s", value.val);
            break;
        case CONTENT_TYPE_INT_NUMBER:
            fprintf(fptr, "%s", value.val);
            break;
        case CONTENT_TYPE_FLOAT_NUMBER:
            fprintf(fptr, "%s", value.val);
            break;
        case CONTENT_TYPE_CHAR:
            fprintf(fptr, "%s", value.val);
            break;
        case CONTENT_TYPE_EXPRESSION:
            translateExpression(value.expression);
            break;
        case CONTENT_TYPE_FUNCTION:
            translateFunctionCall(value.funtionCall);
            break;
        case CONTENT_TYPE_ARRAY:
            translateArrayCall(value.arrayCall);
            break;
        default:
        printf("Unrecognized type");
    }
}

void translateExpression(struct AstNodeExpression *expression) {
    fprintf(fptr, "%s %s %s", expression->leftOper->value.val, expression->op, expression->rightOper->value.val);
}

void translateArrayDecleration(struct AstNodeArrayDecl *arrayDecl) {
    fprintf(fptr, "%s", arrayDecl->arrayName);
}

void translateArrayCall(struct AstNodeArrayCall *arrayCall) {
    fprintf(fptr, "%s", arrayCall->arrayName);
    fprintf(fptr, "[");
    translateOperand(arrayCall->elementIndex->value, arrayCall->elementIndex->contentType);
    fprintf(fptr, "]");
}

void translateArrayInitialization(struct AstNodeArrayInit *arrayInit) {
    if(arrayInit->elements == NULL) {
        translateArrayDecleration(arrayInit->arrayDecl);
        fprintf(fptr, " = None");
    } else {
        translateArrayDecleration(arrayInit->arrayDecl);
        fprintf(fptr, " = ");
        fprintf(fptr, "[ ");
        translateArrayElements(arrayInit->elements);
        fprintf(fptr, " ]");
    }
    fprintf(fptr, "\n");
}

void translateArrayAssignment(struct AstNodeArrayAssign *arrayAssign) {
    translateArrayCall(arrayAssign->arrayCall);
    fprintf(fptr, " = ");
    translateArrayElements(arrayAssign->elements);
    fprintf(fptr, "\n");
}

void translateArrayElements(struct AstNodeArrayElements *arrayElements) {
    if (arrayElements->nextElement != NULL) {
        translateOperand(arrayElements->element->value, arrayElements->element->contentType);
        fprintf(fptr, ", ");
        translateArrayElements(arrayElements->nextElement);
    } else {
        translateOperand(arrayElements->element->value, arrayElements->element->contentType);
    }
}

void translateFunctionDeclaration(struct AstNodeFunctionDecl *functionDecl) {
    fprintf(fptr, "def %s(", functionDecl->functionName);
    if (functionDecl->functionParams != NULL) {
        translateFunctionParams(functionDecl->functionParams);
    }
    fprintf(fptr, "):");
    fprintf(fptr, "\n");
    counter++;
    translateBody(functionDecl->functiontBody);
    counter--;
    fprintf(fptr, "\n");
    
    char *main = "main";
    if (strcmp(functionDecl->functionName, main) == 0) {
        fprintf(fptr, "main()");
    }
}

void translateFunctionCall(struct AstNodeFunctionCall *functionCall) {
    //printCounter(counter);
    fprintf(fptr, "%s(", functionCall->functionName);
    if (functionCall->functionParams != NULL) {
        translateFunctionParams(functionCall->functionParams);
    }
    fprintf(fptr, ")");
    fprintf(fptr, "\n");
}

void translateFunctionParams(struct AstNodeFunctionParams *functionParams) {
    if (functionParams->initParam != NULL) {
        //Translate parameters inside a function declaration
        fprintf(fptr, "%s", functionParams->initParam->variableName);
        if (functionParams->nextParams != NULL) {
            fprintf(fptr, ", ");
            translateFunctionParams(functionParams->nextParams);
        }
    } else {
        //Translate parameteres inside a function call
        fprintf(fptr, "%s", functionParams->callParams->value.val);
        if (functionParams->nextParams != NULL) {
            fprintf(fptr, ", ");
            translateFunctionParams(functionParams->nextParams);
        }
    }
}

void translateIf(struct AstNodeIf *ifStatement) {
    fprintf(fptr, "if ");
    translateExpression(ifStatement->ifCondition);
    fprintf(fptr, ":");
    fprintf(fptr, "\n");
    counter++;
    translateBody(ifStatement->ifBody);
    counter--;
}

void translateElseIf(struct AstNodeElseIf *elseifStatement) {
    fprintf(fptr, "elif ");
    translateExpression(elseifStatement->elseifCondition);
    fprintf(fptr, ":");
    fprintf(fptr, "\n");
    counter++;
    translateBody(elseifStatement->elseifBody);
    counter--;
}

void translateElse(struct AstNodeElse *elseStatement) {
    fprintf(fptr, "else");
    fprintf(fptr, ":");
    fprintf(fptr, "\n");
    counter++;
    translateBody(elseStatement->elseBody);
    counter--;
    fprintf(fptr, "\n");
}

void translateWhile(struct AstNodeWhile *whileLoop) {
    fprintf(fptr, "while ");
    translateExpression(whileLoop->whileCondition);
    fprintf(fptr, ":");
    fprintf(fptr, "\n");
    counter++;
    translateBody(whileLoop->whileBody);
    counter--;
    fprintf(fptr, "\n");
}

void translateBody(struct AstNodeBody *body) {
    translate(body->bodyStatements);
    if (body->returnValue != NULL) {
        printCounter(counter);
        fprintf(fptr, "return ");
        translateOperand(body->returnValue->value, body->returnValue->contentType);
        fprintf(fptr, "\n");
    }
}

void translateFunctionOutput(struct AstNodeFunctionOutput *outputFunction) {
	char formatSpecifier[][3] = {"%d", "%i", "%lf", "%f", "%c", "%s"};
    int numFormats = sizeof(formatSpecifier) / sizeof(formatSpecifier[0]);
    
	for (int i = 0; i<numFormats; i++) {
        char *format = formatSpecifier[i];
		char *substr = strstr(outputFunction->string, format);
        
		while (substr != NULL) {
            memset(substr, ' ', strlen(format));
            substr = strstr(outputFunction->string, format);
		}
	}
    
    if(outputFunction->outputElements == NULL) {
        fprintf(fptr, "print(");
        fprintf(fptr, "%s",outputFunction->string);
        fprintf(fptr, ")");
        fprintf(fptr, "\n");
    } else {
        fprintf(fptr, "print(");
        fprintf(fptr, "%s",outputFunction->string);
        translateOutputElements(outputFunction->outputElements);
        fprintf(fptr, ")");
        fprintf(fptr, "\n");
    }
}

void translateFunctionInput(struct AstNodeFunctionInput *inputFunction) {
    char formatSpecifier[][3] = {"%d", "%i", "%lf", "%f", "%c", "%s"};
    int numFormats = sizeof(formatSpecifier) / sizeof(formatSpecifier[0]);
    
	for (int i = 0; i<numFormats; i++) {
        char *format = formatSpecifier[i];
		char *substr = strstr(inputFunction->string, format);
        
		while (substr != NULL) {
            memset(substr, ' ', strlen(format));
            substr = strstr(inputFunction->string, format);
		}
	}
    
    if(inputFunction->inputElements != NULL) {
        fprintf(fptr, "print(");
        fprintf(fptr, "%s",inputFunction->string);
        fprintf(fptr, ")");
        fprintf(fptr, "\n");
        translateInputElements(inputFunction->inputElements);
    } else {
        printf("Syntax Error\n");
    }
}

void translateOutputElements(struct AstNodeOutputElements *outputElements) {
    if (outputElements->nextElement != NULL) {
        fprintf(fptr, " + ");
        translateOperand(outputElements->element->value, outputElements->element->contentType);
        translateOutputElements(outputElements->nextElement);
    } else {
        fprintf(fptr, " + ");
        translateOperand(outputElements->element->value, outputElements->element->contentType);
    }
}

void translateInputElements(struct AstNodeInputElements *inputElements) {
    printCounter(counter);
    if (inputElements->nextElement != NULL) {
        translateOperand(inputElements->element->value, inputElements->element->contentType);
        fprintf(fptr, " =");
        fprintf(fptr, " input()");
        fprintf(fptr, "\n");
        translateInputElements(inputElements->nextElement);
    } else {
        translateOperand(inputElements->element->value, inputElements->element->contentType);
        fprintf(fptr, " =");
        fprintf(fptr, " input()");
        fprintf(fptr, "\n");
    }
}