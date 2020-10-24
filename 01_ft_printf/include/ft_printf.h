/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:45:54 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/24 21:04:23 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# define SPECIFIER "cspdiuxX"

typedef struct	s_set
{
	int		f_minus;
	int		f_zero;
	int		f_point;
	int		width;
	int		precs;
	char	specifier;
	int		print_size;
	int		arglen;
}				t_set;

int		ft_printf(const	char *str, ...);
t_set	*ft_init_set(t_set *set);
void	ft_reset_set(t_set *set);
int		ft_read_str(const char *str, va_list args, t_set *set);
t_set	*ft_check_format(const char *str, t_set *set);
int		ft_count_format(const char *str);
int		is_flag(const char *str, t_set *set);
int		is_width(const char *str);
int		is_precision(const char *str);
void	ft_func_by_specifier(va_list args, t_set *set);
void	ft_conversion(va_list args, t_set *set);
void	ft_print_integer(va_list args, t_set *set);
void	ft_arglen_int(int num, t_set *set);

#endif
