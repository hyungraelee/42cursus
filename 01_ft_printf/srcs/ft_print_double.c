/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:16:10 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/17 17:16:46 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_inputdata_int(t_set *set)
{
	int i;
	int j;

	i = set->integer_len;
	j = 1;
	set->input_data[i--] = '.';
	int k=0;
	while (k < 11)
		printf("%c", set->input_data[k++]);
	printf("\n");
	while (i >= 0)
	{
		if ((set->input_data[i] = set->bi_int_arr.int_result[309 - j] + set->rounding) >= 10)
		{
			set->input_data[i] = set->input_data[i] % 10;
			set->rounding = 1;
		}
		else
			set->rounding = 0;
		i--;
		j++;
	}
	return ;
}

void	ft_fill_inputdata_dec(t_set *set)
{
	int i;

	i = set->integer_len + set->precision;
	if (set->bi_dec_arr.dec_result[set->precision--] >= 5)
		set->rounding = 1;
	while (set->precision >= 0)
	{
		if ((set->input_data[i] = set->bi_dec_arr.dec_result[set->precision--] + set->rounding) >= 10)
		{
			set->input_data[i] = set->input_data[i] % 10;
			set->rounding = 1;
		}
		else
			set->rounding = 0;
		i--;
	}

	return ;
}

static int		ft_input_data(t_set *set)
{
	if (set->f_point == 0)
		set->precision = 6;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (set->integer_len + set->precision + 2))))
		return (0);
	set->input_data[set->integer_len + set->precision + 1] = '\0';
	ft_fill_inputdata_dec(set);

	ft_fill_inputdata_int(set);
	set->arglen = ft_strlen(set->input_data);

	return (1);
}

int		ft_print_double(t_set *set)
{
	t_double dbl;

	dbl.dnum = va_arg(*(set->args), double);
	ft_make_bigint_arr(set, dbl);
	if (!(ft_input_data(set)))
		return (0);
	int i=0;
	while (i < set->integer_len)
	{
		printf("%d", set->bi_int_arr.int_result[309 - set->integer_len + i++]);
	}
	printf("\n");
	i = 0;
	while (i < 1024)
		printf("%d", set->bi_int_arr.int_binary[i++]);
	printf("\n");
	i = 0;
	while (i < 1074)
		printf("%d", set->bi_dec_arr.dec_binary[i++]);
	return (1);
}
