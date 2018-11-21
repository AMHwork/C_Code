#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 256

/*
This program repeatedly reads its stdin and writes this to stdout
with a line number prepended (i.e. added to the beginning)
*/

int main(int ac,char**av)
{

	char buf[BUFSIZE];
    
    // counter for each line
	int j = 0;

    // infinite loop
	while(1) {

	    int i = 0;
        
        // store the string in a buffer 
		while(i < BUFSIZE) {
			buf[i] = 0;
			i++;
		}

		// read the input from stdin
		read(0, buf, BUFSIZE);

		
		i = 0;

		// convert uppercase to lower case
		while (buf[i] != 0){
			buf[i] = tolower(buf[i]);
			i++;
		}
        
		
		// print the string with the a number line at the beginning
		printf("%d %s", ++j, buf);


	}

	return EXIT_SUCCESS;

}
