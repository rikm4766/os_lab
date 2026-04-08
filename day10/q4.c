#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdbool.h>
#define N 5

int number[N]={0};
bool choosing[N]={false};

int sharedVar=0;

int findmax(int *arr){
    int max=0;
    for(int i=0;i<N;i++){
        if(max<arr[i]) max=arr[i];
    }
    return max;
}

void lock(int i){
    choosing[i]=true;
    number[i]=findmax(number)+1;
    choosing[i]=false;

    for(int j=0;j<N;j++){
        if(j==i) continue;
        while(choosing[j]);
        while(number[j]!=0 && 
              (number[j]<number[i] ||
              (number[j]==number[i] && j<i)));

    }
    
}

void unlock(int i){
    number[i]=0;
}

void* process(void *arg){
    int id=*(int*)arg;
    lock(id);
    for(int i=0;i<5;i++){
        sharedVar++;
    }
    printf("Shared Var = %d by thread %d\n",sharedVar,id);
    unlock(id);
    return NULL;
}


int main(){

    pthread_t thread[N];
    int threadid[N];
    for(int i=0;i<N;i++){
        threadid[i]=i;
        pthread_create(&thread[i],NULL,process,&threadid[i]);
    }
    for(int i=0;i<N;i++){
        pthread_join(thread[i],NULL);
    }

}