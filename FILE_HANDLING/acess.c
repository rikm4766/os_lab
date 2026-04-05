#include<stdio.h>
#include<unistd.h>

//used to check the file acess
// F_OK → check if file exists
// R_OK → check read permission
// W_OK → check write permission
// X_OK → check execute permission

int main(){

    int report = access("./hello.txt",F_OK);
    printf("%d",report);

    return 0;
}