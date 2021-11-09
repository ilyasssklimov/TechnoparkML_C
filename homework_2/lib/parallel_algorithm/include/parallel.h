#ifndef __PARALLEL_H__
#define __PARALLEL_H__


#include "parser.h"

#define PROCCESS_2  2 
#define PROCCESS_4  4
#define PROCCESS_8  8
#define PROCCESS_16 16


enum 
{
    FORK_ERROR,
    PARAM_ERROR,
    MAP_ERROR
};


int count_predicate_truth(int *array, int n, predicate *pred);


#endif
