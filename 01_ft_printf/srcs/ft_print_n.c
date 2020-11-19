/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbyte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:47:39 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/18 22:32:37 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbyte(t_set *set)
{
	if (set->l_l == 1)
		*((long *)va_arg(*(set->args), long *)) = (long)set->print_size;
	else if (set->l_l >= 2)
		*((long long *)va_arg(*(set->args), long long *)) = set->print_size;
	else if (set->l_h == 1)
		*((short *)va_arg(*(set->args), short *)) = (short)set->print_size;
	else if (set->l_h >= 2)
		*((char *)va_arg(*(set->args), char *)) = (char)set->print_size;
	else
		*((int *)va_arg(*(set->args), int *)) = (int)set->print_size;
	return (1);
}
