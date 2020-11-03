/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:27:08 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/03 18:38:38 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ull_change_num(t_set *set, unsigned long long num, int size)
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

int		ft_ull_check_size(unsigned long long num)
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

int		ft_ulltoa(t_set *set, unsigned long long num)
{
	int		size;

	size = ft_ull_check_size(num);
	set->arglen = size;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_ull_change_num(set, num, size);
	return (1);
}

// int	ft_apply_precision_to_u(t_set *set)
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
// 		temp = set->input_data;
// 		if (!(set->input_data = (char *)malloc(sizeof(char) * (set->precision + 1))))
// 			return (0);
// 		set->input_data[set->precision] = '\0';
// 		while ((set->precision)-- > set->arglen)
// 			ft_memcpy(set->input_data + index++, "0", 1);
// 		ft_strlcpy(set->input_data + index, temp, set->arglen + 1);
// 		set->arglen = ft_strlen(set->input_data);
// 		free(temp);
// 	}
// 	return (1);
// }

int		ft_print_u_wid(t_set *set)
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
		while ((set->width)-- - set->arglen)
			ft_memcpy(set->print_buf + temp++, "0", 1);
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

int		ft_print_u_arg(t_set *set)
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

int		ft_print_uint(t_set *set)
{
	unsigned long long	num;

	// if (set->f_length_modifier == "ll")
	// 	num = va_arg(*(set->args), long long);
	num = va_arg(*(set->args), unsigned int);
	if (!(ft_ulltoa(set, num)))
		return (0);
	if (!(ft_apply_precision_to_uxp(set)))
		return (0);
	if (set->width > set->arglen)
	{
		if (!(ft_print_u_wid(set)))
			return (0);
	}
	else
	{
		if (!(ft_print_u_arg(set)))
			return (0);
	}
	ft_putstr_fd(set->print_buf, 1);
	set->print_size += ft_strlen(set->print_buf);
	free(set->input_data);
	free(set->print_buf);
	return (1);
}
