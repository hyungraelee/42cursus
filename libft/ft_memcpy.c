#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t size)
{
    unsigned char *dp;
    const unsigned char *sp;
    size_t i;

    dp = dest;
    sp = src;
    i = 0;
    while (i++ < size)
        *dp++ = *sp++;
    return (dest);
}