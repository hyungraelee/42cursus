/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e_util_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:50:52 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 20:25:53 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_fill_inputdata(t_set *set)
{
	int i;
	int j;

	i = 0;
	j = set->integer_len;
	while (i < set->integer_len)
	{
		set->input_data[i] = set->bi_inte.inte_res[309 - j];
		i++;
		j--;
	}
	j = 0;
	while (i < set->integer_len + 1074)
	{
		set->input_data[i] = set->bi_deci.deci_res[j];
		i++;
		j++;
	}
	return ;
}

static void	ft_fill_point_check_round(t_set *set, char *temp, int *i)
{
	if (temp[0] == '0')
	{
		set->input_data[0] = temp[1];
		(*i)++;
	}
	else
	{
		set->cnt_exp++;
		set->input_data[0] = temp[0];
	}
	return ;
}

int			ft_fill_point(t_set *set)
{
	char	*temp;
	int		size;
	int		i;
	int		j;

	size = set->arglen;
	temp = set->input_data;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	set->input_data[size] = '\0';
	i = 1;
	ft_fill_point_check_round(set, temp, &i);
	if (!set->precision && !set->f_hash)
	{
		set->input_data[1] = '\0';
		free(temp);
		return (1);
	}
	set->input_data[1] = '.';
	j = 2;
	while (j < size)
		set->input_data[j++] = temp[i++];
	free(temp);
	return (1);
}

void		ft_exponent_two_figures(t_set *set, int i)
{
	if (set->cnt_exp < 0)
		set->cnt_exp *= -1;
	set->input_data[i++] = set->cnt_exp / 10 + '0';
	set->input_data[i++] = set->cnt_exp % 10 + '0';
	return ;
}
