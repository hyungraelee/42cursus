/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:40:56 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/05 16:14:10 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dstlen;
	size_t srclen;
	size_t res;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= size || size == 0)
	{
		return (srclen + size);
	}
	if (srclen < size - dstlen)
	{
		ft_memcpy(dst + dstlen, src, srclen);
		dst[dstlen + srclen] = '\0';
	}
	else
	{
		ft_memcpy(dst + dstlen, src, size - dstlen - 1);
		dst[size - 1] = '\0';
	}
	return (srclen + dstlen);
}
