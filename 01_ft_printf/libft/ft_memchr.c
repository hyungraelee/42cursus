/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:56:18 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/10 01:29:36 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *sp;

	sp = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*sp == (unsigned char)c)
		{
			return (sp);
		}
		sp++;
	}
	return (0);
}
