/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:00:19 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/24 22:02:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_integer(va_list args, t_set *set)
{
	long long	num;

	num = va_arg(args, int);
	if (set->f_point == 1 && set->precs == 0 && num == 0)
	{
		ft_putstr_fd("", 1);
		return ;
	}
	ft_arglen_int(num, set);
	if (set->arglen > set->width && set->arglen > set->precs)
	{
		set->print_size += set->arglen;
		ft_putnbr_fd(num, 1);
	}
	else if (set->precs > set->width && set->precs > set->arglen)
	{
		set->print_size += set->precs;
		if (num < 0)
		{
			ft_putchar_fd('-', 1);
			(set->print_size)++;
			num *= (-1);
			(set->arglen)--;
		}
		while (((set->precs)--) - set->arglen)
			ft_putchar_fd('0', 1);
		ft_putnbr_fd(num, 1);
	}
	else if (set->width > set->arglen && set->width > set->precs)
	{
		set->print_size += set->width;
		if (set->precs > set->arglen)
		{
			while (((set->width)--) - set->precs)
				ft_putchar_fd(' ', 1);
			if (num < 0)
			{
				ft_putchar_fd('-', 1);
				(set->print_size)++;
				num *= (-1);
			}
			while (((set->precs)--) - set->arglen)
				ft_putchar_fd('0', 1);
			ft_putnbr_fd(num, 1);
		}
		else
		{
			if (set->f_zero == 1 && set->f_minus == 0 && set->f_point == 0)
			{
				if (num < 0)
				{
					ft_putchar_fd('-', 1);
					num *= (-1);
				}
				while (((set->width)--) - set->arglen)
					ft_putchar_fd('0', 1);
				ft_putnbr_fd(num, 1);
			}
			else
			{
				while (((set->width)--) - set->arglen)
					ft_putchar_fd(' ', 1);
				ft_putnbr_fd(num, 1);
			}
		}
	}
	return ;
}

void	ft_arglen_int(int num, t_set *set)
{
	unsigned int	temp;

	temp = num;
	if (num < 0)
	{
		(set->arglen)++;
		temp = -num;
	}
	if (temp == 0)
		(set->arglen)++;
	while (temp)
	{
		(set->arglen)++;
		temp /= 10;
	}
	return ;
}
