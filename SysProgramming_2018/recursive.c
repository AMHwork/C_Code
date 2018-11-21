/* Practical lab 3 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int recursive(int n);

int main (int argc, char *argv[]){

	int i;

	printf("Enter a number for the factorial number: ");
	scanf("%d", &i);
	printf("Your factorial number is: %d\n", recursive(i));

	return EXIT_SUCCESS;
}

int recursive(int n) {

	if (n == 0){
		return 1;
	}
	else if (n < 0){
		return -1; // return invalid number
	}
	else {
		return n*recursive(n-1);
	}

}
