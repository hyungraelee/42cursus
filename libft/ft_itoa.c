/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:20:06 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/11 19:20:33 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*change_num(int n, int size, char *dst)
{
	char temp;

	dst[size] = '\0';
	if (n < 0)
	{
		while (size - 1 > 0)
		{
			temp = n % 10;
			dst[size - 1] = temp;
			n /= 10;
			size--;
		}
		dst[0] = '-';
	}
	else
		while (size - 1 >= 0)
		{
			temp = n % 10;
			dst[size - 1] = temp;
			n /= 10;
			size--;
		}
	return (dst);
}

int		check_size(int n)
{
	int size;

	if (n == 0)
		return (1);
	if (n > 0)
		size = 0;
	else if (n < 0)
		size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;

	if (n == -2147483648)
		result = "-2147483648";
	else
	{
		size = check_size(n);
		if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
			return (0);
		result = change_num(n, size, result);
	}
	return (result);
}
