#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>


void* process(void *arg){
    int *ptr=(int*)malloc(sizeof(int));
    *ptr=4;
    return ptr;
}

int main(){

    pthread_t t1;
    pthread_create(&t1,NULL,process,NULL);
    void *retval;
    pthread_join(t1,&retval);
    printf("%d\n",*(int*)retval);
    free(retval);
    
    return 0;
}