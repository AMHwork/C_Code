#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 256

/*
This program reapeatly reads its stdin, converts the upper case of
the input to lower case, and writes this to stdout.
*/

int main(int ac,char**av)
{

	/* add your code */
	char buf[BUFSIZE];

	while(1){

		int i = 0; 
        
		// create the buffr size for the string 
		while (i < BUFSIZE){
			buf[i] = 0;
			i++;
		}

		// read the input from stdin
		read(0, buf, BUFSIZE);
        
        // reset the buff postion back to zero
		i = 0;

		// convert uppercase to lower case
		while (buf[i] != 0){
			buf[i] = tolower(buf[i]);
			i++;
		}

        // printf the string out 
		printf("%s", buf);
	}

	return EXIT_SUCCESS;

}
