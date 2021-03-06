/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:00:19 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 20:23:15 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_apply_precision_to_int(t_set *set, long long num)
{
	if (set->f_point == 1 && set->precision == 0 && *set->input_data == '0')
	{
		*set->input_data = '\0';
		set->arglen = 0;
	}
	else if (num >= 0 && set->precision > set->arglen)
		return (ft_apply_prec_d_pos(set));
	else if (num < 0 && set->precision > (set->arglen - 1))
		return (ft_apply_prec_d_neg(set));
	return (1);
}

static int	ft_apply_flag_to_int(t_set *set, long long num)
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

static void	ft_print_int_zero(t_set *set)
{
	size_t	temp;

	temp = 0;
	if (*(set->input_data) == '-' || \
	*(set->input_data) == '+' || *(set->input_data) == ' ')
		set->print_buf[temp++] = *(set->input_data);
	while ((set->width)-- - set->arglen)
		ft_memcpy(set->print_buf + temp++, "0", 1);
	if (*(set->input_data) == '-' || \
	*(set->input_data) == '+' || *(set->input_data) == ' ')
		ft_strlcpy(set->print_buf + temp, set->input_data + 1, set->arglen);
	else
		ft_strlcpy(set->print_buf + temp, set->input_data, set->arglen + 1);
	return ;
}

static int	ft_print_int_wid(t_set *set)
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
		ft_print_int_zero(set);
	else
	{
		while ((set->width)-- - set->arglen)
			ft_memcpy(set->print_buf + temp++, " ", 1);
		ft_strlcpy(set->print_buf + temp, set->input_data, set->arglen + 1);
	}
	set->print_buf[size] = '\0';
	return (1);
}

int			ft_print_di(t_set *set)
{
	long long	num;

	ft_get_data_d(set, &num);
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
		if (!(ft_print_arg(set)))
			return (0);
	}
	ft_put_and_free(set);
	return (1);
}
