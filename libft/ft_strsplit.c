/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:39:38 by aleung-c          #+#    #+#             */
/*   Updated: 2015/03/11 10:57:07 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_countw(char *s, char c)
{
	unsigned int i;
	unsigned int j;

	if (!s || !c)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
		{
			j++;
			i++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (j);
}

static char				**ft_mallocl(char **tb, char *str, char c)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] != c && str[i] != '\0')
		{
			while (str[i] != c && str[i] != '\0')
			{
				k++;
				i++;
			}
			if (!(tb[j] = (char *)malloc(sizeof(char) * k + 1)))
				return (NULL);
			j++;
		}
		else
			i++;
	}
	return (tb);
}

static char				**ft_splitcpy(char **tb, char *str, char c)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] != c && str[i] != '\0')
		{
			while (str[i] != c && str[i] != '\0')
			{
				tb[j][k] = str[i];
				k++;
				i++;
			}
			tb[j][k] = '\0';
			k = 0;
			j++;
		}
		else
			i++;
	}
	return (tb);
}

char					**ft_strsplit(char const *s, char c)
{
	char			*str;
	char			**tb;
	unsigned int	nbw;

	str = (char *)s;
	nbw = ft_countw(str, c);
	if (!(tb = (char **)malloc(sizeof(char *) * nbw + 2)))
		return (NULL);
	tb[nbw] = NULL;
	if (nbw == 0)
	{
		tb[1] = NULL;
		return (tb);
	}
	tb = ft_mallocl(tb, str, c);
	tb = ft_splitcpy(tb, str, c);
	return (tb);
}
