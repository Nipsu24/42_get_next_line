/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:41:20 by mmeier            #+#    #+#             */
/*   Updated: 2024/01/18 12:10:09 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*txt[4925];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr(txt[fd], '\n'))
		txt[fd] = ft_read(fd, txt[fd]);
	if (!txt[fd])
		return (NULL);
	line = ft_getline(txt[fd]);
	if (!line)
		return (ft_free(&txt[fd]));
	txt[fd] = ft_remainder(txt[fd]);
	return (line);
}

char	*ft_read(int fd, char *str)
{
	char	buf[BUFFER_SIZE + 1];
	int		count;

	count = 1;
	while (count > 0)
	{
		count = read (fd, buf, BUFFER_SIZE);
		if (!str && count == 0)
			return (ft_free(&str));
		if (count == -1)
			return (ft_free(&str));
		buf[count] = '\0';
		if (!str)
			str = ft_strdup(buf);
		else
			str = ft_gnl_strjoin(str, buf);
		if (!str)
			return (ft_free(&str));
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (str);
}

char	*ft_getline(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (str == 0)
		return (ft_free(&str));
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_substr(str, 0, i);
	if (!line)
		return (ft_free(&line));
	if (line[0] == '\0')
		return (ft_free(&line));
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
	if (!str[i])
		return (ft_free(&str));
	remainder = (char *) malloc ((ft_strlen(str) - i + 1) * sizeof(char));
	if (!remainder)
		return (ft_free(&str));
	if (str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		remainder[j++] = str[i++];
	}
	remainder[j] = '\0';
	ft_free(&str);
	return (remainder);
}

char	*ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}
