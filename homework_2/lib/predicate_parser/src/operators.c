#include "operators.h"
#include <stddef.h>


bool lt(int a, int b)
{
    return a < b;
}


bool le(int a, int b)
{
    return a <= b;
}


bool eq(int a, int b)
{
    return a == b;
}


bool gt(int a, int b)
{
    return a > b;
}


bool ge(int a, int b)
{
    return a >= b;
}


logic_opr get_logic(my_string opr)
{
    if (equal_strings(opr, "&&"))
        return AND;
    else if (equal_strings(opr, "||"))
        return OR;
    else
        return ERROR;
}


cmp_opr get_compare(my_string opr)
{
    if (equal_strings(opr, "<"))
        return lt;
    else if (equal_strings(opr, "<="))
        return le;
    else if (equal_strings(opr, "="))
        return eq;
    else if (equal_strings(opr, ">"))
        return gt;
    else if (equal_strings(opr, ">="))
        return ge;
    else 
		return NULL;
}
