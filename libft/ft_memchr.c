/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:10:23 by aleung-c          #+#    #+#             */
/*   Updated: 2014/11/07 15:07:40 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*str;
	unsigned int	i;

	i = 0;
	cc = c;
	str = (unsigned char *)s;
	if (str && n > 0)
	{
		while (i < n)
		{
			if (str[i] == cc)
			{
				return ((void *)str + i);
			}
			i++;
		}
	}
	return (NULL);
}
