#include<stdio.h>

#define p 3
#define r 3

int alloc[p][r];
int need[p][r];
int available[r];

int doneprocess[p];

int main(){
    int count=0;
    while(count<p){
        int safe=0;
    for(int i=0;i<p;i++){
        
        int flag=0;
        if(doneprocess[i]!=1){
        for(int j=0;j<r;j++){
            if(need[i][j]>available[j]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            for(int k=0;k<r;k++){
                available[k]+=alloc[i][k];
                
            }
            doneprocess[i]=1;
            count++;
            safe=1;
        }
    }
    }
    if(safe==0){
        printf("no safe state found\n");
        return 0;
    }
}

}