/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:18:45 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 02:53:35 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_input_infnan(t_set *set, t_double dbl)
{
	if (dbl.bitfield.mantissa == 0)
		set->input_data = ft_strdup("inf");
	else
	{
		set->input_data = ft_strdup("nan");
		set->nan = 1;
	}
	set->infnan = 1;
	set->arglen = ft_strlen(set->input_data);
	return ;
}

int		ft_print_arg(t_set *set)
{
	size_t	size;

	size = set->arglen;
	if (!(set->print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_strlcpy(set->print_buf, set->input_data, set->arglen + 1);
	set->print_buf[size] = '\0';
	return (1);
}

int		ft_print_wid_double(t_set *set)
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
	else if (set->f_zero == 1 && !set->infnan)
	{
		if (*(set->input_data) == '-' || *(set->input_data) == '+' || *(set->input_data) == ' ')
			set->print_buf[temp++] = *(set->input_data);
		while ((set->width)-- - set->arglen)
			ft_memcpy(set->print_buf + temp++, "0", 1);
		if (*(set->input_data) == '-' || *(set->input_data) == '+' || *(set->input_data) == ' ')
			ft_strlcpy(set->print_buf + temp, set->input_data + 1, set->arglen);
		else
			ft_strlcpy(set->print_buf + temp, set->input_data, set->arglen + 1);
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

void	ft_put_and_free(t_set *set)
{
	ft_putstr_fd(set->print_buf, 1);
	set->print_size += ft_strlen(set->print_buf);
	free(set->input_data);
	free(set->print_buf);
	return ;
}
