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
	unsigned char	*dp;
	unsigned char	*sp;
	size_t res;

	res = ft_strlen(src);
	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	while (size-- > 1)
	{
		*dp++ = *sp++;
	}
	*dp = 0;
	return (res);
}
