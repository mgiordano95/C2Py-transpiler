#include <stdio.h>

int main() {
    int x = 3;
    int y = 7;
    
    if ( y > x + 3) {
        printf("y is greater than x plus 3");
    }
    
    if(!(x > 5 && y >= 10)) {
        printf("x is equal to %d", x);
        printf("y is equal to %d", y);
    } else {
        int z = x + y;
        printf("The sum of x and y is equal to %d", z);
    }
    
    return 0;
}
