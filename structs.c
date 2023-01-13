/****************************************
 * Please be sure to read data_structures.h
 * before beginning this one!
 ****************************************/

#include "structs.h"
#include <stdlib.h>

/****************************************
 * The first task is to create a linked
 * list using the node_t defined in 
 * struct.h. The final list needs to have
 * the elements 1, 2, 3, 4, 5 in that 
 * order, with the last node being null-
 * terminated.
 * 
 * The code written creates the list for
 * you, however, it has a major flaw in 
 * that it will return pointers to local
 * variables, similar to one of the pointer
 * tasks. Your job is to fix this.
 * Hint: allocate space with malloc() and 
 * use pointers insteads.
 ****************************************/
node_t *structs_task_1() {
    node_t *head = NULL;
    for (int i = 5; i > 0; i--) {
        // STUDENT TODO: Replace these lines inside the loop.
        node_t temp;
        temp.data = i;
        temp.next = head;
        head = &temp;
    }
    return head;
}


/****************************************
 * Now, we want to reverse the list we 
 * made in the first task. The basic
 * algorithm is this: loop through the 
 * list and keep track of the previous, 
 * current, and next nodes. At each 
 * iteration, update the current node's
 * next pointer to be the previous node,
 * and move each 
 ****************************************/
node_t *structs_task_2(node_t *head) {
    node_t *prev = NULL;
    node_t *next = head->next;

    // Note: A null pointer has the value 0, so
    // "while(next)" is equivalent to
    // "while(next != NULL)".
    while(next) {
        // STUDENT TODO: Your code here.
    }
    
    head->next = prev;
    return head;
}