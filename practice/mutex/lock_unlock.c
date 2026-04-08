#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t mutex;

void *process(void* arg){
    int i = *(int*)arg;
    pthread_mutex_unlock(&mutex);
    // if(i==1){

    //     pthread_mutex_lock(&mutex);
    // }
    // else if(i==2){
    //     pthread_mutex_unlock(&mutex);
        
    // }
    printf("%d\n",i);

    return NULL;
}

int main(){

    pthread_mutex_init(&mutex, NULL);

    pthread_t t1, t2;
    int var1 = 1;
    int var2 = 2;

    pthread_create(&t1, NULL, process, &var1);
    sleep(1);
    pthread_create(&t2, NULL, process, &var2);

    // ✅ WAIT for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}