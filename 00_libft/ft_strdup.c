/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:30:40 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/09 18:52:10 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	char	*temp;
	size_t	len;

	len = ft_strlen(s);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	temp = result;
	while (len--)
		*temp++ = *s++;
	*temp = '\0';
	return (result);
}
