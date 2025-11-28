/*
** EPITECH PROJECT, 2025
** mylibc
** File description:
** mystrnlen
*/

#include "mylibc.h"

ssize_t mystrnlen(const char *str, size_t max_len)
{
    ssize_t returned = 0;

    if (!str)
        return (ssize_t)-1;
    for (; str[returned] && returned < max_len; returned++);
    return returned;
}
