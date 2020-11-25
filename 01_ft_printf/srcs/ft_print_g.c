/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_g.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:23:45 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/25 22:03:34 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_delete_zero(t_set *set)
{
	int		i;
	// int		cnt;
	// int		size;
	char	*temp;

	i = set->arglen - 1;
	while (i >= 0)
	{
		if (set->input_data[i] != '0')
			break ;
		i--;
		// cnt++;
	}
	if (set->precision == 0 && set->f_hash == 0)
		i--;
	temp = set->input_data;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	set->input_data[i] = '\0';
	ft_memmove(set->input_data, temp, i + 1);
	set->arglen = ft_strlen(set->input_data);
	free(temp);
	return (1);
}

int		ft_print_g_by_f(t_set *set)
{
	if (!(ft_input_fdata(set)))
		return (0);
	if (!(ft_delete_zero(set)))
		return (0);
	return (1);
}

int		ft_print_g_by_e(t_set *set)
{
	if (!(ft_delete_zero(set)))
		return (0);
	if (!(ft_fill_exponent(set)))
		return (0);
	return (1);
}

int		ft_print_g(t_set *set)
{
	t_double dbl;
	int	tmp;

	dbl.dnum = va_arg(*(set->args), double);
	ft_make_bigint_arr(set, dbl);
	if (!(ft_input_edata(set, dbl)))
		return (0);
	tmp = !set->precision ? 1 : set->precision;
	if (!set->f_point)
		set->precision = 6;
	set->precision = tmp - 1 - set->cnt_exp;
	if (set->cnt_exp < -4 || set->cnt_exp >= tmp)
	{
		if (set->cnt_exp == 0 && tmp == 0)
		{
			if (!(ft_print_g_by_f(set)))
				return (0);
		}
		else
		{
			if (!(ft_print_g_by_e(set)))
				return (0);
		}
	}
	else
	{
		if (!(ft_print_g_by_f(set)))
			return (0);
	}
// **************************** e,f 와 동일
	if (set->f_plus || set->f_space || dbl.bitfield.sign)
	{
		if (!(ft_apply_flag_to_e(set, dbl)))
			return (0);
	}
	if (set->width > set->arglen)
	{
		if (!(ft_print_e_wid(set)))
			return (0);
	}
	else
	{
		if (!(ft_print_e_arg(set)))
			return (0);
	}
	ft_putstr_fd(set->print_buf, 1);
	set->print_size += ft_strlen(set->print_buf);
	free(set->input_data);
	free(set->print_buf);
	return (1);
}
