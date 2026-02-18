#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int i=0;

void handler(int sig){
    i++;
    printf("   SIGINT RECIVED %d times\n",i);
    if(i>=3){
        kill(getpid(),SIGTERM);
    }
}

int main(){

    signal(SIGINT,handler);
    while(1);

    return 0;
}