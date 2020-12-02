/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:16:10 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 20:42:56 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fill_inputdata_int(t_set *set)
{
	int		i;
	int		j;

	i = set->integer_len - 1;
	j = 1;
	while (i >= 0)
	{
		if ((set->input_data[i] = \
		set->bi_inte.inte_res[309 - j] + set->rounding) >= 10)
		{
			set->input_data[i] = set->input_data[i] % 10;
			set->rounding = 1;
		}
		else
			set->rounding = 0;
		set->input_data[i] += '0';
		i--;
		j++;
	}
	if (set->rounding)
		return (ft_rounding_in_int(set));
	return (1);
}

static int	ft_fill_inputdata_dec(t_set *set)
{
	int i;

	if (!set->precision && !set->f_hash)
		return (ft_fill_dec_without_point(set));
	i = set->integer_len + set->precision;
	if (ft_check_bankers_rounding_for_f(set))
		ft_bankers_rounding_for_f(set);
	else if (set->bi_deci.deci_res[set->precision--] >= 5)
		set->rounding = 1;
	while (set->precision >= 0)
	{
		if ((set->input_data[i] = \
		set->bi_deci.deci_res[set->precision--] + set->rounding) >= 10)
		{
			set->input_data[i] = set->input_data[i] % 10;
			set->rounding = 1;
		}
		else
			set->rounding = 0;
		set->input_data[i] += '0';
		i--;
	}
	set->input_data[i] = '.';
	return (1);
}

int			ft_input_fdata(t_set *set)
{
	if (!(set->input_data = \
	(char *)malloc(sizeof(char) * (set->integer_len + set->precision + 2))))
		return (0);
	set->input_data[set->integer_len + set->precision + 1] = '\0';
	set->arglen = set->integer_len + set->precision + 1;
	if (!(ft_fill_inputdata_dec(set)))
		return (0);
	if (!(ft_fill_inputdata_int(set)))
		return (0);
	set->arglen = ft_strlen(set->input_data);
	return (1);
}

int			ft_print_f(t_set *set)
{
	t_double dbl;

	dbl.dnum = va_arg(*(set->args), double);
	if (dbl.bitfield.exponent == 2047)
		ft_input_infnan(set, dbl);
	else
	{
		ft_make_bigint_arr(set, dbl);
		if (set->f_point == 0)
			set->precision = 6;
		if (!(ft_input_fdata(set)))
			return (0);
	}
	if (!(ft_apply_flag_and_print(set, dbl)))
		return (0);
	ft_put_and_free(set);
	return (1);
}
