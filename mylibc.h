/*
** EPITECH PROJECT, 2025
** mylibc
** File description:
** header
*/

#ifndef MYGLIBC_H
    #define MYGLIBC_H
    #include <stddef.h>
    #include <sys/types.h>
void *mymemset(void *, int, size_t);
ssize_t mystrlen(const char *);
void *mycalloc(size_t, size_t);
void *mymemmem(const void *, size_t, const void *, size_t);
char *mystrstr(const char *, const char *);
#endif
