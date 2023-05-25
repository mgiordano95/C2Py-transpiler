int main() {
    x = 28; //Assign_Error_1 (Error: variable x not declared)
    
    int i = 7.9; //Assign_Error_2 ()

    char c1 = 'F';
    char c2 = 'L';
    char c3 = c1 + c2; //Expression_Error_1 (Error: cannot add variables of type char)
    
    return 0;
}