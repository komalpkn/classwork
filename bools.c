#include <stdio.h>

int main(void){
  int x;
  
  printf("Enter an integer: ");
  scanf("%d", &x);

  if(!x){
    printf("***hi***\nYou entered %d.\n", x);
  }
  else{
    printf("***bye***\n");
  }
  
  if(0==x){
    printf("You entered %d. In c99, 0 is the same as %d\n", x, x);
  }
  else{
    printf("You entered %d. In c99, 0 is not the same as %d\n", x, x);
  }

}
