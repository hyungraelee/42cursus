/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:33:51 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/18 22:19:34 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// ft_printf 본체. 최종적으로 출력되는 문자열의 길이를 res에 담아 retrun.
int		ft_printf(const	char *str, ...)
{
	va_list	ap;
	t_set	*set;
	int		res;

	set = NULL;
	if (!(set = ft_init_set(str, set)))
		return (0);
	va_start(ap, str);
	set->args = &ap;
	if ((ft_parse_check(set)) == -1)
		return (-1);
	va_end(ap);
	res = (int)set->print_size;
	free(set);
	return (res);
}
