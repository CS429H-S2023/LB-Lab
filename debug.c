#include "pointers.h"
#include "strings.h"
#include "structs.h"

/*********************************
 * The main testing suite doesn't
 * lend itself well for using GDB,
 * so this small script runs the 
 * same tests in a more suitable
 * format.
 *********************************/

static int init_buffer(char *buf, int len) {
    for(int i = 0; i < len; i++) {
        buf[i] = 'a' + (i%26);
    }
    buf[len-1] = 0;
}

int main (void) {
    /* Pointer tasks */
    int a = 10, b = 2;
    pointers_task_1(&a, &b);
    pointers_task_2();

    /* String tasks */
    char buf[256];
    int len = 256;
    init_buffer(buf, len);
    strings_task_1(buf);
    init_buffer(buf, len);
    buf[12] = 0;
    strings_task_2(buf);
    init_buffer(buf, len);
    buf[16] = 0;
    strings_task_3(buf);

    /* Struct tasks */
    node_t *head = structs_task_1();
    head = structs_task_2(head);

    return 0;
}