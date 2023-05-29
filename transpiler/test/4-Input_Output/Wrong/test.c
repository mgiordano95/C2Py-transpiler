#include <stdio.h>

int main() {
    int x;
    
    printf(); //outputFunction_Error (Error: too few arguments to function 'printf')
    
    scanf(); //inputFunction_Error_1 (Error: too few arguments to function 'scanf')
    
    printf("Enter an integer:\n");
    scanf("%d", x); //inputFunction_Error_2 (syntax error)
}