#include "libft.h"

void    ft_bzero(void *dest, size_t n)
{
    unsigned char *dp;
    size_t i;

    dp = dest;
    i = 0;
    while (i++ < n)
        *dp++ = 0;
    return ;
}