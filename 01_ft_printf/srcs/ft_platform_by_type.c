/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_platform_by_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:03:05 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/24 16:03:25 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// datatype���� ����ϴ� ����� �ٸ��� ������ �� �ٸ� �Լ��� �����ִ� ��� ���.
void	ft_func_by_specifier(va_list args, t_set *set)
{
	if (set->specifier == 'd' || set->specifier == 'i')
		ft_print_integer(args, set);
}


// conversion ����� ù��° �Լ�.
// ���⼭ flag, width, precision���� üũ ��.
void	ft_conversion(va_list args, t_set *set)
{
	ft_func_by_specifier(args, set);
}
