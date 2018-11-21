#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

/*
This program implements the controller. It sets up
pipes for the children to communicate, and then invokes the three
programs to perform the tasks.
*/



int main(int ac,char**av)
{

	int pipe1[2];
	pipe(pipe1);
	int pipe2[2];
	pipe(pipe2);
	int forkValue;

	printf("The Controller is starting......\n");

    // check to make sure that the pipe1 has no errors 
	if (pipe(pipe1) == -1) {
		perror("Cannot create pipe1");
		return 0;
	} 
    
     // check to make sure that the pipe2 has no errors
	if (pipe(pipe2) == -1) {
		perror("Cannot create pipe2");
		return 0;
	}

    // processing the information from child 1
	forkValue = fork();
	if (forkValue == 0){
		// obtain stdout and copy it.
		close(1);
		dup(pipe1[1]);
		execl("./c1", "./c1", (char*) NULL); 
	}
	else if (forkValue == -1) {
		perror("Cannot create child1");
		return 0;
	}


	// processing the information from child 2
	forkValue = fork();
	if (forkValue == 0){
		// obtain stdin from c1 and dup to pipe2
		close(1);
		dup(pipe2[1]);
		close(0);
		dup(pipe1[0]);
		execl("./c2", "./c2", (char*) NULL); 
	} 
	else if (forkValue == -1){
		perror("Cannot create child2");
		return 0;
	}

    // processing the information from child 3
	forkValue = fork();
	if (forkValue == 0){
		// obtain pipe2 and output to stdout
		execl("./c3", "./c3", (char*) NULL); 
		close(0);
		dup(pipe2[0]);
	}
	else if (forkValue == -1){
		perror("Cannot create child3");
		return 0;
	}

    // close parent pipes
	close(pipe1[1]);
	close(pipe1[0]);
	close(pipe2[1]);
	close(pipe2[0]);

	printf("Child is now procssing...\n");
	// wait until each child is done before starting the next child
	wait((int*) 0);

	return 0;

}




