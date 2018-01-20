/*Convert farenheit to celsius*/

#include <stdio.h>

#define FREEZING_PT 32.0
#define SCALE_FACTOR (5.0f/9.0f)

int main(void){
  float farenheit, celsius;
  printf("Enter farenheit temo: ");
  scanf("%f", &farenheit);

  celsius = (farenheit - FREEZING_PT) * SCALE_FACTOR;
  
  printf("Celsius equivalent: %0.1f\n", celsius);
  return 0;
}
