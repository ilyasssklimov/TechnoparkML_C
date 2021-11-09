#include <gtest/gtest.h>

extern "C"
{
    #include <dlfcn.h>
    #include "parser.h" 
}


TEST(PARALLEL_TEST, FIND_NUMBERS)
{
    predicate *pred = (predicate*) malloc(sizeof(predicate));
    if (pred != NULL)
    {
        int *array = (int*) calloc(10, sizeof(int));
        if (array != NULL)
        {
            array[0] = 25;
            array[1] = 30;
            array[2] = 60;
            array[3] = 71;
            array[4] = 20;
            array[5] = 90;
            array[6] = 12;
            array[7] = 31;
            array[8] = 10;
            array[9] = 29;
            
            char str_pred[] = "(x > 10) && (x <= 30) || (x = 90)";
            int count_result = 6;      
            if (parse_predicate(str_pred, pred) == OK)
            {
                void *library;
			    int (*count_predicate)(int*, int, predicate*);

			    library = dlopen("libparallel_algorithm.so", RTLD_LAZY);
			    if (!library)
			    {
			        free(array);
                    free_predicate(&pred);
                    ADD_FAILURE();
        		}
			
			    count_predicate = (int (*)(int*, int, predicate*)) dlsym(library, "count_predicate_truth");
                int alg_result = (*count_predicate)(array, 10, pred);
			    dlclose(library);
                EXPECT_EQ(alg_result, count_result);
                free(array);
                free_predicate(&pred);
            }
            else
            {
                free(pred);
                ADD_FAILURE();
            } 
        }
        else
        {
            free(pred);
            ADD_FAILURE();
        }
    }
    else
        ADD_FAILURE();
}


TEST(PARALLEL_TEST, NO_FIND_NUMBERS)
{
    predicate *pred = (predicate*) malloc(sizeof(predicate));
    if (pred != NULL)
    {
        int *array = (int*) calloc(10, sizeof(int));
        if (array != NULL)
        {
            array[0] = -25;
            array[1] = -30;
            array[2] = -60;
            array[3] = -71;
            array[4] = -20;
            array[5] = -90;
            array[6] = -12;
            array[7] = -31;
            array[8] = -10;
            array[9] = -29;
            
            char str_pred[] = "(x > 10) && (x <= 30) || (x = 90)";
            int count_result = 0;      
            if (parse_predicate(str_pred, pred) == OK)
            {
                void *library;
			    int (*count_predicate)(int*, int, predicate*);

			    library = dlopen("libparallel_algorithm.so", RTLD_LAZY);
			    if (!library)
			    {
			        free(array);
                    free_predicate(&pred);
                    ADD_FAILURE();
        		}
			
			    count_predicate = (int (*)(int*, int, predicate*)) dlsym(library, "count_predicate_truth");
                int alg_result = (*count_predicate)(array, 10, pred);
			    dlclose(library);
                EXPECT_EQ(alg_result, count_result);
                free(array);
                free_predicate(&pred);
            }
            else
            {
                free(pred);
                ADD_FAILURE();
            } 
        }
        else
        {
            free(pred);
            ADD_FAILURE();
        }
    }
    else
        ADD_FAILURE();
}


TEST(PARALLEL_TEST, NULL_ARRAY)
{
    predicate *pred = (predicate*) malloc(sizeof(predicate));
    if (pred != NULL)
    {
        int *array = NULL;
        char str_pred[] = "(x > 10) && (x <= 30) || (x = 90)";
        int count_result = -1;      
        if (parse_predicate(str_pred, pred) == OK)
        {
            void *library;
		    int (*count_predicate)(int*, int, predicate*);

		    library = dlopen("libparallel_algorithm.so", RTLD_LAZY);
		    if (!library)
		    {
                free_predicate(&pred);
                ADD_FAILURE();
      		}
			
		    count_predicate = (int (*)(int*, int, predicate*)) dlsym(library, "count_predicate_truth");
            int alg_result = (*count_predicate)(array, 10, pred);
	        dlclose(library);
            EXPECT_EQ(alg_result, count_result);
            free_predicate(&pred);
        }
        else
        {
            free(pred);
            ADD_FAILURE();
        } 
    }
    else
        ADD_FAILURE();
}


TEST(PARALLEL_TEST, NULL_PREDICATE)
{
    int *array = (int*) calloc(10, sizeof(int));
    if (array != NULL)
    {
		array[0] = -25;
		array[1] = -30;
		array[2] = -60;
		array[3] = -71;
		array[4] = -20;
		array[5] = -90;
		array[6] = -12;
		array[7] = -31;
		array[8] = -10;
		array[9] = -29;
        
        predicate *pred = NULL;
        int count_result = -1;
        
        void *library;
		int (*count_predicate)(int*, int, predicate*);

		library = dlopen("libparallel_algorithm.so", RTLD_LAZY);
		if (!library)
		{
		    free(array);
            ADD_FAILURE();
        }
			
		count_predicate = (int (*)(int*, int, predicate*)) dlsym(library, "count_predicate_truth");
        int alg_result = (*count_predicate)(array, 10, pred);
		dlclose(library);
        EXPECT_EQ(alg_result, count_result);
        free(array);
     }
     else
         ADD_FAILURE();   
}


TEST(PARALLEL_TEST, ZERO_SIZE)
{
    predicate *pred = (predicate*) malloc(sizeof(predicate));
    if (pred != NULL)
    {
        int *array = (int*) calloc(10, sizeof(int));
        if (array != NULL)
        {
            array[0] = 25;
            array[1] = 30;
            array[2] = 60;
            array[3] = 71;
            array[4] = 20;
            array[5] = 90;
            array[6] = 12;
            array[7] = 31;
            array[8] = 10;
            array[9] = 29;
            
            char str_pred[] = "(x > 10) && (x <= 30) || (x = 90)";
            int count_result = -1;      
            if (parse_predicate(str_pred, pred) == OK)
            {
                void *library;
			    int (*count_predicate)(int*, int, predicate*);

			    library = dlopen("libparallel_algorithm.so", RTLD_LAZY);
			    if (!library)
			    {
			        free(array);
                    free_predicate(&pred);
                    ADD_FAILURE();
        		}
			
			    count_predicate = (int (*)(int*, int, predicate*)) dlsym(library, "count_predicate_truth");
                int alg_result = (*count_predicate)(array, 0, pred);
			    dlclose(library);
                EXPECT_EQ(alg_result, count_result);
                free(array);
                free_predicate(&pred);
            }
            else
            {
                free(pred);
                ADD_FAILURE();
            } 
        }
        else
        {
            free(pred);
            ADD_FAILURE();
        }
    }
    else
        ADD_FAILURE();
}