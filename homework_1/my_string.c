// Copyright 2021 Klimov Ilya
#include "homework_1/my_string.h"

int get_string(FILE *flow, char *in_string, int max_len) {
    if (!flow || !in_string || max_len <= 0)
        return -1;

    int last_sym = max_len - 1;
    char c = '\0';
    int length = -1;

    while ((c = fgetc(flow)) == '\n') {};
    
    while (c != '\n' && c != EOF && length < last_sym) {
        length++;
        in_string[length] = c;
        c = fgetc(flow);
    }

    if (length < last_sym) {
        length++;
        in_string[length] = '\0';
    } else {
        length = -1;
    }

    return length;
}
