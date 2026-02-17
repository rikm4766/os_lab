#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void handler(){
    printf("error mem acess");
    // exit(1);
}
int main(){
    signal(SIGSEGV,handler);
//  int *ptr = (int *)5;   // invalid address
//     *ptr = 10;             // 💥 triggers SIGSEGV

//     int *ptr1 = (int *)malloc(sizeof(int));
//     free(ptr1);
//     *ptr1=5;


    crash();

    return 0;
}