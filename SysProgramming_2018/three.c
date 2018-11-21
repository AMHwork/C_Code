/* conversion of three numbers */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

	if (var1 < var2 && var1 < var3){
		printf ("the smallest number out of the three variables is %d\n.", var1);
	}
	else if (var2 < var3){
		printf ("the smallest number out of the three variables is %d\n.", var2);
	}
	else {
		printf ("the smallest number out of the three variables is %d\n.", var3);
	}

	return EXIT_SUCCESS;

}