/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_by_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:03:05 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/02 21:38:15 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// datatype���� ����ϴ� ����� �ٸ��� ������ �� �ٸ� �Լ��� �����ִ� ��� ���.
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
	else if (set->specifier == 'x')
		ret = ft_print_hex(set) ? 1 : 0;
	return (ret);
}
