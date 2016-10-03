/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 09:40:16 by aleung-c          #+#    #+#             */
/*   Updated: 2014/11/08 10:48:57 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(s))))
		return (NULL);
	str = (char *)s;
	if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(s))))
		return (NULL);
	while (str[i])
	{
		dest[i] = f(str[i]);
		i++;
	}
	return (dest);
}
