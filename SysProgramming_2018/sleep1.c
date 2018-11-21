/* hello1.c
 *	purpose	 show the minimal calls needed to use curses
 *	outline  initialize, draw stuff, wait for input, quit
 */

#include	<stdio.h>
#include	<curses.h>
#include    <unistd.h>
#include    <signal.h>
#include    <string.h>
#include    <sys/ioctl.h>


void wakeup(int signum);
void alarmhandle(int signal);

int main(int argc, char* argv[])
{

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int rowNum = w.ws_row/2-1;
    int colNum = w.ws_col/2-1;

    char str[] = "Hello, world";

	initscr();		/* turn on curses	*/


	while (1){

		move(rowNum, colNum);

		if (argc > 1){
		    addstr(argv[1]);
		    sleep(1);
		    refresh();
	    }
	    else if (argc == 1){
		    addstr(str);
		    sleep(1);
		    refresh();
	    }

	    move(rowNum, colNum);
	    signal(SIGALRM, wakeup);
	    alarm(1);
	    refresh();

	    sleep(3);
	    move(rowNum, colNum);
	    refresh();	   

	}


	getch();		/* wait for user input	*/
	endwin();		/* turn off curses	*/

	return 0;
}

void wakeup(int signum){
	clear();
	refresh();
}



