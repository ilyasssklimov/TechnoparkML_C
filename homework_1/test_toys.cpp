#include <gtest/gtest.h>

extern "C"
{
#include "toys.h"
}

#define N0 0
#define N1 1
#define N2 3

TEST(POSITIVE_TOYS_TEST, NO_TOYS)
{
    toy **toys = NULL;
    const char *filename = "test.txt";
    FILE *file = NULL;

    file = fopen(filename, "w");
    fprintf(file, "Toy1\n200\n100\nRussia\n");
    fclose(file);

    file = fopen(filename, "r");
    toys = add_toys(file, N0);
    fclose(file);

    EXPECT_TRUE(toys == NULL);
}

TEST(POSITIVE_TOYS_TEST, ONE_TOY)
{
    toy **toys = NULL;
    const char *filename = "test.txt";
    FILE *file = NULL;

    file = fopen(filename, "w");
    fprintf(file, "Toy1\n200\n100\nRussia\n");
    fclose(file);

    file = fopen(filename, "r");
    toys = add_toys(file, N1);
    fclose(file);

    EXPECT_STREQ(toys[0]->name, "Toy1");
    EXPECT_DOUBLE_EQ(toys[0]->price, 200.0);
    EXPECT_EQ(toys[0]->volume, 100);
    EXPECT_STREQ(toys[0]->country, "Russia");

    free_toys(toys, N1);
}

TEST(POSITIVE_TOYS_TEST, THREE_TOYS)
{
    toy **toys = NULL;
    const char *filename = "test.txt";
    FILE *file = NULL;

    file = fopen(filename, "w");
    fprintf(file, "Toy1\n200\n100\nRussia\n");
    fprintf(file, "Toy2\n99.99\n10\nItaly\n");
    fprintf(file, "Toy3\n20.5\n500\nFrance\n");
    fclose(file);

    file = fopen(filename, "r");
    toys = add_toys(file, N2);
    fclose(file);

    EXPECT_STREQ(toys[0]->name, "Toy1");
    EXPECT_DOUBLE_EQ(toys[0]->price, 200.0);
    EXPECT_EQ(toys[0]->volume, 100);
    EXPECT_STREQ(toys[0]->country, "Russia");

    EXPECT_STREQ(toys[1]->name, "Toy2");
    EXPECT_DOUBLE_EQ(toys[1]->price, 99.99);
    EXPECT_EQ(toys[1]->volume, 10);
    EXPECT_STREQ(toys[1]->country, "Italy");

    EXPECT_STREQ(toys[2]->name, "Toy3");
    EXPECT_DOUBLE_EQ(toys[2]->price, 20.5);
    EXPECT_EQ(toys[2]->volume, 500);
    EXPECT_STREQ(toys[2]->country, "France");

    free_toys(toys, N2);
}

TEST(POSITIVE_TOYS_TEST, FIND_BY_COUNTRY)
{
    toy **toys = NULL;
    const char *filename = "test.txt";
    const char *country = "Russia";
    FILE *file = NULL;

    file = fopen(filename, "w");
    fprintf(file, "Toy1\n200\n100\nRussia\n");
    fprintf(file, "Toy2\n99.99\n10\nItaly\n");
    fprintf(file, "Toy3\n20.5\n500\nRussia\n");
    fclose(file);

    file = fopen(filename, "r");
    toys = add_toys(file, N2);
    fclose(file);

    int *indeces = NULL;
    int amount_countries = 0;
    indeces = get_toys_from_country(toys, N2, country, &amount_countries);
    EXPECT_EQ(amount_countries, 2);
    EXPECT_EQ(indeces[0], 0);
    EXPECT_EQ(indeces[1], 2);

    free(indeces);
    free_toys(toys, N2);
}

TEST(POSITIVE_TOYS_TEST, NOT_FIND_BY_COUNTRY)
{
    toy **toys = NULL;
    const char *filename = "test.txt";
    const char *country = "Germany";
    FILE *file = NULL;

    file = fopen(filename, "w");
    fprintf(file, "Toy1\n200\n100\nRussia\n");
    fprintf(file, "Toy2\n99.99\n10\nItaly\n");
    fprintf(file, "Toy3\n20.5\n500\nRussia\n");
    fclose(file);

    file = fopen(filename, "r");
    toys = add_toys(file, N2);
    fclose(file);

    int *indeces = NULL;
    int amount_countries = 0;
    indeces = get_toys_from_country(toys, N2, country, &amount_countries);
    EXPECT_EQ(amount_countries, 0);

    free(indeces);
    free_toys(toys, N2);
}

