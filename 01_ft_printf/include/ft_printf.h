/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:45:54 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/23 21:22:05 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# define SPECIFIER "cspdiuxX"

typedef struct	s_conv
{
	int		f_minus;
	int		f_zero;
	int		width;
	int		precs;
	char	specifier;
	int		print_size;
	int		arglen;
}				t_conv;

int	ft_printf(const	char *str, ...);

#endif
