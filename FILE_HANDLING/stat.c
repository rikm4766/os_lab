#include<stdio.h>
#include<sys/stat.h>

int main(){
    struct stat s;
    int exsist=stat("./hello.txt",&s);
    if(exsist==0){

        printf("%ld\n",s.st_size);
    }
    else{
        printf("file not exsist\n");
    }

    return 0;
}