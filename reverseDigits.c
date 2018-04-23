/*Asks user to enter a two-digit number. Print a number with the digits in reverse order*/


#include <stdio.h>

int main(void){
  int userInput, reversedNum = 0, remainder;

  printf("*****Enter a positive integer: ");
  scanf("%d", &userInput);
 
  while(userInput != 0){
    printf("reversedNum = %d, userInput = %d\n", reversedNum, userInput);
    remainder = userInput%10;
    reversedNum = reversedNum*10 + remainder;
    userInput /= 10;
    printf("remainder = %d, reversedNum = %d\n", remainder, reversedNum);
  }

  printf("*****The reversal is: %d*****\n", reversedNum);

  return 0;

}
