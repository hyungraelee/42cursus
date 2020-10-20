/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:14:31 by hyunlee           #+#    #+#             */
/*   Updated: 2020/09/28 16:14:31 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t n)
{
	unsigned char	*dp;
	size_t			i;

	dp = dest;
	i = 0;
	while (i++ < n)
		*dp++ = 0;
	return ;
}
