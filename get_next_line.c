/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:23:16 by ophelieba         #+#    #+#             */
/*   Updated: 2020/01/30 20:03:31 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*re_malloc(char *buf)
{
	static char	*save;
	char		*tmp;

	save = NULL;
	if(!(tmp = malloc(ft_strlen(save) + 1)))
		return (0);
	ft_strcpy(tmp, save);
	free(save);
	if(!(save = malloc(ft_strlen(buf) + ft_strlen(tmp) + 1)))
		return (0);
	save = ft_strcat(tmp, buf);
	free(tmp);
	return (save);
}	

int	get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE];
	int	ret_read;
	int	i;
	int count;

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
			re_malloc(buf);
			return (1);
		}
		if (i == BUFFER_SIZE - 1)
		{
			re_malloc(buf);
			i = 0;
		}
		else
			i++;
	}
	*line = re_malloc(buf);
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
		{
			printf("%s\n", tmp);
			free(tmp);
		}
		else
			printf("aïe");
		if(ret <= 0)
			cont = 0;
	}
}
