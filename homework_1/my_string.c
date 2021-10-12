#include "my_string.h"


int get_string(FILE *flow, char *string, int max_len)
{
    if (!flow || !string || max_len <= 0)
        return -1;
        
    int last_sym = max_len - 1;
    char c = '\0';
    int length = -1;
    
    while ((c = fgetc(flow)) == '\n');
    while (c != '\n' && c != EOF && length < last_sym)
    {
        length++;
        string[length] = c;
        c = fgetc(flow);
    }

    if (length < last_sym)
    {
        length++;
        string[length] = '\0';
    }
    else
    {
        length = -1;
    }

    return length;
}
