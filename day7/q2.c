#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#define BUFFER_SIZE 5
sem_t mutex;
sem_t full;
sem_t empty;
int in=0;
int out=0;
int buffer[BUFFER_SIZE];
void * producer(void *arg){
    int produced_num;
    while(1){
        sem_wait(&empty);
        produced_num=rand()%1000;
        sem_wait(&mutex);
        printf("INDEX = %d\tPRODUCED NUM=%d\n",in,produced_num);
        buffer[in]=produced_num;
        in=(in+1)%BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&full);
        sleep(2);
    }
    return NULL;
}
void *consumer(void *arg){
    while(1){
        sem_wait(&full);
        sem_wait(&mutex);
        printf("CONSUMING INDEX = %d\tVALUE=%d\n",out,buffer[out]);
        out=(out+1)%BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&empty);
        sleep(2);
    }
    return NULL;
}
int main(){
    sem_init(&mutex,0,1);
    sem_init(&empty,0,BUFFER_SIZE);
    sem_init(&full,0,0);
    pthread_t proThread,consThread;
    pthread_create(&proThread,NULL,producer,NULL);
    pthread_create(&consThread,NULL,consumer,NULL);
    pthread_join(proThread,NULL);
    pthread_join(consThread,NULL);
    return 0;
}