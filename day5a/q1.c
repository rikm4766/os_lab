#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define STACK_SIZE (1024 * 1024)

void alarmhandler(int sig){
    printf("termainating child process\n");
    // exit(1);
    return ;
}

int child_func(void *arg) {
    printf("Child PID: %d\n", getpid());
    alarm(5);
    signal(SIGALRM,alarmhandler);
    pause();
    // printf("terminating child \n");
    return 0;
}

int main() {
    char *stack = malloc(STACK_SIZE);
    if (!stack) {
        perror("malloc");
        exit(1);
    }

    char *stack_top = stack + STACK_SIZE;

    int pid = clone(child_func, stack_top, SIGCHLD, NULL);
    if (pid == -1) {
        perror("clone");
        exit(1);
    }

    printf("%d\n",pid);

    printf("Parent PID: %d\n", getpid());

    // wait(NULL);
    waitpid(pid, NULL, 0);
    free(stack);


    printf("parent is terminating \n");

    return 0;
}
