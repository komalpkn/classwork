/*converts a farenheit to celsius*/

#include <stdio.h>

#define FREEZING_PT 32.0f //boldface for macro definition
#define SCALE_FACTOR (5.0f/9.0f)

int main(void){
  float farenheit, celsius;
 
  for(;;){
    printf("Enter farenheit temp: ");
    if (scanf("%f", &farenheit) == 1){
      celsius = (farenheit - FREEZING_PT) * SCALE_FACTOR;
      printf("\a");
      printf("Celsius equivalent: %.1f\n", celsius);
    }
    else break;
  }
  return 0;
}
  

