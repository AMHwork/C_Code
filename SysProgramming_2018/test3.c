#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int pid, fd;
	if ((pid=fork()) == -1){
		perror("fork"); exit(1);
	}
	if (pid == 0){
		close(1);
		fd = creat("userlist", 0644);
		execlp("who", "who", NULL);
		perror("execlp");
		exit(1);
	}
	if (pid != 0){
		wait (NULL);
	}
}