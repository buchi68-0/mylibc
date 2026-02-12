/*
** EPITECH PROJECT, 2025
** mylibc
** File description:
** mystrlen
*/

#include "../includes/mylibc.h"

ssize_t mystrlen(const char *str)
{
    ssize_t returned = 0;

    if (!str)
        return (ssize_t)-1;
    for (; str[returned]; returned++);
    return returned;
}
