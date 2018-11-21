#include <stdlib.h>
#include <stdio.h>

void swap (int* s, int* t){
	int w;
	w = *s;
	*s = *t;
	*t = w;
}

int main(){

	int i=10, j=20;
	printf("Before swap: i = %d and j = %d \n", i, j);
	swap(&i, &j);
	printf("After swap: i = %d and j = %d \n", i, j);
}