/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:33:51 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/20 20:48:12 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	is_flag(char chr)
{
	if (chr == '0' || chr == '-')
		return (1);
	return (0);
}

int	is_width(char chr)
{
	while (ft_isdigit(chr))
	{

	}
}

int	is_precision(char chr)
{

}

int	ft_conversion(const char *str, va_list args)
{
	int cnt;

	str++;
	cnt = 1;
//	if (isflags(*str))
	if (is_flag(*str))
	{
		ft_work_flag(str);
	}
	if (is_width(*str))
	{
		ft_work_width(str);
	}
	if(is_precision(*str))
	{
		ft_work_precision(str);
	}
	if (*str == 'd')
	{
		ft_putnbr_fd(va_arg(args, int), 1);
		cnt++;
	}
	return (cnt);
}

int	ft_printf(const	char *str, ...)
{
	va_list		args;

	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			str += ft_conversion(str, args);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
		}
	}

	va_end(args);
	return (0);
}
