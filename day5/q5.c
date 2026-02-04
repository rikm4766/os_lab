#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int p2c[2], c2p[2];
    char parent_msg[] = "Hello from parent";
    char child_msg[] = "Hello from child";
    char buffer[50];

    pipe(p2c);
    pipe(c2p);

    if (fork() == 0)
    {
        close(p2c[1]);
        read(p2c[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        close(c2p[0]);
        write(c2p[1], child_msg, strlen(child_msg) + 1);
    }
    else
    {
        close(p2c[0]);
        write(p2c[1], parent_msg, strlen(parent_msg) + 1);

        close(c2p[1]);
        read(c2p[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);
    }

    return 0;
}
