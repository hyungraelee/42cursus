/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:17:58 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/19 22:59:45 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_inputdata(t_set *set)
{
	int i, j;

	i = 0;
	j = set->integer_len;
	while (i < set->integer_len)
	{
		set->input_data[i] = set->bi_int_arr.int_result[309 - j];
		i++;
		j--;
	}
	j = 0;
	while (i < set->integer_len + 1074)
	{
		set->input_data[i] = set->bi_dec_arr.dec_result[j];
		i++;
		j++;
	}
	return ;
}

int		ft_apply_precision_to_e(t_set *set)
{
	char	*temp;

	temp = set->input_data;

	return (1);
}

int		ft_input_edata(t_set *set)
{
	if (set->f_point == 0)
		set->precision = 6;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (set->integer_len + 1074 + 1))))
		return (0);
	set->input_data[set->integer_len + 1074] = '\0';
	ft_fill_inputdata(set);
	if (!(ft_apply_precision_to_e(set)))
		return (0);
int k = 0;
while (k < set->integer_len + 1073)
	{printf("%d", set->input_data[k++]);}
	return (1);
}

int		ft_print_e(t_set *set)
{
	t_double dbl;
	dbl.dnum = va_arg(*(set->args), double);

	ft_make_bigint_arr(set, dbl);
	if (!(ft_input_edata(set)))
		return (0);

	return (1);
}
