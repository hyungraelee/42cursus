/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:27:08 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/01 22:27:59 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_change_num(t_set *set, unsigned long long num, int size)
{
	char	chr;

	set->input_data[size] = '\0';
	while (size - 1 >= 0)
	{
		set->input_data[size - 1] = (num % 10) + '0';
		num /= 10;
		size--;
	}
	return ;
}

int		ft_unlo_check_size(unsigned long long num)
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

int		ft_unlotoa(t_set *set, unsigned long long num)
{
	int		size;

	size = ft_check_size(num);
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_change_num(set, num, size);
	return (1);
}

int		ft_print_uint(t_set *set)
{
	unsigned long long	num;

	// if (set->f_length_modifier == "ll")
	// 	num = va_arg(*(set->args), long long);
	num = va_arg(*(set->args), int);
	if (!(ft_unlotoa(set, num)))
		return (-1);
}
