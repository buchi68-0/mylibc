/*
** EPITECH PROJECT, 2025
** mylibc
** File description:
** mystrdup
*/

#include "../includes/mylibc.h"
#include <malloc.h>

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

char *mystrcat(char *dst, const char *src)
{
    if (!dst || !src)
        return dst;
    mystrcpy(dst + mystrlen(dst), src);
    return dst;
}

char *mystrconcat(char const *s1, const char *s2)
{
    ssize_t len = mystrlen(s1) + mystrlen(s2) + 1;
    char *r = NULL;

    if (!s1)
        return mystrdup(s2);
    if (!s2)
        return mystrdup(s1);
    r = mycalloc(len, sizeof(char));
    if (!r)
        return NULL;
    mystrcpy(r, s1);
    mystrcat(r, s2);
    return r;
}
