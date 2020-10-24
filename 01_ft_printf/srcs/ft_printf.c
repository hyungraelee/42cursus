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

// �̹� conversion�� datatype�� üũ�Ͽ� ft_conversion���� �����ش�.
// char	ft_check_specifier(const char *str)
// {
// 	char	*check_type;

// 	while (!ft_strchr(SPECIFIER, *str))
// 		str++;
// 	check_type = ft_strchr(SPECIFIER, *str);
// 	return (*check_type);
// }

// ù ���ڿ� str�� �޾� �� �����鼭 conversion�� ��� ft_check_format���� t_conv reset �ϰ� input�� ���� �ٽ� ����
// �׸��� ft_conversion���� �Ѿ, �ƴ� ��� ���.
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



// ft_printf ��ü. ���������� ��µǴ� ���ڿ��� ���̸� res�� ��� retrun.
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
