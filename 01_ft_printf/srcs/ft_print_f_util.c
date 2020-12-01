/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:08:16 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 02:09:18 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_bankers_rounding_for_f(t_set *set)
{
	int i;

	i = set->precision + 1;
	if (set->bi_dece.dece_res[set->precision] != 5)
		return (0);
	while (i < 1074)
	{
		if (set->bi_dece.dece_res[i] != 0)
			break ;
		i++;
	}
	if (i != 1074)
		return (0);
	return (1);
}

int		ft_rounding_in_int(t_set *set)
{
	char	*temp;

	temp = set->input_data;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (set->arglen + 2))))
		return (0);
	set->input_data[0] = '1';
	set->input_data[set->arglen + 1] = '\0';
	ft_strlcpy(set->input_data + 1, temp, set->arglen + 1);
	set->arglen = ft_strlen(set->input_data);
	free(temp);
	return (1);
}

int		ft_fill_dec_without_point(t_set *set)
{
	free(set->input_data);
	if (!(set->input_data = (char *)malloc(sizeof(char) * set->arglen)))
		return (0);
	set->input_data[set->arglen - 1] = '\0';
	if (ft_check_bankers_rounding_for_f(set))
		set->rounding = (set->bi_inte.inte_res[308] % 2) == 1 ? 1 : 0;
	else if (set->bi_dece.dece_res[0] >= 5)
		set->rounding = 1;
	return (1);
}

void	ft_bankers_rounding_for_f(t_set *set)
{
	if (set->precision == 0)
		set->rounding = (set->bi_inte.inte_res[308] % 2) == 1 ? 1 : 0;
	else
		set->rounding = \
		(set->bi_dece.dece_res[set->precision-- - 1] % 2) == 1 ? 1 : 0;
	return ;
}
