/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_by_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:03:05 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/29 01:40:25 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_func_by_specifier(t_set *set)
{
	if (set->specifier == 'd' || set->specifier == 'i')
		return (ft_print_di(set));
	else if (set->specifier == 'c')
		return (ft_print_c(set));
	else if (set->specifier == 's')
		return (ft_print_s(set));
	else if (set->specifier == 'u')
		return (ft_print_u(set));
	else if (set->specifier == 'x' || set->specifier == 'X')
		return (ft_print_x(set));
	else if (set->specifier == 'p')
		return (ft_print_p(set));
	else if (set->specifier == '%')
		return (ft_print_pct(set));
	else if (set->specifier == 'o')
		return (ft_print_o(set));
	else if (set->specifier == 'n')
		return (ft_print_n(set));
	else if (set->specifier == 'f')
		return (ft_print_f(set));
	else if (set->specifier == 'e')
		return (ft_print_e(set));
	else if (set->specifier == 'g')
		return (ft_print_g(set));
	return (0);
}
