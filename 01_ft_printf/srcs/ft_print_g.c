/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_g.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:23:45 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 02:31:40 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_delete_zero(t_set *set)
{
	int		i;
	char	*temp;

	i = set->arglen;
	while (--i > 0)
	{
		if (set->input_data[i] != '0')
			break ;
	}
	if (i != 0 && set->f_hash == 0 && set->input_data[i] == '.')
		i--;
	temp = set->input_data;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (i + 2))))
		return (0);
	set->input_data[i + 1] = '\0';
	ft_memmove(set->input_data, temp, i + 1);
	set->arglen = ft_strlen(set->input_data);
	free(temp);
	return (1);
}

int		ft_print_g_by_f(t_set *set)
{
	int	tmp;

	free(set->input_data);
	tmp = !set->precision ? 1 : set->precision;
	set->precision = tmp - 1 - set->cnt_exp;
	if (!(ft_input_fdata(set)))
		return (0);
	if (!set->f_hash)
	{
		if (!(ft_delete_zero(set)))
			return (0);
	}
	return (1);
}

int		ft_print_g_by_e(t_set *set, t_double dbl)
{
	int	tmp;

	free(set->input_data);
	set->cnt_exp = 0;
	tmp = !set->precision ? 1 : set->precision;
	set->precision = tmp - 1;
	if (!(ft_input_edata(set, dbl)))
		return (0);
	if (!set->f_hash)
	{
		if (!(ft_delete_zero(set)))
			return (0);
	}
	if (!(ft_fill_exponent(set)))
		return (0);
	return (1);
}

int		ft_branch_g(t_set *set, t_double dbl)
{
	int tmp;

	tmp = !set->precision ? 1 : set->precision;
	if (set->cnt_exp < -4 || set->cnt_exp >= tmp)
	{
		if (set->cnt_exp == 0 && tmp == 0)
		{
			if (!(ft_print_g_by_f(set)))
				return (0);
		}
		else
		{
			if (!(ft_print_g_by_e(set, dbl)))
				return (0);
		}
	}
	else
	{
		if (!(ft_print_g_by_f(set)))
			return (0);
	}
	return (1);
}

int		ft_print_g(t_set *set)
{
	t_double	dbl;
	int			temp;

	dbl.dnum = va_arg(*(set->args), double);
	ft_make_bigint_arr(set, dbl);
	if (!set->f_point)
		set->precision = 6;
	temp = set->precision;
	set->precision = !set->precision ? 0 : set->precision - 1;
	if (!(ft_input_edata(set, dbl)))
		return (0);
	set->precision = temp;
	if (!(ft_branch_g(set, dbl)))
		return (0);
	if (!(ft_apply_flag_and_print(set, dbl)))
		return (0);
	ft_put_and_free(set);
	return (1);
}
