/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:26:48 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/14 18:57:16 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		s2_len;
	const char	*s1ptr;
	const char	*s2ptr;

	if (*s2 == '\0')
		return ((char *)s1);
	s2_len = ft_strlen(s2);
	while (*s1 && (n >= s2_len))
	{
		if (*s1 == *s2)
		{
			s1ptr = s1;
			s2ptr = s2;
			while (*s1ptr == *s2ptr && *s2ptr && *s1ptr)
			{
				s1ptr++;
				s2ptr++;
			}
			if (*s2ptr == '\0')
				return ((char *)s1);
		}
		s1++;
		n--;
	}
	return (0);
}
