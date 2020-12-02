/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 00:02:06 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 18:19:57 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_bi_decimal_arr_multiple_five(t_set *set, int j)
{
	int	round;

	if (j < 1073)
	{
		round = 0;
		while (j >= 0)
		{
			if ((((set->bi_deci.five_mul[j] * 5) % 10) + round) < 10)
			{
				(set->bi_deci.five_mul)[j + 1] = \
				((set->bi_deci.five_mul[j] * 5) % 10) + round;
				round = 0;
			}
			else
			{
				(set->bi_deci.five_mul)[j + 1] = \
				(((set->bi_deci.five_mul[j] * 5) % 10) + round) % 10;
				round = (((set->bi_deci.five_mul[j] * 5) % 10) + round) / 10;
			}
			round += (set->bi_deci.five_mul[j] * 5) / 10;
			set->bi_deci.five_mul[j--] = round;
		}
	}
	return ;
}

static void	ft_bi_addition_dece_res(t_set *set, int j)
{
	int round;

	round = 0;
	while (j >= 0)
	{
		if ((set->bi_deci.deci_res[j] + set->bi_deci.five_mul[j] + round) < 10)
		{
			set->bi_deci.deci_res[j] = \
			set->bi_deci.deci_res[j] + set->bi_deci.five_mul[j] + round;
			round = 0;
		}
		else
		{
			set->bi_deci.deci_res[j] = \
			(set->bi_deci.deci_res[j] + set->bi_deci.five_mul[j] + round) % 10;
			round = 1;
		}
		j--;
	}
	return ;
}

void		ft_bi_decimal_arr_put_result(t_set *set)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < 1074)
	{
		j = i + 1;
		if (set->bi_deci.deci_bin[i] == 1)
			ft_bi_addition_dece_res(set, j);
		ft_bi_decimal_arr_multiple_five(set, i);
		i++;
	}
	return ;
}
