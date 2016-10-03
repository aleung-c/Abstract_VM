/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:11:08 by aleung-c          #+#    #+#             */
/*   Updated: 2014/11/12 15:57:03 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int i;
	unsigned int j;
	unsigned int x;
	unsigned int lens;
	unsigned int lend;

	lens = ft_strlen(src);
	lend = ft_strlen(dst);
	i = lend;
	j = 0;
	x = size;
	if (size == 0)
		return (lens);
	if (size <= lend)
		return (size - 1 + lens);
	while (src[j] && size > 0)
	{
		dst[i] = (char)src[j];
		j++;
		i++;
		size--;
	}
	if (lens > x)
		return (lens);
	return (i);
}
