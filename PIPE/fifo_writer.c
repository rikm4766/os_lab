// #include<stdio.h>
// #include<unistd.h>
// #include<fcntl.h>
// #include<sys/stat.h>

// int main(){
//     char buffer[] = "hello child";

//     mkfifo("myfifo", 0777);  // create if not exists

//     int fd = open("myfifo", O_WRONLY);

//     if(fd == -1){
//         perror("open");
//         return 1;
//     }

//     write(fd, buffer, sizeof(buffer));
//     close(fd);

//     return 0;
// }


#include<stdio.h>
#include<unistd.h>
#include<string.h>

#include<fcntl.h>

int main(){
    mkfifo("myfifo");
    int fd = open("myfifo",O_WRONLY,0777);
    write(fd,"hellochild",10);


    return 0;
}