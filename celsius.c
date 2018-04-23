/*Convert farenheit to celsius*/

#include <stdio.h>

#define FREEZING_PT 32.0
#define SCALE_FACTOR (5.0f/9.0f)

int main(void){
  FILE* fp_in1 = fopen("farenheitTemp.txt", "r");
  FILE* fp_out1 = fopen("celsiusTemp.txt", "w");
  float farenheit, celsius;
  
  fscanf(fp_in1, "%f", &farenheit);
  printf("Enter farenheit temp: %0.1f\n", farenheit);
 
  celsius = (farenheit - FREEZING_PT) * SCALE_FACTOR;
  
  printf("Celsius equivalent: %0.1f\n", celsius);
  fprintf(fp_out1, "%0.1f\n", celsius);
   
  fclose(fp_in1);
  fclose(fp_out1);

  return 0;
}
