/*
** EPITECH PROJECT, 2026
** mylibc-unit_tests
** File description:
** test_mystrcpy.c
** tests mystrcpy and mystrncpy
*/

#include <criterion/criterion.h>
#include "../includes/mylibc.h"

Test(mystrcpy, test_null)
{
    cr_assert(mystrcpy(NULL, NULL) == NULL);
}

Test(mystrcpy, test_no_src)
{
    char buffer[15] = "Hello World";

    cr_assert(mystrcpy(buffer, NULL) == buffer);
}

Test(mystrcpy, test_no_dst)
{
    char buffer[15] = "Hello World";

    cr_assert(mystrcpy(NULL, buffer) == NULL);
}

Test(mystrcpy, test_classical)
{
    char buffer_dst[25] = "Hello World of Tech";
    char buffer_src[15] = "Hello World";
    size_t res = mystrlen(buffer_src);

    mystrcpy(buffer_dst, buffer_src);
    cr_expect(mystrlen(buffer_src) == res);
    cr_assert(mystrlen(buffer_dst) == mystrlen(buffer_src));
}

Test(mystrncpy, test_null)
{
    cr_assert(mystrncpy(NULL, NULL, 0) == NULL);
}

Test(mystrncpy, test_no_src)
{
    char buffer[15] = "Hello World";

    cr_assert(mystrncpy(buffer, NULL, 1) == buffer);
}

Test(mystrncpy, test_no_dst)
{
    char buffer[15] = "Hello World";

    cr_assert(mystrncpy(NULL, buffer, 1) == NULL);
}

Test(mystrncpy, test_n_too_small)
{
    char buffer_dst[25] = "Hello World of Tech";
    char buffer_src[15] = "Hell! World";
    size_t res = mystrlen(buffer_src);
    size_t len_dst = mystrlen(buffer_dst);

    mystrncpy(buffer_dst, buffer_src, 5);
    cr_expect(mystrlen(buffer_src) == res);
    cr_expect(buffer_dst[4] == '!');
    cr_assert(mystrlen(buffer_dst) == len_dst);
}

Test(mystrncpy, test_classical)
{
    char buffer_dst[25] = "Hello World of Tech";
    char buffer_src[15] = "Hello World!";
    size_t res = mystrlen(buffer_src);

    mystrncpy(buffer_dst, buffer_src, 15);
    cr_expect(mystrlen(buffer_src) == res);
    cr_assert(mystrlen(buffer_dst) == res);
}
