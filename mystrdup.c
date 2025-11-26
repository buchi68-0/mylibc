/*
** EPITECH PROJECT, 2025
** mylibc
** File description:
** mystrdup
*/

#include "mylibc.h"

char *mystrcpy(char *dst, const char *src)
{
    size_t len = mystrlen(src);
    size_t i = 0;

    if (!src || !dst)
        return dst;
    for (; i < len; i++)
        dst[i] = src[i];
    dst[i] = '\0';
    return dst;
}

char *mystrdup(const char *str)
{
    ssize_t len = mystrlen(str) + 1;
    char *r = mycalloc(len, sizeof(char));

    if (!str || !r) {
        free(r);
        return NULL;
    }
    mystrcpy(r, str);
    return r;
}
