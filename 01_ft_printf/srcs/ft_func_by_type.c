/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_by_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:03:05 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/03 18:53:59 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// datatype별로 출력하는 방식이 다르기 때문에 각 다른 함수로 보내주는 길목 기능.
int	ft_func_by_specifier(t_set *set)
{
	int	ret;

	ret = 1;
	if (set->specifier == 'd' || set->specifier == 'i')
		ft_print_int(set);
	else if (set->specifier == 'c')
		ret = ft_print_char(set) ? 1 : 0;
	else if (set->specifier == 's')
		ret = ft_print_str(set) ? 1 : 0;
	else if (set->specifier == 'u')
		ret = ft_print_uint(set) ? 1 : 0;
	else if (set->specifier == 'x' || set->specifier == 'X')
		ret = ft_print_hex(set) ? 1 : 0;
	else if (set->specifier == 'p')
		ret = ft_print_ptr(set) ? 1 : 0;
	else if (set->specifier == '%')
		ret = ft_print_per(set) ? 1 : 0;
	return (ret);
}
