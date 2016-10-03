/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:10:08 by aleung-c          #+#    #+#             */
/*   Updated: 2014/11/06 16:52:12 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *d;

	if (dst == NULL || src == NULL || dst == src)
		return (dst);
	if (n)
	{
		d = dst;
		while (n)
		{
			*d++ = *(char *)src++;
			n--;
		}
		return (dst);
	}
	return (dst);
}
