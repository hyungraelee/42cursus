/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:39:20 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/25 22:18:46 by hyunlee          ###   ########.fr       */
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

void	ft_bi_integer_arr_multiple_two(t_set *set)
{
	int	round = 0;
	int i = 0;
	int temp;

	while (i < set->mul_len)
	{
		temp = (set->bi_int_arr.int_two_mul[i] * 2) + round;
		if (temp >= 10)
		{
			set->bi_int_arr.int_two_mul[i] = temp % 10;
			round = temp / 10;
		}
		else
		{
			set->bi_int_arr.int_two_mul[i] = temp;
			round = 0;
		}
		i++;
	}
	if (round == 1)
	{
		set->bi_int_arr.int_two_mul[i] = 1;
		set->mul_len++;
	}
	return ;
}

void	ft_bi_integer_reverse_arr(t_set *set)
{
	char	temp[309];
	int		i;

	i = 0;
	ft_memmove(temp, set->bi_int_arr.int_result, 309);
	ft_memset(set->bi_int_arr.int_result, 0, 309);
	while (i < set->integer_len)
	{
		set->bi_int_arr.int_result[308 - i] = temp[i];
		i++;
	}
	return ;
}

void	ft_bi_integer_arr_put_result(t_set *set)
{
	int		i = 1024;
	int		j = 0;
	int		round = 0;

	while (i-- > (1023 - set->exp))
	{
		if (set->bi_int_arr.int_binary[i] == 1)
		{
			j = 0;
			while (j < set->mul_len + 1)
			{
				if ((set->bi_int_arr.int_result[j] + set->bi_int_arr.int_two_mul[j] + round) < 10)
				{
					set->bi_int_arr.int_result[j] = set->bi_int_arr.int_result[j] + set->bi_int_arr.int_two_mul[j] + round;
					round = 0;
				}
				else
				{
					set->bi_int_arr.int_result[j] = (set->bi_int_arr.int_result[j] + set->bi_int_arr.int_two_mul[j] + round) % 10;
					round = 1;
				}
				j++;
			}
			set->integer_len = set->bi_int_arr.int_result[set->mul_len] != 0 ? set->mul_len + 1 : set->mul_len;
		}
		ft_bi_integer_arr_multiple_two(set);
	}
// int k=0;
// while(k<309)
// 	printf("%d", set->bi_int_arr.int_result[k++]);
// printf("\n");
	ft_bi_integer_reverse_arr(set);
// k=0;
// while(k<309)
// 	printf("%d", set->bi_int_arr.int_two_mul[k++]);
// printf("\n");
// k=0;
// while(k<309)
// 	printf("%d", set->bi_int_arr.int_result[k++]);
// printf("\n");
	return ;
}

void	ft_bi_integer_arr_put_binary(t_set *set,t_double dbl)
{
	int	i;
	unsigned long	temp;

	i = 0;
	set->exp = dbl.bitfield.exponent - (int)BIAS;
	temp = dbl.bitfield.mantissa;
	if (set->exp >= 0)
	{
		set->bi_int_arr.int_binary[1024 - set->exp - 1] = 1;
		while (i < set->exp && i < 52)
		{
			set->bi_int_arr.int_binary[1024 - set->exp + i] = ((temp >> (51 - i)) & 1) ? 1 : 0;
			i++;
		}
	}

// int k=0;
// while(k<1024)
// 	printf("%d", set->bi_int_arr.int_binary[k++]);
	return ;
}

void	ft_bi_init_arr(t_set *set)
{
	ft_memset(set->bi_dec_arr.dec_binary, 0, 1074);
	ft_memset(set->bi_dec_arr.dec_five_mul, 0, 1074);
	(set->bi_dec_arr.dec_five_mul)[0] = 5;
	ft_memset(set->bi_dec_arr.dec_result, 0, 1074);
	ft_memset(set->bi_int_arr.int_binary, 0, 1024);
	ft_memset(set->bi_int_arr.int_two_mul, 0, 309);
	(set->bi_int_arr.int_two_mul)[0] = 1;
	ft_memset(set->bi_int_arr.int_result, 0, 309);
	return ;
}

void	ft_make_bigint_arr(t_set *set,t_double dbl)
{
	// if (dbl.bitfield.exponent == 2047)
	// {
	// 	if (dbl.bitfield.mantissa == 0)
	// 		dbl.bitfield.sign == 0 ?
	// }
	ft_bi_init_arr(set);
	ft_bi_decimal_arr_put_binary(set, dbl);
	ft_bi_decimal_arr_put_result(set);
	ft_bi_integer_arr_put_binary(set, dbl);
	ft_bi_integer_arr_put_result(set);
	return ;
}
