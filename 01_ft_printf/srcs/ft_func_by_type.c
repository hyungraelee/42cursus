/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_by_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:03:05 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/28 03:56:01 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// datatype���� ����ϴ� ����� �ٸ��� ������ �� �ٸ� �Լ��� �����ִ� ��� ���.
int	ft_func_by_specifier(t_set *set)
{
	if (set->specifier == 'd' || set->specifier == 'i')
		ft_print_int(set);
	else if (set->specifier == 'c')
		if (ft_print_char(set) == -1)
			return (-1);
	else if (set->specifier == 's')
		if (ft_print_str(set) == -1)
			return (-1);

	return (1);
}


// conversion ����� ù��° �Լ�.
// ���⼭ flag, width, precision���� üũ ��.
// void	ft_conversion(t_set *set)
// {
// 	ft_func_by_specifier(set);
// }
