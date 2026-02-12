/*
** EPITECH PROJECT, 2025
** mylibc
** File description:
** mycalloc (uses malloc)
*/

#include <malloc.h>
#include <errno.h>
#include "mylibc.h"

void *mycalloc(size_t nmemb, size_t size)
{
    size_t total_size = nmemb * size;
    void *r = NULL;

    if (total_size < nmemb && size != 0) {
        errno = ENOMEM;
        return NULL;
    }
    r = malloc(total_size);
    if (!r)
        return NULL;
    mymemset(r, 0, total_size);
    return r;
}
