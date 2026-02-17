/*
** EPITECH PROJECT, 2025
** mylibc
** File description:
** mystrlen; using unsigned long long to go faster
*/

#include "../includes/mylibc.h"
#include <stdint.h>

static const unsigned long long STRLENCONST1 = 0x0101010101010101ULL;
static const unsigned long long STRLENCONST2 = 0x8080808080808080ULL;
static const unsigned long ratio = sizeof(long long) / sizeof(char);

// consider it's +8 before verification
static void end(size_t *ret, unsigned long long *val)
{
    unsigned char *newptr = (unsigned char *)val;
    size_t subtraction = ratio;

    while (!(*newptr)) {
        subtraction--;
        newptr++;
    }
    (*ret) -= subtraction;
    return;
}

static size_t rest(uintptr_t ptr)
{
    size_t ret = 0UL;
    unsigned long long *newptr = (unsigned long long *)ptr;
    unsigned long long curent = 0ULL;
    unsigned long long has_zero = 0ULL;

    while (has_zero == 0ULL) {
        curent = *newptr;
        newptr++;
        has_zero = ((curent - STRLENCONST1) & ~curent & STRLENCONST2);
        ret += ratio;
    }
    end(&ret, &has_zero);
    return ret;
}

ssize_t opt_mystrlen(const char *str)
{
    ssize_t returned = 0;
    size_t checks = sizeof(long long) - (uintptr_t)str % sizeof(long long);

    if (!str)
        return (ssize_t)-1;
    while (checks > 0) {
        if (!(*str))
            return returned;
        returned++;
        str++;
        checks--;
    }
    returned += rest((uintptr_t)str);
    return returned;
}
