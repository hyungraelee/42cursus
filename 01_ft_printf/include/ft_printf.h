/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:45:54 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/03 13:22:38 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

#ifndef FLAGS
# define FLAGS "-0#"
#endif
#ifndef STAR
# define STAR "*"
#endif
#ifndef WIDTH
# define WIDTH "123456789"
#endif
#ifndef PRECISION
# define PRECISION "."
#endif
#ifndef SPECIFIER
# define SPECIFIER "cspdiuxX"
#endif

typedef struct	s_set
{
	int			f_minus;
	int			f_zero;
	int			f_point;
	int			f_hash;
	int			width;
	int			precision;
	char		specifier;
	int			print_size;
	int			arglen;
	const char	*str;
	char		*input_data;
	char		*print_buf;
	va_list		*args;
}				t_set;


int		ft_printf(const	char *str, ...);
t_set	*ft_init_set(const char *str, t_set *set);
void	ft_reset_set(t_set *set);
int		ft_parse_check(t_set *set);
int		ft_parse(t_set *set);
void	ft_input_flag(t_set *set);
void	ft_input_width(t_set *set);
void	ft_input_precision(t_set *set);
int		ft_func_by_specifier(t_set *set);
void	ft_print_int(t_set *set);
void	ft_arglen_int(int num, t_set *set);
int		ft_print_char(t_set *set);
int		ft_print_str(t_set *set);
int		ft_print_uint(t_set *set);
int		ft_print_hex(t_set *set);
int		ft_apply_precision_to_ux(t_set *set);

#endif
