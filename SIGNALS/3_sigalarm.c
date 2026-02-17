#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void handler(int sig){
    printf("handling alarm signal %d\n",sig);
    
}

int main(){
    signal(SIGALRM,handler);
    alarm(3);
    while(1);

    return 0;
}