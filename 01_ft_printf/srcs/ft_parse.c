/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 15:56:20 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/29 01:47:57 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_input_flag_or_length(t_set *set)
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
	else if (*(set->str) == 'l')
		(set->l_l) += 1;
	else if (*(set->str) == 'h')
		(set->l_h) += 1;
	(set->str)++;
	return ;
}

static void	ft_input_precision(t_set *set)
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

static void	ft_input_width(t_set *set)
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

static int	ft_parse(t_set *set)
{
	ft_reset_set(set);
	while (!ft_strchr(SPECIFIER, *(set->str)))
	{
		if (ft_strchr(FLAGS, *(set->str)) || ft_strchr(LENGTH, *(set->str)))
			ft_input_flag_or_length(set);
		else if (ft_strchr(WIDTH, *(set->str)) || ft_strchr(STAR, *(set->str)))
			ft_input_width(set);
		else if (ft_strchr(PRECISION, *(set->str)))
			ft_input_precision(set);
		if (!(*(set->str)))
			return (0);
	}
	set->specifier = *(set->str)++;
	return (1);
}

int			ft_parse_check(t_set *set)
{
	while (*(set->str))
	{
		if (*(set->str) == '%')
		{
			(set->str)++;
			if (ft_parse(set))
			{
				if (!(ft_func_by_specifier(set)))
					return (0);
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
