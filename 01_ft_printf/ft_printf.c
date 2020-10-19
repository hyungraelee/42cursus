/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:33:51 by hyunlee           #+#    #+#             */
/*   Updated: 2020/10/19 22:31:30 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	ft_printf(const	char *str, ...)
{
	int s;
	int width;

	va_list args;
	va_start(args, str);

	while (*str)
	{
		if (*str++ == '%')
		{
			width = ft_atoi(str);
			break;
		}

		str++;
	}

	s = va_arg(args, int);
	ft_putnbr_fd(s, 1);


	va_end(args);
	return (0);
}

int	main()
{
	printf("This is real printf = %10d", 27);
	printf("\n");
	ft_printf("%10d", 20);

	return 0;
}
