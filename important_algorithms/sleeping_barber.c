#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define CHAIRS 5

sem_t barber;
sem_t mutex;
sem_t customer;

int nocustomer=0;

void* barberProcess(){
    while(1){

        sem_wait(&customer);
        sem_wait(&mutex);
        nocustomer--;
        printf("Barber is cutting hair\n");
        sem_post(&barber);
        sem_post(&mutex);
        sleep(2);
    }

}

void* customerProcess(void *arg){
    sem_wait(&mutex);
    if(nocustomer<CHAIRS){
        printf("Customer Came for hair cut");
        nocustomer++;
        sem_post(&customer);
        printf("Customer is waiting for hair cut\n");
        sem_post(&mutex);
        sem_wait(&barber);
        printf("Customer is getting hair cut\n");
    }
    else{
        sem_post(&mutex);
        printf("No empty space available \n");
    }
}

int main(){

    sem_init(&mutex,0,1);
    sem_init(&customer,0,0);
    sem_init(&barber,0,0);

    pthread_t barberid;
    pthread_create(&barberid,NULL,barberProcess,NULL);
    pthread_t threadid[10];

    for(int i=0;i<10;i++){
        pthread_create(&threadid[i],NULL,customerProcess,NULL);
    }

    pthread_join(barberid,NULL);
    for(int i=0;i<10;i++){
        pthread_join(threadid[i],NULL);
    }
}