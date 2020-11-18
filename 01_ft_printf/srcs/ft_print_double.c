/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:16:10 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/19 01:28:45 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_bankers_rounding(t_set *set)
{
	int i;

	i = set->precision + 1;
	if (set->bi_dec_arr.dec_result[set->precision] != 5)
		return (0);
	while (i < 1074)
	{
		if (set->bi_dec_arr.dec_result[i] != 0)
			break;
		i++;
	}
	if (i != 1074)
		return (0);
	return (1);
}

int		ft_fill_inputdata_int(t_set *set)
{
	int		i;
	int		j;
	char	*temp;

	i = set->integer_len - 1;
	j = 1;
	while (i >= 0)
	{
		if ((set->input_data[i] = set->bi_int_arr.int_result[309 - j] + set->rounding) >= 10)
		{
			set->input_data[i] = set->input_data[i] % 10;
			set->rounding = 1;
		}
		else
			set->rounding = 0;
		set->input_data[i] += '0';
		i--;
		j++;
	}
	if (set->rounding)
	{
		temp = set->input_data;
		if (!(set->input_data = (char *)malloc(sizeof(char) * (set->arglen + 2))))
			return (0);
		set->input_data[0] = '1';
		set->input_data[set->arglen + 1] = '\0';
		ft_strlcpy(set->input_data + 1, temp, set->arglen + 1);
		set->arglen = ft_strlen(set->input_data);
		free(temp);
	}
	return (1);
}

void	ft_fill_inputdata_dec(t_set *set)
{
	int i;

	if (!set->precision && !set->f_hash)
	{
		if (ft_check_bankers_rounding(set))
		{
			if (set->bi_int_arr.int_result[308] % 2 == 1)
				set->rounding = 1;
		}
		else if (set->bi_dec_arr.dec_result[0] >= 5)
			set->rounding = 1;
		return ;
	}
	i = set->integer_len + set->precision;
	if (ft_check_bankers_rounding(set))
	{
		if (set->precision == 0)
		{
			if (set->bi_int_arr.int_result[308] % 2 == 1)
				set->rounding = 1;
		}
		else
		{
			if (set->bi_dec_arr.dec_result[set->precision-- - 1] % 2 == 1)
				set->rounding = 1;
		}
	}
	else if (set->bi_dec_arr.dec_result[set->precision--] >= 5)
		set->rounding = 1;
	while (set->precision >= 0)
	{
		if ((set->input_data[i] = set->bi_dec_arr.dec_result[set->precision--] + set->rounding) >= 10)
		{
			set->input_data[i] = set->input_data[i] % 10;
			set->rounding = 1;
		}
		else
			set->rounding = 0;
		set->input_data[i] += '0';
		i--;
	}
	set->input_data[i] = '.';
	return ;
}

static int		ft_input_fdata(t_set *set)
{
	if (set->f_point == 0)
		set->precision = 6;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (set->integer_len + set->precision + 2))))
		return (0);
	set->input_data[set->integer_len + set->precision + 1] = '\0';
	set->arglen = set->integer_len + set->precision + 1;
	ft_fill_inputdata_dec(set);
	if(!(ft_fill_inputdata_int(set)))
		return (0);
	set->arglen = ft_strlen(set->input_data);
	return (1);
}

int		ft_apply_flag_to_f(t_set *set, t_double dbl)
{
	char	*temp;
	size_t	size;

	size = set->arglen + 1;
	temp = set->input_data;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (dbl.bitfield.sign == 1)
		set->input_data[0] = '-';
	else if (set->f_plus == 1 && dbl.dnum >= 0)
		set->input_data[0] = '+';
	else if (set->f_space == 1 && set->f_plus == 0 && dbl.dnum >= 0)
		set->input_data[0] = ' ';
	ft_strlcpy(set->input_data + 1, temp, size);
	set->input_data[size] = '\0';
	set->arglen = ft_strlen(set->input_data);
	free(temp);
	return (1);
}

int		ft_print_f_wid(t_set *set)
{
	size_t	size;
	size_t	temp;

	size = set->width;
	temp = 0;
	if (!(set->print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (set->f_minus == 1)
	{
		temp = ft_strlcpy(set->print_buf, set->input_data, set->arglen + 1);
		while ((set->width)-- - set->arglen)
			ft_memcpy(set->print_buf + temp++, " ", 1);
	}
	else if (set->f_zero == 1 && !set->infnan)
	{
		if (*(set->input_data) == '-' || *(set->input_data) == '+' || *(set->input_data) == ' ')
			set->print_buf[temp++] = *(set->input_data);
		while((set->width)-- - set->arglen)
			ft_memcpy(set->print_buf + temp++, "0", 1);
		if (*(set->input_data) == '-' || *(set->input_data) == '+' || *(set->input_data) == ' ')
			ft_strlcpy(set->print_buf + temp, set->input_data + 1, set->arglen);
		else
			ft_strlcpy(set->print_buf + temp, set->input_data, set->arglen + 1);
	}
	else
	{
		while ((set->width)-- - set->arglen)
			ft_memcpy(set->print_buf + temp++, " ", 1);
		ft_strlcpy(set->print_buf + temp, set->input_data, set->arglen + 1);
	}
	set->print_buf[size] = '\0';
	return (1);
}

int		ft_print_f_arg(t_set *set)
{
	size_t	size;

	size = set->arglen;
	if (!(set->print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_strlcpy(set->print_buf, set->input_data, set->arglen + 1);
	set->print_buf[size] = '\0';
	return (1);
}

int		ft_print_double(t_set *set)
{
	t_double dbl;

	dbl.dnum = va_arg(*(set->args), double);
	if (dbl.bitfield.exponent == 2047)
	{
		if (dbl.bitfield.mantissa == 0)
			set->input_data = ft_strdup("inf");
		else
		{
			set->input_data = ft_strdup("nan");
			set->nan = 1;
		}
		set->infnan = 1;
		set->arglen = ft_strlen(set->input_data);
	}
	else
	{
		ft_make_bigint_arr(set, dbl);
		if (!(ft_input_fdata(set)))
			return (0);
	}
	if ((set->f_plus == 1 || set->f_space == 1 || dbl.bitfield.sign == 1) && !set->nan)
	{
		if (!(ft_apply_flag_to_f(set, dbl)))
			return (0);
	}
	// ****************************
	// 여기 밑에 부분 int 구현이랑 동일함. 나중에 합칠것.
	if (set->width > set->arglen)
	{
		if (!(ft_print_f_wid(set)))
			return (0);
	}
	else
	{
		if (!(ft_print_f_arg(set)))
			return (0);
	}
	ft_putstr_fd(set->print_buf, 1);
	set->print_size += ft_strlen(set->print_buf);
	free(set->input_data);
	free(set->print_buf);
	// int k=0;
	// while (k < set->arglen)
	// 	printf("%c", set->input_data[k++]);
	// printf("\n");
	// int i=0;
	// while (i < set->integer_len)
	// {
	// 	printf("%d", set->bi_int_arr.int_result[309 - set->integer_len + i++]);
	// }
	// printf("\n");
	// i = 0;
	// while (i < 1024)
	// 	printf("%d", set->bi_int_arr.int_binary[i++]);
	// printf("\n");
	// i = 0;
	// while (i < 1074)
	// 	printf("%d", set->bi_dec_arr.dec_binary[i++]);
	return (1);
}
