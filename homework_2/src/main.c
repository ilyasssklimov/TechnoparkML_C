#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include "parser.h"
#include "serial.h"
#include <dlfcn.h>
#include <time.h>


#define N 1000000

int main()
{
	my_string tmp = "(x < 20) && (x >= 0) || (x > 30)";
	printf("predicate = %s\n", tmp);
	predicate *pred = malloc(sizeof(predicate));
	
	if (parse_predicate(tmp, pred) != OK)
		printf("error");
	else
	{
		// printf("count = %d\ngood\n%p\n", pred->count_cmp, pred);
		
		int *array = calloc(N, sizeof(int));
		int a = -100;
		int b = 1000;
		for (int i = 0; i < N; i++)
		{
		    array[i] = a + rand() % (b - a + 1);
		}
		clock_t start, finish;
		start = clock();
		int count_serial = count_predicate_truth(array, N, pred);
		finish = clock();
		printf("result by serial = %d, time = %lf\n", count_serial, (double) (finish - start) / CLOCKS_PER_SEC);
		
		
		void *library;
        int (*myfunc)(int*, int, predicate*);

        library = dlopen("libparallel_algorithm.so", RTLD_LAZY);
        if (!library)
		    return OK;
		
        myfunc = dlsym(library, "count_predicate_truth");
        start = clock();
        int count_parallel = (*myfunc)(array, N, pred);
        finish = clock();
        dlclose(library);

	    printf("result by parall = %d, time = %lf\n", count_parallel, (double) (finish - start) / CLOCKS_PER_SEC);
		
	    free(array);
	    free_predicate(&pred);
    }
    
	return 0;

}