#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>

#define HUNGRY 0
#define THINKING 1
#define EATING 2

#define N 5

sem_t s[N];
sem_t mutex;

int state[N];

int philosopherId[N]={0,1,2,3,4};


int left(int i){
    return (i+N-1)%N;
}
int right(int i){
    return (i+1)%N;
}

void test(int i){
    if(state[i]==HUNGRY &&
        state[left(i)]!=EATING&&
        state[right(i)]!=EATING){
            printf("Philosopher %d taken Sticks from %d and %d\n",i,left(i),right(i));
            state[i]=EATING;
            printf("Philosopher %d is Eating\n",i);
            sem_post(&s[i]);
        }
}


void getStick(int i){
    sem_wait(&mutex);
    state[i]=HUNGRY;
    printf("Philopher %d is Hungry\n",i);
    test(i);
    sem_post(&mutex);
    sem_wait(&s[i]);
}

void putStick(int i){
    sem_wait(&mutex);
    state[i]=THINKING;
    test(left(i));
    test(right(i));
    sem_post(&mutex);
}

void* philosopherProcess(void *arg){
    int i=*(int*)arg;
    while(1){
        printf("PHILOSOPHER %d is Thinking\n",i);
        getStick(i);
        sleep(2);
        putStick(i);
        sleep(1);
    }
}

int main(){

    sem_init(&mutex,0,1);
    for(int i=0;i<N;i++){
        sem_init(&s[i],0,0);
    }

    pthread_t threadid[N];

    for(int i=0;i<N;i++){
        pthread_create(&threadid[i],NULL,philosopherProcess,&philosopherId[i]);
    }

    for(int i=0;i<N;i++){
        pthread_join(threadid[i],NULL);
    }

    

    return 0;
}