/*This program illustrates how to check for errors before and while reading a file*/

#include <stdio.h>
#include <stdlib.h> //included to use exit and EXIT_FAILURE

int main(int argc, char *argv[]){
  FILE* fp = fopen(argv[1], "r");
  int n;
   
  if (argc != 2){
    printf("Usage: cannot open filename\n");
    exit(EXIT_FAILURE); 
  }




  if (fp == NULL){    /*if cannot open file*/
    fprintf(stderr, "ERROR: input file %s does not exit.\n", argv[1]);
    exit(EXIT_FAILURE);
  }




  while (fscanf(fp, "%d", &n) != 1){
    if (ferror(fp)){   /*if read error*/ 
      fclose(fp);
      fprintf(stderr, "A read error has occured. Program exited\n");
      exit(EXIT_FAILURE);
    }
   
    if (feof(fp)){  /*The return value of feof is an integer*/
                    /*A nonzero integer(TRUE) signifies that the end of the file has been reached*/
                    /*0(FALSE) signifies that it is not*/
      fclose(fp);
      printf("The input file does not contain lines that begin with an integer\n");
      return 0;  
    }

    fscanf(fp, "%*[^\n]"); /*skips the rest of the line*/
  }
  fclose(fp);
  printf("Found a line that begins with the integer: %d\n", n);
  return 0;
}
