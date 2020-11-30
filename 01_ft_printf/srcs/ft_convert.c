/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:33:06 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/30 21:46:08 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_check_size(unsigned long long num)
{
	int	size;

	if (num == 0)
		return (1);
	size = 0;
	while (num)
	{
		num /= 16;
		size++;
	}
	return (size);
}

int			ft_convert_hex(t_set *set, unsigned long long num)
{
	int	size;

	size = ft_hex_check_size(num);
	set->arglen = size;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	set->input_data[size] = '\0';
	while (size - 1 >= 0)
	{
		if (num % 16 >= 10 && num % 16 <= 15 && \
		(set->specifier == 'x' || set->specifier == 'p'))
			set->input_data[size - 1] = (num % 16) - 10 + 'a';
		else if (num % 16 >= 10 && num % 16 <= 15 && set->specifier == 'X')
			set->input_data[size - 1] = (num % 16) - 10 + 'A';
		else if (num % 16 >= 0 && num % 16 < 10)
			set->input_data[size - 1] = (num % 16) + '0';
		num /= 16;
		size--;
	}
	return (1);
}
