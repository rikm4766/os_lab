#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t r1,r2;

void* process0(void *arg){
    pthread_mutex_lock(&r1);
    printf("Entering process 1\n");
    pthread_mutex_lock(&r2);
    printf("Exitting Process 1\n");
    pthread_mutex_lock(&r2);
    pthread_mutex_lock(&r1);
}

void* process1(void *arg){
    pthread_mutex_lock(&r2);
    printf("Entering process 2\n");
    pthread_mutex_lock(&r1);
    printf("Exitting Process 2\n");
    pthread_mutex_lock(&r1);
    pthread_mutex_lock(&r2);
}


int main(){

    pthread_t t0,t1;

    pthread_mutex_init(&r1,NULL);
    pthread_mutex_init(&r2,NULL);

    pthread_create(&t0,NULL,process0,NULL);
    pthread_create(&t1,NULL,process1,NULL);

    pthread_join(t0,NULL);
    pthread_join(t1,NULL);



    return 0;
}