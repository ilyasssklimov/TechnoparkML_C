#include <stdio.h>
#include <stdlib.h>
#include "toys.h"
#define N 2


int main()
{
    toy **toys = NULL;
    toys = add_toys(stdin, N);
    print_toys(stdout, toys, N);

    char *country = "Russia";
    int amount_countries = 0;
    printf("\nI find toys from %s...\n", country);
    int *indeces = NULL;
    indeces = get_toys_from_country(toys, N, country, &amount_countries);    
    print_toys_by_indeces(stdout, toys, indeces, amount_countries);
    
    if (amount_countries == 0)
    {
        printf("There are no toys from %s :(\n", country);
    }
    if (indeces)
    {
        free(indeces);
    }

    free_toys(toys, N);

    return 0;
}
