#include<stdio.h>
#include<unistd.h>
#include<signal.h>

//ctrl+c

void interputhandler(int sig){
    printf("interupt handler called\n");
}


int main(){
    signal(SIGINT,interputhandler);
    while(1);
    return 0;
}