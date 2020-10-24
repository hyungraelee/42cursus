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

// datatype별로 출력하는 방식이 다르기 때문에 각 다른 함수로 보내주는 길목 기능.
void	ft_func_by_specifier(va_list args, t_set *set)
{
	if (set->specifier == 'd' || set->specifier == 'i')
		ft_print_integer(args, set);
}


// conversion 기능의 첫번째 함수.
// 여기서 flag, width, precision등을 체크 함.
void	ft_conversion(va_list args, t_set *set)
{
	ft_func_by_specifier(args, set);
}
