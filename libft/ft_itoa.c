/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:55:39 by acuesta-          #+#    #+#             */
/*   Updated: 2022/09/20 11:54:36 by acuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_itovals(int n, int *p)
{
	*p = 0;
	if (n == 0)
	{
		*p = 1;
		return (p);
	}
	else
	{
		while (n != 0)
		{
			*p = *p + 1;
			n = n / 10;
		}
	}
	return (p);
}

static void	*ft_itosymb(int n, int *s, int *a)
{
	*s = 0;
	if (n < 0)
	{
		*s = 1;
		*a = -1;
	}
	else
	{
		*s = 0;
		*a = 1;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		pos;
	int		symb;
	char	*str;
	int		a;

	ft_itosymb(n, &symb, &a);
	ft_itovals(n, &pos);
	str = (char *)malloc(sizeof(char) * (pos + symb + 1));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	str[pos + symb] = '\0';
	if (n != 0)
	{
		if (symb == 1)
			str[0] = '-';
		while (n != 0)
		{
			str[pos - 1 + symb] = (a * (n % 10)) + '0';
			pos--;
			n = n / 10;
		}
	}
	return (str);
}