TEST(NEGATIVE_TOYS_TEST, NO_DATA)
{
    toy **toys = NULL;
    const char *filename = "test.txt";
    FILE *file = NULL;

    file = fopen(filename, "w");
    fclose(file);

    file = fopen(filename, "r");
    toys = add_toys(file, N1);
    fclose(file);

    EXPECT_TRUE(toys == NULL);
    free_toys(toys, N1);
}

TEST(NEGATIVE_TOYS_TEST, INVALID_PRICE)
{
    toy **toys = NULL;
    const char *filename = "test.txt";
    FILE *file = NULL;

    file = fopen(filename, "w");
    fprintf(file, "Toy1\na200\n100\nRussia\n");
    fclose(file);

    file = fopen(filename, "r");
    toys = add_toys(file, N1);
    fclose(file);

    EXPECT_TRUE(toys == NULL);
    free_toys(toys, N1);
}

TEST(NEGATIVE_TOYS_TEST, NEGATIVE_PRICE)
{
    toy **toys = NULL;
    const char *filename = "test.txt";
    FILE *file = NULL;

    file = fopen(filename, "w");
    fprintf(file, "Toy1\n-200\n100\nRussia\n");
    fclose(file);

    file = fopen(filename, "r");
    toys = add_toys(file, N1);
    fclose(file);

    EXPECT_TRUE(toys == NULL);
    free_toys(toys, N1);
}

TEST(NEGATIVE_TOYS_TEST, INVALID_VOLUME)
{
    toy **toys = NULL;
    const char *filename = "test.txt";
    FILE *file = NULL;

    file = fopen(filename, "w");
    fprintf(file, "Toy1\n200\na100\nRussia\n");
    fclose(file);

    file = fopen(filename, "r");
    toys = add_toys(file, N1);
    fclose(file);

    EXPECT_TRUE(toys == NULL);
    free_toys(toys, N1);
}

TEST(NEGATIVE_TOYS_TEST, NEGATIVE_VOLUME)
{
    toy **toys = NULL;
    const char *filename = "test.txt";
    FILE *file = NULL;

    file = fopen(filename, "w");
    fprintf(file, "Toy1\n200\n-100\nRussia\n");
    fclose(file);

    file = fopen(filename, "r");
    toys = add_toys(file, N1);
    fclose(file);

    EXPECT_TRUE(toys == NULL);
    free_toys(toys, N1);
}

TEST(NEGATIVE_TOYS_TEST, NO_COUNTRY)
{
    toy **toys = NULL;
    const char *filename = "test.txt";
    FILE *file = NULL;

    file = fopen(filename, "w");
    fprintf(file, "Toy1\n200\na100\n");
    fclose(file);

    file = fopen(filename, "r");
    toys = add_toys(file, N1);
    fclose(file);

    EXPECT_TRUE(toys == NULL);
    free_toys(toys, N1);
}

TEST(NEGATIVE_TOYS_TEST, OVER_SIZE_NAME)
{
    toy **toys = NULL;
    const char *filename = "test.txt";
    FILE *file = NULL;

    file = fopen(filename, "w");
    char name[MAX_NAME_LENGTH + 1];
    for (int i = 0; i < MAX_NAME_LENGTH; i++)
    {
        name[i] = 'a';
    }
    name[MAX_NAME_LENGTH] = '\0';
    fprintf(file, "%s\n200\n100\nRussia\n", name);

    file = fopen(filename, "r");
    toys = add_toys(file, N1);
    fclose(file);

    EXPECT_TRUE(toys == NULL);
    free_toys(toys, N1);
}

TEST(NEGATIVE_TOYS_TEST, OVER_SIZE_COUNTRY)
{
    toy **toys = NULL;
    const char *filename = "test.txt";
    FILE *file = NULL;

    file = fopen(filename, "w");
    char country[MAX_COUNTRY_LENGTH + 1];
    for (int i = 0; i < MAX_COUNTRY_LENGTH; i++)
    {
        country[i] = 'a';
    }
    country[MAX_COUNTRY_LENGTH] = '\0';
    fprintf(file, "Toy1\n200\n100\n%s\n", country);
    fclose(file);

    file = fopen(filename, "r");
    toys = add_toys(file, N1);
    fclose(file);

    EXPECT_TRUE(toys == NULL);
    free_toys(toys, N1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
