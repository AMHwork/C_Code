/* this is a program to print a pyramid of stars */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

	int height, space, i, j;

    printf("how high do you want your pyramid to be?: \n");
    scanf("%d",&height);

    for(i=1; i<=height; ++i, j=0)
    {
        for(space=1; space<=height-i; ++space)
        {
            printf("  ");
        }

        while(j != 2*i-1)
        {
            printf("* ");
            ++j;
        }

        printf("\n");
    }
    
    return 0;
}