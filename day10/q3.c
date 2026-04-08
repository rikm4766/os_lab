#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int req[50], wait[50];
    int totalSeek = 0;

    printf("Enter number of I/O requests: ");
    scanf("%d", &n);

    printf("Enter the I/O request sequence:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(req[i] > req[j])
            {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    wait[0] = 0;

    for(i = 1; i < n; i++)
    {
        wait[i] = wait[i - 1] + (req[i] - req[i - 1]);
        totalSeek += (req[i] - req[i - 1]);
    }

    printf("\nExecution Order :\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", req[i]);
    }

    printf("\n\nWaiting Time for each request:\n");
    for(i = 0; i < n; i++)
    {
        printf("Request %d: %d\n", req[i], wait[i]);
    }

    printf("\nTotal Seek Time: %d\n", totalSeek);

    return 0;
}