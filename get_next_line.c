/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:23:16 by ophelieba         #+#    #+#             */
/*   Updated: 2020/02/04 18:38:44 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	re_malloc(char **line, char *buf, int signal)
{
	static char	*save;
	char		*tmp;

	tmp = ft_strdup(save);
	free(save);
	save = NULL;
	save = ft_strjoin(tmp, buf);
	if (signal == 1)
	{
		*line = ft_strdup(save);
		ft_bzero(save, ft_strlen(save));
	}
	if (signal == 2)
	{
		*line = ft_strdup(save);
		free(save);
		save = NULL;
	}
	free(tmp);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret_read;
	int		i;

	i = 0;
	while (i >= 0)
	{
		ret_read = read(fd, buf + i, 1);
		if (ret_read < 0)
			return (-1);
		if (ret_read == 0)
		{
			buf[i] = '\0';
			re_malloc(line, &buf[0], 2);
			return (0);
		}
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			re_malloc(line, &buf[0], 1);
			return (1);
		}
		if (i == BUFFER_SIZE - 1)
		{
			buf[i + 1] = '\0';
			re_malloc(line, buf, 0);
			i = 0;
		}
		else
			i++;
	}
	return (0);
}
