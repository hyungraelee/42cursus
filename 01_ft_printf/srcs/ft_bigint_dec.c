/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 00:02:06 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 00:14:50 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bi_decimal_arr_multiple_five(t_set *set, int i)
{
	int j;
	int	round;

	if (i < 1073)
	{
		j = i;
		round = 0;
		while (j >= 0)
		{
			if ((((set->bi_dece.five_mul[j] * 5) % 10) + round) < 10)
			{
				(set->bi_dece.five_mul)[j + 1] = \
				((set->bi_dece.five_mul[j] * 5) % 10) + round;
				round = 0;
			}
			else
			{
				(set->bi_dece.five_mul)[j + 1] = \
				(((set->bi_dece.five_mul[j] * 5) % 10) + round) % 10;
				round = (((set->bi_dece.five_mul[j] * 5) % 10) + round) / 10;
			}
			round += (set->bi_dece.five_mul[j] * 5) / 10;
			set->bi_dece.five_mul[j--] = round;
		}
	}
	return ;
}

void	ft_bi_addition_dece_res(t_set *set, int j)
{
	int round;

	round = 0;
	while (j >= 0)
	{
		if ((set->bi_dece.dece_res[j] + set->bi_dece.five_mul[j] + round) < 10)
		{
			set->bi_dece.dece_res[j] = \
			set->bi_dece.dece_res[j] + set->bi_dece.five_mul[j] + round;
			round = 0;
		}
		else
		{
			set->bi_dece.dece_res[j] = \
			(set->bi_dece.dece_res[j] + set->bi_dece.five_mul[j] + round) % 10;
			round = 1;
		}
		j--;
	}
	return ;
}

void	ft_bi_decimal_arr_put_result(t_set *set)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < 1074)
	{
		j = i + 1;
		if (set->bi_dece.dece_bin[i] == 1)
			ft_bi_addition_dece_res(set, j);
		ft_bi_decimal_arr_multiple_five(set, i);
		i++;
	}
	return ;
}

void	ft_bi_decimal_arr_put_binary(t_set *set, t_double dbl)
{
	int				i;
	unsigned long	one;
	unsigned long	temp;

	i = 0;
	one = 1;
	one <<= 52;
	temp = dbl.bitfield.mantissa;
	if (set->exp >= 0)
	{
		temp <<= (set->exp);
		while (i < 52)
		{
			(set->bi_dece.dece_bin)[i] = ((temp >> (51 - i)) & 1) ? 1 : 0;
			++i;
		}
	}
	else
	{
		temp |= one;
		(set->exp) *= (-1);
		while (i < 53)
			(set->bi_dece.dece_bin)[(set->exp)++ - 1] = \
			((temp >> (52 - i++)) & 1) ? 1 : 0;
	}
	return ;
}
