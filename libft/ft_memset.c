#include "libft.h"

void        *ft_memset(void *ptr, int c, size_t n)
{
    unsigned char   *newPtr;
    unsigned char   src;
    size_t i;

    newPtr = ptr;
    src = c;
    i = 0;
    while (i++ < n)
        *newPtr++ = src;
    return (ptr);
}