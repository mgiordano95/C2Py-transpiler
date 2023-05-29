#include <stdio.h>

int myFunction(int a, int b) {
    int c = a + b;
    return c;
}

int main() {
    
    float output = myFunction(7, 3); //Functions_Error_1 (Error: cannot assign type int to type float)
    
    int result = myFunction(7, 3.8); //Functions_Error_2 (Error: the parameters in the function call are incorrect)
    
    myFunc(2.7); //Functions_Error_3 (Error: function myFunc not declared)
    
    return 0;
}