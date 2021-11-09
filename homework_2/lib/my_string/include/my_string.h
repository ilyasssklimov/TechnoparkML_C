#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <stdbool.h>

#define unlikely(expr) __builtin_expect(!!(expr), 0)
#define likely(expr) __builtin_expect(!!(expr), 1)


enum string_error
{
    NOT_FOUND = -1,
    NULL_STRING = -2
};


typedef char* my_string;

bool is_empty(my_string src_string);
int length_string(my_string);

void copy_string(my_string*, my_string, int);

bool equal_strings(my_string, my_string);

int find_first_chr(my_string, char);
int find_chr_from(my_string, char, int);

int find_last_chr(my_string, char);

void slice_string(my_string, my_string*, int, int);
void erase_string(my_string*, int, int);


#endif