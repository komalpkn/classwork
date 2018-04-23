#include <stdlib.h>

void createEntry(int **p, int value){
    *p = malloc(sizeof(int));
    **p = value;
}

int main(){
    int *array[3];
    int **p;
    
    for (int i = 0 ; i < 3; i++){
        p = &array[i]; 
        createEntry(p, i + 1);
    }
    
    free(*p);

    return 0;
}
