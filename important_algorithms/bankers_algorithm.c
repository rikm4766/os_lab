#include <stdio.h>

#define p 3
#define r 3

int max[p][r] =
    {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2}};
int alloc[p][r] =
    {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2}};

int need[p][r];
int available[r] = {5,4,5};

int completed[p]={0};

int safeState[p]={0};

void getNeed()
{
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

// void getavailable(){
//     for(int i=0;i<p;i++){
//         for(int j=0;j<r;j++){
//             available[i]=available[i]+alloc[j][i];
//         }
//     }

//     for(int i=0;i<r;i++){
//         printf("%d\t",available[i]);
//     }
//     printf("\n");
// }

int main()
{

    getNeed();
    int count=0;

    while(count<p){
    int found=0;
    for (int i = 0; i < p; i++)

    {
        if (completed[i] == 0)
        {
            int flag=0;
            for (int j = 0; j < r; j++)
            {
                if(available[j]<need[i][j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                for(int k=0;k<r;k++){
                    available[k]=available[k]+alloc[i][k];
                }
                completed[i]=1;
                safeState[count]=i;
                count++;
                found=1;
            }
        }
    }
    if(found==0){
        printf("Cant find safe state exitting");
        return 0;
    }
}

printf("printing safe state\n");
for(int i=0;i<p;i++){
    printf("p%d  ->  ",safeState[i]);
}
printf("\n");



    return 0;
}