#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(){
    int fd;
    struct stat st;
    fd = open("labtext.txt",O_RDONLY);
    stat("labtext.txt",&st);
    printf("file size is %d bytes \n",st.st_size);
    off_t offset = lseek(fd,0,SEEK_END);
    printf("Current file offset %d\n",offset);
    close(fd);
}