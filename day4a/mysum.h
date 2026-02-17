#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char *str) {
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to add two numeric strings
char* addStrings(char *num1, char *num2) {
    
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    int maxLen = (len1 > len2) ? len1 : len2;

    // Allocate memory dynamically (DMA)
    char *result = (char *)malloc(maxLen + 2);  
    // +1 for possible carry, +1 for '\0'

    int i = len1 - 1;
    int j = len2 - 1;
    int k = 0;
    int carry = 0;

    // Add digits from right to left
    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;

        result[k++] = (sum % 10) + '0';

        i--;
        j--;
    }

    result[k] = '\0';

    // Reverse because we stored digits in reverse order
    reverse(result);

    return result;
}