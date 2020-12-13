/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:17:17 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/13 20:26:34 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_linefeed(char *sv)
{
	int i;

	i = 0;
	while (sv[i])
	{
		if (sv[i] == '\n' || (sv[i] == '\0' && i < BUFFER_SIZE))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	char	*temp;
	size_t	len;

	len = ft_strlen(s);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	temp = result;
	while (len--)
		*temp++ = *s++;
	*temp = '\0';
	return (result);
}

int		ft_put_line(char **sv, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(*line = (char *)malloc(sizeof(char) * (ft_linelen(*sv) + 1))))
		return (-1);
	while ((*sv)[i] != '\0' && (*sv)[i] != '\n')
	{
		(*line)[i] = (*sv)[i];
		i++;
	}
	(*line)[i] = '\0';
	if ((*sv)[i] == '\0')
	{
		free(*sv);
		*sv = NULL;
		return (0);
	}
	tmp = ft_strdup(ft_strchr(*sv, '\n') + 1);
	free(*sv);
	*sv = tmp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		temp[BUFFER_SIZE + 1];
	int			read_size;

	if (fd < 0 || fd > OPEN_MAX ||line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (save[fd] == 0)
		save[fd] = ft_strdup("");
	if (!(ft_check_linefeed(save[fd])))
	{
		while (((read_size = read(fd, temp, BUFFER_SIZE)) > 0))
		{
			temp[read_size] = '\0';
			save[fd] = ft_strjoin(save[fd], temp);
			if (ft_check_linefeed(temp))
				break ;
		}
		if (read_size == -1)
			return (-1);
	}
	return (ft_put_line(&save[fd], line));
}
