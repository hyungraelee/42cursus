/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_by_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:03:05 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/11 21:23:46 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// datatype별로 출력하는 방식이 다르기 때문에 각 다른 함수로 보내주는 길목 기능.
int	ft_func_by_specifier(t_set *set)
{
	if (set->specifier == 'd' || set->specifier == 'i')
		return (ft_print_int(set));
	else if (set->specifier == 'c')
		return (ft_print_char(set));
	else if (set->specifier == 's')
		return (ft_print_str(set));
	else if (set->specifier == 'u')
		return (ft_print_uint(set));
	else if (set->specifier == 'x' || set->specifier == 'X')
		return (ft_print_hex(set));
	else if (set->specifier == 'p')
		return (ft_print_ptr(set));
	else if (set->specifier == '%')
		return (ft_print_per(set));
	else if (set->specifier == 'o')
		return (ft_print_oct(set));
	else if (set->specifier == 'n')
		return (ft_print_nbyte(set));
	else if (set->specifier == 'f')
		return (ft_print_double(set));
	return (0);
}
