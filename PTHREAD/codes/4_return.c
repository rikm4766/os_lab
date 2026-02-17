#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void* hello(void *arg){
//    int x=10;
// this will create error as this is local variable;

    int *ptr =(int *)malloc(sizeof(int));
    *ptr=5;
    return ptr;


}

int main(){
   
    pthread_t t;

    pthread_create(&t,NULL,hello,NULL);


    void **result;
    pthread_join(t,result);



    printf("RESULT = %d\n",**result);

    free(result);

    return 0;
}