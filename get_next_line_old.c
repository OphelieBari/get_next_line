/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:23:16 by ophelieba         #+#    #+#             */
/*   Updated: 2020/02/06 17:19:14 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	re_malloc(char **line, char *buf)
{
	static char	*save;
	static int 	i;

	i = 0;
	if (!save)
		save = ft_strdup_mod(buf, ft_strlen(buf));
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == 0)
	{
		save = ft_strjoin(save, buf);
		printf("\nsave is = |%s|\n", save);
		return (1);
	}
	if (save[i] == '\n')
	{
		*line = ft_strdup_mod(save, i);
		save = ft_strdup_mod(&save[i + 1], ft_strlen(&save[i + 1]));
		return (0);
	}
//	save = NULL;
//	free(save);
//	buf = NULL;
//	free(buf);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret_read;
	int		i;

	i = 1;
	ret_read = 1;
	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	while (ret_read > 0)
	{
		ret_read = read(fd, buf, BUFFER_SIZE);
		if (ret_read < 0)
			return (-1);
		buf[BUFFER_SIZE] = '\0';
		while ((re_malloc(line, buf) > 0))
			re_malloc(line, buf);
		return (1);
	}
//	re_malloc(line, &buf[0]);
	*line = NULL;
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
