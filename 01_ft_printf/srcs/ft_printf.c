/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:33:51 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/26 21:39:09 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int		ft_count_argsize(va_list args)
// {

// }

// int		ft_width_length(const char *str)
// {

// }

// int	is_precision(char chr)
// {

// }

// �̹� conversion�� datatype�� üũ�Ͽ� ft_conversion���� �����ش�.
// char	ft_check_specifier(const char *str)
// {
// 	char	*check_type;

// 	while (!ft_strchr(SPECIFIER, *str))
// 		str++;
// 	check_type = ft_strchr(SPECIFIER, *str);
// 	return (*check_type);
// }





// ft_printf ��ü. ���������� ��µǴ� ���ڿ��� ���̸� res�� ��� retrun.
int		ft_printf(const	char *str, ...)
{
	va_list	ap;
	int		res;
	t_set	*set;

	set = NULL;
	if (!ft_init_set(str, set))
		return (0);
	va_start(set->args, str);
	if ((res = ft_parse_check(set)) == -1)
		return (-1);
	va_end(ap);
	return (res);
}
