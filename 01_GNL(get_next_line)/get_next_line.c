/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:17:17 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/07 23:09:51 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_linefeed(char * sv)
{
	int i;

	i = 0;
	while (sv[i])
	{
		if (sv[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		temp[BUFFER_SIZE + 1];

	if (!(ft_check_linefeed(save)))
	{
		if (read(fd, temp, BUFFER_SIZE) == -1)
			return (-1);
	}
	temp[BUFFER_SIZE] = '\0';

	return (1);
}
