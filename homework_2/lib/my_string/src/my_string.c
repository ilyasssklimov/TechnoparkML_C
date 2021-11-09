#include "my_string.h"
#include <stdlib.h>


bool is_empty(my_string src_string)
{
    if (src_string == NULL || src_string[0] == '\0')
        return true;
    else
        return false;
}


void copy_string(my_string *string_1, my_string string_2, int n)
{
    if (likely(*string_1 && !is_empty(string_2) && n > 0))
	{
	    int ind = 0;
	    for (int i = 0; i < n && string_2[i] != '\0'; i++)
	    {
	        (*string_1)[ind++] = string_2[i];
	    }
	    (*string_1)[ind] = '\0';
	}
}


int length_string(my_string src_string)
{
	if (unlikely(is_empty(src_string)))
	    return 0;

    int i = -1;
    while (src_string[++i] != '\0') {}
	
    return i;
}


bool equal_strings(my_string string_1, my_string string_2)
{
    if (unlikely(string_1 == NULL || string_2 == NULL))
    {
        return false;
    }
        
	int i = 0;
	bool end = false;
	
	while (string_1[i] == string_2[i] && end == false)
	{
		i++;
		if (string_1[i] == '\0')
			end = true;
	}
	
	return end;
}


int find_first_chr(my_string src_string, char value)
{
    if (unlikely(is_empty(src_string)))
	    return NULL_STRING;

    int i = 0;
    
    while (src_string[i] != '\0')
    {
	    if (src_string[i] == value)
        {
            return i;
        }
        i++;
    }
    
    return NOT_FOUND;
}


int find_chr_from(my_string src_string, char value, int start)
{
    if (unlikely(is_empty(src_string)))
	    return NULL_STRING;

    if (unlikely(start < 0))
        return NOT_FOUND;
        
    int i = start;
    
    while (src_string[i] != '\0')
    {
	    if (src_string[i] == value)
        {
            return i;
        }
        i++;
    }
    
    return NOT_FOUND;
}


int find_last_chr(my_string src_string, char value)
{
    if (unlikely(is_empty(src_string)))
	    return NULL_STRING;
		
    int i = 0;
    int find_index = NOT_FOUND;
    
    while (src_string[i] != '\0')
    {
	    if (src_string[i] == value)
        {
            find_index = i;
        }
        i++;
    }
    
    return find_index;
}


void slice_string(my_string src_string, my_string *slc_string, int first, int last)
{
    if (likely(!is_empty(src_string) && slc_string && first >= 0 && first < length_string(src_string) && first < last))
    {
	    int ind = 0;
	    for (int i = first; i < last && src_string[i] != '\0'; i++)
	    {
	        (*slc_string)[ind++] = src_string[i];
	    }
	    (*slc_string)[ind] = '\0';
    }
}


void erase_string(my_string *src_string, int first, int last)
{
    if (likely(!is_empty(*src_string) && first >= 0 && first < length_string(*src_string) && first <= last))
    {
        int len = length_string(*src_string);
        my_string tmp_string = malloc(len * sizeof(char));
        if (tmp_string)
        {
		    int ind = 0;
			for (int i = 0; i < first && (*src_string)[i] != '\0'; i++)
			{
				tmp_string[ind++] = (*src_string)[i];
 			}
 			for (int i = last + 1; i < len && (*src_string)[i] != '\0'; i++)
 			{
 			    tmp_string[ind++] = (*src_string)[i];
 			}
 			tmp_string[ind] = '\0';
 			for (int i = 0; i < ind + 1; i++)
 			{
				(*src_string)[i] = tmp_string[i];
			}
 			free(tmp_string);
		}
    }
}