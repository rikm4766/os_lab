#include<stdio.h>
#include<pthread.h>

void* thread1(void * argv){
   int *counter =(int*)argv;
   printf("%d\n",*counter);
   for(int i=0;i<100000;i++){

       (*counter)++;
   }
   
    return NULL;
}

void* thread2(void *argv){
    int *counter =(int*)argv;
printf("%d\n",*counter);
    for(int i=0;i<100000;i++){
        (*counter)++;
    }
    return NULL;
}

int main(){
   
    int count = 5;

    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1,NULL,thread1,&count);
    pthread_create(&t2,NULL,thread2,&count);



    pthread_join(t1,NULL);
    pthread_join(t2,NULL);    


    printf("%d\n",count);


    return 0;
}