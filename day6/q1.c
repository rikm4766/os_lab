#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int flag[2]={0,0};
int turn=0;

void* process0(void* arg){
    flag[0]=1;
    turn = 1;
    while(flag[1]&&turn==1);
    printf("process 0 is entering\n");
    sleep(2);
    printf("process 0 is exitting\n");
    fflush(stdout);
    flag[0]=0;
}

void* process1(void * arg){
    flag[1]=1;
    turn=0;
    while(flag[0]&&turn==0);
    printf("process 1 is entering\n");
    sleep(2);
    printf("process 1 is exitting\n");
    fflush(stdout);
    flag[1]=0;
}

int main(){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,process0,NULL);
    pthread_create(&t2,NULL,process1,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}