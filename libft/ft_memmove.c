/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:26:37 by hyunlee           #+#    #+#             */
/*   Updated: 2020/09/28 16:26:37 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *dp;
	unsigned char *sp;

	if (dest <= src)
	{
		dp = dest;
		sp = (unsigned char *)src;
		while (n-- > 0)
		{
			*dp++ = *sp++;
		}
	}
	else
	{
		dp = dest + n;
		sp = (unsigned char *)src + n;
		while (n-- > 0)
		{
			*--dp = *--sp;
		}
	}
	return (dest);
}
