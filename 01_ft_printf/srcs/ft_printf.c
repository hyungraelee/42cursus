/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:33:51 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/23 22:37:53 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
// int	is_flag(char chr)
// {
// 	if (chr == '0' || chr == '-')
// 		return (1);
// 	return (0);
// }

int		is_width(const char *str)
{
	if (!ft_isdigit(*str))
		return (0);
	return (1);
}

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
char	ft_check_specifier(const char *str)
{
	char	*check_type;

	while (!ft_strchr(SPECIFIER, *str))
		str++;
	check_type = ft_strchr(SPECIFIER, *str);
	return (*check_type);
}

void	ft_arglen_int(int num, t_conv *conv)
{
	unsigned int	temp;

	temp = num;
	if (num < 0)
	{
		(conv->arglen)++;
		temp = -num;
	}
	while (temp)
	{
		(conv->arglen)++;
		temp /= 10;
	}
	return ;
}

void	ft_print_integer(va_list args, t_conv *conv)
{
	int	num;

	num = va_arg(args, int);

	ft_arglen_int(num, conv);
	if (conv->arglen > conv->width)
	{
		ft_putnbr_fd(num, 1);
		conv->print_size += conv->arglen;
	}
	else
	{
		conv->print_size += conv->width;
		while ((conv->width)-- - conv->arglen)
			ft_putchar_fd(' ', 1);
		while ((conv->arglen)--)
			ft_putnbr_fd(num, 1);
	}
}

// datatype���� ����ϴ� ����� �ٸ��� ������ �� �ٸ� �Լ��� �����ִ� ��� ���.
void	ft_func_by_specifier(va_list args, t_conv *conv)
{
		write(1, &(conv->specifier), 1);
	if (conv->specifier == 'd' || conv->specifier == 'i')
		ft_print_integer(args, conv);
}

//conv ����ü ������� ���� reset.
void	ft_reset_conv(t_conv *conv)
{
	conv->f_minus = 0;
	conv->f_zero = 0;
	conv->width = 0;
	conv->precs = 0;
	conv->specifier = 0;
	conv->print_size = 0;
	conv->arglen = 0;
	return ;
}

// conversion ����� ù��° �Լ�.
// ���⼭ flag, width, precision���� üũ ��.
void	ft_conversion(va_list args, t_conv *conv)
{
	ft_func_by_specifier(args, conv);
}

// %���� datatype���� flag, width, precision ���� ������ ī��Ʈ�ؼ� return.
// ���� str���� �� ����ŭ �ּڰ� �̵���.(ft_read_str����)
int		ft_count_format(const char *str)
{
	int cnt;
	const char *temp;

	cnt = 0;
	temp = str;
	while (!ft_strchr(SPECIFIER, *temp++))
		cnt++;
	return (cnt);
}

t_conv	*ft_check_format(const char *str, t_conv *conv)
{
	ft_reset_conv(conv);
	while (is_width(str))
	{
		conv->width *= 10;
		conv->width += (*str) - '0';
		str++;
	}
	// conv->specifier = ft_check_specifier(str);
	conv->specifier = *str;
	return (conv);
}

// ù ���ڿ� str�� �޾� �� �����鼭 conversion�� ��� ft_check_format���� t_conv reset �ϰ� input�� ���� �ٽ� ����
// �׸��� ft_conversion���� �Ѿ, �ƴ� ��� ���.
// print_size�� count�ؼ� ft_printf�� return �ϴµ�, ���� ���������� �ٲܼ��� ���� ��.
int		ft_read_str(const char *str, va_list args, t_conv *conv)
{
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			conv = ft_check_format(str, conv);
			ft_conversion(args, conv);
			str += ft_count_format(str);
		}
		else if (*str == '%' && *(str + 1) == '%')
		{
			ft_putchar_fd('%', 1);
			(conv->print_size)++;
			str += 2;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			(conv->print_size)++;
			str++;
		}
	}
	return (conv->print_size);
}

t_conv	*ft_init_conv(t_conv *conv)
{
	if (!(conv = (t_conv *)malloc(sizeof(t_conv) * 1)))
		return (0);
	ft_reset_conv(conv);
	return (conv);
}

// ft_printf ��ü. ���������� ��µǴ� ���ڿ��� ���̸� res�� ��� retrun.
int		ft_printf(const	char *str, ...)
{
	va_list	args;
	int		res;
	t_conv	*conv;

	va_start(args, str);
	conv = NULL;
	conv = ft_init_conv(conv);
	res = ft_read_str(str, args, conv);
	va_end(args);
	return (res);
}
