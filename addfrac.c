#include <stdio.h>
 int main(void){
  int num1, denom1, num2, denom2, result_num, result_denom;
  float result_frac;

  printf("Enter first fraction: ");
  scanf("%d/%d", &num1, &denom1);

  printf("Enter second fraction: ");
  scanf("%d/%d", &num2, &denom2);

  result_num = (num1*denom2) + (num2*denom1);
  result_denom  = denom1*denom2;
  result_frac = result_num/result_denom;

  printf("The sum is: %.2f\n", result_frac);
  
  return 0;
 } 
