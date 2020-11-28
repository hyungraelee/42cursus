/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:34:36 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/29 01:41:25 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hex_check_size_p(unsigned long long num)
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

int		ft_convert_hex_p(t_set *set, unsigned long long num)
{
	int	size;

	size = ft_hex_check_size_p(num);
	set->arglen = size;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	set->input_data[size] = '\0';
	while (size - 1 >= 0)
	{
		if (num % 16 >= 10 && num % 16 <= 15)
			set->input_data[size - 1] = (num % 16) - 10 + 'a';
		else if (num % 16 >= 0 && num % 16 < 10)
			set->input_data[size - 1] = (num % 16) + '0';
		num /= 16;
		size--;
	}
	return (1);
}

int		ft_print_p_wid(t_set *set)
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

int		ft_print_p_arg(t_set *set)
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

int		ft_apply_hash_to_p(t_set *set)
{
	char	*temp;
	int		size;

	temp = set->input_data;
	size = set->arglen + 2;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	set->input_data[size] = '\0';
	set->input_data[0] = '0';
	set->input_data[1] = 'x';
	ft_strlcpy(set->input_data + 2, temp, set->arglen + 1);
	set->arglen = ft_strlen(set->input_data);
	free(temp);
	return (1);
}

int		ft_print_p(t_set *set)
{
	unsigned long long	num;

	num = (unsigned long long)va_arg(*(set->args), void *);
	if (!(ft_convert_hex_p(set, num)))
		return (0);
	if (!(ft_apply_precision_to_uxpo(set)))
		return (0);
	if (!(ft_apply_hash_to_p(set)))
		return (0);
	if (set->width > set->arglen)
	{
		if (!(ft_print_p_wid(set)))
			return (0);
	}
	else
	{
		if (!(ft_print_p_arg(set)))
			return (0);
	}
	ft_putstr_fd(set->print_buf, 1);
	set->print_size += ft_strlen(set->print_buf);
	free(set->input_data);
	free(set->print_buf);
	return (1);
}
