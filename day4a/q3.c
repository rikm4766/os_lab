#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

char buffer[100];

void concatination(char **files,int nofile){
    int ff = open(files[0],O_RDWR,0777);
    for(int i=1;i<nofile;i++){
        int fd=open(files[i],O_RDONLY);
        int n=0;
        while((n=read(fd,buffer,sizeof(buffer)))>0){
            lseek(ff,0,SEEK_END);
            write(ff,buffer,n);
        }
        close(fd);
        unlink(files[i]);
        
    }
}

int main(){


    char * files[]={"f1.txt","f2.txt","f3.txt"};
    concatination(files,3);


    return 0;
}