

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/wait.h>
#include <signal.h>

#define STACK_SIZE 1024*1024

void * childFunction(void *arg){
    printf("This is child process\n");
    exit(0);
}

int main(){

    char * stack=malloc(STACK_SIZE);
    char *stacktop=stack+STACK_SIZE;

    int flags=SIGCHLD;

    int pid = clone(childFunction,stacktop,flags,NULL);
    if(pid==-1) printf("clone failed\n");

    waitpid(pid,NULL,0);
    free(stack);
    return 0;

}