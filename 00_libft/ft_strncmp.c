/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:16:50 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/10 01:23:57 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char src1;
	unsigned char src2;

	while (n--)
	{
		src1 = *(unsigned char *)s1++;
		src2 = *(unsigned char *)s2++;
		if (src1 != src2)
			return (src1 - src2);
		if (src1 == '\0')
			return (0);
	}
	return (0);
}
