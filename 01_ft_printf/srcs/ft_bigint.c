/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:39:20 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 00:06:43 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bi_init_arr(t_set *set)
{
	ft_memset(set->bi_dece.dece_bin, 0, 1074);
	ft_memset(set->bi_dece.five_mul, 0, 1074);
	(set->bi_dece.five_mul)[0] = 5;
	ft_memset(set->bi_dece.dece_res, 0, 1074);
	ft_memset(set->bi_inte.inte_bin, 0, 1024);
	ft_memset(set->bi_inte.two_mul, 0, 309);
	(set->bi_inte.two_mul)[0] = 1;
	ft_memset(set->bi_inte.inte_res, 0, 309);
	return ;
}

void	ft_make_bigint_arr(t_set *set, t_double dbl)
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
