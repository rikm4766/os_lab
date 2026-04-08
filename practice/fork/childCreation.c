#include<stdio.h>
#include<unistd.h>

int main(){
    int id=fork() ;
    if(id==0){
        printf("child1 running\n");
    }
    else{
        printf("parent is running\n");
    }
    return 0;
}