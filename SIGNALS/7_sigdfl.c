#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(){
    signal(SIGINT,SIG_DFL);

    //default behaviour of the SIGINT; 
    while (1)
    {
        /* code */
    }
    

    return 0;
}