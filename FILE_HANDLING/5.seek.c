#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

// SEEK_SET	From beginning
// SEEK_CUR	From current position
// SEEK_END	From end

int main(){

    int fd=open("hello.txt",O_RDONLY);
    char buffer[10];
    int n=read(fd,buffer,10);
    buffer[n]='\0';
    printf("%s",buffer);

    n=read(fd,buffer,10);
    buffer[n]='\0';
    printf("%s",buffer);

    lseek(fd,SEEK_SET,0);

    n=read(fd,buffer,10);
    buffer[n]='\0';
    printf("%s",buffer);

    lseek(fd,SEEK_END,-22);

    n=read(fd,buffer,10);
    buffer[n]='\0';
    printf("%s",buffer);


    return 0;
}