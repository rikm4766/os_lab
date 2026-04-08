#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (int i = 0; i < 3; i++) {
        if (fork() == 0) {
            printf("Child %d PID: %d\n", i, getpid());
            sleep(2);
            return 0;
        }
    }

    // Parent waits for all children
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    printf("All children finished\n");
    return 0;
}