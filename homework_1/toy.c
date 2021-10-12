#include "toy.h"
#include "my_string.h"
#include <stdlib.h>



toy* add_toy(FILE *flow)
{
    if (!flow)
        return NULL;
    
    char *name = (char*) malloc(MAX_NAME_LENGTH * sizeof(char));
    if (!name)
    {
        printf("Allocate error! Try again.\n");
        fflush(stdout);
        return NULL;
    }

    if (flow == stdin)
    {
        printf("Name (len < %d): ", MAX_NAME_LENGTH);
        fflush(stdout);
    }
    
    if (get_string(flow, name, MAX_NAME_LENGTH) <= 0)
    {
        printf("Incorrect name! The length should be less then %d and more then 0.\n", MAX_NAME_LENGTH);
        free(name);
        fflush(stdout);
        return NULL;
    }
    
    double price = -1.0;

    if (flow == stdin)
    {
        printf("Price: ");
        fflush(stdout);
    }
    
    if (fscanf(flow, "%lf", &price) != 1 || price <= EPS)
    {
        printf("Incorrect price! The price should be positive number.\n");
        free(name);
        fflush(stdout);
        return NULL;
    }

    int volume = -1;

    if (flow == stdin)
    {
        printf("Volume of stocks: ");
        fflush(stdout);
    }
    
    if (fscanf(flow, "%d", &volume) != 1 || volume < 0)
    {
        printf("Incorrect price! The volume should be not negative number.\n");
        free(name);
        fflush(stdout);
        return NULL;
    }

    char *country = (char*) malloc(MAX_COUNTRY_LENGTH * sizeof(char));  
    if (!country)
    {
        printf("Allocate error!. Try again.\n");
        free(name);
        fflush(stdout);
        return NULL;
    }

    if (flow == stdin)
    {
        printf("Manufacturer country (len < %d): ", MAX_COUNTRY_LENGTH);
        fflush(stdout); 
    }
    
    if (get_string(flow, country, MAX_COUNTRY_LENGTH) <= 0)
    {
        printf("Incorrect name of country! The length should be less then %d and more then 0.\n", MAX_COUNTRY_LENGTH);
        free(name);
        free(country);
        fflush(stdout);
        return NULL;
    }

    toy *new_toy = (toy*) malloc(sizeof(toy));
    new_toy->name = name;
    new_toy->price = price;
    new_toy->volume = volume;
    new_toy->country = country;

    return new_toy;
}


void print_toy(FILE *flow, toy *output_toy)
{
    if (!flow)
        return;

    if (output_toy && output_toy->name && output_toy->country && output_toy->price > EPS && output_toy->volume >= 0)
    {
        fprintf(flow, "Name: %s\nPrice: %.2lf\nVolume of stocks: %d\nManufacturer country: %s\n", 
        output_toy->name, output_toy->price, output_toy->volume, output_toy->country);
    }
    else
    {
        fprintf(flow, "Invalid toy\n");
    }
}


void free_toy(toy *free_toy)
{   
    if (free_toy)
    {
        if (free_toy->name)
        {
            free(free_toy->name);
            free_toy->name = NULL;
        }
        if (free_toy->country)
        {
            free(free_toy->country);
            free_toy->country = NULL;
        }
        free(free_toy);
        free_toy = NULL;
    }
}