#include <stdio.h>

int number = 6;
char letter = 'A';
char str[] = "Hello, World!";
float floatNumber = 6.3;
float floatDecimal = .7;
int array[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
int numberInput;

int i = 0;
int j = 0;

// Create a function
void myFunction() {
   printf("I just got executed!\n");
}

int main() {
   printf("--------------------------\n");
   printf("Call the function:\n");
   myFunction(); // call the function
   
   printf("--------------------------\n");
   printf("Print integer:\n");
   printf("%d\n", number);
   
   printf("--------------------------\n");
   printf("Print letter:\n");
   printf("%c\n", letter);
   
   printf("--------------------------\n");
   printf("Print string:\n");
   printf("%s\n", str);
   
   printf("--------------------------\n");
   printf("Print float:\n");
   printf("%f\n", floatNumber);
   
   printf("--------------------------\n");
   printf("Print float:\n");
   printf("%f\n", floatDecimal);
   
   printf("--------------------------\n");
   printf("Print If... Else:\n");
   if (number > floatNumber) {
      printf("The integer number is greater than the float number.\n");
   } else if (number < floatNumber) {
      printf("The integer number is less than the float number.\n");
   } else {
      printf("The integer number is equal to the float number.\n");
   }
   
   printf("--------------------------\n");
   printf("Print Fibonacci numbers with While Loop:\n");
   while (i < 11) {
      printf("%d): %d\n", i, array[i]);
      i++;
   }
   
   printf("--------------------------\n");
   array[2] = 100;
   printf("Print Wrong Fibonacci numbers with While Loop:\n");
   while (j < 11) {
      printf("%d): %d\n", j, array[j]);
      j++;
   }
   
   printf("--------------------------\n");
   printf("Type a number: \n");
   scanf("%d", &numberInput);
   printf("Your number is: %d\n", numberInput);
   
   return 0;
}