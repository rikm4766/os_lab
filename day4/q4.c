#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main() {
    char *msg1 = "hello world";
    char inbuf[SIZE];
    int p[2];
    int nbytes;

    if (pipe(p) == -1) {
        perror("pipe");
        exit(1);
    }

    int pid = fork();

    if (pid > 0) { 
        close(p[0]);
        write(p[1], msg1, strlen(msg1) + 1);
        close(p[1]);
        wait(NULL);
    } else { 
        close(p[1]);
        while ((nbytes = read(p[0], inbuf, SIZE)) > 0) {
            inbuf[nbytes] = '\0';
            printf("%s\n", inbuf);
        }
        close(p[0]);
    }

    return 0;
}
