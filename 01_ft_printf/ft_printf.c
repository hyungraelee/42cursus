/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:33:51 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/22 23:02:31 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	is_flag(char chr)
// {
// 	if (chr == '0' || chr == '-')
// 		return (1);
// 	return (0);
// }

int		is_width(const char *str)
{
	if (!ft_isdigit(*str))
		return (0);
	return (1);
}

int		ft_count_argsize(va_list args)
{

}

int		ft_width_length(const char *str)
{

}

void	ft_work_width(const char *str, va_list args, int width)
{
	int	arg_size;

	arg_size = ft_count_argsize(args);
	if (width > arg_size)
	{

	}
}

// int	is_precision(char chr)
// {

// }

char	ft_check_type(const char *str)
{
	char	*check_type;

	while (!ft_strchr(data_type, *str))
		str++;
	check_type = ft_strchr(data_type, *str);
	return (*check_type);
}

void	ft_func_by_type(const char *str, va_list args, char type)
{
	if (type == 'd' || type == 'i')
}

int		ft_conversion(const char *str, va_list args, int *print_size)
{
	char	type;

	// if (is_flag(*str))
	// {
	// 	ft_work_flag(str);
	// }
	if (is_width(str))
	{
		ft_width_length(str);
		ft_work_width(str, args, ft_atoi(str));
	}
	// if(is_precision(*str))
	// {
	// 	ft_work_precision(str);
	// }
	// if (*str == 'd')
	// {
	// 	ft_putnbr_fd(va_arg(args, int), 1);
	// }
	type = ft_check_type(str);
	ft_func_by_type(str, args, type);

}

int		ft_count_format(const char *str, va_list args)
{
	int cnt;
	const char *temp;

	cnt = 0;
	temp = str;
	while (!ft_strchr(data_type, *temp++))
		cnt++;
	return (cnt);
}

int		ft_read_str(const char *str, va_list args)
{
	int	*print_size;

	*print_size = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			ft_conversion(str, args, print_size);
			str += ft_count_format(str, args);
		}
		else if (*str == '%' && *(str + 1) == '%')
		{
			ft_putchar_fd('%', 1);
			(*print_size)++;
			str += 2;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			(*print_size)++;
			str++;
		}
	}
	return (*print_size);
}

int		ft_printf(const	char *str, ...)
{
	va_list	args;
	int		res;

	va_start(args, str);
	res = ft_read_str(str, args);
	va_end(args);
	return (res);
}
