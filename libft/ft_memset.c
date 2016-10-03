/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:21:16 by aleung-c          #+#    #+#             */
/*   Updated: 2014/11/06 14:38:08 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*d;

	d = b;
	i = 0;
	if (len == 0)
		return (b);
	while (i < len)
	{
		d[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
