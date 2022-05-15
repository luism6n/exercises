#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.c"

// Check if the string large is the same as small with one character removed. small must
// have lenght len and large must be len + 1 in length.
int is_one_insertion_away(char *small, char *large, int len)
{
    int insertions_needed = 0;
    int i = 0, j = 0;
    while (i < len && j < len + 1)
    {
        if (large[j] != small[i])
        {
            insertions_needed += 1;
            j++;
        }
        else
        {
            j++;
            i++;
        }
    }

    // If i == j, small and large are the same up to len, so we need to add 1 char to
    // small, the one at the end of large.
    return i == j || insertions_needed == 1;
}

// Check if s1 has at most one char different than s2. s1 must have a length of len
int is_one_replacement_away(char *s1, char *s2, int len)
{
    int diff_count = 0;
    for (int i = 0; i < len; i++)
    {
        if (s1[i] != s2[i])
        {
            diff_count += 1;
        }
    }

    return diff_count == 1;
}

int main()
{
    int err;

    char *s1, *s2;
    int l1, l2;

    err = read_string(&s1, &l1);
    if (err)
    {
        return err;
    }

    err = read_string(&s2, &l2);
    if (err)
    {
        free(s1);
        return err;
    }

    if (l1 == l2 + 1 && is_one_insertion_away(s2, s1, l2))
    {
        printf("true\n");
    }
    else if (l2 == l1 + 1 && is_one_insertion_away(s1, s2, l1))
    {
        printf("true\n");
    }
    else if (l1 == l2 && (strcmp(s1, s2) == 0 || is_one_replacement_away(s1, s2, l1)))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    free(s1);
    free(s2);
    return 0;
}