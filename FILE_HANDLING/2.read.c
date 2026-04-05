#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#define SIZE 6




int main(){
    char buffer[SIZE];
    int fd=open("hello.txt",O_CREAT|O_APPEND|O_RDWR);


    int noOfChar=read(fd,buffer,5);
    printf("no of chars are %d\n",noOfChar);
    printf("%s\n",buffer);

    //moving pointer to the first
    lseek(fd,SEEK_SET,0);
    //this causes buffer overflow so that complety print not occurs

    //2nd method
    int bytes;
    while((bytes=read(fd,buffer,SIZE))>0){
        buffer[bytes]='\0';
        printf("%s",buffer);
    }


    //read from stdin

    char stdbuffer[100];
    int lastByte=read(0,stdbuffer,100);
    stdbuffer[lastByte]='\0';
    // printf("%s",stdbuffer);
    write(0,stdbuffer,strlen(stdbuffer));


    return 0;
}