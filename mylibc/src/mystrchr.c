/*
** EPITECH PROJECT, 2026
** mylibc
** File description:
** mystrchr.c
*/

#include <stddef.h>
#include "mylibc.h"

char *mystrchr(const char *s, int c)
{
    if (!s)
        return NULL;
    while (*s && (int)(*s) != c) {
        s++;
    }
    if (!(*s) && c != '\0')
        return NULL;
    return (char *)(void *)s;
}

char *mystrrchr(const char *s, int c)
{
    char *scpy = (char *)(void *)s;
    size_t i = 0;

    if (!s)
        return NULL;
    i = mystrlen(s);
    while (i > 0 && (int)scpy[i] != c) {
        i--;
    }
    if (i == 0 && (int)scpy[i] != c)
        return NULL;
    return scpy + i;
}
