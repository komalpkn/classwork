#include <stdio.h>
 int main(void){
  int classNumber;

  printf("What is your class number? ");
  scanf("%d", &classNumber);
  
  printf("Welcome to CMPUT %d", classNumber);
  return 0;
 }
 
