/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:58:36 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/13 18:14:16 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	size;
	size_t	i;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (i < size)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[size] = '\0';
	return (result);
}
