#include <stdio.h>


int main(int argc, char **argv)
{
    char buffer[5];
    for (int i = 0; i <= 5; i++) { // Off-by-one error: writes past buffer[4]
        buffer[i] = 'A' + i;
    }

    buffer[4] = '\0';
    printf("Buffer: %s\n", buffer);
    return 0;
}
