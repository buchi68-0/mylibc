/*
** EPITECH PROJECT, 2025
** mylibc
** File description:
** unit tests
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include "mylibc.h"

Test(mystrlen, testnull)
{
    ssize_t size = mystrlen(NULL);

    cr_assert(size == (ssize_t)-1);
}

Test(mystrlen, testempty)
{
    ssize_t size = mystrlen("");

    cr_assert(size == 0);
}

Test(mystrlen, testnormal)
{
    ssize_t size = mystrlen("Hello World!");

    cr_assert(size == strlen("Hello World!"));
}

Test(mycalloc, testone)
{
    char *array = mycalloc(100, sizeof(char));

    cr_assert(mystrlen(array) == 0);
}

Test(mycalloc, overflow)
{
    size_t nmemb = 1;
    size_t size = 1;
    nmemb = nmemb << 40;
    size = size << 40;
    char *array = mycalloc(nmemb, size);

    cr_assert(array == NULL);
}

Test(mycalloc, nomem)
{
    size_t nmemb = (1ULL << 40);
    size_t size = sizeof(double);
    char *array = mycalloc(nmemb, size);

    cr_assert(array == NULL);
}

Test(mycalloc, each_zero)
{
    char *array = mycalloc(0, sizeof(double));
    char *array2 = mycalloc(sizeof(double), 0);

    cr_assert(1);
}

Test(mymemset, testnosize)
{
    char *array = mycalloc(100, sizeof(char));

    mymemset(array, '0', 0);
    cr_assert(mystrlen(array) == 0);
}

Test(mymemset, testreal)
{
    char *array = mycalloc(100, sizeof(char));

    mymemset(array, '0', 99);

    cr_assert(mystrlen(array) == 99);
}

Test(mymemset, testsmol)
{
    char *array = mycalloc(100, sizeof(char));

    mymemset(array, '0', 10);

    cr_assert(mystrlen(array) == 10);
}

Test(mymset, testunaligned)
{
    char *array = mycalloc(100, sizeof(char));

    mymemset(array + 1, '0', 25);
}
