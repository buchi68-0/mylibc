/*
** EPITECH PROJECT, 2026
** mylibc
** File description:
** test_mystrchr.c
** tests mystrchr and mystrrchr
*/

#include <criterion/criterion.h>
#include "../includes/mylibc.h"

Test(mystrchr, test_null)
{
    char *comp = NULL;
    char *res = mystrchr(NULL, 'H');

    cr_assert(comp == res);
}

Test(mystrchr, test_classic)
{
    char buffer[15] = "Hello World";
    char *comp = &buffer[6];
    char *res = mystrchr(buffer, 'W');

    cr_assert(comp == res);
}

Test(mystrchr, test_theresnot)
{
    char buffer[15] = "Hello World";
    char *comp = NULL;
    char *res = mystrchr(buffer, 'Z');

    cr_assert(comp == res);
}

Test(mystrrchr, test_null)
{
    char *comp = NULL;
    char *res = mystrrchr(NULL, 'H');

    cr_assert(comp == res);
}

Test(mystrrchr, test_classic)
{
    char buffer[15] = "Hello World";
    char *comp = &buffer[7];
    char *res = mystrrchr(buffer, 'o');

    cr_assert(comp == res);
}

Test(mystrrchr, test_theresnot)
{
    char buffer[15] = "Hello World";
    char *comp = NULL;
    char *res = mystrrchr(buffer, 'Z');

    cr_assert(comp == res);
}
