/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:17:58 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/23 16:37:16 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_inputdata(t_set *set)
{
	int i, j;

	i = 0;
	j = set->integer_len;
	while (i < set->integer_len)
	{
		set->input_data[i] = set->bi_int_arr.int_result[309 - j];
		i++;
		j--;
	}
	j = 0;
	while (i < set->integer_len + 1074)
	{
		set->input_data[i] = set->bi_dec_arr.dec_result[j];
		i++;
		j++;
	}
	return ;
}

int		ft_check_bankers_rounding_for_e(char *temp)
{
	if (*temp != 5)
		return (0);
	while (*temp++)
	{
		if (*temp != 0)
			return (0);
	}
	return (1);
}

void	ft_count_exp(t_set *set)
{
	int	i;

	i = 0;
	if (!set->input_data[0])
	{
		while (!set->input_data[i++])
			set->cnt_exp--;
	}
	else
		set->cnt_exp = set->integer_len - 1;
	return ;
}

int		ft_apply_precision_to_e(t_set *set)
{
	char	*temp;
	int		i;
	int		j;

	ft_count_exp(set);
	temp = set->input_data;
	if (set->f_point == 0)
		set->precision = 6;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (set->precision + 3))))
		return (0);
	set->input_data[set->precision + 2] = '\0';
	i = !temp[0] ? -set->cnt_exp + set->precision + 1 : set->precision + 1;
	if (ft_check_bankers_rounding_for_e(temp + i))
	{
		if (temp[i - 1] % 2 == 1)
			set->rounding = 1;
	}
	else if (temp[i] >= 5)
		set->rounding = 1;
	i--;
	j = set->precision + 1;
	while (j >= 0)
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
	free(temp);
	return (1);
}

int		ft_fill_point(t_set *set)
{
	char	*temp;
	int		size;
	int		i;
	int		j;

	size = set->input_data[0] == '0' ? set->arglen : set->arglen + 1;
	temp = set->input_data;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	set->input_data[size] = '\0';
	i = 1;
	if (temp[0] == '0')
	{
		set->input_data[0] = temp[1];
		set->input_data[1] = '.';
		i++;
	}
	else
	{
		set->cnt_exp++;
		set->input_data[0] = temp[0];
		set->input_data[1] = '.';
	}
	j = 2;
	while (temp[i])
		set->input_data[j++] = temp[i++];
	set->arglen = ft_strlen(set->input_data);
	free(temp);
// int k = 0;
// while (k < set->arglen)
// 	printf("%c",set->input_data[k++]);
	return (1);
}

int		ft_fill_exponent(t_set *set)
{
	int	size;

	// size = (set->cnt_exp > -100 && set->cnt_exp < 100) ? set->arglen
	// if (set->cnt_exp > -100 && set->cnt_exp < 100)
	// {

	// }
	return (1);
}

int		ft_input_edata(t_set *set)
{
	if (set->f_point == 0)
		set->precision = 6;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (set->integer_len + 1074 + 1))))
		return (0);
	set->input_data[set->integer_len + 1074] = '\0';
	ft_fill_inputdata(set);

// int k = 0;
// while (k < set->integer_len + 1074)
// 	{printf("%d", set->input_data[k++]);}

	if (!(ft_apply_precision_to_e(set)))
		return (0);
	set->arglen = ft_strlen(set->input_data);
	if (!(ft_fill_point(set)))
		return (0);
	if (!(ft_fill_exponent(set)))
		return (0);
// k = 0;
// printf("\n");
// while (k < set->precision + 2)
// 	{printf("%c", set->input_data[k++]);}
	return (1);
}

int		ft_print_e(t_set *set)
{
	t_double dbl;
	dbl.dnum = va_arg(*(set->args), double);

	ft_make_bigint_arr(set, dbl);
	if (!(ft_input_edata(set)))
		return (0);
	if (set->f_plus || set->f_minus || dbl.bitfield.sign)
	{
		if (!(ft_apply_flag_to_e(set, dbl)))
			return (0);
	}
	ft_putstr_fd(set->print_buf, 1);
	set->print_size += ft_strlen(set->print_buf);
	free(set->input_data);
	free(set->print_buf);
	return (1);
}
