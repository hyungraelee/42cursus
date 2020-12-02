/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:45:54 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/02 18:04:51 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# ifndef FLAGS
#  define FLAGS "-0# +"
# endif
# ifndef STAR
#  define STAR "*"
# endif
# ifndef WIDTH
#  define WIDTH "123456789"
# endif
# ifndef PRECISION
#  define PRECISION "."
# endif
# ifndef SPECIFIER
#  define SPECIFIER "nocspdiuxXfeg%"
# endif
# ifndef LENGTH
#  define LENGTH "lh"
# endif
# ifndef BIAS
#  define BIAS 1023
# endif

typedef struct		s_bi_decimal
{
	char	deci_bin[1074];
	char	five_mul[1074];
	char	deci_res[1074];
}					t_bi_decimal;

typedef struct		s_bi_integer
{
	char	inte_bin[1024];
	char	two_mul[309];
	char	inte_res[309];
	int		res_len;
}					t_bi_integer;

typedef struct		s_set
{
	int				f_minus;
	int				f_zero;
	int				f_point;
	int				f_hash;
	int				f_plus;
	int				f_space;
	int				l_l;
	int				l_h;
	int				width;
	int				precision;
	int				exp;
	char			specifier;
	int				mul_len;
	int				integer_len;
	int				rounding;
	int				nan;
	int				infnan;
	int				cnt_exp;
	long long		print_size;
	int				arglen;
	const char		*str;
	char			*input_data;
	char			*print_buf;
	t_bi_decimal	bi_deci;
	t_bi_integer	bi_inte;
	va_list			*args;
}					t_set;

typedef union		u_double
{
	struct			s_bitfield
	{
		unsigned long	mantissa : 52;
		unsigned long	exponent : 11;
		unsigned long	sign : 1;
	}				bitfield;
	double			dnum;
}					t_double;

int					ft_printf(const	char *str, ...);
t_set				*ft_init_set(const char *str, t_set *set);
void				ft_reset_set(t_set *set);
int					ft_parse_check(t_set *set);
int					ft_func_by_specifier(t_set *set);
int					ft_print_di(t_set *set);
void				ft_arglen_int(int num, t_set *set);
int					ft_print_c(t_set *set);
int					ft_print_s(t_set *set);
int					ft_print_u(t_set *set);
int					ft_print_u_wid(t_set *set);
int					ft_print_x(t_set *set);
int					ft_print_p(t_set *set);
int					ft_print_pct(t_set *set);
int					ft_print_o(t_set *set);
int					ft_print_n(t_set *set);

int					ft_print_f(t_set *set);
int					ft_check_bankers_rounding_for_f(t_set *set);
int					ft_rounding_in_int(t_set *set);
int					ft_fill_dec_without_point(t_set *set);
void				ft_bankers_rounding_for_f(t_set *set);

int					ft_print_e(t_set *set);
int					ft_check_bankers_rounding_for_e\
					(t_set *set, char *temp, int i);
void				ft_count_exp(t_set *set, t_double dbl);
int					ft_apply_precision_to_e(t_set *set, t_double dbl);
void				ft_fill_inputdata(t_set *set);
int					ft_fill_point(t_set *set);
void				ft_exponent_two_figures(t_set *set, int i);

int					ft_print_g(t_set *set);

int					ft_apply_flag_and_print(t_set *set, t_double dbl);
int					ft_apply_precision_to_uxpo(t_set *set);
int					ft_apply_prec_d_pos(t_set *set);
int					ft_apply_prec_d_neg(t_set *set);

void				ft_make_bigint_arr(t_set *set, t_double dbl);
void				ft_bi_decimal_arr_put_result(t_set *set);
void				ft_bi_integer_arr_put_result(t_set *set);

int					ft_lltoa(t_set *set, long long num);
int					ft_ulltoa(t_set *set, unsigned long long num);

void				ft_get_data_d(t_set *set, long long *num);
void				ft_get_data_u(t_set *set, unsigned long long *num);

void				ft_input_infnan(t_set *set, t_double dbl);
int					ft_print_wid_double(t_set *set);
int					ft_print_arg(t_set *set);
void				ft_put_and_free(t_set *set);

int					ft_convert_hex(t_set *set, unsigned long long num);
int					ft_convert_oct(t_set *set, unsigned long long num);

int					ft_input_edata(t_set *set, t_double dbl);
int					ft_input_fdata(t_set *set);
int					ft_fill_exponent(t_set *set);
#endif
