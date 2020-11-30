/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:37:48 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/30 20:39:02 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ull_check_size(unsigned long long num)
{
	int	size;

	if (num == 0)
		return (1);
	size = 0;
	while (num)
	{
		num /= 10;
		size++;
	}
	return (size);
}

static void	ft_ull_change_num(t_set *set, unsigned long long num, int size)
{
	set->input_data[size] = '\0';
	while (size - 1 >= 0)
	{
		set->input_data[size - 1] = (num % 10) + '0';
		num /= 10;
		size--;
	}
	return ;
}

int			ft_ulltoa(t_set *set, unsigned long long num)
{
	int		size;

	size = ft_ull_check_size(num);
	set->arglen = size;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_ull_change_num(set, num, size);
	return (1);
}
