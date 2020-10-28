/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:20:09 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/28 05:39:02 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_char(t_set *set)
{
	unsigned char	chr;
	char			*print_buf;
	char			*temp;
	size_t			size;

	size = set->width > 0 ? set->width : 1;
	if (!(print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (-1);
	set->print_size += size;
	temp = print_buf;
	chr = va_arg(*(set->args), int);
	if (set->f_minus == 1)
	{
		temp = (char *)ft_memcpy(temp, &chr, 1);
		temp++;
		while (size-- > 1)
		{
			temp = (char *)ft_memcpy(temp, " ", 1);
			temp++;
		}
	}
	else
	{
		if (set->f_zero == 1)
		{
			while (size-- > 1)
			{
				temp = (char *)ft_memcpy(temp, "0", 1);
				temp++;
			}
			temp = (char *)ft_memcpy(temp, &chr, 1);
		}
		else
		{
			while (size-- > 1)
			{
				temp = (char *)ft_memcpy(temp, " ", 1);
				temp++;
			}
			temp = (char *)ft_memcpy(temp, &chr, 1);
		}
		temp++;
	}
	*temp = '\0';
	ft_putstr_fd(print_buf, 1);
	free(print_buf);
	return (1);
}
