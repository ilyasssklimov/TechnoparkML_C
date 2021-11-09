#include <gtest/gtest.h>
#include "parallel.h"


TEST(PARALLEL_TEST, FIND_NUMBERS)
{
    predicate *pred = (predicate*) malloc(sizeof(predicate));
    if (pred)
    {
        int array[10] = {25, 30, 60, 71, 20, 90, 12, 31, 10, 29};
        char str_pred[] = "(x > 10) && (x <= 30) || (x = 90)";
        int count_result = 6;      
        if (parse_predicate(str_pred, pred) == OK)
        {
            int alg_result = count_predicate_truth(array, 10, pred);
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


TEST(PARALLEL_TEST, NO_FIND_NUMBERS)
{
    predicate *pred = (predicate*) malloc(sizeof(predicate));
    if (pred)
    {
        int array[10] = {-25, -30, -60, -71, -20, -90, -12, -31, -10, -29};
        char str_pred[] = "(x > 10) && (x <= 30) || (x = 90)";
        int count_result = 0;      
        if (parse_predicate(str_pred, pred) == OK)
        {
            int alg_result = count_predicate_truth(array, 10, pred);
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


TEST(PARALLEL_TEST, NULL_ARRAY)
{
    predicate *pred = (predicate*) malloc(sizeof(predicate));
    if (pred)
    {
        int *array = NULL;
        char str_pred[] = "(x > 10) && (x <= 30) || (x = 90)";
        int count_result = -1;      
        if (parse_predicate(str_pred, pred) == OK)
        {
            int alg_result = count_predicate_truth(array, 10, pred);
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
    predicate *pred = NULL;
    int array[10] = {25, 30, 60, 71, 20, 90, 12, 31, 10, 29};
    int count_result = -1;
    int alg_result = count_predicate_truth(array, 10, pred);
    EXPECT_EQ(alg_result, count_result);
}


TEST(PARALLEL_TEST, ZERO_SIZE)
{
    predicate *pred = (predicate*) malloc(sizeof(predicate));
    if (pred)
    {
        int array[10] = {25, 30, 60, 71, 20, 90, 12, 31, 10, 29};
        char str_pred[] = "(x > 10) && (x <= 30) || (x = 90)";
        int count_result = -1;      
        if (parse_predicate(str_pred, pred) == OK)
        {
            int alg_result = count_predicate_truth(array, 0, pred);
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