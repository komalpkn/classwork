#include <stdio.h>
#include <stdlib.h>

int main(void){
  FILE *fp = fopen("test_read_file.txt", "w");
  int one = 1, two = 2, courseNum = 201;
  char *char1 = "hello", *char2 = "cmput";

  fprintf(fp, "%d %s\n%d %s %d:\n", one, char1, two, char2, courseNum);
  fclose(fp);
}
