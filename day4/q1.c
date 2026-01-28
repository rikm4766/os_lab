// Q1.) Write a code to where the parent process P asks the user to input an integer value ‘n; and
// then P should create exactly n child process under it (single level child process hierarchy). Each
// child process should display its pid &amp; ppid and goes to an infinite loop. Execute ps and
// pstree to visualize the process hierarchy. Take a snapshot of the output. Finally execute kill
// command to terminate all the user processes.

#include<stdio.h>
#include<unistd.h>



int main(){
    
    int childno ;
    int pid = 0;
    printf("Enter the number of child\n");
    scanf("%d",&childno);
    for(int i=0;i<childno;i++){
         pid = fork();
    
    if(pid==0){
        printf("pid = %d and ppid = %d\n",getpid(),getppid());
        while(1);
    }

}

while(1);

return 0;
}