#include<stdio.h>
#include<pthread.h>

void *hello(void *arg){
    int x = *(int*)arg;
    printf("hello %d\n",x);
    return NULL;
}
int main(){
   int x = 15;
   pthread_t t;  
   pthread_create(&t,NULL,hello,&x);
   pthread_join(t,NULL);
   return 0;
}