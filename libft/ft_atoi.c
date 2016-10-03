/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:51:14 by aleung-c          #+#    #+#             */
/*   Updated: 2014/11/10 17:40:57 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int neg;
	int num;
	int chiffre;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\f')
		i++;
	neg = 1;
	chiffre = 0;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i - 1] == '-')
		neg = -1;
	while (ft_isdigit(str[i]) && str[i] != '\0')
	{
		chiffre = str[i] - 48;
		num = (num * 10) + chiffre;
		i++;
	}
	return (num * neg);
}
