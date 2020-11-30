/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:01:00 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/30 21:33:31 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		ft_print_x(t_set *set)
{
	unsigned long long	num;

	ft_get_data_u(set, &num);
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
		if (!(ft_print_arg(set)))
			return (0);
	}
	ft_put_and_free(set);
	return (1);
}
