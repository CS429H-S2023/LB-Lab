/****************************************
 * The typedef keyword allows us to define
 * a new datatype. It's mostly useful for
 * providing a shorthand notation for
 * data structures. In this example, we
 * have a node data structure for part of
 * a linked list. It's defined as
 * "struct node", but with the typedef
 * keyword, we can shorten this to node_t.
 * 
 * Note that there's a convention of
 * ending the typedef'd name with "_t",
 * but there's nothing special about it
 * except that VSCode will recognize it
 * and give it a different highlighting
 * color.
 * 
 * Now that we've defined this struct
 * here, any C source file that includes
 * data_structures.h will be able to use 
 * it. There are two ways we can use this
 * struct in our code, either as an 
 * instance of the struct itself, or as
 * a pointer to the struct. 
 * 
 * Example:
 * struct node n;
 * node_t m;
 * n.next = &m;
 * n.data = 10;
 * 
 * Note that we can use struct node and node_t
 * interchangeably as is done here, because of
 * the typedef.
 * 
 * Pointer Example:
 * struct node *n = malloc(sizeof(struct node));
 * node_t *m = malloc(sizeof(node_t));
 * n->next = m;
 * n->data = 10;
 * 
 * Note that you're probably used to using
 * the "new" keyword in Java to declare 
 * a new data structure. This keyword 
 * doesn't exist in C, and you must
 * manually allocate space with malloc().
 * 
 * In the first example, we are working
 * with the nodes directly, so we use
 * the dot . syntax to access the fields 
 * of the node. In the second example, 
 * we have pointers to the nodes, so we
 * use the arrow -> syntax to acccess 
 * the fields of the node. Note that the 
 * arrow is another way of dereferencing
 * the pointer, so the pointer must be
 * a valid memory location. You will find 
 * that pointers are most commonly used, 
 * since C is a pass-by-value language and
 * if we want a function's changes to a 
 * struct to be persistent, we need to
 * use pointers.
 ****************************************/

typedef struct node {
    struct node *next;
    unsigned long data;
} node_t;

node_t *structs_task_1();
node_t *structs_task_2(node_t *head);