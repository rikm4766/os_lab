#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int main() {
    FILE *f;
    char line[1024];

    int total = 0, running = 0, terminals = 0;
    int cpu_pids[MAX], mem_pids[MAX];
    int cpu_count = 0, mem_count = 0;

    system("ps aux > aux.txt");
    system("ps -ef > ef.txt");

    f = fopen("aux.txt", "r");

    fgets(line, sizeof(line), f);

    while (fgets(line, sizeof(line), f)) {
        total++;

        char user[50], tty[50], stat[10];
        int pid;
        float cpu, mem;

        sscanf(line, "%s %d %f %f %*s %*s %s %s",
               user, &pid, &cpu, &mem, tty, stat);

        if (stat[0] == 'R')
            running++;

        if (strcmp(tty, "?") != 0)
            terminals++;

        if (cpu > 1.0)
            cpu_pids[cpu_count++] = pid;

        if (mem > 1.0)
            mem_pids[mem_count++] = pid;
    }

    fclose(f);

    printf("Total Processes: %d\n", total);
    printf("Running Processes: %d\n", running);
    printf("Processes with Terminals: %d\n", terminals);

    printf("CPU Intensive PIDs:\n");
    for (int i = 0; i < cpu_count; i++)
        printf("%d ", cpu_pids[i]);
    printf("\n");

    printf("Memory Intensive PIDs:\n");
    for (int i = 0; i < mem_count; i++)
        printf("%d ", mem_pids[i]);
    printf("\n");

    return 0;
}