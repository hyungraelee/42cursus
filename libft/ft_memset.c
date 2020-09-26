#include "libft.h"

void    *ft_memset(void *dest, int c, size_t n)
{
    unsigned char *dp;
    size_t i;

    dp = dest;
    i = 0;
    while (i++ < n)
        *dp++ = c;
    return (dest);
}