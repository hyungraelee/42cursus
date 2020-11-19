/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:17:58 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/20 03:09:49 by hyunlee          ###   ########.fr       */
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

int		ft_check_bankers_rounding_for_e(t_set *set, char *temp)
{
	if (*temp != 5)
		return (0);
	while (*temp++)
	{
		if (*temp != 0)
			return (0);
	}
	return (1);
}

int		ft_apply_precision_to_e(t_set *set)
{
	char	*temp;
	int		cnt_exp;
	int		i;
	int		j;

	temp = set->input_data;
	cnt_exp = 0;
	i = 1;
	j = 0;
	if (set->f_point == 0)
		set->precision = 6;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (set->precision + 3))))
		return (0);
	if (temp[0] == 0)
	{
		while (!temp[i++])
			cnt_exp++;
		if (!set->precision && !set->f_hash)
		{
			if (ft_check_bankers_rounding_for_e(set, temp + i))
			{
				if (temp[i - 1] % 2 == 1)
					set->rounding = 1;
			}
			else if (temp[i] >= 5)
				set->rounding = 1;
***************************************************************************;
		}
		if (ft_check_bankers_rounding_for_e(set, temp + i + set->precision))
		{

		}


	}
	else
	{

	}


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
