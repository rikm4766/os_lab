#include<stdio.h>
#include<unistd.h>
int main(int argc,char * argv[]){
   printf("no of argument = ") ;
    printf("%d\n",argc);
    printf("showing arguments\n");
    for(int i=0;i<argc;i++){
        printf("%s\n",argv[i]);
    }
return 0;
}
