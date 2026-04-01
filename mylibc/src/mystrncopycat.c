/*
** EPITECH PROJECT, 2026
** mylibc
** File description:
** mystrncopycat.c
** functions mystrncpy and mystrncat and mystrndup
*/


#include "mylibc.h"
#include <malloc.h>

char *mystrncpy(char *dst, const char *src, size_t n)
{
    size_t len = mystrlen(src);
    size_t i = 0;

    if (!src || !dst)
        return dst;
    for (; i < n && i < len; i++)
        dst[i] = src[i];
    if (i < n)
        dst[i] = '\0';
    return dst;
}

char *mystrndup(const char *str, size_t n)
{
    ssize_t len = 0;
    char *r = NULL;

    if (!str)
        return NULL;
    len = mystrnlen(str, n) + 1;
    r = mycalloc(len, sizeof(char));
    if (!r)
        return NULL;
    mystrncpy(r, str, n);
    return r;
}

char *mystrncat(char *restrict dst, const char *restrict src, size_t ssize)
{
    if (!dst || !src)
        return dst;
    mystrncpy(dst + mystrlen(dst), src, ssize);
    return dst;
}


char *mystrnconcat(char const *s1, size_t s1size,
    const char *s2, size_t s2size)
{
    ssize_t len = mystrnlen(s1, s1size) + mystrnlen(s2, s2size) + 1;
    char *r = NULL;

    if (!s1)
        return mystrndup(s2, s2size);
    if (!s2)
        return mystrndup(s1, s1size);
    r = mycalloc(len, sizeof(char));
    if (!r)
        return NULL;
    mystrncpy(r, s1, s1size);
    mystrncat(r, s2, s2size);
    return r;
}
