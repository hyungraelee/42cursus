/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:01:00 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/25 17:17:22 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		ft_hex_check_size(unsigned long long num)
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

int		ft_convert_hex(t_set *set, unsigned long long num)
{
	int	size;

	size = ft_hex_check_size(num);
	set->arglen = size;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	set->input_data[size] = '\0';
	while (size - 1 >= 0)
	{
		if (num % 16 >= 10 && num % 16 <= 15 && set->specifier == 'x')
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

// int		ft_print_x_wid(t_set *set)
// {
// 	size_t	size;
// 	size_t	temp;

// 	size = set->width;
// 	temp = 0;
// 	if (!(set->print_buf = (char *)malloc(sizeof(char) * (size + 1))))
// 		return (0);
// 	if (set->f_minus == 1)
// 	{
// 		temp = ft_strlcpy(set->print_buf, set->input_data, set->arglen + 1);
// 		while ((set->width)-- - set->arglen)
// 			ft_memcpy(set->print_buf + temp++, " ", 1);
// 	}
// 	else
// 	{
// 		while ((set->width)-- - set->arglen)
// 			ft_memcpy(set->print_buf + temp++, " ", 1);
// 		ft_strlcpy(set->print_buf + temp, set->input_data, set->arglen + 1);
// 	}
// 	set->print_buf[size] = '\0';
// 	return (1);
// }

int		ft_print_x_wid(t_set *set, unsigned long long num)
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
		if (set->f_hash == 1 && num != 0)
		{
			set->print_buf[temp++] = '0';
			set->print_buf[temp++] = set->specifier == 'x' ? 'x' : 'X';
			while ((set->width)-- - set->arglen)
				ft_memcpy(set->print_buf + temp++, "0", 1);
			ft_strlcpy(set->print_buf + temp, set->input_data + 2, set->arglen + 1);
		}
		else
		{
			while ((set->width)-- - set->arglen)
				ft_memcpy(set->print_buf + temp++, "0", 1);
			ft_strlcpy(set->print_buf + temp, set->input_data, set->arglen + 1);
		}
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

int		ft_print_x_arg(t_set *set)
{
	size_t	size;
	size_t	temp;

	size = set->arglen;
	temp = 0;
	if (!(set->print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_strlcpy(set->print_buf, set->input_data, set->arglen + 1);
	set->print_buf[size] = '\0';
	return (1);
}

// int		ft_apply_precision_to_x(t_set *set)
// {
// 	char	*temp;
// 	int		index;

// 	if (set->f_point == 1 && set->precision == 0 && *set->input_data == '0')
// 	{
// 		*set->input_data = '\0';
// 		set->arglen = 0;
// 	}
// 	else if (set->precision > set->arglen)
// 	{
// 		index = 0;
// 	}
// }

int		ft_apply_hash_to_x(t_set *set, unsigned long long num)
{
	char	*temp;
	int		size;

	if (set->f_hash == 1 && num != 0)
	{
		temp = set->input_data;
		size = set->arglen + 2;
		if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
			return (0);
		set->input_data[size] = '\0';
		set->input_data[0] = '0';
		set->input_data[1] = set->specifier == 'x' ? 'x' : 'X';
		ft_strlcpy(set->input_data + 2, temp, set->arglen + 1);
		set->arglen = ft_strlen(set->input_data);
		free(temp);
	}
	return (1);
}

int		ft_print_hex(t_set *set)
{
	unsigned long long	num;

	if (set->l_l == 1)
		num = va_arg(*(set->args), unsigned long);
	else if (set->l_l >= 2)
		num = va_arg(*(set->args), unsigned long long);
	else if (set->l_h == 1)
		num = (unsigned short)va_arg(*(set->args), unsigned int);
	else if (set->l_h >= 2)
		num = (unsigned char)va_arg(*(set->args), unsigned int);
	else
		num = va_arg(*(set->args), unsigned int);
	if (!(ft_convert_hex(set, num)))
		return (0);
	if (!(ft_apply_precision_to_uxpo(set)))
		return (0);
	if (!(ft_apply_hash_to_x(set, num)))
		return (0);
	if (set->width > set->arglen)
	{
		if (!(ft_print_x_wid(set, num)))
			return (0);
	}
	else
	{
		if (!(ft_print_x_arg(set)))
			return (0);
	}
	ft_putstr_fd(set->print_buf, 1);
	set->print_size += ft_strlen(set->print_buf);
	free(set->input_data);
	free(set->print_buf);
	return (1);
}
