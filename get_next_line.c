/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:03:02 by ophelieba         #+#    #+#             */
/*   Updated: 2020/02/12 16:56:59 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*build_save(char *save, int i, char **line, char *buf)
{
	char *tmp;

	if (ft_strchr(save, '\n'))
	{
		i = 0;
		while (save[i] && save[i] != '\n')
			i++;
		*line = ft_strdup_mod(save, i);
		tmp = ft_strdup_mod(&save[i + 1], ft_strlen(&save[i + 1]));
	}
	else
	{
		buf[i] = '\0';
		tmp = ft_strjoin(save, buf);
	}
	free(save);
	save = NULL;
	save = ft_strdup_mod(tmp, ft_strlen(tmp));
	free(tmp);
	return (save);
}

int		free_save(char **save, char **line)
{
	*line = ft_strdup_mod(*save, ft_strlen(*save));
	free(*save);
	*save = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		buf[BUFFER_SIZE + 1];
	static int	ret_read;

	if (!BUFFER_SIZE || fd < 0 || !line)
		return (-1);
	if (save == NULL)
	{
		if ((ret_read = read(fd, buf, BUFFER_SIZE)) < 0)
			return (-1);
		buf[ret_read] = '\0';
		save = ft_strdup_mod(buf, ft_strlen(buf));
	}
	if (ft_strchr(save, '\n'))
	{
		save = build_save(save, ret_read, line, buf);
		return (1);
	}
	while (!(ft_strchr(save, '\n'))
		&& (ret_read = read(fd, buf, BUFFER_SIZE)) > 0)
		save = build_save(save, ret_read, line, buf);
	if (ret_read == 0)
		return (free_save(&save, line));
	save = build_save(save, ret_read, line, buf);
	return (1);
}
