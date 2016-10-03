/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 11:11:17 by aleung-c          #+#    #+#             */
/*   Updated: 2014/11/13 11:34:09 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*space_fill(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		s[i] = ' ';
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char		*itoa_plus(char *dst, int n, int i)
{
	dst[i] = 48 + (n % 10);
	n = n / 10;
	i--;
	while (n != 0)
	{
		dst[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (dst);
}

static char		*itoa_less(char *dst, int n, int i)
{
	dst[i] = 48 - (n % 10);
	n = n / 10;
	i--;
	while (n != 0)
	{
		dst[i] = 48 - (n % 10);
		n = n / 10;
		i--;
	}
	dst[i] = '-';
	return (dst);
}

char			*ft_itoa(int n)
{
	char	*dst;
	int		i;

	dst = ft_strnew(20);
	dst = space_fill(dst);
	i = 19;
	if (n >= 0)
		dst = itoa_plus(dst, n, i);
	else if (n < 0)
		dst = itoa_less(dst, n, i);
	dst = ft_strtrim(dst);
	return (dst);
}
