#include<stdio.h>
#include<pthread.h>

struct mydata
{
    int a;
    float b;
};
void *hello(void *arg){
    struct mydata *d1;
    d1=(struct mydata*)arg;
    printf("a= %d b= %f\n",d1->a,d1->b);
    return NULL;
}

int main(){

       struct mydata d;
       d.a=5;
       d.b=4.2;

       struct mydata *ptr;
       ptr=&d;


       pthread_t t;
       pthread_create(&t,NULL,hello,ptr);
       pthread_join(t,NULL);
       return 0;
}