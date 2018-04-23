#include <stdio.h>

int sum(int a, int b){
return a+b;
}

int multiply(int a, int b){
return a*b;
}

int operate(int (*func)(int, int), int a, int b){
return (*func)(a, b);
}

int main(){
	printf("1+2 = %d\n", operate(sum, 1,2));
	printf("3*4 = %d\n", operate(multiply, 3, 4));
return 0;
}
