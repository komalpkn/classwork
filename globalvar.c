#include <stdio.h>
#define SIZE 10

int main(void){
  printf("%d", SIZE);
  int x = SIZE;
  printf("%d", x);
  int SIZE = 2;
  printf("%d", SIZE);

  return 0;
}
