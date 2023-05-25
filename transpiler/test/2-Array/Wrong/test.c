int main() {
    int array[4] = {1, 2, 3, 4};
    
    //Init Error:
    int myArray[]; //ArrayInit_Error_1 (Error: array size missing in ‘myArray’ !!!)
    int myArray2[] = 24; //ArrayInit_Error_2 (Error: invalid initializer !!!)
    int myArray3[3] = 24; //ArrayInit_Error_3 (Error: invalid initializer !!!)
    
    //Assignment Error:
    array[] = {}; //ArrayAssign_Error_1 (Syntax Error)
    array[3] = {}; //ArrayAssign_Error_2 (Syntax Error)
    array[] = 24; //ArrayAssign_Error_3 (Syntax Error)
    array[] = {24, 27, 29}; //ArrayAssign_Error_4 (Syntax Error)
    array[3] = {24, 27, 29}; //ArrayAssign_Error_5 (Syntax Error)
    
    //Length Error:
    array[5] = 6; //ArrayLength_Error (Error: the length of array is 4)
    
    return 0;
}
