#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include "parser.h"

#ifdef WITH_PARALLEL
    #include <dlfcn.h>
#else 
    #include "serial.h"
#endif


#define N 10e8
#define MAX_PRED 256


int main(int argc, char **argv)
{
	my_string str_pred = calloc(MAX_PRED, sizeof(char));
	if (str_pred == NULL)
	{
	    printf("Allocate error. Try again.\n");
	    return 0;
	}
	
	FILE *f = NULL;
	
	if (argc == 2)
	{
	    f = fopen(argv[1], "r");
		if (f != NULL)
		{
			if (fgets(str_pred, MAX_PRED, f) == NULL)
			{
				free(str_pred);
	            fclose(f);
				printf("Invalid predicate. Try again.\n");
				return 0;
			}
	    }
	    else
	    {
	        free(str_pred);
			printf("Invalid file. Try again.\n");
			return 0;
		}
    }
    else
    {
	    printf("Input predicate: ");
		if (fgets(str_pred, MAX_PRED, stdin) == NULL)
		{
			free(str_pred);
			printf("Invalid predicate. Try again.\n");
			return 0;
		}
    }
    
	int len_pred = length_string(str_pred);
	if (str_pred[len_pred - 1] == '\n')
    	erase_string(&str_pred, len_pred - 1, len_pred - 1);
    	
	printf("%s\n", str_pred);
	predicate *pred = malloc(sizeof(predicate));
	
	if (pred != NULL)
	{
		int res = parse_predicate(str_pred, pred);
		free(str_pred);
		if (res == OK)
		{
			int *array = calloc(N, sizeof(int));
            if (array != NULL)
            {
                int x, n;
                if (argc == 2)
                {
					n = 0;
					while (fscanf(f, "%d", &x) == 1)
					{
						array[n++] = x;
					} 
					fclose(f);
                }
                else
                {
                    printf("Input size: ");
                    if (scanf("%d", &n) == 1)
                    {
                        for (int i = 0; i < n; i++)
                        {
                            if (scanf("%d", &x) == 1)   
                            {
                                array[i] = x;
                            }
                            else
                            {
                                free(array);
                                free_predicate(&pred);
                                printf("Incorrect number. Try again.\n");
                                return 0;
                            }   
                        }
                    }
                    else
                    {
                        free(array);
                        free_predicate(&pred);
                        printf("Incorrect size. Try again.\n");
                        return 0;
                    }    
                }
				#ifdef WITH_PARALLEL
					void *library;
					int (*count_predicate)(int*, int, predicate*);

					library = dlopen("libparallel_algorithm.so", RTLD_LAZY);
					if (library != NULL)
					{
					    *(void**)(&count_predicate) = dlsym(library, "count_predicate_truth");
					    int count_parallel = (*count_predicate)(array, n, pred);
					    printf("Result by parallel algorithm = %d\n", count_parallel);
					    dlclose(library);
					}
					else 
					{
					    printf("Problem with open library. Try again.\n");
				    }
				#else
					int count_serial = count_predicate_truth(array, n, pred);
					printf("Result by serial algorithm = %d\n", count_serial);
				#endif
				
				free(array);
				free_predicate(&pred);
			}
			else
			{
                printf("Allocate error. Try again.\n");
			    free_predicate(&pred);
			}
		}
		else 
		{
		    if (res == INVALID_SYNTAX)
		        printf("Syntax error. Try again.\n");
		    else
                printf("Allocate error. Try again.\n");
            free(pred);
        }
    }
    else
    {
        printf("Allocate error. Try again.\n");
    }
    
	return 0;

}