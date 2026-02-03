/*
Q2.) Write a C program using the file-related system calls creat(), open(), write(), read(), and
close() to create a file data.txt, write the string "Operating Systems Lab" into it, reopen the file
in read mode, and display its contents on the screen.
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main(){
    int fd;
    char buffer[100];
    char text[]="operating system";

    fd=creat("labtext.txt",0644);
    if(fd<0) return 1;


    printf("writing in the file\n");
    write(fd,text,strlen(text));
    close(fd);

    fd = open("labtext.txt",0666);
    if(fd<0) return 1;
   
    int bytes = read(fd,buffer,sizeof(buffer)-1);

    printf("Reading from file\n%s\n",buffer);

    close(fd);

    return 0;

}