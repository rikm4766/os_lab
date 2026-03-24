#include<stdio.h>
int allocation[5][3]={
    {0,1,0},
    {2,0,0},
    {3,0,2},
    {2,1,1},
    {0,0,2}
};
int maxallocate[5][3]={
    {7,5,3},
    {3,2,2},
    {9,0,2},
    {2,2,2},
    {4,3,3}
};
int available[3]={3,3,2};
int need[5][3];
int visited[5]={0};
int Count=0;
int processes=5;
int resources=3;
int safeSequence[5];
int main(){
    int ss=0;
    for(int i=0;i<processes;i++){
    for(int j=0;j<resources;j++){
        need[i][j]=(maxallocate[i][j]-allocation[i][j]);
    }
}
    int npflag=0;
    while(Count<processes){
        int found=0;
        for(int i=0;i<processes;i++){
             npflag=0;
             if(visited[i]) continue;
            for(int j=0;j<resources;j++){               
                if(need[i][j]>available[j]){
                    npflag=1;
                    break;
                }
            }
            if(npflag==0) {
                found=1;
            visited[i]=1;
            safeSequence[ss]=i;
            ss++;
            Count++;
            for(int k=0;k<resources;k++){
                available[k]+=allocation[i][k];
                
            }
        }
        }
        if(found==0){
            printf("unsafe state\n");
            return 0;
        }
    }
    printf("Printing safe sequence\n");
    for(int i=0;i<processes;i++){
        printf("P%d\t",safeSequence[i]);
    }
    printf("\n");
    return 0;
}

