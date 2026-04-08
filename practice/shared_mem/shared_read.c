#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include <string.h>
#include<stdlib.h>

int main(){
    key_t key=1234;
    int shmid=shmget(key,1024,0777);
    char* data=(char*)shmat(shmid,NULL,0);
    if(data==NULL){
        exit(0);
    }
    printf("REad data %s\n",data);
    shmdt(data);
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
}