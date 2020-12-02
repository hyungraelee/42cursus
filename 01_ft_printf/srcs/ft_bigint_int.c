/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 00:04:32 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 18:11:22 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_round_one(t_set *set, int i)
{
	set->bi_inte.two_mul[i] = 1;
	set->mul_len++;
	return ;
}

static void	ft_bi_integer_arr_multiple_two(t_set *set)
{
	int	round;
	int i;
	int temp;

	round = 0;
	i = 0;
	while (i < set->mul_len)
	{
		temp = (set->bi_inte.two_mul[i] * 2) + round;
		if (temp >= 10)
		{
			set->bi_inte.two_mul[i] = temp % 10;
			round = temp / 10;
		}
		else
		{
			set->bi_inte.two_mul[i] = temp;
			round = 0;
		}
		i++;
	}
	if (round == 1)
		ft_round_one(set, i);
	return ;
}

static void	ft_bi_integer_reverse_arr(t_set *set)
{
	char	temp[309];
	int		i;

	i = 0;
	ft_memmove(temp, set->bi_inte.inte_res, 309);
	ft_memset(set->bi_inte.inte_res, 0, 309);
	while (i < set->integer_len)
	{
		set->bi_inte.inte_res[308 - i] = temp[i];
		i++;
	}
	return ;
}

static void	ft_bi_addition_inte_res(t_set *set)
{
	int	j;
	int	round;

	j = 0;
	round = 0;
	while (j < set->mul_len + 1)
	{
		if ((set->bi_inte.inte_res[j] + set->bi_inte.two_mul[j] + round) < 10)
		{
			set->bi_inte.inte_res[j] = \
			set->bi_inte.inte_res[j] + set->bi_inte.two_mul[j] + round;
			round = 0;
		}
		else
		{
			set->bi_inte.inte_res[j] = \
			(set->bi_inte.inte_res[j] + set->bi_inte.two_mul[j] + round) % 10;
			round = 1;
		}
		j++;
	}
	set->integer_len = \
	set->bi_inte.inte_res[set->mul_len] != 0 ? set->mul_len + 1 : set->mul_len;
	return ;
}

void		ft_bi_integer_arr_put_result(t_set *set)
{
	int		i;

	i = 1024;
	while (i-- > (1023 - set->exp))
	{
		if (set->bi_inte.inte_bin[i] == 1)
			ft_bi_addition_inte_res(set);
		ft_bi_integer_arr_multiple_two(set);
	}
	ft_bi_integer_reverse_arr(set);
	return ;
}
