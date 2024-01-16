/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:47:22 by mmeier            #+#    #+#             */
/*   Updated: 2024/01/16 16:16:07 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const	char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)(s));
		s++;
	}
	if (*s == (char)c)
		return ((char *)(s));
	return (NULL);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = (char *) malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ptr == 0)
		return (ft_free(&s1));
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	ft_free(&s1);
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	ptr = (char *) malloc ((len + 1) * sizeof(char));
	if (ptr == 0)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (start + len > (ft_strlen(s)))
		len = (ft_strlen(s) - start);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	ptr = (char *) malloc ((len + 1) * sizeof(char));
	if (ptr == 0)
		return (NULL);
	if (len == 0)
		ptr[len] = '\0';
	while (len > 0)
	{
		ptr[i] = s[start];
		len--;
		start++;
		i++;
	}
	//ft_free(&s);
	ptr[i] = '\0';
	return (ptr);
}
