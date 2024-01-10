/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:47:22 by mmeier            #+#    #+#             */
/*   Updated: 2024/01/10 16:19:45 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const	char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)(s));
		s++;
	}
	if (*s == (char)c)
		return ((char *)(s));
	return (0);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		s1len;
	int		s2len;
	char	*result;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = (char *) malloc ((s1len + s2len + 1) * sizeof(char));
	if (ptr == 0)
	{
		free (s1);
		free (s2);
		return (NULL);
	}
	result = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (result);
}
