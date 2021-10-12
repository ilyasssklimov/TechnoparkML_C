#ifndef _TOYS_H_
#define _TOYS_H_

#include "toy.h"

toy** add_toys(FILE *flow, int n);
void print_toys(FILE *flow, toy *toys[], int n);
void free_toys(toy *toys[], int n);
int *get_toys_from_country(toy **toys, int n, const char *search_country, int *amount);
void print_toys_by_indeces(FILE *flow, toy **toys, int *indeces, int m);

#endif
