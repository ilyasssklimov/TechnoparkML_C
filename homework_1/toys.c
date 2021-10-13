// Copyright 2021 Klimov Ilya
#include "homewwork_1/toys.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "homework_1/my_string.h"

toy **add_toys(FILE *flow, int n) {
    if (n <= 0 || !flow)
        return NULL;

    toy **toys = malloc(n * sizeof(toy *));
    if (!toys) {
        printf("Allocate error! Try again.\n");
        fflush(stdout);
        return NULL;
    }

    toy *tmp_toy = NULL;

    for (int i = 0; i < n; i++) {
        toys[i] = malloc(sizeof(toy));
        if (toys[i]) {
            toys[i]->name = NULL;
            toys[i]->country = NULL;
            if (flow == stdin) {
                printf("Adding toy №%d...\n", i + 1);
                fflush(stdout);
            }
            tmp_toy = add_toy(flow);

            if (tmp_toy) {
                toys[i] = tmp_toy;
                printf("\n");
            } else {
                free_toys(toys, i + 1);
                return NULL;
            }
        } else {
            printf("Allocate error! Try again.\n");
            free_toys(toys, i);
            return NULL;
        }
    }
    fflush(stdout);

    return toys;
}

void print_toys(FILE *flow, toy *toys[], int n) {
    if (!toys || n <= 0 || !flow)
        return;

    fprintf(flow, "-----------------------------\n");
    fprintf(flow, "Table of toys\n");
    fprintf(flow, "-----------------------------\n");
    for (int i = 0; i < n; i++) {
        fprintf(flow, "Toy №%d\n", i + 1);
        if (toys[i]) {
            print_toy(flow, toys[i]);
        } else {
            fprintf(flow, "Invalid toy\n");
        }
        fprintf(flow, "-----------------------------\n");
    }
}

void free_toys(toy *toys[], int n) {
    if (!toys || n < 0)
        return;

    for (int i = 0; i < n; i++) {
        if (toys[i]) {
            free_toy(toys[i]);
        }
    }
    free(toys);
    toys = NULL;
}

int *get_toys_from_country(toy **toys, int n, const char *search_country, int *amount) {
    if (strlen(search_country) == 0 || !toys || n <= 0)
        return NULL;

    int *indeces = malloc(n * sizeof(int));
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(toys[i]->country, search_country) == 0) {
            indeces[j] = i;
            j++;
        }
    }

    *amount = j;
    return indeces;
}

void print_toys_by_indeces(FILE *flow, toy **toys, int *indeces, int m) {
    if (!toys || !indeces || m <= 0 || !flow)
        return;

    int index = 0;
    fprintf(flow, "-----------------------------\n");
    fprintf(flow, "Found toys\n");
    fprintf(flow, "-----------------------------\n");
    for (int i = 0; i < m; i++) {
        index = indeces[i];
        fprintf(flow, "Toy №%d\n", index + 1);
        if (toys[index]) {
            print_toy(flow, toys[index]);
        } else {
            fprintf(flow, "Invalid toy\n");
        }
        fprintf(flow, "-----------------------------\n");
    }
}
