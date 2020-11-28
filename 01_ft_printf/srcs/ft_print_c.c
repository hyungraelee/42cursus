/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:20:09 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/29 02:51:28 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstr_of_char(char *s, int fd, int size)
{
	if (!s)
		return ;
	write(fd, s, size);
	return ;
}

static void	ft_print_c_left(t_set *set, unsigned char chr, int size)
{
	char	*temp;

	temp = set->print_buf;
	temp = (char *)ft_memcpy(temp, &chr, 1);
	temp++;
	while (size-- > 1)
	{
		temp = (char *)ft_memcpy(temp, " ", 1);
		temp++;
	}
	*temp = '\0';
	return ;
}

static void	ft_print_c_zero(t_set *set, char chr, int size)
{
	char	*temp;

	temp = set->print_buf;
	while (size-- > 1)
	{
		temp = (char *)ft_memcpy(temp, "0", 1);
		temp++;
	}
	temp = (char *)ft_memcpy(temp, &chr, 1);
	temp++;
	*temp = '\0';
	return ;
}

static void	ft_print_c_wid(t_set *set, char chr, int size)
{
	char	*temp;

	temp = set->print_buf;
	while (size-- > 1)
	{
		temp = (char *)ft_memcpy(temp, " ", 1);
		temp++;
	}
	temp = (char *)ft_memcpy(temp, &chr, 1);
	temp++;
	*temp = '\0';
	return ;
}

int			ft_print_c(t_set *set)
{
	unsigned char	chr;
	int				size;

	size = set->width > 0 ? set->width : 1;
	set->arglen = size;
	if (!(set->print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	chr = va_arg(*(set->args), int);
	if (set->f_minus == 1)
		ft_print_c_left(set, chr, size);
	else
	{
		if (set->f_zero == 1)
			ft_print_c_zero(set, chr, size);
		else
			ft_print_c_wid(set, chr, size);
	}
	ft_putstr_of_char(set->print_buf, 1, set->arglen);
	set->print_size += set->arglen;
	free(set->print_buf);
	return (1);
}
