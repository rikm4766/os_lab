
#include <stdlib.h>
#include <string.h>

char* multiplyStrings(char *num1, char *num2) {

    int len1 = strlen(num1);
    int len2 = strlen(num2);

    if (len1 == 0 || len2 == 0)
        return NULL;

    // Maximum length of result = len1 + len2
    int *temp = (int*)calloc(len1 + len2, sizeof(int));

    // Multiply like school method
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {

            int mul = (num1[i] - '0') * (num2[j] - '0');

            int sum = mul + temp[i + j + 1];

            temp[i + j + 1] = sum % 10;     // Store digit
            temp[i + j] += sum / 10;        // Carry
        }
    }

    // Allocate result string
    char *result = (char*)malloc(len1 + len2 + 1);

    int k = 0;
    int i = 0;

    // Skip leading zeros
    while (i < len1 + len2 && temp[i] == 0)
        i++;

    if (i == len1 + len2) {
        result[k++] = '0';
    } else {
        while (i < len1 + len2)
            result[k++] = temp[i++] + '0';
    }

    result[k] = '\0';

    free(temp);
    return result;
}
