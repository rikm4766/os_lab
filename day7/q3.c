#include<stdio.h>
#define P 3
int waitGraph[P][P]; 
int visited[P] = {0};
int recStack[P] = {0};
int dfs(int node){
    visited[node] = 1;
    recStack[node] = 1;
    for(int i=0;i<P;i++){
        if(waitGraph[node][i]){
            if(!visited[i] && dfs(i))
                return 1;
            else if(recStack[i])
                return 1;
        }
    }
    recStack[node] = 0;
    return 0;
}
int main(){ 
    waitGraph[0][1] = 1; 
    waitGraph[1][0] = 1;
    for(int i=0;i<P;i++){
        if(!visited[i]){
            if(dfs(i)){
                printf("Deadlock detected\n");
                return 0;
            }
        }
    }
    printf("No deadlock\n");
    return 0;
}