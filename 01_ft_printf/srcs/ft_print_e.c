/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:17:58 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 17:22:35 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_input_edata(t_set *set, t_double dbl)
{
	if (!(set->input_data = \
	(char *)malloc(sizeof(char) * (set->integer_len + 1074 + 1))))
		return (0);
	set->input_data[set->integer_len + 1074] = '\0';
	ft_fill_inputdata(set);
	if (!(ft_apply_precision_to_e(set, dbl)))
		return (0);
	set->arglen = ft_strlen(set->input_data);
	if (!(ft_fill_point(set)))
		return (0);
	set->arglen = ft_strlen(set->input_data);
	return (1);
}

int		ft_fill_exponent(t_set *set)
{
	int		size;
	char	*temp;
	int		i;
	char	*exptoa;

	size = (set->cnt_exp > -100 && set->cnt_exp < 100) ? \
	set->arglen + 4 : set->arglen + 5;
	temp = set->input_data;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	set->input_data[size] = '\0';
	ft_memmove(set->input_data, temp, set->arglen);
	i = set->arglen;
	set->input_data[i++] = 'e';
	set->input_data[i++] = set->cnt_exp >= 0 ? '+' : '-';
	if (!(exptoa = ft_itoa(set->cnt_exp)))
		return (0);
	if (set->cnt_exp > -100 && set->cnt_exp < 100)
		ft_exponent_two_figures(set, i);
	else
		ft_memmove(set->input_data + i, exptoa, ft_strlen(exptoa));
	set->arglen = ft_strlen(set->input_data);
	free(temp);
	free(exptoa);
	return (1);
}

int		ft_print_e(t_set *set)
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
		if (!(ft_input_edata(set, dbl)))
			return (0);
		if (!(ft_fill_exponent(set)))
			return (0);
	}
	if (!(ft_apply_flag_and_print(set, dbl)))
		return (0);
	ft_put_and_free(set);
	return (1);
}
