/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 10:50:03 by aleung-c          #+#    #+#             */
/*   Updated: 2014/11/08 11:01:45 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	char			*str;
	unsigned int	i;

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
		dest[i] = f(i, str[i]);
		i++;
	}
	return (dest);
}
