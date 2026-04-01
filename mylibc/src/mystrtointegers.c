/*
** EPITECH PROJECT, 2026
** mylibc
** File description:
** mystrtointergers.c
** 2 funcs, to convert to int or unsigned int
*/

#include "private_mylibc.h"
#include <errno.h>

static const int max_neg = ((unsigned)-1 / 2) + 1;
static const int max_pos = (unsigned)-1 / 2;
static const unsigned max_uns = (unsigned)-1;

static int check_unsigned_int_overflow(unsigned int val, int base, int dig)
{
    if (val * base < val) {
        errno = EOVERFLOW;
        return 1;
    }
    val = val * base;
    if (val + dig < val) {
        errno = EOVERFLOW;
        return 1;
    }
    return 0;
}

// val is ALWAYS positive; flag determines if the number is negative or not
static int check_signed_int_overflow(int val, int flag, int base, int dig)
{
    int cpy = val;

    val = val * base;
    if (val < cpy) {
        errno = EOVERFLOW;
        return 1;
    }
    cpy = val;
    val += dig;
    if (val == max_neg && flag == -1)
        return 0;
    if (val < cpy) {
        errno = EOVERFLOW;
        return 1;
    }
    return 0;
}

static void handle_flag(const char *restrict *nptr, int *flag)
{
    if (**nptr == '-') {
        (*flag) = -1;
        (*nptr)++;
        return;
    }
    if (**nptr == '+') {
        (*nptr)++;
        return;
    }
    return;
}

static int is_char_of(char c, int base)
{
    if (c == '\0')
        return 0;
    if (base == 1)
        return (c == '1');
    if (base <= 10)
        return (c - '0' < base);
    if (c >= '0' && c <= '9')
        return 1;
    if (c >= 'a' && c <= base - 10 + 'a')
        return 1;
    if (c >= 'A' && c <= base - 10 + 'A')
        return 1;
    return 0;
}

static int get_digit(char c, int base)
{
    if (c >= '0' && c <= '9')
        return (int)(c - '0');
    if (c >= 'A' && c <= 'Z')
        return (int)(c - 'A');
    return (int)(c - 'a');
}

static void handle_endptr_change(char **restrict endptr,
    const char *restrict nptr)
{
    void *cpy = (void *)nptr;

    if (endptr)
        (*endptr) = cpy;
    return;
}

/*
* converts string nptr to a signed integer
* stores the last character checked into endptr
* usually, this char is not a digit
* it can be a digit if the number overflowed
* changes errno in case of errors
*/
int mystrtoi(const char *restrict nptr,
    char **restrict endptr,
    int base)
{
    int res = 0;
    int flag = 1;
    int dig = 0;

    if (base <= 0 || base > 36 || !nptr) {
        errno = EINVAL;
        return 0;
    }
    handle_flag(&nptr, &flag);
    for (; is_char_of(*nptr, base); nptr++) {
        dig = get_digit(*nptr, base);
        if (check_signed_int_overflow(res, flag, base, dig)) {
            res = max_pos;
            break;
        }
        res *= base;
        res += dig;
    }
    handle_endptr_change(endptr, nptr);
    return res * flag;
}

unsigned int mystrtou(const char *restrict nptr,
    char **restrict endptr,
    int base)
{
    unsigned int res = 0;
    int flag = 1;
    int dig = 0;

    if (base <= 0 || base > 36 || !nptr) {
        errno = EINVAL;
        return 0;
    }
    handle_flag(&nptr, &flag);
    for (; is_char_of(*nptr, base); nptr++) {
        dig = get_digit(*nptr, base);
        if (check_unsigned_int_overflow(res, base, dig)) {
            res = max_uns;
            break;
        }
        res *= base;
        res += dig;
    }
    handle_endptr_change(endptr, nptr);
    return res * flag;
}
