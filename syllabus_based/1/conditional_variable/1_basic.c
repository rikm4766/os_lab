#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


pthread_mutex_t mutex;
pthread_cond_t cond;

int flag = 0;

void* process0(void* arg){
    pthread_mutex_lock(&mutex);
    while(flag==0){
        printf("Waiting..\n");
        pthread_cond_wait(&cond,&mutex);
    }
    pthread_mutex_unlock(&mutex);
    return NULL; 
}

void* process1(void* arg){
    pthread_mutex_lock(&mutex);
    sleep(1);
    flag=1;
    printf("sending signal\n");
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
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