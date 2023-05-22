int a;

int myFunction(int a, int b) {
    int i = 1;
    return a + b;
}

int main() {
    int a = 5;
    int b = 6;
    int c = a;
    int d = b;
    
    myFunction(c, d);
    
    void myFunction2(float c, float d) {
        printf("Hello myFunction2!!!");
    }
    
    myFunction2();
    
    return 0;
}