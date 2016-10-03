/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:55:47 by aleung-c          #+#    #+#             */
/*   Updated: 2014/11/07 15:55:50 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (s2[0] == '\0' || s2 == NULL)
		return ((char *)s1);
	while (s1[i] != '\0' && n > 0)
	{
		if (s1[i] == s2[j])
		{
			j++;
		}
		else
		{
			j = 0;
		}
		if (!s2[j])
			return ((char *)s1 + (i - (j - 1)));
		i++;
		n--;
	}
	return (NULL);
}
