/* this is a program for  fahtocel1.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char* argv[]){
   int fah, cel;
   int lower, upper, step;
   lower=0;  /*lower limit of the temperature table */
   upper=200;  /* upper limit */
   step=10;  /*step size */
   for (fah=lower;fah<=upper; fah=fah+step){
     cel=5*(fah-32)/9;
     printf("%d\t%d\n", fah, cel);
   }

   return EXIT_SUCCESS;

}