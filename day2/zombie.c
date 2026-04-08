#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid > 0) {
        while(1){
        // Parent process
        printf("Parent PID: %d\n", getpid());
         // Parent sleeps, child becomes zombie
        }
    }
    else if (pid == 0) {
        // Child process
        printf("Child PID: %d\n", getpid());
        printf("Child exiting...\n");
        exit(0); // Child terminates
    }
    else {
        perror("Fork failed");
    }

    return 0;
} // Zombie process