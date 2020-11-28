/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 01:34:33 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/29 01:36:34 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_ll_check_size(long long num)
{
	int	size;

	if (num == 0)
		return (1);
	if (num > 0)
		size = 0;
	else
		size = 1;
	while (num)
	{
		num /= 10;
		size++;
	}
	return (size);
}

static void	ft_ll_change_num(t_set *set, long long num, int size)
{
	unsigned long long temp;

	set->input_data[set->arglen] = '\0';
	if (num < 0)
	{
		temp = -num;
		while (size - 1 > 0)
		{
			set->input_data[size - 1] = (temp % 10) + '0';
			temp /= 10;
			size--;
		}
		set->input_data[0] = '-';
	}
	else
	{
		while (size - 1 >= 0)
		{
			set->input_data[size - 1] = (num % 10) + '0';
			num /= 10;
			size--;
		}
	}
	return ;
}

int			ft_lltoa(t_set *set, long long num)
{
	int	size;

	size = ft_ll_check_size(num);
	set->arglen = size;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_ll_change_num(set, num, size);
	return (1);
}
