#include <stdio.h>

int main() {
    //This is a single line comment
    /*
    This is a multi line comment
    */
    int a = 5;
    int b = 6;
    int c;
    int d;
    
    if (a > b) {
        int c = 7;
    } else if (a < b) {
        int d = 4;
    } else {
        float e = 5.5;
    }

    if( c == 7) {
        printf("a is greater than b!\n");
    } else if (d == 4) {
        printf("a is less than b!\n");
    } else {
        printf("a equals b!\n");
    }

    while (a < b) {
        a = a + b;
    }
    
    return 0;
}