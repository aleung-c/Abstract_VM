/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:27:06 by aleung-c          #+#    #+#             */
/*   Updated: 2014/11/13 10:30:22 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*d;
	unsigned char	cc;

	if (!dst || !src || n == 0)
		return (NULL);
	if (n)
	{
		cc = c;
		d = dst;
		while (n--)
		{
			if (*d == cc)
			{
				*d++ = *(char *)src++;
				return (d);
			}
			*d++ = *(char *)src++;
		}
	}
	d = NULL;
	return (d);
}
