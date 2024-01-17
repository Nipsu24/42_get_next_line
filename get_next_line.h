/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:42:58 by mmeier            #+#    #+#             */
/*   Updated: 2024/01/17 12:23:41 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);
size_t	ft_strlen(const	char *s);
char	*ft_read(int fd, char *str);
char	*ft_getline(char *str);
char	*ft_remainder(char *str);
char	*ft_free(char **str);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif
