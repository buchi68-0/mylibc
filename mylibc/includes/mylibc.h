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

/* sets the next n bytes of buf to the byte c */
void *mymemset(void *buf, int c, size_t n);

/* returns the length of the string str. Returns -1 if str is NULL */
ssize_t mystrlen(const char *str);

/* [experimental] returns the length of the string str faster */
ssize_t opt_mystrlen(const char *str);

/* returns the minimum between the length of the string str and n */
ssize_t mystrnlen(const char *str, size_t n);

/*
* returns a buffer of nelem elements of size size allocated by malloc
* all bytes are set to 0
*/
void *mycalloc(size_t nelem, size_t size);

/*
* finds the sub block "needle" in the block "haystack"
* because it uses void *s, it needs the length of each blocks
*/
void *mymemmem(const void *haystack, size_t haystacklen,
    const void *needle, size_t needlelen);

/* finds the substring needle in the string haystack */
char *mystrstr(const char *haystack, const char *needle);

/* copies the string str into a dynamically allocated block */
char *mystrdup(const char *str);

/* copies at most n bytes of str into a dynamically allocated block */
char *mystrndup(const char *str, size_t n);

/*
* copies directly the string src at the pointer dst
* the caller is responsible for having enough size in dst
*/
char *mystrcpy(char *dst, const char *src);

/*
* copies at most n bytes from src to dst
* the caller is responsible for having enough size in dst
* for mystrnlen(src, n) bytes at least
* If the pointer got to n, there will be no terminating NUL byte in dst
*/
char *mystrncpy(char *dst, const char *src, size_t n);

/*
* compares s1 and s2 up to n bytes or their respective ends
* if both strings are equal (up to n bytes or their ends) return 0
* returns positive number if s1 >
* returns negative number is s1 <
*/
int mystrncmp(const char *s1, const char *s2, size_t n);


/*
* compares s1 and s2 up their respective ends
* if both strings are equal return 0
* returns positive number if s1 >
* returns negative number is s1 <
*/
int mystrcmp(const char *s1, const char *s2);

/*
* concats the string src at the end of dst
* the caller is responsible for
* allocating enough space for dst to contain itself AND src
*/
char *mystrcat(char *restrict dst, const char *restrict src);

/*
* concats the string src at the end of dst
* takes at most n bytes from src to put at the end of dst
* the caller is responsible for
* allocating enough space for dst to contain itself AND src
*/
char *mystrncat(char *restrict dst, const char *restrict src, size_t ssize);

/*
* creates a dynamically allocated string
* that contains s1 ans s2 glued together.
*/
char *mystrconcat(char const *s1, const char *s2);

/*
* creates a dynamically allocated string
* that contains s1 and s2 glued together.
* up to s1size bytes of s1 are taken and s2size bytes of s2
*/
char *mystrnconcat(char const *s1, size_t s1size,
    const char *s2, size_t s2size);

/*
* returns a pointer to the first occurence of c in the string s;
* returns NULL if cannot find
*/
char *mystrchr(const char *s, int c);

/*
* returns a pointer to the last occurence of c in the string s;
* returns NULL if cannot find
*/
char *mystrrchr(const char *s, int c);

/*
* converts string to an unsigned integer.
* stores the last byte checked in endptr
*/
unsigned int mystrtou(const char *restrict nptr,
    char **restrict endptr,
    int base);

/*
* converts string to an integer.
* stores the last byte checked in endptr
*/
int mystrtoi(const char *restrict nptr,
    char **restrict endptr,
    int base);

#endif /* MYLIBC_H */
