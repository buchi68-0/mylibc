/*
** EPITECH PROJECT, 2025
** mylibc
** File description:
** mymemset
*/

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

static void *short_ver(void *dst, int c, size_t n)
{
    unsigned char *ptr = (unsigned char *)dst;

    for (size_t i = 0; i < n; i++)
        ptr[i] = c;
    return dst;
}

static void get_thing(unsigned long long *dst,
    int c)
{
    (*dst) = (unsigned char)c;
    for (int i = 0; i <= sizeof(long long) >> i; i++)
        (*dst) = (*dst) | (*dst) << (8 << i);
    return;
}

static void *handle_high(uintptr_t ptr, int c, size_t n)
{
    unsigned long long *ltmp = (unsigned long long *)ptr;
    size_t sh_len = n / sizeof(long long);
    unsigned long long thing;

    get_thing(&thing, c);
    for (size_t i = 0; i < sh_len; i++)
        ltmp[i] = thing;
    return (ltmp + (sh_len));
}

void *mymemset(void *dst, int c, size_t n)
{
    uintptr_t ptr = (uintptr_t)dst;
    unsigned char *tmp = dst;

    if (n <= 2 * sizeof(long long))
        return short_ver(dst, c, n);
    while (ptr % sizeof(long long) != 0) {
        (*tmp) = c;
        tmp++;
        ptr++;
        n--;
    }
    tmp = (unsigned char *)handle_high(ptr, c, n);
    for (size_t i = 0; i < n % sizeof(long long); i++)
        tmp[i] = c;
    return dst;
}
