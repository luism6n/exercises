#include <stdlib.h>
#include <stdio.h>

int read_string(char **dest, int *len)
{
    char *str;
    int allocated = 4;
    str = (char *)malloc(allocated);
    if (str == NULL)
    {
        return 1;
    }

    char c;
    *len = 0;
    while ((c = getc(stdin)) != EOF && c != '\n')
    {
        // Guarantee space for next + null char at the end
        if (allocated == *len + 2)
        {
            char *larger;
            allocated *= 2;
            larger = realloc(str, allocated);
            if (larger == NULL)
            {
                // Realloc does not free on failure
                free(str);
                return 1;
            }
            else
            {
                str = larger;
            }
        }

        str[*len] = c;
        (*len)++;
    }

    str[*len] = '\0';
    *dest = str;
    return 0;
}

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