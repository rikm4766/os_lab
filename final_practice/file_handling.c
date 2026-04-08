#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char text[100] = "Hello, this is a text file using fread and fwrite!";
    char buffer[100];

    // 🔹 Write text to file
    fp = fopen("text.txt", "w");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fwrite(text, sizeof(char), strlen(text), fp);
    fclose(fp);

    printf("Text written successfully\n");

    // 🔹 Read text from file
    fp = fopen("text.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fread(buffer, sizeof(char), sizeof(buffer), fp);
    fclose(fp);

    printf("Read from file:\n%s\n", buffer);

    return 0;
}