int main() {
    x = 28; //Assign_Error_1 (Error: variable x not declared)
    
    int i = 7.9; //Assign_Error_2 (Error: Cannot assign type float to type int )

    int a = 3;
    int a = 6; //Init_Error_1 (Error: variable a already declared)

    char c1 = 'F';
    char c2 = 'L';
    char c3 = c1 + c2; //Expression_Error_1 (Error: cannot add variables of type char)
    
    return 0;
}