#include <stdlib.h>
#include <stdio.h>
#include "utils.c"

int main()
{
    char *input;
    char *counts;
    int err;
    int len;

    counts = calloc(256, 1); // Assume extended ASCII

    err = read_string(&input, &len);
    if (err)
    {
        return err;
    }

    for (int i = 0; i < len; i++)
    {
        char c = input[i];
        if (counts[c])
        {
            printf("true\n");
            return 0;
        }

        counts[c] = 1;
    }

    printf("false\n");
    return 0;
}