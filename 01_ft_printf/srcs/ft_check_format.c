/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 15:56:20 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/24 21:48:51 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(const char *str, t_set *set)
{
	if (*str == '-')
	{
		set->f_minus = 1;
		return (1);
	}
	else if (*str == '0')
	{
		set->f_zero = 1;
		return (1);
	}
	return (0);
}

int		is_precision(const char *str)
{
	if (ft_isdigit(*str))
		return (1);
	return (0);
}

// flag를 지나간 이후 곧바로 숫자인지 판별해서 width인지 판별할때 사용.
int		is_width(const char *str)
{
	if (ft_isdigit(*str))
		return (1);
	return (0);
}

// %부터 datatype까지 flag, width, precision 등의 갯수를 카운트해서 return.
// 기존 str에서 이 수만큼 주솟값 이동함.(ft_read_str에서)
int		ft_count_format(const char *str)
{
	int cnt;
	const char *temp;

	cnt = 1;
	temp = str;
	while (!ft_strchr(SPECIFIER, *temp++))
		cnt++;
	return (cnt);
}

t_set	*ft_check_format(const char *str, t_set *set)
{
	ft_reset_set(set);
	while (is_flag(str, set))
		str++;
	while (is_width(str))
	{
		set->width *= 10;
		set->width += (*str) - '0';
		str++;
	}
	if (*str == '.')
	{
		set->f_point = 1;
		str++;
		while (is_precision(str))
		{
			set->precs *= 10;
			set->precs += (*str) - '0';
			str++;
		}
	}
	// conv->specifier = ft_check_specifier(str);
	set->specifier = *str;
	return (set);
}
