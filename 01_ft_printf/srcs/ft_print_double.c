/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:16:10 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/10 19:05:32 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_bigint_arr(t_set *set, t_double dnumb)
{
	ft_memset(set->bigint.num, 0, 1074);
	ft_memset(set->bigint.five, 0, 1074);
	(set->bigint.five)[0] = 5;
	ft_memset(set->bigint.result, 0, 1074);
	set->bigint.len = 0;
	return ;
}

void	ft_bigint_decimal(t_set *set,t_double dnumb)
{
	int	exp;
	int i;
	unsigned long	one;
	unsigned long	temp;

	ft_init_bigint_arr(set, dnumb);
	i = 0;
	one = 1;
	one <<= 52;
	exp = dnumb.bitfield.exponent - (int)BIAS;
	temp = dnumb.bitfield.mantissa;
	if (exp >= 0)
	{
		while (i < 52)
		{
			(set->bigint.num)[i] = ((temp >> (51 - i)) & 1) ? 1 : 0;
			++i;
		}
	}
	else
	{
		temp |= one;
		exp *= (-1);
		while (i < 53)
			(set->bigint.num)[exp++ - 1] = ((temp >> (52 - i++)) & 1) ? 1 : 0;
	}

	i = 0;
	while (i < 1074)
	{
		printf("%d", (set->bigint.num)[i++]);
	}


	return ;
}

int		ft_print_double(t_set *set, t_double dnumb)
{
	dnumb.dnum = va_arg(*(set->args), double);
	ft_bigint_decimal(set, dnumb);

	return (1);
}
