/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:34:38 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/04 16:29:07 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_apply_precision_to_uxpo(t_set *set)
{
	char	*temp;
	int		index;

	if (set->f_point == 1 && set->precision == 0 && *set->input_data == '0')
	{
		*set->input_data = '\0';
		set->arglen = 0;
	}
	else if (set->precision > set->arglen)
	{
		index = 0;
		temp = set->input_data;
		if (!(set->input_data = (char *)malloc(sizeof(char) * (set->precision + 1))))
			return (0);
		set->input_data[set->precision] = '\0';
		while ((set->precision)-- > set->arglen)
			ft_memcpy(set->input_data + index++, "0", 1);
		ft_strlcpy(set->input_data + index, temp, set->arglen + 1);
		set->arglen = ft_strlen(set->input_data);
		free(temp);
	}
	return (1);
}
