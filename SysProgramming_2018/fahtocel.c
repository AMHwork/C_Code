/* This program is for fahtocel.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int celc(int);

int main (int argc, char* argv[]){
	int temp;

    printf("\nPlease enter temp F ");
    scanf("%d", &temp);

    printf("\n%dF to centigrade is %dC\n", temp, celc(temp));
    
    return EXIT_SUCCESS;
}

int celc(int f)
 {
     return 5*(f - 32)/9;

 }
