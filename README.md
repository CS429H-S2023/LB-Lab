# CS429 Assignment 1: Linux Bootcamp Lab

### About this repository
There are several modules in this designed to help 
you start using the Linux terminal and programming in C.
Namely, we focus on the differences between C and Java,
since that's the language you're coming from.

### Part A and B: Linux
Parts A and B of your assignment are about working with the
Linux terminal.
You will have to complete most of part A before cloning
this repository, so make sure that when you do,
you clone it to the `~/cs429/projects/proj1` directory.

The files `partB-ref-18.txt` and `partB-ref-20.txt` are
for you to reference the answer to part B.
You may not use them in your solution.

The `Makefile` contains targets for building part A and
part B automatically, though you will need to fill in the
target for part B to complete the section.

### Part C: Programming in C
The remaining files are for the section on C programming.
The files `pointers.c`, `strings.c`, and `structs.c` contain
materials to help you understand some key differences between
C and Java. The corresponding header files `pointers.h`, `strings.h`,
and `structs.h` contain declarations of the functions and data
structures you will use. You should try completing `pointers.c`,
then `strings.c`, then `structs.c` in that order.

The file `main.c` is the "driver" code that takes your
implementation of each task and tests it automatically.
If you're not familiar with some of the code it contains,
don't worry, because it utilizes some concepts outside the
scope of this class (though if you are really curious, you
can look it up on your own).
You can use the target `make C` to test all your code at once,
or `make pointers`, `make strings`, `make structs` to test
each section individually.

Finally, `debug.c` contains code that runs each test individually
and allows you to utilize GDB to debug your code with the target
`make debug`. You are free to modify this file how you choose,
as it will not be tested on.

### Good luck!
