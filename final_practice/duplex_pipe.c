#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int p1[2], p2[2];
    pipe(p1);
    pipe(p2);

    int pid = fork();

    if (pid == 0) {
        close(p1[1]);
        close(p2[0]);

        char msg1[100];
        read(p1[0], msg1, sizeof(msg1));
        printf("Child received: %s\n", msg1);

        char reply[] = "Hello Parent";
        write(p2[1], reply, strlen(reply) + 1);
    } 
    else {
        close(p1[0]);
        close(p2[1]);

        char msg[] = "Hello Child";
        write(p1[1], msg, strlen(msg) + 1);

        char msg2[100];
        read(p2[0], msg2, sizeof(msg2));
        printf("Parent received: %s\n", msg2);
    }

    return 0;
}