#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

#define SIZE 100

int main(){
    char buffer[SIZE]="hello world";
    int fd=open("hello1.txt",O_CREAT|O_RDWR,0777);
    if(fd<0) return 1;
    write(fd,buffer,strlen(buffer));
    write(0,buffer,strlen(buffer)); // for printing in stdout
    close(fd);

    return 0;
}