/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:10:23 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/29 21:59:21 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_str_pre(t_set *set, char *str)
{
	size_t	size;
	size_t	temp;
	char	*print_buf;

	size = set->width > set->arglen ? set->width : set->arglen;
	temp = 0;
	if (!(print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (-1);
	if (set->f_minus == 1)
	{
		if (set->width > set->arglen)
		{
			temp = ft_strlcpy(print_buf, str, set->arglen);
			while ((set->width)-- - set->arglen > 0)
				ft_memcpy(print_buf + temp++, " ", 1);
		}
		else
			ft_strlcpy(print_buf, str, set->arglen);
	}
	else
	{
		if (set->width > set->arglen)
		{
			while ((set->width)-- - set->arglen > 0)
				ft_memcpy(print_buf + temp++, " ", 1);
			ft_strlcpy(print_buf + temp, str, set->arglen);
		}
		else
			ft_strlcpy(print_buf, str, set->arglen);
	}
	print_buf[size] = '\0';
	ft_putstr_fd(print_buf, 1);
	free(print_buf);
	return (1);
}

int		ft_print_str_arg(t_set *set, char *str)
{
	size_t	size;
	size_t	temp;
	char	*print_buf;

	if (set->width == 0 && set->precision == 0)
	{
		ft_putstr_fd(str, 1);
		return (1);
	}
	else
		size = set->width > set->precision ? set->width : set->precision;
	temp = 0;
	if (!(print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (-1);
	if (set->f_minus == 1)
	{
		if (set->width > set->precision)
		{
			ft_strlcpy(print_buf, str, set->precision);
			temp = set->precision;
			while ((set->width)-- - set->precision)
				ft_memcpy(print_buf + temp++, " ", 1);
		}
		else
			ft_strlcpy(print_buf, str, set->precision);
	}
	else
	{
		if (set->width > set->precision)
		{
			while (set->width - set->precision)
				ft_memcpy(print_buf + temp++, " ", 1);
			ft_strlcpy(print_buf + temp, str, set->precision);
		}
		else
			ft_strlcpy(print_buf, str, set->precision);
	}
	print_buf[size] = '\0';
	ft_putstr_fd(print_buf, 1);
	free(print_buf);
	return (-1);
}

int		ft_print_str_wid(t_set *set, char *str)
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
		if (set->precision > set->arglen)
		{
			temp = ft_strlcpy(print_buf, str, set->arglen);
			while ((set->width)-- - set->arglen)
				ft_memcpy(print_buf + temp++, " ", 1);
		}
		else
		{
			ft_strlcpy(print_buf, str, set->precision);
			temp = set->precision;
			while ((set->width)-- - set->precision)
				ft_memcpy(print_buf + temp++, " ", 1);
		}
	}
	else
	{
		while ((set->width)-- - set->precision)
			ft_memcpy(print_buf + temp++, " ", 1);
		set->precision > set->arglen ? ft_strlcpy(print_buf + temp, str, set->arglen) : \
			ft_strlcpy(print_buf + temp, str, set->precision);
	}
	print_buf[size] = '\0';
	ft_putstr_fd(print_buf, 1);
	free(print_buf);
	return (1);
}

int		ft_print_str(t_set *set)
{
	char	*str;

	str = va_arg(*(set->args), char *);
	set->arglen = ft_strlen(str);
	if (set->precision > set->arglen && set->precision > set->width)
	{
		if (ft_print_str_pre(set, str) == -1)
			return (-1);
	}
	else if (set->arglen > set->width && set->arglen > set->precision)
	{
		if (ft_print_str_arg(set, str) == -1)
			return (-1);
	}
	else if (set->width > set->arglen && set->width > set->precision)
	{
		if (ft_print_str_wid(set, str) == -1)
			return (-1);
	}
	return (1);
}
