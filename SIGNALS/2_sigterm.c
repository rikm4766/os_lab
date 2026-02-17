#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void handler(int sig){
    printf("sigterm called\n");
}

int main(){
    signal(SIGTERM,handler);
    while ((1))
    {
        /* code */
    }
    
    return 0;
}