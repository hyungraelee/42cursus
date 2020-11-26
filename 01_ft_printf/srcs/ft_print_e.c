/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:17:58 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/26 18:40:01 by hyunlee          ###   ########.fr       */
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
// printf("int=%d", set->bi_int_arr.int_result[309 - j]);
		i++;
		j--;
	}
	j = 0;
	while (i < set->integer_len + 1074)
	{
		set->input_data[i] = set->bi_dec_arr.dec_result[j];
// printf("dec%d=%d", j, set->bi_dec_arr.dec_result[j]);
		i++;
		j++;
	}
// printf("\n");
// int k = 0;
// while (k < set->integer_len + 1074)
// 	{printf("%d", set->input_data[k++]);}
	return ;
}

int		ft_check_bankers_rounding_for_e(t_set *set, char *temp, int i)
{
	if (*temp != 5)
		return (0);
	temp++;
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
	if (dbl.bitfield.mantissa == 0)
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
// printf("exp = %d\n", set->cnt_exp);
	temp = set->input_data;
	if (set->f_point == 0)
		set->precision = 6;
	if (!(set->input_data = (char *)malloc(sizeof(char) * (set->precision + 3))))
		return (0);
	set->input_data[set->precision + 2] = '\0';
	i = !temp[0] ? -set->cnt_exp + set->precision + 1 : set->precision + 1;
// int k=0;
// while (k < set->integer_len + 1074)
// printf("%d", temp[k++]);
	if (ft_check_bankers_rounding_for_e(set, temp + i, i))
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
	// if (i == -1 && j == 0 && set->rounding == 1)
	// 	set->input_data[0] = '1';
	// else if (i == 0 && j > 0 && set->rounding == 0)
	// 	set->input_data[0] = '0';
// int k=0;
// while (k < 2)
// printf("%d", temp[k++]);
	free(temp);
	return (1);
}

int		ft_fill_point(t_set *set)
{
	char	*temp;
	int		size;
	int		i;
	int		j;

	// size = set->input_data[0] == '0' ? set->arglen : set->arglen + 1;
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
// int k = 0;
// while (k < set->arglen)
// 	printf("%c",set->input_data[k++]);
	return (1);
}

int		ft_fill_exponent(t_set *set)
{
	int		size;
	char	*temp;
	int		i;
	char	*exptoa;

	size = (set->cnt_exp > -100 && set->cnt_exp < 100) ? set->arglen + 4 : set->arglen + 5;
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
	// printf("%d\n", set->cnt_exp);
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
	free(exptoa);
	return (1);
}

int		ft_input_edata(t_set *set, t_double dbl)
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
	if (!(ft_apply_precision_to_e(set, dbl)))
		return (0);
	set->arglen = ft_strlen(set->input_data);
// int k = 0;
// while (k < set->arglen)
// 	printf("%c",set->input_data[k++]);
	if (!(ft_fill_point(set)))
		return (0);
	set->arglen = ft_strlen(set->input_data);
// int k = 0;
// while (k < set->arglen)
// 	printf("%c",set->input_data[k++]);

// int k = 0;
// while (k < set->arglen)
// 	printf("%c",set->input_data[k++]);
// k = 0;
// printf("\n");
// while (k < set->precision + 2)
// 	{printf("%c", set->input_data[k++]);}
	return (1);
}

int		ft_apply_flag_to_e(t_set *set, t_double dbl)
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

int		ft_print_e_wid(t_set *set)
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

int		ft_print_e_arg(t_set *set)
{
	size_t	size;

	size = set->arglen;
	if (!(set->print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_strlcpy(set->print_buf, set->input_data, set->arglen + 1);
	set->print_buf[size] = '\0';
	return (1);
}

int		ft_print_e(t_set *set)
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
	else{
	ft_make_bigint_arr(set, dbl);
	if (!(ft_input_edata(set, dbl)))
		return (0);
	if (!(ft_fill_exponent(set)))
		return (0);
	}
// ******이하 f 와 동일
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
