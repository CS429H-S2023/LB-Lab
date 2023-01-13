# These are variables defined for the makefile.
# Similar to #define's in C, the makefile will
# replace anything inside $(VAR) in a command
# with whatever VAR is equal to. Here, we have
# variables for the C compiler, compiler flags,
# and C source/object files.

CC = gcc
CC_FLAGS = -Wall -Werror -O0 -ggdb -c
RUNNER_FLAGS = -o runner
DEBUG_FLAGS = -ggdb -o debug
SRCS = pointers.c strings.c structs.c
OBJS := $(SRCS:%.c=%.o)


# These are targets defined for the makefile.
# Simply typing "make" in the terminal will
# just run the first target, so in this case
# it's equivalent to "make all". These targets
# are just sequences of terminal commands that
# allow for more streamlined compiling - it's
# convenient to just type "make all".
#
# The basic syntax for a target looks like this:
# <target name>: <dependencies>
#	<commands>
# The dependencies must be other targets, which
# are run in the order they appear when this target
# is invoked. If a dependency is already up to date,
# (i.e., the files it creates already exist,) then
# it is skipped. Then, the commands (which must 
# have a tab-length space in front of them) 
# are run in order.

# This target will be run for your final submission.
all: linux c clean

# Students will need to add dependencies to this
linux: partA.txt partB.txt

partA.txt:
	ls -lrR ~/cs429 > partA.txt

partB.txt:
# STUDENT TODO: Put your commands for part B here.

# This target compiles the main runner executable.
c: runner

runner: $(OBJS)
	$(CC) $(RUNNER_FLAGS) -DPOINTERS -DSTRINGS -DSTRUCTS main.c $(OBJS)
	./runner

# This is a more generic target that will 
# compile any .c source file into a corresponding
# .o object file. For example, if we type
# "make pointers.o" at the command line,
# this will expand to "gcc -Wall -Werror -O0 -ggdb -c pointers.c"
# and create the file pointers.o

%.o: %.c
	$(CC) $(CC_FLAGS) $<

# These are for testing each module individually.
pointers: pointers.o
	$(CC) $(CFLAGS) -DPOINTERS main.c pointers.c
	./runner

strings: strings.o
	$(CC) $(CFLAGS) -DSTRINGS main.c strings.c
	./runner

structs: structs.o
	$(CC) $(CFLAGS) -DSTRUCTS main.c structs.c
	./runner

# This target compiles the code and opens GDB for debugging.
debug: $(OBJS)
	$(CC) $(DEBUG_FLAGS) -DPOINTERS -DSTRINGS -DSTRUCTS debug.c $(OBJS)
	gdb debug


# Finally, this target is just used to remove 
# any executables leftover for when you're done
# - it's just good practice to not include
# these when you make a commit or submission.
clean:
	rm -rf *.o runner debug


# By default, targets are file names.
# If a file with the name of the target exists,
# then make will assume that no more changes 
# need to be made to the file, and it will 
# simply print a message saying "already up to date".
# So for example, if we have a file named "all"
# created, then "make all" would fail even though
# that's not what we want. Declaring it as a
# "phony" target tells make that we don't care about
# the file "all" and allows it to work even if
# the file already exists. 

.PHONY: all clean linux c pointers strings structs
