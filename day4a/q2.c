#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include"mymul.h"



int main(){
    char * answer;
    char buffer1[100];
    char buffer2[100];
    int n;
    int file1 = open("num1.txt",O_RDONLY);
    int file2 = open("num2.txt",O_RDONLY);
    int ansfile = open("ans.txt",O_CREAT|O_RDWR,0777);
    n=read(file1,buffer1,sizeof(buffer1));
    buffer1[n]='\0';
    n=read(file2,buffer2,sizeof(buffer2));
    buffer2[n]='\0';

    
    answer=multiplyStrings(buffer1,buffer2);
    write(ansfile,answer,strlen(answer));

    close(file1);
    close(file2);
    close(ansfile);
}