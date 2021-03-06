/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:10:23 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/30 20:31:06 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_str_arg(t_set *set)
{
	size_t	size;
	size_t	temp;

	size = set->arglen;
	temp = 0;
	if (!(set->print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_strlcpy(set->print_buf, set->input_data, set->arglen + 1);
	set->print_buf[size] = '\0';
	return (1);
}

static int	ft_print_str_wid(t_set *set)
{
	size_t	size;
	size_t	temp;

	size = set->width;
	temp = 0;
	if (!(set->print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (set->f_minus == 1)
	{
		temp = ft_strlcpy(set->print_buf, set->input_data, set->arglen + 1);
		while ((set->width)-- - set->arglen)
			ft_memcpy(set->print_buf + temp++, " ", 1);
	}
	else
	{
		while ((set->width)-- - set->arglen)
			ft_memcpy(set->print_buf + temp++, " ", 1);
		ft_strlcpy(set->print_buf + temp, set->input_data, set->arglen + 1);
	}
	set->print_buf[size] = '\0';
	return (1);
}

static void	ft_apply_precision_to_s(t_set *set)
{
	if (set->f_point && set->precision < set->arglen)
	{
		set->input_data = (char *)ft_memmove(set->input_data,\
		set->input_data, set->precision);
		set->input_data[set->precision] = '\0';
		set->arglen = ft_strlen(set->input_data);
	}
	return ;
}

static int	ft_input_data_s(t_set *set)
{
	char	*str;

	str = va_arg(*(set->args), char *);
	if (str == NULL)
	{
		if (!(set->input_data = ft_strdup("(null)")))
			return (0);
	}
	else
	{
		if (!(set->input_data = ft_strdup(str)))
			return (0);
	}
	set->arglen = ft_strlen(set->input_data);
	return (1);
}

int			ft_print_s(t_set *set)
{
	if (!(ft_input_data_s(set)))
		return (0);
	ft_apply_precision_to_s(set);
	if (set->width > set->arglen)
	{
		if (!(ft_print_str_wid(set)))
			return (0);
	}
	else
	{
		if (!(ft_print_str_arg(set)))
			return (0);
	}
	ft_put_and_free(set);
	return (1);
}
