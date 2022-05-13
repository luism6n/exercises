#include <stdlib.h>

int read_int(int *dest)
{
    int num_items_read = scanf("%d", dest);
    if (num_items_read != 1)
    {
        return 1;
    }

    return 0;
}

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