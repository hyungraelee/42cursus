/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 15:53:01 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/26 21:33:40 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_set	*ft_init_set(const char *str, t_set *set)
{
	if (!(set = (t_set *)malloc(sizeof(t_set) * 1)))
		return (0);
	ft_reset_set(set);
	set->str = str;
	return (set);
}

//set구조체 멤버들의 값을 reset.
void	ft_reset_set(t_set *set)
{
	set->f_minus = 0;
	set->f_zero = 0;
	set->f_point = 0;
	set->width = 0;
	set->precision = 0;
	set->specifier = 0;
	set->print_size = 0;
	set->arglen = 0;
	return ;
}
