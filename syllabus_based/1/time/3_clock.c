#include<stdio.h>
#include<time.h>

int main(){
    clock_t start,end;
    start=clock();
    for(int i=0;i<__INT_MAX__;i++);
    end=clock();
    printf("%f\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}