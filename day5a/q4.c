#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>



void exithandler(int sig){
    printf("exitting \n");
    exit(1);
}

int main(){

    signal(SIGINT,SIG_IGN);
    sleep(5);
    printf("restore default behviour\n");
    signal(SIGINT,SIG_DFL) ;
    while (1)
    {
        /* code */
    }
    
    return 0;
}