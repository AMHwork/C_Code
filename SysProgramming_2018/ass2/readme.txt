Austin Hua
18061765

Solution Logic:
1) first make the program using the command make
2) Once done, enter ./controller on terminal
3) enter your input from stdin and wait for stdout
4) to exit, press control c

files:
c1.c) This file can be run by entering ./c1
      The file works by entering an input and expecting an output.
      The output should be exactly the same as the expected input.

c2.c) This file can be run by entering ./c2
      The file works by entering an input and expecting an output.
      The output should convert all upper alphanumerical characters into lower case.

c3.c) This file can be run by entering ./c3
      The file works by entering an input and expectin an output.
      The output should return a number line after each input entered.

Controller.c) The file works by forking all three files from c1.c,c2.c the program should 
              convert the input of c1.c and returning the ouput of c3.c.

              The logic behind is to create two pipes pipe1 and pipe2 with array size 2.
              fork and if the value is 0, then dup pipe1 and exec ./c1.

              close(0)
              dup(pipe)
              exec (c1)

              Once child one has been processed, execute child2, if the fork value is 0,
              then close stdin and stdout, pipe the process and execute ./c2 this should in turn
              convert the input of c1 and pipe the output of c2.

              close(0) close(1)
              dup(pipe[0]) dup(pipe[1])
              exec (c2)

              Once the child has been processed, execute child3, Since child 2 has been piped,
              pipe1 the output of child2 and pipe the ouput to pipe2. This should in turn add the 
              number line to the output of child2 hence producing the expected output.

              exec(c3)
              dup(pipe2)
              close(0)

Results.

c1.c produces expected output
c2.c produces expected output
c3.c produced expected output
controller.c output c1.c 
controller.c able to obtain input

Limitation:
controller.c does not return expected output all the time.
program is unstable
controller.c has an empty line every consecutive enter.
No command to end the program


