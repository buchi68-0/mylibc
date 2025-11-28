/*
** EPITECH PROJECT, 2025
** tes
** File description:
** tes
*/

#include "../mylibc.h"
#include <stdio.h>

static const char *const hs = "HFJEFHEJfhjhfkehjzfhellofhjzjhkdj";
static const char *const ne = "hello";

int main(void)
{
    const char *test = mystrstr(hs, ne);

    printf("%p : %p %p\n", test, hs, ne);
    printf("%s\n", test);
    return 0;
}
