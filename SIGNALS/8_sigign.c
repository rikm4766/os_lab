#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(){

    signal(SIGINT,SIG_IGN);

    //ignore the SIGINT signal
    while (1)
    {
        /* code */
    }
    

    return 0;
}