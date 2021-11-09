#include <gtest/gtest.h>

extern "C"
{
    #include "my_string.h"
}


TEST(IS_EMPTY_TEST, EMPTY_STRING)
{
    char test_string[] = "";
    EXPECT_EQ(is_empty(test_string), true);
}


TEST(IS_EMPTY_TEST, NULL_STRING)
{
    char *test_string = NULL;
    EXPECT_EQ(is_empty(test_string), true);
}


TEST(IS_EMPTY_TEST, NOT_EMPTY_STRING)
{
    char test_string[] = "a";
    EXPECT_EQ(is_empty(test_string), false);
}


TEST(COPY_TEST, CORRECT_COPY)
{
    char string_from[] = "abcde";
    char *string_to = (char*) calloc(6, sizeof(char));
    if (string_to != NULL)
    {
        copy_string(&string_to, string_from, 5);
        EXPECT_STREQ(string_to, string_from);
        free(string_to);
    }
    else
        ADD_FAILURE();
}


TEST(COPY_TEST, NULL_STRING)
{
    char string_from[] = "abcde";
    char *string_to = NULL;
    copy_string(&string_to, string_from, 5);
    EXPECT_TRUE(string_to == NULL);
}


TEST(COPY_TEST, EMPTY_SRC_STRING)
{
    char string_from[] = "";
    char *string_to = (char*) calloc(6, sizeof(char));
    if (string_to != NULL)
    {
        copy_string(&string_to, string_from, 5);
        EXPECT_STREQ(string_to, "");
        free(string_to);
    }
    else
        ADD_FAILURE();
}


TEST(COPY_TEST, ZERO_SIZE)
{
    char string_from[] = "abcde";
    char *string_to = (char*) calloc(6, sizeof(char));
    if (string_to != NULL)
    {
        copy_string(&string_to, string_from, 0);
        EXPECT_STREQ(string_to, "");
        free(string_to);
    }
    else
        ADD_FAILURE();
}


TEST(LENGTH_TEST, NOT_ZERO_LENGTH)
{
    char src_string[] = "abcde";
    EXPECT_EQ(length_string(src_string), 5);
}


TEST(LENGTH_TEST, ZERO_LENGTH)
{
    char src_string[] = "";
    EXPECT_EQ(length_string(src_string), 0);
}


TEST(EQUAL_TEST, EQUAL_STRINGS)
{
    char string_1[] = "abcde";
    char string_2[] = "abcde";
    EXPECT_EQ(equal_strings(string_1, string_2), true);
}


TEST(EQUAL_TEST, NOT_EQUAL_STRINGS)
{
    char string_1[] = "abcde";
    char string_2[] = "aaaaa";
    EXPECT_EQ(equal_strings(string_1, string_2), false);
}


TEST(EQUAL_TEST, DIFFERENT_LENGTH)
{
    char string_1[] = "abcde";
    char string_2[] = "abcd";
    EXPECT_EQ(equal_strings(string_1, string_2), false);
}


TEST(EQUAL_TEST, NULL_STRING_1)
{
    char *string_1 = NULL;
    char string_2[] = "abcde";
    EXPECT_EQ(equal_strings(string_1, string_2), false);
}


TEST(EQUAL_TEST, NULL_STRING_2)
{
    char string_1[] = "abcde";
    char *string_2 = NULL;
    EXPECT_EQ(equal_strings(string_1, string_2), false);
}


TEST(FIND_FIRST_TEST, FIND_CHAR)
{
    char src_string[] = "abcbe";
    EXPECT_EQ(find_first_chr(src_string, 'b'), 1);
}


TEST(FIND_FIRST_TEST, NO_FIND_CHAR)
{
    char src_string[] = "abcbe";
    EXPECT_EQ(find_first_chr(src_string, 'p'), NOT_FOUND);
}


TEST(FIND_FIRST_TEST, EMPTY_STRING)
{
    char src_string[] = "";
    EXPECT_EQ(find_first_chr(src_string, 'a'), NULL_STRING);
}


TEST(FIND_LAST_TEST, FIND_CHAR)
{
    char src_string[] = "abcbe";
    EXPECT_EQ(find_last_chr(src_string, 'b'), 3);
}


TEST(FIND_LAST_TEST, NO_FIND_CHAR)
{
    char src_string[] = "abcbe";
    EXPECT_EQ(find_last_chr(src_string, 'p'), NOT_FOUND);
}


TEST(FIND_LAST_TEST, EMPTY_STRING)
{
    char src_string[] = "";
    EXPECT_EQ(find_last_chr(src_string, 'a'), NULL_STRING);
}


TEST(FIND_FROM_TEST, FIND_CHAR)
{
    char src_string[] = "abcbe";
    EXPECT_EQ(find_chr_from(src_string, 'b', 2), 3);
}


TEST(FIND_FROM_TEST, NO_FIND_CHAR)
{
    char src_string[] = "abcbe";
    EXPECT_EQ(find_chr_from(src_string, 'a', 1), NOT_FOUND);
}


TEST(FIND_FROM_TEST, EMPTY_STRING)
{
    char src_string[] = "";
    EXPECT_EQ(find_chr_from(src_string, 'a', 0), NULL_STRING);
}


TEST(FIND_FROM_TEST, NEGATIVE_FROM_VALUE)
{
    char src_string[] = "abcd";
    EXPECT_EQ(find_chr_from(src_string, 'a', -1), NOT_FOUND);
}


TEST(SLICE_TEST, CORRECT_SLICE_ALL)
{
    char src_string[] = "abcdefh";
    char *slc_string = (char*) calloc(8, sizeof(char));
    if (slc_string != NULL)
    {
        slice_string(src_string, &slc_string, 0, length_string(src_string)); 
        EXPECT_STREQ(slc_string, src_string);
        free(slc_string);
    }
    else
        ADD_FAILURE();
}


TEST(SLICE_TEST, CORRECT_SLICE_PART)
{
    char src_string[] = "abcdefh";
    char *slc_string = (char*) calloc(4, sizeof(char));
    if (slc_string != NULL)
    {
        slice_string(src_string, &slc_string, 0, 3); 
        EXPECT_STREQ(slc_string, "abc");
        free(slc_string);
    }
    else
        ADD_FAILURE();
}


TEST(ERASE_TEST, CORRECT_ERASE_ALL)
{
    char src_string[] = "abcdefh";
    char *ers_string = (char*) calloc(8, sizeof(char));
    if (ers_string != NULL)
    {
        slice_string(src_string, &ers_string, 0, length_string(src_string)); 
        erase_string(&ers_string, 0, length_string(src_string));
        EXPECT_STREQ(ers_string, "");
        free(ers_string);
    }
    else
        ADD_FAILURE();
}


TEST(ERASE_TEST, CORRECT_ERASE_PART)
{
    char src_string[] = "abcdefh";
    char *ers_string = (char*) calloc(8, sizeof(char));
    if (ers_string != NULL)
    {
        slice_string(src_string, &ers_string, 0, length_string(src_string));
        erase_string(&ers_string, 1, 3);
        EXPECT_STREQ(ers_string, "aefh");
        free(ers_string);
    }
    else
        ADD_FAILURE();
}