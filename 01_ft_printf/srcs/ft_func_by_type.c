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

// datatype별로 출력하는 방식이 다르기 때문에 각 다른 함수로 보내주는 길목 기능.
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


// conversion 기능의 첫번째 함수.
// 여기서 flag, width, precision등을 체크 함.
// void	ft_conversion(t_set *set)
// {
// 	ft_func_by_specifier(set);
// }
