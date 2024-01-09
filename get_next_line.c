/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:41:20 by mmeier            #+#    #+#             */
/*   Updated: 2024/01/09 14:40:18 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*txt = "\0";
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	txt = ft_read(fd, txt);
	if (txt == 0)
		return (0);
	line = ft_getline(txt);
	txt = ft_remainder(txt);
	return (line);
}

char	*ft_read(int fd, char *str)
{
	char	*buf;
	int		count;

	count = 1;
	buf = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == 0)
		return (NULL);
	while (!ft_strchr(str, '\n') && count > 0)
	{
		count = read (fd, buf, BUFFER_SIZE);
		if (count == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[count] = '\0';
		str = ft_strjoin(str, buf);
	}
	free (buf);
	return (str);
}

char	*ft_getline(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (str == 0)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *) malloc ((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_remainder(char *str)
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == 0)
	{
		free (str);
		return (NULL);
	}
	remainder = (char *) malloc ((ft_strlen(str) - i + 1) * sizeof(char));
	if (!remainder)
		return (NULL);
	i++;
	while (str[i] != '\0')
	{
		remainder[j++] = str[i++];
	}
	remainder[j] = '\0';
	free (str);
	return (remainder);
}
