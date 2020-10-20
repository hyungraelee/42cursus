/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:50:38 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/10 01:38:52 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	size_t	len;

	last = 0;
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + len));
	while (*s)
	{
		if (*s == (char)c)
		{
			last = (char *)s;
		}
		s++;
	}
	return (last);
}
