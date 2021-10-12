#ifndef _TOY_H_
#define _TOY_H_

#include <stdio.h>

#define MAX_NAME_LENGTH 128
#define MAX_COUNTRY_LENGTH 64
#define EPS 1e-5

typedef struct toy
{
    char *name;
    double price;
    int volume;
    char *country;
} toy;

toy *add_toy(FILE *flow);
void print_toy(FILE *flow, toy *output_toy);
void free_toy(toy *free_toy);

#endif
