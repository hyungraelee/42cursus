/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:34:38 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 02:52:27 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_apply_precision_to_uxpo(t_set *set)
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
		if (!(set->input_data = \
		(char *)malloc(sizeof(char) * (set->precision + 1))))
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

static int	ft_apply_flag_to_double(t_set *set, t_double dbl)
{
	char	*temp;
	size_t	size;

	size = set->arglen + 1;
	temp = set->input_data;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (dbl.bitfield.sign == 1)
		set->input_data[0] = '-';
	else if (set->f_plus == 1 && dbl.dnum >= 0)
		set->input_data[0] = '+';
	else if (set->f_space == 1 && set->f_plus == 0 && dbl.dnum >= 0)
		set->input_data[0] = ' ';
	ft_strlcpy(set->input_data + 1, temp, size);
	set->input_data[size] = '\0';
	set->arglen = ft_strlen(set->input_data);
	free(temp);
	return (1);
}

int			ft_apply_flag_and_print(t_set *set, t_double dbl)
{
	if ((set->f_plus == 1 || set->f_space == 1 || dbl.bitfield.sign == 1) \
	&& !set->nan)
	{
		if (!(ft_apply_flag_to_double(set, dbl)))
			return (0);
	}
	if (set->width > set->arglen)
	{
		if (!(ft_print_wid_double(set)))
			return (0);
	}
	else
	{
		if (!(ft_print_arg(set)))
			return (0);
	}
	return (1);
}

int			ft_apply_prec_d_pos(t_set *set)
{
	char	*temp;
	int		i;

	i = 0;
	temp = set->input_data;
	if (!(set->input_data = \
	(char *)malloc(sizeof(char) * (set->precision + 1))))
		return (0);
	set->input_data[set->precision] = '\0';
	while ((set->precision)-- > set->arglen)
		ft_memcpy(set->input_data + i++, "0", 1);
	ft_strlcpy(set->input_data + i, temp, set->arglen + 1);
	set->arglen = ft_strlen(set->input_data);
	free(temp);
	return (1);
}

int			ft_apply_prec_d_neg(t_set *set)
{
	char	*temp;
	int		i;

	i = 0;
	temp = set->input_data;
	if (!(set->input_data = \
	(char *)malloc(sizeof(char) * (set->precision + 2))))
		return (0);
	set->input_data[set->precision + 1] = '\0';
	set->input_data[i++] = '-';
	while ((set->precision)-- > (set->arglen - 1))
		ft_memcpy(set->input_data + i++, "0", 1);
	ft_strlcpy(set->input_data + i, temp + 1, set->arglen);
	set->arglen = ft_strlen(set->input_data);
	free(temp);
	return (1);
}
