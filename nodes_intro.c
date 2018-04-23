#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct node *add_to_list(struct node *first, int n_value){
	struct node *newNode;
	newNode = malloc(sizeof(struct node));
	if (newNode != NULL){
		newNode->value = n_value;
		newNode->next = first;
	}
	else {
		fprintf(stderr, "...");
		exit(EXIT_FAILURE);
	}
return newNode;
}

/*Search option 1*/
struct node *search1_list(struct node *list, int n_value){
	struct node *p;
	
	for (p = list; p != NULL; p = p->next){
		if (p->value == n_value){
			return p;
		}
	}
return NULL;
}

/*Search option 2*/
struct node *search2_list(struct node *list, int n){
        // list is local variable here, i.e. is a copy of the original list pointer
	// So, no harm in modifying it. Modifying will not change the original list
	// pointer in the caller funtion (here, main) 
	for(; list != NULL; list = list->next){
		if(list->value == n){
			return list;
		}
	}
return NULL;
}

/*Search option 3*/
struct node *search3_list(struct node *list, int n){
	for(; list != NULL && list->value != n ; list = list->next){ }
return list;
}

/*Search option 4*/
struct node *search4_list(struct node *list, int n){
	while(list != NULL && list->value != n){
		list = list->next;
	}
return list;
}


int main(void){
	struct node *first = NULL;
	int n;

	printf("Enter a series of integers (0 to terminate): ");
	int count = 0;
	for (;;){
		scanf("%d", &n);
		if (n != 0){
			first = add_to_list(first, n);
			count++;
		}
		else {
			break;
		}
	}

	/*Search way 1*/
	struct node *search1;
	int look_for_int1;

	printf("Enter a int to look for using option 1: ");
	scanf("%d", &look_for_int1);
	search1 = search1_list(first, look_for_int1);
	if(search1 != NULL){
		printf("%d\n", search1->value);
	}
	/*Search way 2*/
	struct node *search2;
	int look_for_int2;

	printf("Enter a int to look for using option 2: ");
	scanf("%d", &look_for_int2);
	search2 = search2_list(first, look_for_int2);
	if(search2 != NULL){
		printf("%d\n", search2->value);
	}
	/*Search way 3*/
	struct node *search3;
	int look_for_int3;

	printf("Enter a int to look for using option 3: ");
	scanf("%d", &look_for_int3);
	search3 = search3_list(first, look_for_int3);
	if(search3 != NULL){
		printf("%d\n", search3->value);
	}
	/*Search way 4*/
	struct node *search4;
	int look_for_int4;

	printf("Enter a int to look for using option 4: ");
	scanf("%d", &look_for_int4);
	search4 = search4_list(first, look_for_int4);
	if(search4 != NULL){
		printf("%d\n", search4->value);
	}

while(first != NULL){
	struct node *tempry = first->next;
	free(first);
	first = tempry;
}

return 0;
}
