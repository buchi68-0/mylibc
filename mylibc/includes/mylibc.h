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

// set's each byte of buffer to c for n bytes
void *mymemset(void *buf, int c, size_t n);

// get's length of string "str", returns -1 in case of errors
ssize_t mystrlen(const char *str);

// get's length of string "str", returns -1 in case of errors [experimental]
ssize_t opt_mystrlen(const char *str);

// returns the minimum between n, and the length of the string
ssize_t mystrnlen(const char *str, size_t n);

/*
* allocates a block of size nelem * size,
* all bytes are being initialised to 0
*/
void *mycalloc(size_t nelem, size_t size);

// finds needle in the haystack. If this fails, returns NULL
void *mymemmem(const void *haystack, size_t haystacklen,
    const void *needle, size_t needlelen);

/*
* finds the substring needle in the string haystack,
* if this fails, returns NULL
*/
char *mystrstr(const char *haystack, const char *needle);

// copies str into a dynamically allocated string
char *mystrdup(const char *str);

/*
* copies the string dst into src.
* The caller is responsible for allocating at least mystrlen(dst) bytes for src
*/
char *mystrcpy(char *src, const char *dst);

/*
* compares both s1 and s2 strings to up to n bytes (or their respective ends).
* If the strings are equal returns 0
* if s1 is superior to s2, returns a positive number
* if s2 is superior to s2, returns a negative number
*/
int mystrncmp(const char *s1, const char *s2, size_t n);

/*
* compares both s1 and s2 strings up to their respective ends.
* If the strings are equal returns 0
* if s1 is superior to s2, returns a positive number
* if s2 is superior to s2, returns a negative number
*/
int mystrcmp(const char *s1, const char *s2);

/*
* adds the string src at the end of dst.
* The caller is responsible for having enough bytes to do this operation
*/
char *mystrcat(char *dst, const char *src);

/*
* creates a new dynamically allocated string
* that contains s1 with s2 concatenated
*/
char *mystrconcat(char const *s1, const char *s2);

/*
* give the pointer inside the string s
* to the first byte equal to c
* if this fails, returns NULL
*/
char *mystrchr(const char *s, int c);

/*
* give the pointer inside the string s
* to the last byte equal to c
* if this fails, returns NULL
*/
char *mystrrchr(const char *s, int c);

/*
* give the pointer inside the block s
* to the first byte equal to c
* if this fails, returns NULL
*/
void *mymemrchr(const void *s, int c, size_t n);

/*
* give the pointer inside the block s
* to the last byte equal to c
* if this fails, returns NULL
*/
void *mymemchr(const void *s, int c, size_t n);

#endif
