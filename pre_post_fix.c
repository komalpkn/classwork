/*Prefix and postfix*/

#include <stdio.h>

int main(void){
  int i, j, k, m;
  i = 1;
  j = 2;

  k = ++i + j++;
  m = j++ - 1;
  
  printf("k = %d, m = %d\n", k, m);

}
