/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:17:17 by hyunlee           #+#    #+#             */
/*   Updated: 2020/12/09 00:22:24 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

size_t	ft_linelen(const char *s)
{
	size_t	cnt;

	if (!s)
		return (0);
	cnt = 0;
	while (*s != '\0' && *s != '\n')
	{
		cnt++;
		s++;
	}
	return (cnt);
}

size_t	ft_strlen(const char *s)
{
	size_t cnt;

	if (!s)
		return (0);
	cnt = 0;
	while (*s++)
	{
		cnt++;
	}
	return (cnt);
}

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*dp;
	unsigned char	*sp;
	size_t			i;

	// if (!dest && !src)
	// 	return (0);
	dp = (unsigned char *)dest;
	sp = (unsigned char *)src;
	i = 0;
	while (i++ < size)
		*dp++ = *sp++;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	// if (!s1)
	// 	return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	ft_memcpy(str, s1, s1_len);
	ft_memcpy(str + s1_len, s2, s2_len);
	free(s1);
	str[s1_len + s2_len] = '\0';
	return (str);
}

int	ft_check_linefeed(char *sv)
{
	int i;

	i = 0;
	if (sv == 0)
		return (0);
	while (sv[i])
	{
		if (sv[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
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

void	ft_trim_save(char **sv)
{
	char *tmp;
	// int i;
	// int j;


	tmp = ft_strdup(ft_strchr(*sv, '\n') + 1);
	// j = 0;
	free(*sv);
	*sv = tmp;
	return ;
}

int	ft_put_line(char **sv, char **line)
{
	int i;

	i = 0;
	// write(1, save[1], 1);
	// write(1, save[2], 1);
	if (!(*line = (char *)malloc(sizeof(char) * ft_linelen(*sv))))
		return (-1);
	// printf("%d\n", (int)ft_linelen(*sv));
	while ((*sv)[i] != '\0' && (*sv)[i] != '\n')
	{
		// write(1, *line, 1);
		(*line)[i] = (*sv)[i];
		i++;
	}
	(*line)[i] = '\0';
	if ((*sv)[i] == '\0')
		return (0);
	ft_trim_save(sv);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[10240];
	char		temp[BUFFER_SIZE + 1];
	int			read_size;

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
