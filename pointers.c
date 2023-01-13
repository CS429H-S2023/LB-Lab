/****************************************
 * Note: This is meant to be the first
 * module for you to look at! Most other
 * modules will build off of information
 * used here, though none will reuse this
 * code.
 * 
 * This series of tasks is meant to
 * help you better understand how to use
 * pointers in C. This is the main C
 * concept that is (probably) new to you,
 * since pointers are abstracted away in
 * Java.
 * 
 * Simply put, a pointer is just a memory
 * address. You can think of memory as a
 * giant array of bytes, and a pointer is
 * just an index into that array. Pointers
 * are declared by adding an asterisk to
 * the data type in C, and they are
 * "de-referenced" by putting an asterisk
 * in front of the variable name. You can
 * get the address of a variable (that is,
 * get a pointer to it) by using an
 * ampersand before a variable.
 * 
 * Example:
 * int a = 10;
 * int *b;
 * b = &a;
 * *b = 2;
 * 
 * This code creates an int a with the 
 * value 10, creates a pointer to it named
 * b, and changes the value b points to
 * to 2 (which also changes the value of
 * a to 2).
 * If you were to try reading the last two
 * lines in English, it would be 
 * "b equals the address of a", and 
 * "the value at b in memory equals 2".
 * 
 * Also to note, arrays in C are actually 
 * just contiguous blocks of memory with a
 * pointer to their first element.
 * 
 * Example:
 * int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
 * and
 * int *array = malloc(10*sizeof(int));
 * for (int i = 0; i < 10; i++) array[i] = i;
 * will create an array with the same values
 * (the function malloc() is explained 
 * further down).
 ****************************************/

/****************************************
 * These #include statements are just like
 * import statements in Java, they look
 * for a file with the matching name and
 * include the definitions contained there.
 * The difference between using "" vs. <>
 * around the file name is where it's defined
 * - quotes "" are used when the file is in 
 * the same directory as the C source file,
 * and angle brackets <> are used when it is
 * not, such as when we're using a standard 
 * library.
 ****************************************/
#include "pointers.h"
#include <stdlib.h>

/****************************************
 * Building off of the example, we can
 * use pointers to remedy this issue.
 * For this task, a and b are now pointers
 * to ints, and you need to swap the
 * values pointed to, such that the change
 * is persistent. To do this, you'll need
 * to de-reference the pointers and set
 * the value that way.
 * 
 * Obviously, this example is a bit trivial,
 * but this concept will also apply to arrays
 * and data structures later on.
 ****************************************/
void pointers_task_1(int *a, int* b) {
    // STUDENT TODO: Uncomment and replace the 
    // question marks with appropriate code.
    // int temp = ?;
    // *a = ?;
    // *b = ?; 
}

/****************************************
 * Sometimes, you'll need to allocate
 * memory for a variable or data structure
 * and return a pointer to it. However,
 * local variables are always stored on
 * the stack, as you'll learn later in the
 * course, and therefore it's possible
 * they end up getting overwritten once
 * the function returns.
 * 
 * In such cases, you'll want to
 * dynamically allocate memory from the
 * heap with malloc(size). This function 
 * takes the number of bytes you want to
 * allocate as an argument, and returns a
 * pointer to the space that was allocated.
 * 
 * For this task, we want to return the
 * array [4, 2, 9], and what's currently
 * written suffers from the issue I 
 * mentioned above (in fact, the compiler
 * will give you a warning about this as 
 * well, and the -Werror flag prevents this
 * from compiling at all). Fix it by using 
 * malloc() to produce the desired result.
 * 
 * Also to note, the sizeof(data type) 
 * operator, which gets the number of bytes 
 * a data type uses, will be useful here.
 ****************************************/
int *pointers_task_2() { 
    int array[3]; // STUDENT TODO: Replace this line.
    array[0] = 4;
    array[1] = 2;
    array[2] = 9;
    return array;
}

/****************************************
 * Finally, as a side note, there is no
 * garbage collector in C. Once we're 
 * done with the memory we dynamically 
 * allocate (this does not include local
 * variables), we need to manually free it 
 * with free(pointer). Forgetting to do
 * this results in a memory leak, which 
 * causes large slowdowns in your programs
 * over time and can cause other strange
 * errors.
 * 
 * Don't worry about freeing things for
 * this assignment, as we need your results
 * for testing correctness and free them
 * when we're done.
 * **************************************/