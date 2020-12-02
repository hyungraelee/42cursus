/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:34:36 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 20:30:20 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_apply_hash_to_p(t_set *set)
{
	char	*temp;
	int		size;

	temp = set->input_data;
	size = set->arglen + 2;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	set->input_data[size] = '\0';
	set->input_data[0] = '0';
	set->input_data[1] = 'x';
	ft_strlcpy(set->input_data + 2, temp, set->arglen + 1);
	set->arglen = ft_strlen(set->input_data);
	free(temp);
	return (1);
}

int			ft_print_p(t_set *set)
{
	unsigned long long	num;

	num = (unsigned long long)va_arg(*(set->args), void *);
	if (!(ft_convert_hex(set, num)))
		return (0);
	if (!(ft_apply_precision_to_uxpo(set)))
		return (0);
	if (!(ft_apply_hash_to_p(set)))
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
