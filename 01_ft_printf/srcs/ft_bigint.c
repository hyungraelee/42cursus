/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:39:20 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 18:09:54 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_bi_decimal_arr_put_binary(t_set *set, t_double dbl)
{
	int				i;
	unsigned long	one;
	unsigned long	temp;

	i = -1;
	one = 1;
	one <<= 52;
	temp = dbl.bitfield.mantissa;
	if (set->exp >= 0)
	{
		temp <<= (set->exp);
		while (++i < 52)
			(set->bi_deci.deci_bin)[i] = ((temp >> (51 - i)) & 1) ? 1 : 0;
	}
	else
	{
		temp |= one;
		(set->exp) *= (-1);
		while (++i < 53)
			(set->bi_deci.deci_bin)[(set->exp)++ - 1] = \
			((temp >> (52 - i)) & 1) ? 1 : 0;
	}
	return ;
}

static void	ft_bi_integer_arr_put_binary(t_set *set, t_double dbl)
{
	int				i;
	unsigned long	temp;

	i = 0;
	temp = dbl.bitfield.mantissa;
	if (set->exp >= 0)
	{
		set->bi_inte.inte_bin[1024 - set->exp - 1] = 1;
		while (i < set->exp && i < 52)
		{
			set->bi_inte.inte_bin[1024 - set->exp + i] = \
			((temp >> (51 - i)) & 1) ? 1 : 0;
			i++;
		}
	}
	return ;
}

void		ft_bi_init_arr(t_set *set)
{
	ft_memset(set->bi_deci.deci_bin, 0, 1074);
	ft_memset(set->bi_deci.five_mul, 0, 1074);
	(set->bi_deci.five_mul)[0] = 5;
	ft_memset(set->bi_deci.deci_res, 0, 1074);
	ft_memset(set->bi_inte.inte_bin, 0, 1024);
	ft_memset(set->bi_inte.two_mul, 0, 309);
	(set->bi_inte.two_mul)[0] = 1;
	ft_memset(set->bi_inte.inte_res, 0, 309);
	return ;
}

void		ft_make_bigint_arr(t_set *set, t_double dbl)
{
	ft_bi_init_arr(set);
	set->exp = dbl.bitfield.exponent - (int)BIAS;
	ft_bi_decimal_arr_put_binary(set, dbl);
	ft_bi_decimal_arr_put_result(set);
	set->exp = dbl.bitfield.exponent - (int)BIAS;
	ft_bi_integer_arr_put_binary(set, dbl);
	ft_bi_integer_arr_put_result(set);
	return ;
}
