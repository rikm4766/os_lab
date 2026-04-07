#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdbool.h>

bool flag[2]={false};
int turn = 0;

void* p0(void* arg){
    while(1){
        flag[0]=true;
        turn=1;
        while(flag[1]&&turn==1);
        printf("process p0 is running\n");
        sleep(1);
        flag[0]=false;
    }
    return NULL;
}

void* p1(void* arg){
    while(1){
        flag[1]=true;
        turn=0;
        while(flag[0]&&turn==0);
        printf("process p1 is running\n");
        sleep(1);
        flag[1]=false;
    }
    return NULL;
}






int main(){

    pthread_t t0,t1;
    pthread_create(&t0,NULL,p0,NULL);
    pthread_create(&t1,NULL,p1,NULL);

    pthread_join(t0,NULL);
    pthread_join(t1,NULL);

}