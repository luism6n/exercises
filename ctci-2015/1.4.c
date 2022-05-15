#include <stdio.h>
#include <stdlib.h>
#include "utils.c"

int main()
{
    int err;
    char *string;
    int len;
    err = read_string(&string, &len);
    if (err)
    {
        return err;
    }

    int *counts;
    int alphabet_size = 256;
    counts = calloc(alphabet_size, 1);
    for (int i = 0; i < len; i++)
    {
        counts[string[i]]++;
    }

    int odd_counts = 0;
    for (int i = 0; i < alphabet_size; i++)
    {
        if (counts[i] % 2 != 0)
        {
            odd_counts++;
        }
    }

    // To form a palindrome, every letter must have a "mirror" letter, except
    // for the one in the middle. So we can have at most 1 letter that appears
    // an odd number of times.
    if (odd_counts > 1)
    {
        printf("false\n");
    }
    else
    {
        printf("true\n");
    }

    return 0;
}