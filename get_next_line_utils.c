/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:35:38 by acuesta-          #+#    #+#             */
/*   Updated: 2023/04/11 13:22:36 by acuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenn(char *str)
{
	size_t	c;

	c = 0;
	if (str == NULL)
	{
		return (0);
	}
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	unsigned int	str1;
	unsigned int	str2;
	char			*final;
	unsigned int	i;

	str1 = ft_strlenn (s1);
	str2 = ft_strlenn (s2);
	final = malloc(sizeof(char) * (str1 + str2 + 1));
	if (final == NULL)
		return (NULL);
	i = 0;
	while (i < str1)
	{
		final[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < str2)
	{
		final[i + str1] = s2[i];
		i++;
	}
	final[str1 + str2] = '\0';
	return (final);
}

size_t	ft_strlcpyy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*pt_src;

	pt_src = (char *)src;
	i = 0;
	if (dstsize > 0)
	{
		while (pt_src[i] && i < dstsize - 1)
		{
			dst[i] = pt_src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_substrr(char *s, unsigned int start, size_t len)
{
	char	*i;

	if (len > ft_strlenn(s))
	{
		len = ft_strlenn(s);
	}
	i = (char *)malloc(len + 1);
	if (start > ft_strlenn(s))
	{
		*i = '\0';
		return (i);
	}
	if (!i)
	{
		return (0);
	}
	ft_strlcpyy(i, &s[start], len + 1);
	return (i);
}

char	*read_line(int fd, char **save)
{
	char	*line;
	int		i;
	char	*temp;

	line = ft_string (*save, fd);
	if (!line)
		return (NULL);
	i = ft_getlin (line);
	if (line[i] == '\n')
	{
		*save = ft_substrr (line, i + 1, ft_strlenn(line + i + 1));
		temp = ft_substrr (line, 0, i + 1);
		free(line);
		line = temp;
	}
	else
		*save = NULL;
	if (line[0] == '\0')
	{
		free (line);
		return (NULL);
	}
	return (line);
}
