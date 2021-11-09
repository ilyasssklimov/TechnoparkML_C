#include <gtest/gtest.h>

extern "C"
{
    #include "parser.h"
}


TEST(PARSER_ALLOCATE_TEST, ALLOCATE_PREDICATE)
{
    predicate *pred = (predicate*) malloc(sizeof(predicate));
    
    if (pred != NULL)
    {
        if (allocate_predicate(pred, 10) == OK)
        {
            EXPECT_TRUE(pred->compare != NULL);
            EXPECT_TRUE(pred->numbers != NULL);
            EXPECT_TRUE(pred->logic != NULL);
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


TEST(PARSER_ALLOCATE_TEST, FREE_PREDICATE)
{
    predicate *pred = (predicate*) malloc(sizeof(predicate));
    if (pred)
    {
        if (allocate_predicate(pred, 10) == OK)
        {
            free_predicate(&pred);
            EXPECT_TRUE(pred == NULL);
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


TEST(PARSE_CORRECT_PREDICATE_TEST, CORRECT_PREDICATE_ONE_EXPR)
{
    char str_pred[] = "(x > 20)";
    predicate *pred = (predicate*) malloc(sizeof(predicate));
    if (pred)
    {
        if (parse_predicate(str_pred, pred) == OK)
        {
            EXPECT_TRUE(pred->compare[0] == gt);
            EXPECT_EQ(pred->numbers[0], 20);
            EXPECT_EQ(pred->count_cmp, 1);
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


TEST(PARSE_CORRECT_PREDICATE_TEST, PREDICATE_THREE_EXPR)
{
    char str_pred[] = "(x < 20) && (x >= -10) || (x = 100)";
    predicate *pred = (predicate*) malloc(sizeof(predicate));
    if (pred)
    {
        if (parse_predicate(str_pred, pred) == OK)
        {
            EXPECT_TRUE(pred->compare[0] == lt);
            EXPECT_EQ(pred->numbers[0], 20);
            EXPECT_TRUE(pred->compare[1] == ge);
            EXPECT_EQ(pred->numbers[1], -10);
            EXPECT_TRUE(pred->compare[2] == eq);
            EXPECT_EQ(pred->numbers[2], 100);
            
            EXPECT_EQ(pred->logic[0], AND);
            EXPECT_EQ(pred->logic[1], OR);
            
            EXPECT_EQ(pred->count_cmp, 3);
            
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

TEST(PARSE_INCORRECT_PREDICATE_TEST, MORE_BRACKETS)
{
    char str_pred[] = "(x > 20))";
    predicate *pred = (predicate*) malloc(sizeof(predicate));
    if (pred)
    {
        EXPECT_EQ(parse_predicate(str_pred, pred), INVALID_SYNTAX);
        free(pred);
    }
    else
        ADD_FAILURE();
}


TEST(PARSE_INCORRECT_PREDICATE_TEST, LESS_BRACKETS)
{
    char str_pred[] = "(x > 20) && (x < 40";
    predicate *pred = (predicate*) malloc(sizeof(predicate));
    if (pred)
    {
        EXPECT_EQ(parse_predicate(str_pred, pred), INVALID_SYNTAX);
        free(pred);
    }
    else
        ADD_FAILURE();
}


TEST(PARSE_INCORRECT_PREDICATE_TEST, INCORRECT_COMPARE_OPR)
{
    char str_pred[] = "(x <> 20) && (x < 40)";
    predicate *pred = (predicate*) malloc(sizeof(predicate));
    if (pred)
    {
        EXPECT_EQ(parse_predicate(str_pred, pred), INVALID_SYNTAX);
        free(pred);
    }
    else
        ADD_FAILURE();
}


TEST(PARSE_INCORRECT_PREDICATE_TEST, INCORRECT_LOGIC_OPR)
{
    char str_pred[] = "(x > 20) & (x < 40)";
    predicate *pred = (predicate*) malloc(sizeof(predicate));
    if (pred)
    {
        EXPECT_EQ(parse_predicate(str_pred, pred), INVALID_SYNTAX);
        free(pred);
    }
    else
        ADD_FAILURE();
}


TEST(PARSE_INCORRECT_PREDICATE_TEST, INCORRECT_NUMBER)
{
    char str_pred[] = "(x > 2d0) || (x < 40)";
    predicate *pred = (predicate*) malloc(sizeof(predicate));
    if (pred)
    {
        EXPECT_EQ(parse_predicate(str_pred, pred), INVALID_SYNTAX);
        free(pred);
    }
    else
        ADD_FAILURE();
}
