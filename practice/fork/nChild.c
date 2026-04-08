#include<stdio.h>
#include<unistd.h>

int main(){

   for(int i=0;i<3;i++) {
    int pid = fork();
    if(pid==0){
        printf("PID = %d , PPID = %d\n",getpid(),getppid());
        while(1);
    }
   }
  while(1);
    return 0;
}