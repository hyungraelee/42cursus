/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:54:59 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 02:27:02 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fill_printbuf(t_set *set)
{
	int i;

	i = 0;
	if (set->f_minus == 1)
	{
		set->print_buf[i++] = '%';
		while ((set->width)-- > 1)
			ft_memcpy(set->print_buf + i++, " ", 1);
	}
	else if (set->f_zero == 1)
	{
		while ((set->width)-- > 1)
			ft_memcpy(set->print_buf + i++, "0", 1);
		set->print_buf[i] = '%';
	}
	else
	{
		while ((set->width)-- > 1)
			ft_memcpy(set->print_buf + i++, " ", 1);
		set->print_buf[i] = '%';
	}
	return ;
}

static int	ft_print_pct_wid(t_set *set)
{
	int	size;

	size = set->width;
	if (!(set->print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_fill_printbuf(set);
	set->print_buf[size] = '\0';
	return (1);
}

int			ft_print_pct(t_set *set)
{
	if (set->width > 1)
	{
		if (!(ft_print_pct_wid(set)))
			return (0);
		ft_putstr_fd(set->print_buf, 1);
		set->print_size += ft_strlen(set->print_buf);
		free(set->print_buf);
	}
	else
	{
		ft_putchar_fd('%', 1);
		set->print_size++;
	}
	return (1);
}
