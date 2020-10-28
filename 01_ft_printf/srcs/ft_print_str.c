/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:10:23 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/28 20:10:23 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(t_set *set)
{
	size_t	size;
	char	*str;
	char	*print_buf;
	char	*temp;

	str = va_arg(*(set->args), char *);
	set->arglen = ft_strlen(str);
	if (set->precision > set->arglen && set->precision > set->width)
		size = set->width > set->arglen ? set->width : set->arglen;
	else if (set->arglen > set->width && set->arglen > set->precision)
		size = set->width;
	else if (set->width > set->arglen && set->width > set->precision)
		size = set->width;
	if (!(print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (-1);
}
