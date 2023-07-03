/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:35:35 by acuesta-          #+#    #+#             */
/*   Updated: 2023/04/11 13:21:16 by acuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# include <stdio.h>
# include <stdlib.h> 
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_get(char	*line);
char	*ft_read(int fd);
char	*ft_string(char	*save, int fd);
int		ft_getlin(char *line);
size_t	ft_strlenn(char *str);
char	*ft_substrr(char *s, unsigned int start, size_t len);
size_t	ft_strlcpyy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoinn(char *s1, char *s2);
char	*read_line(int fd, char **save);

#endif 
#endif 