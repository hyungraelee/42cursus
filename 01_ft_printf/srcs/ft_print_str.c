/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:10:23 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/01 20:20:46 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_str_arg(t_set *set)
{
	size_t	size;
	size_t	temp;
	char	*print_buf;

	size = set->arglen;
	temp = 0;
	if (!(print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (-1);
	ft_strlcpy(print_buf, set->input_data, set->arglen + 1);
	print_buf[size] = '\0';
	ft_putstr_fd(print_buf, 1);
	free(print_buf);
	return (1);
}

int		ft_print_str_wid(t_set *set)
{
	size_t	size;
	size_t	temp;
	char	*print_buf;

	size = set->width;
	temp = 0;
	if (!(print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (-1);
	if (set->f_minus == 1)
	{
		temp = ft_strlcpy(print_buf, set->input_data, set->arglen + 1);
		while ((set->width)-- - set->arglen)
			ft_memcpy(print_buf + temp++, " ", 1);
	}
	else
	{
		while ((set->width)-- - set->arglen)
			ft_memcpy(print_buf + temp++, " ", 1);
		ft_strlcpy(print_buf + temp, set->input_data, set->arglen + 1);
	}
	print_buf[size] = '\0';
	ft_putstr_fd(print_buf, 1);
	free(print_buf);
	return (1);
}

void	ft_apply_precision(t_set *set)
{
	if (set->f_point && set->precision < set->arglen)
	{
		set->input_data = (char *)ft_memmove(set->input_data, set->input_data, set->precision);
		set->input_data[set->precision] = '\0';
		set->arglen = ft_strlen(set->input_data);
	}
	return ;
}

int		ft_input_data(t_set *set)
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

int		ft_print_str(t_set *set)
{
	if (!ft_input_data(set))
		return (-1);
	ft_apply_precision(set);
	if (set->width > set->arglen)
	{
		if (ft_print_str_wid(set) == -1)
			return (-1);
	}
	else
	{
		if (ft_print_str_arg(set) == -1)
			return (-1);
	}
	free(set->input_data);
	return (1);
}
