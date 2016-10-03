/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:24:02 by aleung-c          #+#    #+#             */
/*   Updated: 2014/11/07 16:24:02 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	unsigned int len;

	len = ft_strlen(s) + 1;
	while (len > 0 && s[len - 1] != c)
	{
		len--;
	}
	if (len > 0)
		return ((char *)s + len - 1);
	return (NULL);
}
