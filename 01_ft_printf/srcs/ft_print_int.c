/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:00:19 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/04 21:03:15 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ll_check_size(long long num)
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

void	ft_ll_change_num(t_set *set, long long num, int size)
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

int		ft_lltoa(t_set *set, long long num)
{
	int	size;

	size = ft_ll_check_size(num);
	set->arglen = size;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_ll_change_num(set, num, size);
	return (1);
}

int		ft_apply_precision_to_int(t_set *set, long long num)
{
	char	*temp;
	int		i;

	i = 0;
	if (set->f_point == 1 && set->precision == 0 && *set->input_data == '0')
	{
		*set->input_data = '\0';
		set->arglen = 0;
	}
	else if (num >= 0 && set->precision > set->arglen)
	{
		temp = set->input_data;
		if (!(set->input_data = (char *)malloc(sizeof(char) * (set->precision + 1))))
			return (0);
		set->input_data[set->precision] = '\0';
		while ((set->precision)-- > set->arglen)
			ft_memcpy(set->input_data + i++, "0", 1);
		ft_strlcpy(set->input_data + i, temp, set->arglen + 1);
		set->arglen = ft_strlen(set->input_data);
		free(temp);
	}
	else if (num < 0 && set->precision > (set->arglen - 1))
	{
		temp = set->input_data;
		if (!(set->input_data = (char *)malloc(sizeof(char) * (set->precision + 2))))
			return (0);
		set->input_data[set->precision + 1] = '\0';
		set->input_data[i++] = '-';
		while ((set->precision)-- > (set->arglen - 1))
			ft_memcpy(set->input_data + i++, "0", 1);
		ft_strlcpy(set->input_data + i, temp + 1, set->arglen);
		set->arglen = ft_strlen(set->input_data);
		free(temp);
	}
	return (1);
}

int		ft_apply_flag_to_int(t_set *set, long long num)
{
	char	*temp;
	size_t	size;

	size = set->arglen + 1;
	temp = set->input_data;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
			return (0);
	if (set->f_plus == 1 && num >= 0)
		set->input_data[0] = '+';
	else if (set->f_space == 1 && set->f_plus == 0 && num >= 0)
		set->input_data[0] = ' ';
	ft_strlcpy(set->input_data + 1, temp, size);
	set->input_data[size] = '\0';
	set->arglen = ft_strlen(set->input_data);
	free(temp);
	return (1);
}

