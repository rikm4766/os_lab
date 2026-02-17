#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t lock;

void thread1(void * argv){
    int* counter = (int*)argv;
    for(int i=0;i<100000;i++){
        (*counter)++;
    }
    return NULL;
}


void thread2(void *argv){
    int * counter =(int*)argv;
    for(int i=0;i<100000;i++){
        (*counter)++;
    }
    return NULL;
}


int main(){
    
   pther 

    return 0;
}