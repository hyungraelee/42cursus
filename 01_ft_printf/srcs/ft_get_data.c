/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:14:40 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/30 20:43:44 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_data_u(t_set *set, unsigned long long *num)
{
	if (set->l_l == 1)
		*num = va_arg(*(set->args), unsigned long);
	else if (set->l_l >= 2)
		*num = va_arg(*(set->args), unsigned long long);
	else if (set->l_h == 1)
		*num = (unsigned short)va_arg(*(set->args), unsigned int);
	else if (set->l_h >= 2)
		*num = (unsigned char)va_arg(*(set->args), unsigned int);
	else
		*num = va_arg(*(set->args), unsigned int);
	return ;
}

void	ft_get_data_d(t_set *set, long long *num)
{
	if (set->l_l == 1)
		*num = va_arg(*(set->args), long);
	else if (set->l_l >= 2)
		*num = va_arg(*(set->args), long long);
	else if (set->l_h == 1)
		*num = (short)va_arg(*(set->args), int);
	else if (set->l_h >= 2)
		*num = (char)va_arg(*(set->args), int);
	else
		*num = va_arg(*(set->args), int);
	return ;
}
