#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/wait.h>
#include <signal.h>

int stack_size = 1024 * 1024;

void* child_function(void *arg){
    printf("this is child\n");
    _exit(0);
}

int main(){

    char *stack = malloc(stack_size);
    if (!stack) {
        perror("malloc failed");
        exit(1);
    }

    char *stack_top = stack + stack_size;

    int flags = SIGCHLD;

    int pid = clone(child_function, stack_top, flags, NULL);
    if (pid == -1) {
        perror("clone failed");
        exit(1);
    }

    printf("this is parent\n");

    waitpid(pid, NULL, 0);

    free(stack);
    return 0;
}
