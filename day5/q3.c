#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int fd = open("process_syscall.txt",
                  O_CREAT | O_WRONLY , 0644);

    if (fd < 0)
    {
        perror("File open error");
        exit(1);
    }

    pid_t pid;
    char buffer[100];

    for (int i = 0; i < n; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            sprintf(buffer, "Parent PID: %d, Child PID: %d\n",
                    getppid(), getpid());
            write(fd, buffer, strlen(buffer));
        }
        else
        {
            sprintf(buffer, "Parent PID: %d, Own PID: %d\n",
                    getppid(), getpid());
            write(fd, buffer, strlen(buffer));
            break;
        }
    }

    while (1); // infinite loop

    close(fd);
    return 0;
}