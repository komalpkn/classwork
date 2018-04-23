#include <stdio.h>
#include <stdlib.h>

 int count = 0;
 
 struct node{
         int value;
         struct node* next;
         struct node* prev;
 };
 
 struct node* add_to_front(struct node* first, int val);
 void print_F_to_L(struct node* first);
 void print_L_to_F(struct node* first);
 struct node* search_n(struct node* first, int n);
 struct node* delete_n(struct node* first, int n);
 struct node* ordered_add(struct node* first, int n);
 void free_mem(struct node* first);
 
 int main(){
         struct node* first = NULL;
         int n;
	
         printf("Enter an ascending series of positive integres (0 to terminate): ");
         for (;;){   // create linked list
                 scanf("%d", &n);
                 if (n != 0){
                         count++;
                         first = add_to_front(first, n); }
                 else{
                         break;
                 }
         }
	
         if (count != 0){
                 print_F_to_L(first); // print frist added to last added
                 print_L_to_F(first); // print last added to first added
	}
 
	printf("Enter a value to search: "); scanf("%d", &n);
	if (search_n(first, n) != NULL){
		printf("Found %d\n", n);}
	else{
		printf("Did not find %d\n", n);
	}	

	printf("Enter a boundary value to delete: "); scanf("%d", &n);
	first = delete_n(first, n);

        if (count != 0){
                 print_F_to_L(first); // print frist added to last added
                 print_L_to_F(first); // print last added to first added
	}
 
	printf("Enter a value to ordered add: "); scanf("%d", &n);
	first =	ordered_add(first, n);

        if (count != 0){
                 print_F_to_L(first); // print frist added to last added
                 print_L_to_F(first); // print last added to first added
	}
 
	if (count != 0){
                 free_mem(first);
         }
 return 0;
 }

 struct node* ordered_add(struct node* first, int n){
	struct node* newNode = malloc(sizeof(struct node));
	if (newNode == NULL){fprintf(stderr, "ordered_add newNode malloc fail\n"); exit(EXIT_FAILURE);}
	newNode->value = n;
	if (first == NULL){ //empty linked list
		first = newNode;
		first->prev = NULL;
		first->next = NULL;
	}
        else if (first->value <= n){ // n >= first node
		first->next = newNode;
		newNode->prev = first;
		newNode->next = NULL;
		first = newNode;
	}

	else{
		struct node* curr = first;
		while(curr != NULL && curr->value > n){
			if (curr->prev == NULL){
				curr->prev = newNode;
				newNode->next = curr;
				newNode->prev = NULL;
				break;
			}
			else if(curr->prev != NULL && (curr->prev)->value <= n){
				newNode->prev = curr->prev;
				(curr->prev)->next = newNode;
				curr->prev = newNode;
				newNode->next = curr;
				break;	}
			else{
				curr = curr->prev;
			}
		}
	}
 count++;
 return first;
 }

 struct node* delete_n(struct node* first, int n){
	struct node* curr = first;
	struct node* temp = NULL;
	
	while(curr != NULL && curr->value != n){
		temp = curr;
		curr = curr->prev;
	}

	if(curr == NULL){ // n not found
		return first; 	}
	else if(temp == NULL){ // n found in first node
		if (first->prev != NULL){
			first = first->prev;
			free(first->next);
			first->next = NULL;
			count--;   }
		else{
			free(curr);
			count--;
			first = NULL;
		}
		return first;
	}
	else{ // n found in other than first node
		if (curr->prev != NULL){
			temp->prev = curr->prev;
			(temp->prev)->next = temp;  }
		else{
			temp->prev = NULL;
		}
		free(curr);
		count--;
		return first;
	}
 }
 
 struct node* search_n(struct node* first, int n){
	for(; first != NULL && first->value != n; first = first->prev);
 return first;
 }

 void print_F_to_L(struct node* first){
          struct node* temp = first;
	  while(temp->prev != NULL){
                  temp = temp->prev;
          }
          printf("First added to last: ");
          while (temp != NULL){
                 printf("%d ",temp->value);
                 temp = temp->next;
         }
         printf("\n");
 return;
 }
 
 void print_L_to_F(struct node* first){
         struct node* temp = first;
         printf("Last added to first: ");
         while (temp != NULL){
                 printf("%d ", temp->value);
                 temp = temp->prev;
         }
         printf("\n");
 return;
 }
 
 void free_mem(struct node* first){
         struct node* temp = first;
         while (first != NULL){
		 temp = first->prev;
                 free(first);
		 first = temp;
         } 
return;
}
 
struct node* add_to_front(struct node* first, int val){
        struct node* newNode = malloc(sizeof(struct node));
         if(newNode == NULL){
                 fprintf(stderr, "add_to_front newNode malloc fail\n");
                 exit(EXIT_FAILURE);
         }
         else{
                  if(first == NULL){
                         newNode->value = val;
                         newNode->next = first;
                         newNode->prev = NULL;
                         return newNode;
                 }
                 else{
                         first->next = newNode;
                         newNode->value = val;
                         newNode->next = NULL;
                         newNode->prev = first;
                         return newNode;
                 }
         }
}
