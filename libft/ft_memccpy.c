#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    unsigned char *dp;
    const unsigned char *sp;
    size_t i;

    dp = dest;
    sp = src;
    i = 0;
    while (i++ < n)
    {
        if (*sp == (unsigned char)c)
        {
            *dp++ = *sp;
            break;
        }
        *dp++ = *sp++;
    }
    return (dp);
}