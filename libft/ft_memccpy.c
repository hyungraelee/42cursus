/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:20:31 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/09 21:22:02 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dp;
	unsigned char	*sp;
	size_t			i;

	if (!dest && !src)
		return (0);
	dp = (unsigned char *)dest;
	sp = (unsigned char *)src;
	i = 0;
	while (i++ < n)
	{
		if (*sp == (unsigned char)c)
		{
			*dp++ = *sp;
			return (dp);
		}
		*dp++ = *sp++;
	}
	return (0);
}
