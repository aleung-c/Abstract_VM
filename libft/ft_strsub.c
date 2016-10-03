/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:36:34 by aleung-c          #+#    #+#             */
/*   Updated: 2014/11/08 16:03:41 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;
	char			*dst;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)s;
	if (!(dst = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < start)
	{
		i++;
	}
	while (j < len)
	{
		dst[j] = str[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst);
}
