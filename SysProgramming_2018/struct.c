/* this is an implementation of a struct */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char stackitem;

struct stack {
	stackitem d;
	struct stack *next;
};

typedef struct stack ELEMENT;
typedef ELEMENT *POINTER;

void push(POINTER *Top, stackitem a);
void pop(POINTER *Top);
stackitem pop1(POINTER *item);
void push_string(POINTER *Top, char *string);
void print_stack(POINTER Top);
void delete_stack(POINTER *Top);

void push(POINTER *Top, stackitem a)
/* Put item a into the top of the stack */
     {
		POINTER temp;
		temp = malloc(sizeof(ELEMENT));
		temp->d = a;
		temp->next = *Top;
		*Top = temp;
		printf("Insert element %c\n", temp->d);
     }

void pop(POINTER *Top)
/* Remove the top item */
     {
		POINTER Top1 = *Top;
		if (Top != NULL)
		{
		  *Top = Top1->next;
		  printf("Remove element %c\n", Top1->d);
		  free(Top1);
		}
		else
		  printf("Empty stack.\n");
     }

stackitem pop1(POINTER *item){

	POINTER Top1 = *item;
	stackitem n;

	if (item != NULL){
		*item = Top1->next;
		n = Top1->d;
		printf("current element  = %c\n", Top1->d);
		free(Top1);
	}
	else {
		printf("Empty stack.\n");
	}

	return n;

}

void print_stack(POINTER Top)
/*Print the contents of the stack. Do not modify the stack in any way. */
	{
		printf("Start printing the stack ...\n");

		while (Top != NULL){
			printf ("%c->", Top->d);
			Top = Top->next;
		}
		printf("NULL");
		printf("\n");

	}

void delete_stack(POINTER *Top)
/* Delete the stack, i.e. remove all items from the stack */
	{
		printf("Start deleting the stack...\n");

		POINTER current, head;
		current = *Top;

		while (current != NULL){

			POINTER head = *Top;
		    stackitem n;

			current = current->next;
			n = pop1(&head);
			printf("removing element = %c\n", n);
			*Top = current;

		}
	
	}

void push_string(POINTER *Top,char *string)
/* Push a string of characters into a stack. */
	{
		printf("Start inserting the string ...\n");

		int size = strlen(string);
		int n = 0;

		for (n = 0; n < size; n++){
			push(Top, string[n]);
		}

	}

int main (int argc, char *argv[]){

	POINTER top;
	top= (POINTER) NULL;
	stackitem A='A';
	stackitem B='B';
	char *C="12345";
	//printf("C is %s\n", C);
	push(&top,A);
	push(&top,B);
	print_stack(top);
	pop(&top);
	pop(&top);
	print_stack(top);
	push_string(&top,C);
	print_stack(top);
	delete_stack(&top);
	print_stack(top);

}