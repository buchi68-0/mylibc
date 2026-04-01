/*
** EPITECH PROJECT, 9999
** mylibc
** File description:
** strcmp & strncmp
*/

#include "mylibc.h"

int mystrcmp(const char *s1, const char *s2)
{
    size_t i = 0;
    const unsigned char *u1 = (const unsigned char *)s1;
    const unsigned char *u2 = (const unsigned char *)s2;

    if (!s1 || !s2)
        return (s1 == NULL) - (s2 == NULL);
    for (; u1[i] || u2[i]; i++)
        if (u1[i] != u2[i])
            return (u1[i] - u2[i]);
    return 0;
}

int mystrncmp(const char *s1, const char *s2, size_t n)
{
    size_t i = 0;
    const unsigned char *u1 = (const unsigned char *)s1;
    const unsigned char *u2 = (const unsigned char *)s2;

    if (!s1 || !s2)
        return (s1 == NULL) - (s2 == NULL);
    for (; i < n && (u1[i] || u2[i]); i++)
        if (u1[i] != u2[i])
            return (u1[i] - u2[i]);
    return 0;
}
