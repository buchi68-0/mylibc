/*
** EPITECH PROJECT, 2026
** mylibc
** File description:
** mystrchr.c
*/

#include <stddef.h>
#include "../includes/mylibc.h"

void *mymemchr(const void *s, int c, size_t n)
{
    const unsigned char *scpy = (const unsigned char *)s;
    size_t i = 0;
    unsigned char byte = (unsigned char)c;
    
    if (!s)
        return NULL;
    while (i < n && scpy[i] != byte)
        i++;
    if (i == n)
        return NULL;
    return (void *)(scpy + i);
}

void *mymemrchr(const void *s, int c, size_t n)
{
    const unsigned char *scpy = (const unsigned char *)s;
    size_t i = n - 1;
    unsigned char byte = (unsigned char)c;
    
    if (!s)
        return NULL;
    while (i > 0 && scpy[i] != byte)
        i--;
    if (i == 0 && scpy[i] != byte)
        return NULL;
    return (void *)(scpy + i);
}

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
