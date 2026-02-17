// to create the file of approx 1.5Gb 
//dd if=/dev/zero of=largefile.txt bs=1M count=1500

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#define BUFFER_SIZE 4096
double system_copy(const char *src_file, const char *dest_file) {
    int src = open(src_file, O_RDONLY);
    int dest = open(dest_file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    char buffer[BUFFER_SIZE];
    ssize_t bytes;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    while ((bytes = read(src, buffer, BUFFER_SIZE)) > 0) {
        write(dest, buffer, bytes);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    close(src);
    close(dest);

    return (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec) / 1e9;
}

double library_copy(const char *src_file, const char *dest_file) {

    FILE *src = fopen(src_file, "rb");
    FILE *dest = fopen(dest_file, "wb");

    char buffer[BUFFER_SIZE];
    size_t bytes;

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    fclose(src);
    fclose(dest);

    return (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec) / 1e9;
}

int main() {

    const char *source = "largefile.txt";

    double sys_time = system_copy(source, "sys_output.txt");
    double lib_time = library_copy(source, "lib_output.txt");

    printf("System Call Copy Time   : %f seconds\n", sys_time);
    printf("Library Function Copy Time : %f seconds\n", lib_time);

    if (sys_time < lib_time)
        printf("System Calls were faster.\n");
    else
        printf("Library Functions were faster.\n");

    return 0;
}
