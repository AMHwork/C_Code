/* A Program which shift each character by one, goes to the next alphabet

map a->b b->c, ... z->a
purpose: useful for showing tty modes

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <termios.h>
#include <string.h>

static struct termios stored;

int main(){

	int c;
	while ((c=getchar()) != EOF){
		if ( c == 'z'){
			c = 'a';
		}
		else if (islower(c)) {
			c++;
		}
		void echo_off();
		putchar(c);
	}
}

void echo_off(){
	struct termios new;
	if (tcgetattr(fileno (stream), &old ) != 0){
		return -1;
	}
	else {
		new = old;
		
	}
}


