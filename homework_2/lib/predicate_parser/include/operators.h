#ifndef __OPERATORS_H__
#define __OPERATORS_H__


#include <stdbool.h>
#include "my_string.h"


typedef bool (*cmp_opr)(int, int);


typedef enum
{
    AND,
    OR,
    ERROR
} logic_opr;


bool lt(int a, int b);
bool le(int a, int b);

bool eq(int a, int b);

bool gt(int a, int b);
bool ge(int a, int b);


cmp_opr get_compare(my_string opr);
logic_opr get_logic(my_string opr);


#endif
