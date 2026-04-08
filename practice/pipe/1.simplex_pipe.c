#include<stdio.h>
#include<unistd.h>
#include<string.h>

int fd[2];



int main(){
    char* message="hello child from parent";
    char buffer[100];
    pipe(fd);
    int pid=fork();
    if(pid==0){
        close(fd[1]);
        read(fd[0],buffer,sizeof(buffer));
        printf("Child recieved %s\n",buffer);
    }
    else{
    close(fd[0]);
    write(fd[1],message,strlen(message)+1);
    }
    return 0;
}