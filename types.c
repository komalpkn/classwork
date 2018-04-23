#include <stdio.h>

#define BOOL int
typedef int Bool;

int main(void){
  BOOL flag1 = 0;
  Bool flag2 = 1;

  printf("Value of flag1 defined through #define is: %d \nValue of flag2 defines through typedef is: %d \n", flag1, flag2);
 
  printf("Size of an int is  : %zu \nSize of a float is : %zu \nSize of a double is: %zu\n", sizeof(int), sizeof(float), sizeof(double));
  
  printf("Size of 100 is     : %zu \nSize of 100.578f is: %zu \nSize of 100.578 is: %zu\n", sizeof(100), sizeof(100.578f), sizeof(100.578));

return 0;
}
