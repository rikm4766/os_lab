#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler(int sig){
    printf("illegal signal\n");
}

int main(){
    signal(SIGILL,handler);
    raise(SIGILL);

    while (1)
    {
        /* code */
    }
    

    return 0;
}