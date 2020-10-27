/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:00:19 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/27 17:20:59 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_print_int_arglen_most(t_set *set, long long num)
{
	set->print_size += set->arglen;
	ft_putnbr_fd(num, 1);
	return ;
}

void	ft_print_int_precision_most(t_set *set, long long num)
{
	set->print_size += set->precision;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		(set->print_size)++;
		num *= (-1);
		(set->arglen)--;
	}
	while (((set->precision)--) - set->arglen)
		ft_putchar_fd('0', 1);
	ft_putnbr_fd(num, 1);
	return ;
}

void	ft_print_int_width_minus(t_set *set, long long num)
{
	int temp;

	temp = set->precision;
	if (set->precision >= set->arglen)
	{
		if (num < 0)
		{
			ft_putchar_fd('-', 1);
			num *= (-1);
			while ((set->precision)-- > (set->arglen - 1))
				ft_putchar_fd('0', 1);
			ft_putnbr_fd(num, 1);
			temp++;
			while ((set->width)-- > temp)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while ((set->precision)-- > set->arglen)
				ft_putchar_fd('0', 1);
			ft_putnbr_fd(num, 1);
			while ((set->width)-- > temp)
				ft_putchar_fd(' ', 1);
		}
	}
	else
	{
		ft_putnbr_fd(num, 1);
		while ((set->width)-- > set->arglen)
			ft_putchar_fd(' ', 1);
	}
	return ;
}

void	ft_print_int_width(t_set *set, long long num)
{
	if (set->precision > set->arglen)
	{
		if (num < 0)
		{
			(set->print_size)++;
			num *= (-1);
			set->precision++;
			while (((set->width)--) - set->precision)
				ft_putchar_fd(' ', 1);
			ft_putchar_fd('-', 1);
		}
		else
			while (((set->width)--) - set->precision)
				ft_putchar_fd(' ', 1);
		while (((set->precision)--) - set->arglen)
			ft_putchar_fd('0', 1);
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
		}
		else
		{
			while (((set->width)--) - set->arglen)
				ft_putchar_fd(' ', 1);
		}
	}
	ft_putnbr_fd(num, 1);
	return ;
}

void	ft_print_int_width_most(t_set *set, long long num)
{
	set->print_size += set->width;
	if (set->f_minus == 1)
		ft_print_int_width_minus(set, num);
	else
		ft_print_int_width(set, num);
	return ;
}

void	ft_print_integer(t_set *set)
{
	long long	num;

	num = va_arg(*(set->args), int);
	if (set->f_point == 1 && set->precision == 0 && num == 0)	// %.0d <- 0
	{
		while (set->width--)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("", 1);
		return ;
	}
	ft_arglen_int(num, set);
	if (set->arglen >= set->width && set->arglen >= set->precision) // arg辨捞啊 力老 变 版快
		ft_print_int_arglen_most(set, num);
	else if (set->precision >= set->width && set->precision > set->arglen) // precision 辨捞啊 力老 变 版快
		ft_print_int_precision_most(set, num);
	else if (set->width > set->arglen && set->width > set->precision)	// width 辨捞啊 力老 变 版快
		ft_print_int_width_most(set, num);
	return ;
}

// void	ft_print_integer(t_set *set)
// {
// 	long long	num;

// 	num = va_arg(*(set->args), int);
// 	if (set->f_point == 1 && set->precision == 0 && num == 0)	// %.0d <- 0
// 	{
// 		ft_putstr_fd("", 1);
// 		return ;
// 	}
// 	ft_arglen_int(num, set);
// 	if (set->arglen > set->width && set->arglen > set->precision)	// arg辨捞啊 力老 变 版快
// 	{
// 		set->print_size += set->arglen;
// 		ft_putnbr_fd(num, 1);
// 	}
// 	else if (set->precision > set->width && set->precision > set->arglen)	// precision 辨捞啊 力老 变 版快
// 	{
// 		set->print_size += set->precision;
// 		if (num < 0)
// 		{
// 			ft_putchar_fd('-', 1);
// 			(set->print_size)++;
// 			num *= (-1);
// 			(set->arglen)--;
// 		}
// 		while (((set->precision)--) - set->arglen)
// 			ft_putchar_fd('0', 1);
// 		ft_putnbr_fd(num, 1);
// 	}
// 	else if (set->width > set->arglen && set->width > set->precision)	//	width 辨捞啊 力老 变 版快
// 	{
// 		set->print_size += set->width;
// 		if (set->precision > set->arglen)
// 		{
// 			while (((set->width)--) - set->precision)
// 				ft_putchar_fd(' ', 1);
// 			if (num < 0)
// 			{
// 				ft_putchar_fd('-', 1);
// 				(set->print_size)++;
// 				num *= (-1);
// 			}
// 			while (((set->precision)--) - set->arglen)
// 				ft_putchar_fd('0', 1);
// 			ft_putnbr_fd(num, 1);
// 		}
// 		else
// 		{
// 			if (set->f_zero == 1 && set->f_minus == 0 && set->f_point == 0)
// 			{
// 				if (num < 0)
// 				{
// 					ft_putchar_fd('-', 1);
// 					num *= (-1);
// 				}
// 				while (((set->width)--) - set->arglen)
// 					ft_putchar_fd('0', 1);
// 				ft_putnbr_fd(num, 1);
// 			}
// 			else
// 			{
// 				while (((set->width)--) - set->arglen)
// 					ft_putchar_fd(' ', 1);
// 				ft_putnbr_fd(num, 1);
// 			}
// 		}
// 	}
// 	return ;
// }

