/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:23:16 by ophelieba         #+#    #+#             */
/*   Updated: 2020/01/31 01:35:46 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	re_malloc(char **line, char *buf, int signal)
{
	static char	*save;
	char		*tmp;

	if(!(tmp = malloc(sizeof(char) * (ft_strlen(save) + 1))))
		return (0);
	ft_strcpy(tmp, save);
	if(!(save = malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(tmp) + 1))))
		return (0);
	if(!(*line = malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(tmp) + 1))))
		return (0);
	save = ft_strcat(tmp, buf);
	ft_strcpy(*line, save);
	if (signal == 1)
		ft_bzero(save, ft_strlen(tmp));
	return (0);
}	

int	get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE];
	int	ret_read;
	int	i;
	int 	count;

	i = 0;
	count = 1;
	while (count == 1)
	{
		ret_read = read(fd, buf + i, 1);
		if (ret_read == 0)
			count = 0;
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			re_malloc(line, &buf[0], 1);
			return (1);
		}
		if (i == BUFFER_SIZE - 2)
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

int	main()
{
	char	*tmp;
	int	fd;
	int	cont;
	int	ret;

	cont = 1;
	ret = 0;
	fd = open("coucou.txt", O_RDONLY);
	while(cont)
	{
		ret = get_next_line(fd, &tmp);
		if(ret >= 0)
			printf("%s\n", tmp);
		if(ret <= 0)
			cont = 0;
	}
	return (0);
}
