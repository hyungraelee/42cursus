/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:31:15 by hyunlee           #+#    #+#             */
/*   Updated: 2020/09/28 17:31:15 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 <= size)
	{
		while (srclen-- > 0)
		{
			*dst++ = *src++;
		}
		dst[srclen];
	}
	else if (size != 0)
	{
		while (size-- > 1)
		{
			*dst++ = *src++;
		}
		dst[size - 1];
	}
	return (srclen);
}
