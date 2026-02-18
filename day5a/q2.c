#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>


struct searchele{
    int start;
    int end;
    int key;
    int *arr;
};

int myarr[]={1,2,3,4,5,6,7,8,9,10,11};

int key = 7;

void* search(void *arg){
    struct searchele* sel = (struct searchele*)arg;
    int start = sel->start;
    int end = sel->end;
    int key = sel->key;
    int *arrp= sel->arr;
    int j=-1;
    int *dma = (int * )malloc(sizeof(int));

    for(int i=start;i<end;i++){
        if(arrp[i]==key){
            j=i;
            break;
            
        }
    }
    // printf("%d\n",j);
    *dma = j;
    return dma;
}


int main(){

    struct searchele s1;
    struct searchele s2;
    s1.start=0;
    s1.end=5;
    s1.key=key;
    s1.arr=myarr;

    s2.start=5;
    s2.end=10;
    s2.key=key;
    s2.arr=myarr;

    // struct searchele * sptr = &s1;

    // search((void*)sptr);
    struct searchele *sptr1 = &s1;
    struct searchele *sptr2 = &s2;

    pthread_t t1,t2;

    pthread_create(&t1,NULL,search,sptr1);
    pthread_create(&t2,NULL,search,sptr2);

    void *result1;
    void *result2;

    pthread_join(t1,&result1);
    pthread_join(t2,&result2);

    int r1 = *(int *)result1;
    int r2 = *(int *)result2;

    if(r1!=-1){
        printf("ELEMENT FOUND AT POSITION %d\n",r1);
    }
    if(r2!=-1){
        printf("ELEMENT FOUND AT POSITION %d\n",r2);
    }




    return 0;


}