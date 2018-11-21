/* this is a program to make link list using a loop */

#include <stdio.h>
#include <stdlib.h>

typedef char DATA ;
struct node
{
    DATA d ;
    struct node * next ;
};

struct node *head;

void printList (struct node * head){
	struct node * current = head;

	while (current != NULL){
		printf("%d->", current->d);
		current = current->next;
	}
	printf("NULL");
	printf("\n");
	    
}

void printReverse(struct node * head){
	struct node *current = head;
	struct node *prev = NULL;
	struct node *next = NULL;

	while (current != NULL){
		current = next;
		next = current->next;
		current->next = prev;
		prev = current;
	}
	head = prev;
	printList(head);
}

void addFront(DATA value){
	struct node * newNode;
	newNode = malloc(sizeof(struct node));
	newNode->d = value;
	newNode->next = head;
	head = newNode;	
}

void addEnd (DATA value){
	struct node * newNode;
	newNode = malloc(sizeof(struct node));
	newNode->d = value;
	newNode->next = NULL;
	struct node * current = head;
	struct node * prev = NULL;

	if (head == NULL){
		head = newNode;
	}
	else {
		while(current != NULL){
			prev = current;
			current = current->next;
		}
		prev->next = newNode;
	}

}

int main() {

    int i,max,new;
	printf("how long is your link list?\n");
	scanf("%d",&max);

	for (i = 0; i<max; i++){
		printf("enter value: ");
		scanf("%d",&new);
		//addFront(new);
	    addEnd(new);
	    printList(head);
	}



/*
	// This is to print out a fixed list which has already been made

	struct node *test_list = malloc(sizeof(struct node));
    test_list->d = 1;
    test_list->next = malloc(sizeof(struct node));
    test_list->next->d = 2;
    test_list->next->next = malloc(sizeof(struct node));
    test_list->next->next->d = 3;
    test_list->next->next->next = malloc(sizeof(struct node));
    test_list->next->next->next->d = 4;
    test_list->next->next->next->next = NULL;

    printList(test_list);
    printReverse(test_list);

*/

}





