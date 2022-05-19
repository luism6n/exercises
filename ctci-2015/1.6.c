#include <stdio.h>
#include "utils.c"

// Compress first char of s into dest, using at most dest_len chars from dest and outputting
// the actual number of chars used to output_len. s must have at least dest_len
// chars. Output how many chars were compressed to compressed_len.
int compress_char(char *s, char *dest, int dest_len, int *output_len, int *compressed_len)
{
    int count = 1;
    while (s[count - 1] == s[count])
    {
        count++;
    }

    int needed_len = snprintf(dest, dest_len, "%c%d", s[0], count);

    if (needed_len < 0)
    {
        return 1;
    }

    if (needed_len > dest_len)
    {
        *output_len = -1;
        return 0;
    }

    *output_len = needed_len;
    *compressed_len = count;

    return 0;
}

int main()
{
    int err;

    char *s;
    int len;

    err = read_string(&s, &len);
    if (err)
    {
        return err;
    }

    char *output;
    err = alloc_string(&output, len);
    if (err)
    {
        free(s);
        return err;
    }

    int i = 0;
    int output_len = 0;
    while (i < len && output_len < len)
    {
        int compressed_len;
        int added_len;
        err = compress_char(s + i, output + output_len, len - output_len, &added_len, &compressed_len);
        if (err)
        {
            free(s);
            free(output);
            return 1;
        }
        else if (added_len < 1)
        {
            break;
        }

        output_len += added_len;
        i += compressed_len;
    }

    if (i < len)
    {
        printf("%s\n", s);
    }
    else
    {
        output[output_len] = '\0';
        printf("%s\n", output);
    }

    free(s);
    free(output);
    return 0;
}