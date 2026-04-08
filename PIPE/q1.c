#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

char buffer[]="hello world";

int main(){
    int fd = open("hello.txt",O_CREAT|O_APPEND|O_RDWR,0777);
    write(fd,buffer,sizeof(buffer));
    return 0;
}