/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:17:58 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 01:20:56 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_inputdata(t_set *set)
{
	int i;
	int j;

	i = 0;
	j = set->integer_len;
	while (i < set->integer_len)
	{
		set->input_data[i] = set->bi_inte.inte_res[309 - j];
		i++;
		j--;
	}
	j = 0;
	while (i < set->integer_len + 1074)
	{
		set->input_data[i] = set->bi_dece.dece_res[j];
		i++;
		j++;
	}
	return ;
}

int		ft_check_bankers_rounding_for_e(t_set *set, char *temp, int i)
{
	if (temp[i] != 5)
		return (0);
	++i;
	while (i < set->integer_len + 1074)
	{
		if (temp[i++] != 0)
			return (0);
	}
	return (1);
}

void	ft_count_exp(t_set *set, t_double dbl)
{
	int	i;

	i = 0;
	if (set->exp == -1023 && dbl.bitfield.mantissa == 0)
	{
		set->cnt_exp = 0;
		return ;
	}
	if (!set->input_data[0])
	{
		while (!set->input_data[i++])
			set->cnt_exp--;
	}
	else
		set->cnt_exp = set->integer_len - 1;
	return ;
}

int		ft_apply_precision_to_e(t_set *set, t_double dbl)
{
	char	*temp;
	int		i;
	int		j;

	ft_count_exp(set, dbl);
	temp = set->input_data;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (set->precision + 3))))
		return (0);
	set->input_data[set->precision + 2] = '\0';
	i = !temp[0] ? -set->cnt_exp + set->precision + 1 : set->precision + 1;
	if (ft_check_bankers_rounding_for_e(set, temp, i))
	{
		if (temp[0] == 0 && i == 1 && set->precision == 0)
		{
			i++;
			set->cnt_exp = -1;
		}
		else if (temp[i - 1] % 2 == 1)
			set->rounding = 1;
	}
	else if (temp[i] >= 5)
		set->rounding = 1;
	i--;
	j = set->precision + 1;
	while ((j >= 0) && (i >= 0))
	{
		if ((set->input_data[j] = temp[i] + set->rounding) >= 10)
		{
			set->input_data[j] = set->input_data[j] % 10;
			set->rounding = 1;
		}
		else
			set->rounding = 0;
		set->input_data[j] += '0';
		j--;
		i--;
	}
	if (i == -1 && j == 0)
		set->input_data[0] = set->rounding == 1 ? '1' : '0';
	free(temp);
	return (1);
}

int		ft_fill_point(t_set *set)
{
	char	*temp;
	int		size;
	int		i;
	int		j;

	size = set->arglen;
	temp = set->input_data;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	set->input_data[size] = '\0';
	i = 1;
	if (temp[0] == '0')
	{
		set->input_data[0] = temp[1];
		i++;
	}
	else
	{
		set->cnt_exp++;
		set->input_data[0] = temp[0];
	}
	if (!set->precision && !set->f_hash)
	{
		set->input_data[1] = '\0';
		free(temp);
		return (1);
	}
	set->input_data[1] = '.';
	j = 2;
	while (j < size)
		set->input_data[j++] = temp[i++];
	free(temp);
	return (1);
}

int		ft_fill_exponent(t_set *set)
{
	int		size;
	char	*temp;
	int		i;
	char	*exptoa;

	size = (set->cnt_exp > -100 && set->cnt_exp < 100) ? \
	set->arglen + 4 : set->arglen + 5;
	temp = set->input_data;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	set->input_data[size] = '\0';
	ft_memmove(set->input_data, temp, set->arglen);
	i = set->arglen;
	set->input_data[i++] = 'e';
	set->input_data[i++] = set->cnt_exp >= 0 ? '+' : '-';
	if (!(exptoa = ft_itoa(set->cnt_exp)))
		return (0);
	if (set->cnt_exp > -100 && set->cnt_exp < 100)
	{
		if (set->cnt_exp < 0)
			set->cnt_exp *= -1;
		set->input_data[i++] = set->cnt_exp / 10 + '0';
		set->input_data[i++] = set->cnt_exp % 10 + '0';
	}
	else
		ft_memmove(set->input_data + i, exptoa, ft_strlen(exptoa));
	set->arglen = ft_strlen(set->input_data);
	free(temp);
	free(exptoa);
	return (1);
}

int		ft_input_edata(t_set *set, t_double dbl)
{
	if (!(set->input_data = \
	(char *)malloc(sizeof(char) * (set->integer_len + 1074 + 1))))
		return (0);
	set->input_data[set->integer_len + 1074] = '\0';
	ft_fill_inputdata(set);
	if (!(ft_apply_precision_to_e(set, dbl)))
		return (0);
	set->arglen = ft_strlen(set->input_data);
	if (!(ft_fill_point(set)))
		return (0);
	set->arglen = ft_strlen(set->input_data);
	return (1);
}

int		ft_print_e(t_set *set)
{
	t_double dbl;

	dbl.dnum = va_arg(*(set->args), double);
	if (dbl.bitfield.exponent == 2047)
		ft_input_infnan(set, dbl);
	else
	{
		ft_make_bigint_arr(set, dbl);
		if (set->f_point == 0)
			set->precision = 6;
		if (!(ft_input_edata(set, dbl)))
			return (0);
		if (!(ft_fill_exponent(set)))
			return (0);
	}
	if (!(ft_apply_flag_and_print(set, dbl)))
		return (0);
	ft_put_and_free(set);
	return (1);
}
