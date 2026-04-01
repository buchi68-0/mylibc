/*
** EPITECH PROJECT, 2025
** mylibc
** File description:
** mymemmem
** finds needle in haystack
*/

#include "mylibc.h"

void *mymemmem(const void *haystack, size_t hs_len,
    const void *needle, size_t ne_len)
{
    const unsigned char *usne = (const unsigned char *)needle;
    const unsigned char *ushs = (const unsigned char *)haystack;
    size_t max_verif = hs_len - ne_len;
    size_t j;

    if (!haystack || !needle || ne_len == 0)
        return (void *)ushs;
    if (ne_len > hs_len)
        return NULL;
    for (size_t i = 0; i <= max_verif; i++) {
        for (j = 0; j < ne_len && ushs[i + j] == usne[j]; j++);
        if (j == ne_len)
            return (void *)(ushs + i);
    }
    return NULL;
}

char *mystrstr(const char *haystack, const char *needle)
{
    const unsigned char *usne = (const unsigned char *)needle;
    const unsigned char *ushs = (const unsigned char *)haystack;
    size_t hs_len = mystrlen(haystack);
    size_t ne_len = mystrlen(needle);

    if (!haystack || !needle || ne_len == 0)
        return (char *)(void *)(ushs);
    if (ne_len > hs_len)
        return NULL;
    return (char *)mymemmem(haystack, hs_len, needle, ne_len);
}
