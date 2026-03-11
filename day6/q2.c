#include<stdio.h>
#include<pthread.h>

int flag[2]={0,0};
int turn=0;

int sharedVar = 0;

void* process0(void* arg){
    for(int i=0;i<1000;i++){
    // printf("entering p0\n");
    //     fflush(stdout);

        flag[0]=1;
        turn=1;
        while(flag[1]==1&&turn==1);
        sharedVar++;
        flag[0]=0;
        // printf("exitting p0\n");
        // fflush(stdout);

    }
}

void* process1(void* arg){
    for(int i=0;i<1000;i++){
        // printf("entering p1\n");
        // fflush(stdout);

        flag[1]=1;
        turn=0;
        while(flag[0]&&turn==0);
        sharedVar++;
        flag[1]=0;
        // printf("exitting p1\n");
        // fflush(stdout);
    }
}

int main(){

    pthread_t t0,t1;
    pthread_create(&t0,NULL,process0,NULL);
    pthread_create(&t1,NULL,process1,NULL);
    pthread_join(t0,NULL);
    pthread_join(t1,NULL);
    printf("shared variable = %d\n",sharedVar);

    return 0;
}