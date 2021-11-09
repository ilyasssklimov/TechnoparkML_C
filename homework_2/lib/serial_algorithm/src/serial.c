#include "serial.h"
#include <stddef.h>


inline int count_predicate_truth(int *array, int n, predicate *pred)
{
    if (array == NULL || n <= 0 || pred == NULL)
        return -1;
    
    int count = 0;
    
    for (int i = 0; i < n; i++)
        count += do_predicate(pred, array[i]);
    
    return count;
}