int		ft_print_int_wid(t_set *set)
{
	size_t	size;
	size_t	temp;

	size = set->width;
	temp = 0;
	if (!(set->print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (set->f_minus == 1)
	{
		temp = ft_strlcpy(set->print_buf, set->input_data, set->arglen + 1);
		while ((set->width)-- - set->arglen)
			ft_memcpy(set->print_buf + temp++, " ", 1);
	}
	else if (set->f_zero == 1 && set->f_point == 0)
	{
		if (*(set->input_data) == '-' || *(set->input_data) == '+' || *(set->input_data) == ' ')
			set->print_buf[temp++] = *(set->input_data);
		while((set->width)-- - set->arglen)
			ft_memcpy(set->print_buf + temp++, "0", 1);
		if (*(set->input_data) == '-' || *(set->input_data) == '+' || *(set->input_data) == ' ')
			ft_strlcpy(set->print_buf + temp, set->input_data + 1, set->arglen);
		else
			ft_strlcpy(set->print_buf + temp, set->input_data, set->arglen + 1);
	}
	else
	{
		while ((set->width)-- - set->arglen)
			ft_memcpy(set->print_buf + temp++, " ", 1);
		ft_strlcpy(set->print_buf + temp, set->input_data, set->arglen + 1);
	}
	set->print_buf[size] = '\0';
	return (1);
}

int		ft_print_int_arg(t_set *set)
{
	size_t	size;

	size = set->arglen;
	if (!(set->print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_strlcpy(set->print_buf, set->input_data, set->arglen + 1);
	set->print_buf[size] = '\0';
	return (1);
}

int		ft_print_int(t_set *set)
{
	long long	num;

	if (set->l_l == 0)
		num = va_arg(*(set->args), int);
	else if (set->l_l == 1)
		num = va_arg(*(set->args), long);
	else
		num = va_arg(*(set->args), long long);
	if (!(ft_lltoa(set, num)))
		return (0);
	if (!(ft_apply_precision_to_int(set, num)))
		return (0);
	if ((set->f_plus == 1 || set->f_space == 1) && num >= 0)
	{
		if (!(ft_apply_flag_to_int(set, num)))
			return (0);
	}
	if (set->width > set->arglen)
	{
		if (!(ft_print_int_wid(set)))
			return (0);
	}
	else
	{
		if (!(ft_print_int_arg(set)))
			return (0);
	}
	ft_putstr_fd(set->print_buf, 1);
	set->print_size += ft_strlen(set->print_buf);
	free(set->input_data);
	free(set->print_buf);
	return (1);
}

// void	ft_arglen_int(int num, t_set *set)
// {
// 	unsigned int	temp;

// 	temp = num;
// 	if (num < 0)
// 	{
// 		(set->arglen)++;
// 		temp = -num;
// 	}
// 	if (temp == 0)
// 		(set->arglen)++;
// 	while (temp)
// 	{
// 		(set->arglen)++;
// 		temp /= 10;
// 	}
// 	return ;
// }

// void	ft_print_int_arglen_most(t_set *set, long long num)
// {
// 	set->print_size += set->arglen;
// 	ft_putnbr_fd(num, 1);
// 	return ;
// }

// void	ft_print_int_precision_most(t_set *set, long long num)
// {
// 	set->print_size += set->precision;
// 	if (num < 0)
// 	{
// 		ft_putchar_fd('-', 1);
// 		(set->print_size)++;
// 		num *= (-1);
// 		(set->arglen)--;
// 	}
// 	while (((set->precision)--) - set->arglen)
// 		ft_putchar_fd('0', 1);
// 	ft_putnbr_fd(num, 1);
// 	return ;
// }

// void	ft_print_int_width_minus(t_set *set, long long num)
// {
// 	int temp;

// 	temp = set->precision;
// 	if (set->precision >= set->arglen)
// 	{
// 		if (num < 0)
// 		{
// 			ft_putchar_fd('-', 1);
// 			num *= (-1);
// 			while ((set->precision)-- > (set->arglen - 1))
// 				ft_putchar_fd('0', 1);
// 			ft_putnbr_fd(num, 1);
// 			temp++;
// 			while ((set->width)-- > temp)
// 				ft_putchar_fd(' ', 1);
// 		}
// 		else
// 		{
// 			while ((set->precision)-- > set->arglen)
// 				ft_putchar_fd('0', 1);
// 			ft_putnbr_fd(num, 1);
// 			while ((set->width)-- > temp)
// 				ft_putchar_fd(' ', 1);
// 		}
// 	}
// 	else
// 	{
// 		ft_putnbr_fd(num, 1);
// 		while ((set->width)-- > set->arglen)
// 			ft_putchar_fd(' ', 1);
// 	}
// 	return ;
// }

// void	ft_print_int_width(t_set *set, long long num)
// {
// 	if (set->precision > set->arglen)
// 	{
// 		if (num < 0)
// 		{
// 			(set->print_size)++;
// 			num *= (-1);
// 			set->precision++;
// 			while (((set->width)--) - set->precision)
// 				ft_putchar_fd(' ', 1);
// 			ft_putchar_fd('-', 1);
// 		}
// 		else
// 			while (((set->width)--) - set->precision)
// 				ft_putchar_fd(' ', 1);
// 		while (((set->precision)--) - set->arglen)
// 			ft_putchar_fd('0', 1);
// 	}
// 	else
// 	{
// 		if (set->f_zero == 1 && set->f_minus == 0 && set->f_point == 0)
// 		{
// 			if (num < 0)
// 			{
// 				ft_putchar_fd('-', 1);
// 				num *= (-1);
// 			}
// 			while (((set->width)--) - set->arglen)
// 				ft_putchar_fd('0', 1);
// 		}
// 		else
// 		{
// 			while (((set->width)--) - set->arglen)
// 				ft_putchar_fd(' ', 1);
// 		}
// 	}
// 	ft_putnbr_fd(num, 1);
// 	return ;
// }

// void	ft_print_int_width_most(t_set *set, long long num)
// {
// 	set->print_size += set->width;
// 	if (set->f_minus == 1)
// 		ft_print_int_width_minus(set, num);
// 	else
// 		ft_print_int_width(set, num);
// 	return ;
// }

// void	ft_print_int(t_set *set)
// {
// 	long long	num;

// 	num = va_arg(*(set->args), int);
// 	if (set->f_point && set->precision == 0 && num == 0)	// %.0d <- 0
// 	{
// 		while (set->width--)
// 			ft_putchar_fd(' ', 1);
// 		ft_putstr_fd("", 1);
// 		return ;
// 	}
// 	ft_arglen_int(num, set);
// 	if (set->arglen >= set->width && set->arglen >= set->precision) // arg辨捞啊 力老 变 版快
// 		ft_print_int_arglen_most(set, num);
// 	else if (set->precision >= set->width && set->precision > set->arglen) // precision 辨捞啊 力老 变 版快
// 		ft_print_int_precision_most(set, num);
// 	else if (set->width > set->arglen && set->width > set->precision)	// width 辨捞啊 力老 变 版快
// 		ft_print_int_width_most(set, num);
// 	return ;
// }

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
