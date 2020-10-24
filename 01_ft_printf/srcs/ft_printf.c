/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:33:51 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/24 21:02:58 by hyunlee          ###   ########.fr       */
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

// 이번 conversion의 datatype을 체크하여 ft_conversion으로 보내준다.
// char	ft_check_specifier(const char *str)
// {
// 	char	*check_type;

// 	while (!ft_strchr(SPECIFIER, *str))
// 		str++;
// 	check_type = ft_strchr(SPECIFIER, *str);
// 	return (*check_type);
// }

// 첫 문자열 str을 받아 쭉 읽으면서 conversion의 경우 ft_check_format에서 t_conv reset 하고 input에 맞춰 다시 세팅
// 그리고 ft_conversion으로 넘어감, 아닌 경우 출력.
int		ft_read_str(const char *str, va_list args, t_set *set)
{
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			str++;
			set = ft_check_format(str, set);
			ft_conversion(args, set);
			str += ft_count_format(str);
		}
		else if (*str == '%' && *(str + 1) == '%')
		{
			ft_putchar_fd('%', 1);
			(set->print_size)++;
			str += 2;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			(set->print_size)++;
			str++;
		}
	}
	return (set->print_size);
}



// ft_printf 본체. 최종적으로 출력되는 문자열의 길이를 res에 담아 retrun.
int		ft_printf(const	char *str, ...)
{
	va_list	args;
	int		res;
	t_set	*set;

	va_start(args, str);
	set = NULL;
	set = ft_init_set(set);
	res = ft_read_str(str, args, set);
	va_end(args);
	return (res);
}
