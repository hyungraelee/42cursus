/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:18:45 by hyunlee           #+#    #+#             */
/*   Updated: 2020/11/30 21:47:08 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_arg(t_set *set)
{
	size_t	size;

	size = set->arglen;
	if (!(set->print_buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_strlcpy(set->print_buf, set->input_data, set->arglen + 1);
	set->print_buf[size] = '\0';
	return (1);
}

void	ft_put_and_free(t_set *set)
{
	ft_putstr_fd(set->print_buf, 1);
	set->print_size += ft_strlen(set->print_buf);
	free(set->input_data);
	free(set->print_buf);
	return ;
}
