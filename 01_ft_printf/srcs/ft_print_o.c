/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:21:13 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 16:17:55 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_apply_hash_to_o(t_set *set, unsigned long long num)
{
	char	*temp;
	int		size;

	if (set->f_hash == 1 && num != 0)
	{
		temp = set->input_data;
		size = set->arglen + 1;
		if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
			return (0);
		set->input_data[size] = '\0';
		set->input_data[0] = '0';
		ft_strlcpy(set->input_data + 1, temp, set->arglen + 1);
		set->arglen = ft_strlen(set->input_data);
		free(temp);
	}
	return (1);
}

int		ft_print_o(t_set *set)
{
	unsigned long long	num;

	ft_get_data_u(set, &num);
	if (!(ft_convert_oct(set, num)))
		return (0);
	if (!(ft_apply_precision_to_uxpo(set)))
		return (0);
	if (!(ft_apply_hash_to_o(set, num)))
		return (0);
	if (set->width > set->arglen)
	{
		if (!(ft_print_u_wid(set)))
			return (0);
	}
	else
	{
		if (!(ft_print_arg(set)))
			return (0);
	}
	ft_put_and_free(set);
	return (1);
}
