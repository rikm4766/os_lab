#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>


void handlefile(int ptype, int pid) {
    FILE *fptr = fopen("data.txt", "a");
    if (fptr == NULL) {
        perror("fopen");
        return;
    }

    if (ptype == 0) {
        fprintf(fptr, "child process with pid %d\n", pid);
    } else {
        fprintf(fptr, "parent process with pid %d\n", pid);
    }

    fclose(fptr);
}



int main(int argc,char*argv[]){
    
   if(argc<2) exit(1);
    int childno ;
    int pid = 0;
    int ppid;
    printf("Enter the number of child\n");
    // scanf("%d",&childno);
    childno=atoi(argv[1]);
    for(int i=0;i<childno;i++){
         pid = fork();
    
    if(pid==0){
     
        printf("pid = %d and ppid = %d\n",getpid(),getppid());
        handlefile(0,getpid());
        while(1);
    }

}
 handlefile(1,getpid()) ;
      
while(1);

return 0;
}