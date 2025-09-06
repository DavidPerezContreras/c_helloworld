#include <stdio.h>
#include <stdlib.h>

char *read_line(size_t *size_before_shrink, size_t *final_size) {
    size_t bufsize = 256;
    size_t len = 0;
    char *buffer = malloc(bufsize);
    if (!buffer) {
        perror("malloc failed");
        return NULL;
    }

    int ch;
    while ((ch = fgetc(stdin)) != EOF) {
        if (ch == '\n') break;

        // Grow buffer if needed
        if (len + 1 >= bufsize) {
            bufsize *= 2;
            char *new_buffer = realloc(buffer, bufsize);
            if (!new_buffer) {
                perror("realloc failed");
                free(buffer);
                return NULL;
            }
            buffer = new_buffer;
        }

        buffer[len++] = (char)ch;
    }

    // Handle EOF with no input
    if (len == 0 ) {
        free(buffer);
        return NULL;
    }

    
    
    buffer[len] = '\0';


    // Save sizes before and after shrinking
    *size_before_shrink = bufsize;
    *final_size = len + 1;

    // Shrink to exact size
    char *shrunk = realloc(buffer, len + 1);
    return shrunk ? shrunk : buffer;
}

int main(void) {
    printf("Enter a line: ");

    size_t before, after;
    char *line = read_line(&before, &after);

    if (line) {
        printf("You entered: '%s'\n", line);
        printf("Buffer size before shrinking: %zu bytes\n", before);
        printf("Buffer size after shrinking:  %zu bytes\n", after);
        free(line);
    } else {
        printf("No input or error occurred.\n");
    }

    return 0;
}
