#include<stdio.h>
#include<pthread.h>
void* helloworld(){
    printf("hello world\n");
}
int main(){
    pthread_t t1; //this is thread 1;
    pthread_create(&t1,NULL,helloworld,NULL) ;
    pthread_join(t1,NULL);
    
    return 0;
}