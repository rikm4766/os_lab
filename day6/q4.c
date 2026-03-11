#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int s0=0;
int s1=0;


void* process0(void *arg){
    printf("entering p0\n");

    s0 = 1;          
    while(s1 == 1);  

    printf("exitting p0\n");
    return NULL;
}

void* process1(void *arg){
    printf("entering p1\n");

    s1 = 1;          
    while(s0 == 1); 

    printf("exitting p1\n");
    return NULL;
}


int main(){

    pthread_t t0,t1;


    pthread_create(&t0,NULL,process0,NULL);
    pthread_create(&t1,NULL,process1,NULL);

    pthread_join(t0,NULL);
    pthread_join(t1,NULL);



    return 0;
}