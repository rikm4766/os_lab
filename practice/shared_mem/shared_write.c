#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>


int main(){

    key_t key=1234;
    int shmid=shmget(key,1024,0777|IPC_CREAT);
    char* data=(char*)shmat(shmid,NULL,0); //0 means read + write
    char *temp="hello world";
    strcpy(data,temp);
    printf("shared %s\n",data);
    shmdt(data);

    return 0;
}