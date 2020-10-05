/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:50:38 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/05 22:04:54 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	const char *last;

	last = 0;
	do
	{
		if (*s == (char)c)
		{
			last = s;
		}
	} while (*s++);
	return ((char *)last);
}
