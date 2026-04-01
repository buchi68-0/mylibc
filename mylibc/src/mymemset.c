/*
** EPITECH PROJECT, 2025
** mylibc
** File description:
** mymemset
*/

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include "private_mylibc.h"

static void *short_ver(void *dst, int c, size_t n)
{
    uchar_t *ptr = (uchar_t *)dst;

    for (size_t i = 0; i < n; i++)
        ptr[i] = c;
    return dst;
}

static void get_thing(ull_t *dst,
    int c)
{
    (*dst) = (uchar_t)c;
    for (int i = 0; 1 < sizeof(ull_t) >> i; i++)
        (*dst) = (*dst) | (*dst) << (8 << i);
    return;
}

static void *handle_high(uintptr_t ptr, int c, size_t n)
{
    ull_t *ltmp = (ull_t *)ptr;
    size_t sh_len = n / sizeof(ull_t);
    ull_t thing;

    get_thing(&thing, c);
    for (size_t i = 0; i < sh_len; i++)
        ltmp[i] = thing;
    return (ltmp + (sh_len));
}

void *mymemset(void *dst, int c, size_t n)
{
    uintptr_t ptr = (uintptr_t)dst;
    uchar_t *tmp = dst;

    if (!dst)
        return NULL;
    if (n <= 2 * sizeof(ull_t))
        return short_ver(dst, c, n);
    while (ptr % sizeof(ull_t) != 0) {
        (*tmp) = c;
        tmp++;
        ptr++;
        n--;
    }
    tmp = (uchar_t *)handle_high(ptr, c, n);
    for (size_t i = 0; i < n % sizeof(ull_t); i++)
        tmp[i] = c;
    return dst;
}
