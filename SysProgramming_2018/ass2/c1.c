#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 256

/*
This program repeatedly prompts the user for input,
reads this input in and writes it to stdout. You may send your
prompts to stderr.
*/

int main(int ac, char**av)
{

	/* add your code */
	char buf[BUFSIZE];

	fprintf(stderr, "Enter your text phrase:\n");
	
	// enters a while loop to loop through the buffersize
	while (1){
		// stores the buffer size
		int i = 0;
		while (i < BUFSIZE){
			buf[i] = 0;
			i++;
		}
		// read the input through stdin
		read(0, buf, BUFSIZE);

        // print out the string 
		printf("%s", buf);
	}

	return EXIT_SUCCESS;

}


