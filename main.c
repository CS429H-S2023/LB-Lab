/****************************************
 * Testing suite for the C modules.
 * Refer to the individual source files
 * for more details.
 ****************************************/

#ifdef POINTERS
#include "pointers.h"
#endif
#ifdef STRINGS
#include "strings.h"
#endif
#ifdef STRUCTS
#include "structs.h"
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUF_SIZE 256
#define NUM_POINTER_TASKS 2
#define NUM_STRING_TASKS 3
#define NUM_STRUCT_TASKS 2

/********************************
 * Any modifications to this
 * file will not be reflected in
 * your final submission.
 * ******************************/

#ifdef POINTERS
static int pointer_tests() {
    /* Verify pointer tasks */
    int tests_passed = 0;

    /* Task 1 */
    int a = 10, b = 2;
    pointers_task_1(&a, &b);
    if (a == 2 && b == 10) {
        printf("Passed pointers task 1\n");
        tests_passed += 1;
    }
    else {
        printf("Failed pointers task 1\n\tYour output: %d, %d\n\tCorrect output: 2, 10\n", a, b);
    }

    /* Task 2 */
    int *answer = pointers_task_2();
    int child_status;
    pid_t child = fork();

    if(child == -1) {
        exit(1);
    }
    if(child == 0) {
        if (answer[0] == 4 && answer[1] == 2 && answer[2] == 9){
            free(answer);
            exit(0);
        }
        exit(1);
    }
    else {
        waitpid(child, &child_status, 0);
        if(!child_status) {
            printf("Passed pointers task 2\n");
            free(answer);
            tests_passed += 1;
        }
        else if(WEXITSTATUS(child_status) == 1){
            printf("Failed pointers task 2\n\tYour output: [%d, %d, %d]\n\tCorrect output: [4, 2, 9]\n", answer[0], answer[1], answer[2]);
            free(answer);
        }
        else {
            printf("Failed pointers task 2\n\tYour output: Segmentation Fault\n\tCorrect output: [4, 2, 9]\n");
        }
    }
    return tests_passed;
}
#endif

#ifdef STRINGS
/* Initialize the string buffer. */
static void init_buffer(char *buf, size_t len) {
    for(int i = 0; i < len; i++) {
        buf[i] = 'a' + (i%26);
    }
    buf[len-1] = 0;
}

static int string_tests() {
    /* Verify string tasks */
    int tests_passed = 0;
    char buf[BUF_SIZE];
    init_buffer(buf, BUF_SIZE);

    /* Task 1 */
    strings_task_1(buf);
    char *answer = "CS429";

    if(!strcmp(buf, answer)) {
        printf("Passed strings task 1\n");
        tests_passed += 1;
    }
    else {
        printf("Failed strings task 1\n\tYour output: %s\n\tCorrect output: %s\n", buf, answer);
    }

    /* Task 2 */
    init_buffer(buf, BUF_SIZE);
    buf[12] = 0;

    strings_task_2(buf);
    answer = "ABCDEFGHIJKL";

    if(!strcmp(buf, answer)) {
        printf("Passed strings task 2\n");
        tests_passed += 1;
    }
    else {
        printf("Failed strings task 2\n\tYour output: %s\n\tCorrect output: %s\n", buf, answer);
    }

    /* Task 3 */
    init_buffer(buf, BUF_SIZE);
    buf[16] = 0;

    answer = strings_task_3(buf);

    if(answer && !strcmp(buf, answer)) {
        printf("Passed strings task 3\n");
        tests_passed += 1;
        free(answer);
    }
    else {
        printf("Failed strings task 3\n\tYour output: %s\n\tCorrect output: %s\n", answer, buf);
    }
    return tests_passed;
}
#endif

#ifdef STRUCTS
static int struct_tests() {
    /* Verify struct tasks */
    int tests_passed = 0;

    /* Task 1 */
    int child_status;
    pid_t child = fork();

    if(child == -1) {
        exit(1);
    }
    if(child == 0) {
        /* Task 1 */
        node_t *head = structs_task_1();
        int total = 0;
        int passed = 1;
        node_t *temp = head;
        for (int i = 1; i <= 5; i++) {
            if (temp->data != i) passed = 0;
            temp = temp->next;
        }
        if (passed) {
            printf("Passed struct task 1\n");
            total++;
        }
        else {
            printf("Failed struct task 1\n\tYour output: ");
            temp = head;
            for (int i = 0; i < 5; i++) {
                printf("%ld ", temp->data);
                if (i < 4) {
                    printf("-> ");
                }
                temp = temp->next;
            }
            
            printf("\n\tCorrect output: 1 -> 2 -> 3 -> 4 -> 5\n");
        }
        /* Task 2 */
        head = structs_task_2(head);
        passed = 1;
        temp = head;
        for (int i = 5; i > 0; i--) {
            if (temp->data != i) passed = 0;
            temp = temp->next;
        }
        if (passed) {
            printf("Passed struct task 2\n");
            total++;
        }
        else {
            printf("Failed struct task 2\n\tYour output: ");
            temp = head;
            for (int i = 0; i < 5; i++) {
                printf("%ld ", temp->data);
                if (i < 4) {
                    printf("-> ");
                }
                temp = temp->next;
            }
            
            printf("\n\tCorrect output: 5 -> 4 -> 3 -> 2 -> 1\n");
        }
        exit(total);
    }
    else {
        waitpid(child, &child_status, 0);
        if(WEXITSTATUS(child_status) < 0 || WEXITSTATUS(child_status) > 2) {
            printf("Failed struct tasks - Segmentation Fault\n");
        }
        if (WEXITSTATUS(child_status) >= 0 && WEXITSTATUS(child_status) <= 2) tests_passed = WEXITSTATUS(child_status);
    }
    return tests_passed;
}
#endif

/* Run all tests. */
int main(int argc, char **argv) {
    int tests_passed = 0;
    int total_tests = 0;
    printf("--------------------------\n");
    
    #ifdef POINTERS
    tests_passed += pointer_tests();
    total_tests += NUM_POINTER_TASKS;
    printf("--------------------------\n");
    #endif

    #ifdef STRINGS
    tests_passed += string_tests();
    total_tests += NUM_STRING_TASKS;
    printf("--------------------------\n");
    #endif

    #ifdef STRUCTS
    tests_passed += struct_tests();
    total_tests += NUM_STRUCT_TASKS;
    printf("--------------------------\n");
    #endif
    
    printf("Total tasks passed: %d out of %d\n", tests_passed, total_tests);
    
    return 0;
}