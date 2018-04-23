/*Type conversion during assignment*/

#include <stdio.h>

int main(void){
  int i;
  float f;

  i = 72;
  f = 136;
  
  printf("\nIn the assignment v = e, if v and e do not have the same type,\nthe value of e is converted to the type of v during assignment\n");
  printf("The assignment i = 72 results to i = %d, f = %f\n", i, f); 
  
  i = 72.99;
  f = 136;
  printf("The assignment i = 72.99 (WARNING: implicit conversion from 'double' to 'int') results to i = %d, f = %f\n", i, f);
  
  i = 72.99f;
  f = 136;
  printf("The assignment i = 72.99f (WARNING: implicit conversion from 'float' to 'int) results to i = %d, f = %f\n", i, f);


  return 0;
}
