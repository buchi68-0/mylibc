/*
** EPITECH PROJECT, 2026
** mylibc-unit tests
** File description:
** test_mystrlen.c
** tests mystrlen and mystrnlen
*/

#include <criterion/criterion.h>
#include "../includes/mylibc.h"

Test(mystrlen, test_null)
{
    ssize_t comp = -1;
    ssize_t res = mystrlen(NULL);

    cr_assert(res == comp);
}

Test(mystrlen, test_classic)
{
    char buffer[15] = "Hello World";
    ssize_t comp = 11;
    ssize_t res = mystrlen(buffer);

    cr_assert(res == comp);
}

Test(mystrnlen, test_null)
{
    ssize_t comp = -1;
    ssize_t res = mystrnlen(NULL, 1);
    ssize_t res2 = mystrnlen(NULL, 0);

    cr_expect(res2 == comp);
    cr_assert(res == comp);
}

Test(mystrnlen, test_classic)
{
    char buffer[15] = "Hello World";
    ssize_t comp = 9;
    ssize_t res = mystrnlen(buffer, 9);

    cr_assert(res == comp);
}

Test(mystrnlen, test_n_too_big)
{
    char buffer[15] = "Hello World";
    ssize_t comp = 11;
    ssize_t res = mystrnlen(buffer, 15);

    cr_assert(res == comp);
}
