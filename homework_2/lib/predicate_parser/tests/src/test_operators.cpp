#include <gtest/gtest.h>

extern "C"
{
    #include "operators.h"
}


TEST(OPERATOR_TEST, OPERATOR_LT_TRUE)
{
    int a = 20, b = 21;
    bool result = lt(a, b);
    EXPECT_TRUE(result == true);
}


TEST(OPERATOR_TEST, OPERATOR_LT_FALSE)
{
    int a = 20, b = 20;
    bool result = lt(a, b);
    EXPECT_TRUE(result == false);
}


TEST(OPERATOR_TEST, OPERATOR_LE_TRUE)
{
    int a = 20, b = 20;
    bool result = le(a, b);
    EXPECT_TRUE(result == true);
}


TEST(OPERATOR_TEST, OPERATOR_LE_FALSE)
{
    int a = 20, b = 19;
    bool result = le(a, b);
    EXPECT_TRUE(result == false);
}


TEST(OPERATOR_TEST, OPERATOR_EQ_TRUE)
{
    int a = 5, b = 5;
    bool result = eq(a, b);
    EXPECT_TRUE(result == true);
}


TEST(OPERATOR_TEST, OPERATOR_EQ_FALSE)
{
    int a = 5, b = 59;
    bool result = eq(a, b);
    EXPECT_TRUE(result == false);
}


TEST(OPERATOR_TEST, OPERATOR_GT_TRUE)
{
    int a = 41, b = 40;
    bool result = gt(a, b);
    EXPECT_TRUE(result == true);
}


TEST(OPERATOR_TEST, OPERATOR_GT_FALSE)
{
    int a = 40, b = 40;
    bool result = gt(a, b);
    EXPECT_TRUE(result == false);
}


TEST(OPERATOR_TEST, OPERATOR_GE_TRUE)
{
    int a = 40, b = 40;
    bool result = ge(a, b);
    EXPECT_TRUE(result == true);
}


TEST(OPERATOR_TEST, OPERATOR_GE_FALSE)
{
    int a = 39, b = 40;
    bool result = ge(a, b);
    EXPECT_TRUE(result == false);
}


TEST(LOGIC_TEST, GET_AND)
{
    char opr[] = "&&";
    EXPECT_EQ(get_logic(opr), AND);
}


TEST(LOGIC_TEST, GET_OR)
{
    char opr[] = "||";
    EXPECT_EQ(get_logic(opr), OR);
}


TEST(LOGIC_TEST, GET_ERROR)
{
    char opr[] = "abc";
    EXPECT_EQ(get_logic(opr), ERROR);
}


TEST(COMPARE_TEST, GET_LT)
{
    char str_opr[] = "<"; 
    cmp_opr opr = get_compare(str_opr);
    EXPECT_EQ(opr, lt);
}


TEST(COMPARE_TEST, GET_LE)
{
    char str_opr[] = "<="; 
    cmp_opr opr = get_compare(str_opr);
    EXPECT_EQ(opr, le);
}


TEST(COMPARE_TEST, GET_EQ)
{
    char str_opr[] = "="; 
    cmp_opr opr = get_compare(str_opr);
    EXPECT_EQ(opr, eq);
}


TEST(COMPARE_TEST, GET_GT)
{
    char str_opr[] = ">"; 
    cmp_opr opr = get_compare(str_opr);
    EXPECT_EQ(opr, gt);
}


TEST(COMPARE_TEST, GET_GE)
{
    char str_opr[] = ">="; 
    cmp_opr opr = get_compare(str_opr);
    EXPECT_EQ(opr, ge);
}


TEST(COMPARE_TEST, GET_NULL)
{
    char str_opr[] = "a"; 
    cmp_opr opr = get_compare(str_opr);
    EXPECT_TRUE(opr == NULL);
}