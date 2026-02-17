#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>


void handler(int sig){
    printf("child process exitted -- msg from handler\n");
}

int main(){

    signal(SIGCHLD,handler);
    int pid = fork();
    if(pid>0){
            printf("pid = %d ppid = %d\n",getpid(),getppid());

        while (1)
        {
        }

            
    }
    else if(pid==0){
        printf("this is the child process \n");
        
        printf("pid = %d ppid = %d\n",getpid(),getppid());

        exit(1);

    }


    return 0;
}