#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

void check_malloc(void *p){
	if(p == NULL){
		fprintf(stderr, "ERROR: malloc failed\n");
		exit(EXIT_FAILURE);
	}
return;
}

void check_realloc(void *p){
	if(p == NULL){
		fprintf(stderr, "ERROR: realloc failed\n");
		exit(EXIT_FAILURE);
	}
return;
}

int main(void){
	char *str1 = malloc(SIZE + 1);
	check_malloc(str1);

	strcpy(str1, "Hello");
	printf("malloc str1 = %s\n", str1);

	char *tempry = realloc(str1, 2*SIZE + 1);
	check_realloc(tempry);	

	str1 = tempry;
	printf("realloc str1 = %s\n", str1);
	strcpy(str1, "Hello there CMPUT201");
	printf("Longer value of str1 = %s\n", str1);
	
	free(str1);

return 0;
}
