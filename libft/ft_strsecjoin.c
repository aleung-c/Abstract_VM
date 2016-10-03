/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsecjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 16:20:29 by aleung-c          #+#    #+#             */
/*   Updated: 2015/03/11 13:36:29 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsecjoin(char const *s1, char const *s2)
{
	char	*temp;

	temp = ft_strnew((strlen(s1) + strlen(s2) + 1));
	ft_strcpy(temp, s1);
	ft_strcat(temp, s2);
	return (temp);
}
