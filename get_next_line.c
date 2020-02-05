/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:23:16 by ophelieba         #+#    #+#             */
/*   Updated: 2020/02/05 19:58:32 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	re_malloc(char **line, char *buf, int signal)
{
	static char	*save;
	static int 	i;

	i = 0;
	if (signal == 0)
	{
		save = NULL;
		free(save);
		buf = NULL;
		free(buf);
		return (0);
	}
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		buf[i] = 0;
		*line = ft_strjoin(save, buf);
		save = ft_strdup_mod(&buf[i + 1], ft_strlen(&buf[i + 1]));
		return (0);
	}
	if (buf[i] == 0)
	{
		save = ft_strjoin(save, buf);
		return (1);
	}
	save = NULL;
	free(save);
	buf = NULL;
	free(buf);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret_read;
	int		i;

	i = 1;
	ret_read = 1;
	if (BUFFER_SIZE == 0)
		return (-1);
	while (i && ret_read != 0)
	{
		ret_read = read(fd, buf, BUFFER_SIZE);
		if (ret_read < 0)
			return (-1);
		buf[BUFFER_SIZE] = '\0';
		if (!(re_malloc(line, &buf[0], 1)))
		{
			re_malloc(line, &buf[0], 0);
			return (1);
		}
	}
	*line = malloc(1);
		*line[0] = '\0';
	return (0);
}

int main()
{
	int             fd;
	int             i;
	int             j;
	char    		*line = 0;
	char			*lineadress[66];

	j = 1;
	printf("\n==========================================\n");
	printf("========== TEST 1 : The Alphabet =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("alphabet", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		lineadress[j - 1] = line;
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	return (0);
}
