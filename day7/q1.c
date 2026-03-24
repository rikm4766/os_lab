#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
sem_t s1;
int cvar=0;
void* incrementor(void *arg){
    int thread_id=*(int*)arg;
    printf("\nEntering Thread %d\n",thread_id); 
    sem_wait(&s1);
    for(int i=0;i<5;i++){
        cvar++;
        printf("THREAD=%d\tCVAR=%d\n",thread_id,cvar);
    }
    sem_post(&s1);
    printf("\nExitting Thread %d\n",thread_id);
    return NULL;
}
int main(){
    int noThread=0;
    printf("INCREMENTS PER THREAD :5\n");
    printf("INITIAL SHARED VARIABLE : 0\n");
    printf("Enter No Of Thread\n");
    scanf("%d",&noThread);
    sem_init(&s1,0,1);
    pthread_t t1,t2;
    int *thread_id=(int*)malloc(noThread*sizeof(int));
    pthread_t* pid=(pthread_t*)malloc(noThread*sizeof(pthread_t));  
    for(int i=0;i<noThread;i++){
        thread_id[i]=i;
        pthread_create(&pid[i],NULL,incrementor,&thread_id[i]);
    }
    for(int i=0;i<noThread;i++){
        pthread_join(pid[i],NULL);
    }
    printf("Final Shared Variable = %d\n",cvar);
    
    return 0;
}