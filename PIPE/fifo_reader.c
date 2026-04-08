// #include<stdio.h>
// #include<unistd.h>
// #include<fcntl.h>
// #include<sys/stat.h>

// int main(){
//     char buffer[100];

//     mkfifo("myfifo", 0777);

//     int fd = open("myfifo", O_RDONLY);

//     if(fd == -1){
//         perror("open");
//         return 1;
//     }

//     read(fd, buffer, sizeof(buffer));
//     printf("%s\n", buffer);

//     close(fd);

//     return 0;
// }

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main(){

    char buffer[10];
    mkfifo("myfifo");

    int fd = open("myfifo",O_RDONLY,0777);
    read(fd,buffer,sizeof(buffer));
    printf("%s\n",buffer);
    unlink("myfifo");

    return 0;
}