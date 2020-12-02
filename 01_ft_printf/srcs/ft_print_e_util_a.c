/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e_util_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:29:23 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 17:10:40 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_check_bankers_rounding_for_e(t_set *set, char *temp, int i)
{
	if (temp[i] != 5)
		return (0);
	++i;
	while (i < set->integer_len + 1074)
	{
		if (temp[i++] != 0)
			return (0);
	}
	return (1);
}

void		ft_count_exp(t_set *set, t_double dbl)
{
	int	i;

	i = 0;
	if (set->exp == -1023 && dbl.bitfield.mantissa == 0)
	{
		set->cnt_exp = 0;
		return ;
	}
	if (!set->input_data[0])
	{
		while (!set->input_data[i++])
			set->cnt_exp--;
	}
	else
		set->cnt_exp = set->integer_len - 1;
	return ;
}

static void	ft_addition_e_data(t_set *set, char *temp, int i)
{
	int j;

	i--;
	j = set->precision + 1;
	while ((j >= 0) && (i >= 0))
	{
		if ((set->input_data[j] = temp[i] + set->rounding) >= 10)
		{
			set->input_data[j] = set->input_data[j] % 10;
			set->rounding = 1;
		}
		else
			set->rounding = 0;
		set->input_data[j] += '0';
		j--;
		i--;
	}
	if (i == -1 && j == 0)
		set->input_data[0] = set->rounding == 1 ? '1' : '0';
	return ;
}

int			ft_apply_precision_to_e(t_set *set, t_double dbl)
{
	char	*temp;
	int		i;

	ft_count_exp(set, dbl);
	temp = set->input_data;
	if (!(set->input_data = \
	(char *)malloc(sizeof(char) * (set->precision + 3))))
		return (0);
	set->input_data[set->precision + 2] = '\0';
	i = !temp[0] ? -set->cnt_exp + set->precision + 1 : set->precision + 1;
	if (ft_check_bankers_rounding_for_e(set, temp, i))
	{
		if (temp[0] == 0 && i == 1 && set->precision == 0)
		{
			i++;
			set->cnt_exp = -1;
		}
		else if (temp[i - 1] % 2 == 1)
			set->rounding = 1;
	}
	else if (temp[i] >= 5)
		set->rounding = 1;
	ft_addition_e_data(set, temp, i);
	free(temp);
	return (1);
}
