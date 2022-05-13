#include <stdio.h>
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

    int true_len;
    err = read_int(&true_len);
    if (err)
    {
        free(string);
        return err;
    }

    for (int i = true_len - 1, j = len - 1; i >= 0; i--)
    {
        if (string[i] == ' ')
        {
            string[j] = '0';
            string[j - 1] = '2';
            string[j - 2] = '%';
            j -= 3;
        }
        else
        {
            string[j] = string[i];
            j--;
        }
    }

    printf("%s\n", string);

    free(string);
    return 0;
}