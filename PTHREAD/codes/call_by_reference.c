#include<stdio.h>
#include<stdlib.h>

int function(int *a){
    printf("%d\n",*a);
    *a=100;
}


int main()
{
   int a=10;
   function(&a); 

    printf("%d\n",a);
    return 0;
}