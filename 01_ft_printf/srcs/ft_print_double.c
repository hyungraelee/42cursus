/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:16:10 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/13 19:10:01 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bi_decimal_arr_init_arr(t_set *set)
{
	ft_memset(set->bi_dec_arr.dec_binary, 0, 1074);
	ft_memset(set->bi_dec_arr.dec_five_mul, 0, 1074);
	(set->bi_dec_arr.dec_five_mul)[0] = 5;
	ft_memset(set->bi_dec_arr.dec_result, 0, 1074);
	return ;
}

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
			if ((((set->bi_dec_arr.dec_five_mul[j] * 5) % 10) + round) < 10)
			{
				(set->bi_dec_arr.dec_five_mul)[j + 1] = ((set->bi_dec_arr.dec_five_mul[j] * 5) % 10) + round;
				round = 0;
			}
			else
			{
				(set->bi_dec_arr.dec_five_mul)[j + 1] = (((set->bi_dec_arr.dec_five_mul[j] * 5) % 10) + round) % 10;
				round = (((set->bi_dec_arr.dec_five_mul[j] * 5) % 10) + round) / 10;
			}
			round += (set->bi_dec_arr.dec_five_mul[j] * 5) / 10;
			set->bi_dec_arr.dec_five_mul[j--] = round;
		}
	}
	return ;
}

void	ft_bi_decimal_arr_put_result(t_set *set)
{
	int	i = 0;
	int j = 0;
	int	round = 0;

	while (i < 1074)
	{
		j = i + 1;
		if (set->bi_dec_arr.dec_binary[i] == 1)
		{
			while (j >= 0)
			{
				if ((set->bi_dec_arr.dec_result[j] + set->bi_dec_arr.dec_five_mul[j] + round) < 10)
				{
					set->bi_dec_arr.dec_result[j] = set->bi_dec_arr.dec_result[j] + set->bi_dec_arr.dec_five_mul[j] + round;
					round = 0;
				}
				else
				{
					set->bi_dec_arr.dec_result[j] = (set->bi_dec_arr.dec_result[j] + set->bi_dec_arr.dec_five_mul[j] + round) % 10;
					round = 1;
				}
				j--;
			}
		}
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
	set->exp = dbl.bitfield.exponent - (int)BIAS;
	temp = dbl.bitfield.mantissa;
	if (set->exp >= 0)
	{
		temp <<= (set->exp);
		while (i < 52)
		{
			(set->bi_dec_arr.dec_binary)[i] = ((temp >> (51 - i)) & 1) ? 1 : 0;
			++i;
		}
	}
	else
	{
		temp |= one;
		(set->exp) *= (-1);
		while (i < 53)
			(set->bi_dec_arr.dec_binary)[(set->exp)++ - 1] = ((temp >> (52 - i++)) & 1) ? 1 : 0;
	}
	return ;
}

void	ft_bi_decimal_arr(t_set *set,t_double dbl)
{
	ft_bi_decimal_arr_init_arr(set);
	ft_bi_decimal_arr_put_binary(set, dbl);
	ft_bi_decimal_arr_put_result(set);
	return ;
}

int		ft_print_double(t_set *set)
{
	t_double dbl;

	dbl.dnum = va_arg(*(set->args), double);
	ft_bi_decimal_arr(set, dbl);

	int i = 0;
	while (i < 1074)
	{
		printf("%d", (set->bi_dec_arr.dec_binary)[i++]);
	}
	printf("\n");
	i = 0;
	while (i < 1074)
	{
		printf("%d", (set->bi_dec_arr.dec_result)[i++]);
	}

	return (1);
}
