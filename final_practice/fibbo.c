#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

void fibbo(int n) {
    int a = 0, b = 1, c;
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Parent PID: %d PPID: %d\n", getpid(), getppid());

    int pid1 = fork();

    if (pid1 == 0) {
        printf("Child 1 PID: %d\n", getpid());
        for (int i = 1; i <= n; i++)
            if (prime(i))
                printf("%d ", i);
        printf("\n");
        exit(0);
    } 
    else {
        int pid2 = fork();

        if (pid2 == 0) {
            printf("Child 2 PID: %d\n", getpid());
            fibbo(n);
            exit(0);
        } 
        else {
            wait(NULL);
            wait(NULL);
        }
    }

    return 0;
}