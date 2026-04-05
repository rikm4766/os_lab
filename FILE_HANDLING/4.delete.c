#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){

    unlink("./a.out");

    return 0;
}