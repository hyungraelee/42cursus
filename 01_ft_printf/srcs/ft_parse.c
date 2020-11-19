/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 15:56:20 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/19 18:02:10 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_input_flag(t_set *set)
{
	if (*(set->str) == '-')
		set->f_minus = 1;
	else if (*(set->str) == '0')
		set->f_zero = 1;
	else if (*(set->str) == '#')
		set->f_hash = 1;
	else if (*(set->str) == '+')
		set->f_plus = 1;
	else if (*(set->str) == ' ')
		set->f_space = 1;
	(set->str)++;
	return ;
}

void	ft_input_precision(t_set *set)
{
	set->precision = 0;
	set->f_point = 1;
	(set->str)++;
	if (*(set->str) == '*')
	{
		if ((set->precision = va_arg(*(set->args), int)) < 0)
		{
			set->precision = 0;
			set->f_point = 0;
		}
		(set->str)++;
	}
	else
	{
		while (ft_isdigit(*(set->str)))
		{
			set->precision *= 10;
			set->precision += (*(set->str) - '0');
			(set->str)++;
		}
	}
	return ;
}

void	ft_input_width(t_set *set)
{
	set->width = 0;
	if (*(set->str) == '*')
	{
		if ((set->width = va_arg(*(set->args), int)) < 0)
		{
			set->f_minus = 1;
			set->width *= (-1);
		}
		(set->str)++;
	}
	while (ft_isdigit(*(set->str)))
	{
		set->width *= 10;
		set->width += (*(set->str) - '0');
		(set->str)++;
	}
	return ;
}

void	ft_input_length(t_set *set)
{
	if (*(set->str) == 'l')
		(set->l_l) += 1;
	else if (*(set->str) == 'h')
		(set->l_h) += 1;
	(set->str)++;
	return ;
}

int		ft_parse(t_set *set)
{
	ft_reset_set(set);
	while (!ft_strchr(SPECIFIER, *(set->str)))
	{
		if (ft_strchr(FLAGS, *(set->str)))
			ft_input_flag(set);
		else if (ft_strchr(WIDTH, *(set->str)) || ft_strchr(STAR, *(set->str)))
			ft_input_width(set);
		else if (ft_strchr(PRECISION, *(set->str)))
			ft_input_precision(set);
		else if (ft_strchr(LENGTH, *(set->str)))
			ft_input_length(set);
		if (!(*(set->str)))
			return (0);
	}
	set->specifier = *(set->str)++;
	return (1);
}


// ù ���ڿ� str�� �޾� �� �����鼭 conversion�� ��� ft_check_format���� t_conv reset �ϰ� input�� ���� �ٽ� ����
// �׸��� ft_conversion���� �Ѿ, �ƴ� ��� ���.
int		ft_parse_check(t_set *set)
{
	while (*(set->str))
	{
		if (*(set->str) == '%')
		{
			(set->str)++;
			if (ft_parse(set))
			{
				if (!(ft_func_by_specifier(set)))
					return (-1);
			}
		}
		else
		{
			ft_putchar_fd(*(set->str), 1);
			(set->print_size)++;
			(set->str)++;
		}
	}
	return (set->print_size);
}



// %���� datatype���� flag, width, precision ���� ������ ī��Ʈ�ؼ� return.
// ���� str���� �� ����ŭ �ּڰ� �̵���.(ft_read_str����)
// int		ft_count_format(const char *str)
// {
// 	int cnt;
// 	const char *temp;

// 	cnt = 1;
// 	temp = str;
// 	while (!ft_strchr(SPECIFIER, *temp++))
// 		cnt++;
// 	return (cnt);
// }

// int		ft_check_format(const char *str, t_set *set)
// {
// 	ft_reset_set(set);
// 	while (is_flag(str, set))
// 		str++;
// 	while (is_width(str))
// 	{
// 		set->width *= 10;
// 		set->width += (*str) - '0';
// 		str++;
// 	}
// 	if (*str == '.')
// 	{
// 		set->f_point = 1;
// 		str++;
// 		while (is_precision(str))
// 		{
// 			set->precs *= 10;
// 			set->precs += (*str) - '0';
// 			str++;
// 		}
// 	}
// 	// conv->specifier = ft_check_specifier(str);
// 	set->specifier = *str;
// 	return (set);
// }
