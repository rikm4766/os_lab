#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

//flags
// O_RDONLY
// O_RDWR
// O_WRONLY
// O_CREAT
// O_APPEND
// O_TRUNC

//0___
    // | | |--others
    // | |---group
    // |____owner

// 4-->read
// 2-->write
// 1-->execute

int main(){
    char buffer[100];
    int fd=open("hello.txt",O_CREAT|O_APPEND|O_RDWR,0777);
    int noOfChar=read(fd,buffer,100);
    printf("no of chars are %d\n",noOfChar);
    printf("%s\n",buffer);
    return 0;
}