/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:21:13 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/01 19:10:20 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_apply_hash_to_o(t_set *set, unsigned long long num)
{
	char	*temp;
	int		size;

	if (set->f_hash == 1 && num != 0)
	{
		temp = set->input_data;
		size = set->arglen + 1;
		if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
			return (0);
		set->input_data[size] = '\0';
		set->input_data[0] = '0';
		ft_strlcpy(set->input_data + 1, temp, set->arglen + 1);
		set->arglen = ft_strlen(set->input_data);
		free(temp);
	}
	return (1);
}

// same with u
int		ft_print_o_wid(t_set *set)
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

int		ft_print_o(t_set *set)
{
	unsigned long long	num;

	ft_get_data_u(set, &num);
	if (!(ft_convert_oct(set, num)))
		return (0);
	if (!(ft_apply_precision_to_uxpo(set)))
		return (0);
	if (!(ft_apply_hash_to_o(set, num)))
		return (0);
	if (set->width > set->arglen)
	{
		if (!(ft_print_o_wid(set)))
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
