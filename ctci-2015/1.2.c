#include <stdio.h>
#include "utils.c"

int main()
{
    int err;
    char *s1, *s2;
    int len1, len2;

    err = read_string(&s1, &len1);
    if (err)
    {
        return err;
    }

    err = read_string(&s2, &len2);
    if (err)
    {
        return err;
    }

    if (len1 != len2)
    {
        printf("false\n");
        return 0;
    }

    int *counts1, *counts2;

    // Assume extended ASCII
    int alphabet_size = 256;
    counts1 = calloc(alphabet_size, sizeof(int));
    if (counts1 == NULL)
    {
        return 1;
    }

    counts2 = calloc(alphabet_size, sizeof(int));
    if (counts2 == NULL)
    {
        return 1;
    }

    for (int i = 0; i < len1; i++)
    {
        char c1 = s1[i];
        counts1[c1]++;
        char c2 = s2[i];
        counts2[c2]++;
    }

    for (int c = 0; c < alphabet_size; c++)
    {
        if (counts1[c] != counts2[c])
        {
            printf("false\n");
            free(s1);
            free(s2);
            free(counts1);
            free(counts2);
            return 0;
        }
    }

    printf("true\n");
    free(s1);
    free(s2);
    free(counts1);
    free(counts2);
    return 0;
}