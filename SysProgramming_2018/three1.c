/* conversion of three numbers */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int convert (int x, int y, int z);

int main (int argc, char* argv[]){

	int var1;
	int var2;
	int var3;

	printf("Enter var1\n");
	scanf("%d", &var1);
	printf("Enter var2\n");
	scanf("%d", &var2);
	printf("Enter var3\n");
	scanf("%d", &var3);

	convert(var1,var2,var3);

	return EXIT_SUCCESS;
} 

int convert (int x, int y, int z){

	if (x < y && x < z){
		return printf ("the smallest number out of the three variables is %d\n.", x);
	}
	else if (y < z){
		return printf ("the smallest number out of the three variables is %d\n.", y);
	}
	else {
		return printf ("the smallest number out of the three variables is %d\n.", z);
	}
}