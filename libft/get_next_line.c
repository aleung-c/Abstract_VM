/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 16:13:53 by aleung-c          #+#    #+#             */
/*   Updated: 2015/02/19 16:32:45 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_recup(char *recup, char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((*str)[i] != '\n')
		i++;
	recup = ft_strnew(ft_strlen(*str) - i + 1);
	i++;
	while ((*str)[i] != '\0')
	{
		recup[j] = (*str)[i];
		j++;
		i++;
	}
	recup[j] = '\0';
	i = i - j - 1;
	while ((*str)[i])
	{
		(*str)[i] = '\0';
		i++;
	}
	return (recup);
}

static int		ft_read(int const fd, char **strl)
{
	int		inret;
	char	*buf;

	buf = ft_strnew(BUF_SIZE + 1);
	if ((inret = read(fd, buf, BUF_SIZE)) == -1)
		return (-1);
	buf[inret] = '\0';
	*strl = ft_strsecjoin(*strl, buf);
	free(buf);
	return (inret);
}

static char		*ft_line_init(char *line, char *recup)
{
	line = ft_strnew(1);
	line = ft_strsecjoin(recup, line);
	return (line);
}

static int		ft_reinit(int *ret, char **recup)
{
	*recup = "";
	*ret = 1;
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static int		ret = 1;
	static char		*recup = "";

	if (ret == 0)
		return ((ft_reinit(&ret, &recup)));
	*line = ft_line_init(*line, recup);
	if (fd < 0 || !(*line) || !line || BUF_SIZE < 1)
		return (-1);
	if (strchr(*line, '\n'))
		recup = ft_recup(recup, &(*line));
	else if (!(strchr(*line, '\n')))
	{
		while (!(strchr(*line, '\n')) && ret)
		{
			if ((ret = ft_read(fd, &(*line))) == -1)
				return (-1);
		}
		if (strchr(*line, '\n'))
			recup = ft_recup(recup, &(*line));
	}
	if (ret == 0 && (*line)[0] != '\0')
		return (1);
	else if (ret == 0)
		return ((ft_reinit(&ret, &recup)));
	return (1);
}
