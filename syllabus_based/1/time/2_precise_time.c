#include<stdio.h>
#include<sys/time.h>

double getTime(){
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec+tv.tv_usec/1000000.0;
}

int main(){
    double start,end;
    start=getTime();
    for(int i=0;i<__INT_MAX__;i++);
    end=getTime();
    printf("%f",end-start);
    return 0;
}