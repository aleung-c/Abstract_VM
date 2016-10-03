/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:37:49 by aleung-c          #+#    #+#             */
/*   Updated: 2014/11/10 15:37:00 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
	{
		i++;
		if (str[i] == '\0')
			return (-1);
	}
	return (i);
}

static int	ft_end(char const *str)
{
	int		j;

	j = 0;
	while (str[j])
		j++;
	j--;
	while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t')
	{
		j--;
	}
	return (j);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		k;
	int		j;
	char	*dst;

	if (!s)
		return (NULL);
	i = ft_start(s);
	if (i == -1)
	{
		if (!(dst = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		dst[0] = '\0';
	}
	else
	{
		k = ft_end(s);
		j = 0;
		if (!(dst = (char *)malloc(sizeof(char) * (k - i) + 1)))
			return (NULL);
		while (i <= ft_end(s))
			dst[j++] = s[i++];
		dst[j] = '\0';
	}
	return (dst);
}
