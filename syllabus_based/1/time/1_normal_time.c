#include<stdio.h>
#include<time.h>
#include<unistd.h>

void logmessage(){
    time_t now=time(NULL);
    struct tm *t=localtime(&now);
    printf("%02d:%02d:%02d\n",t->tm_hour,t->tm_min,t->tm_sec);
}

int main(){
    
    while(1){
        logmessage();
        sleep(1);
    }


    return 0;
}