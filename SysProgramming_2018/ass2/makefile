CFLAGS = -g -Wall -Werror

all: c1 c2 c3 controller

controller: controller.c
	cc -o controller controller.c
c1: c1.c
	cc -o c1 c1.c

c2: c2.c
	cc -o c2 c2.c
c3: c3.c
	cc -o c3 c3.c

clean:
	rm c1 c2 c3 controller