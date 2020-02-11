/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:03:02 by ophelieba         #+#    #+#             */
/*   Updated: 2020/02/09 15:10:27 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		buf[BUFFER_SIZE + 1];
	int		i;
	static int	ret_read;

	i = 0;
	if (save == NULL)
	{
		ret_read = read(fd, buf, BUFFER_SIZE);
		if (ret_read < 0)
			return (-1);
		save = ft_strdup_mod(buf, ft_strlen(buf));
	}
	if(ft_strchr(save, '\n'))
	{
		if (save[0] == '\n')
		{
			*line = NULL;
			save = ft_strdup_mod(&save[1], ft_strlen(&save[1]));
			return (1);
		}
		while (save[i] != '\n')
			i++;
		*line = ft_strdup_mod(save, i);
		save = ft_strdup_mod(&save[i + 1], ft_strlen(&save[i + 1]));
		return (1);
	}
	if (ret_read > 0)
	{
		while (!(ft_strchr(save, '\n')) && ret_read > 0)
		{
			ret_read = read(fd, buf, BUFFER_SIZE);
			if (ret_read > 0)
				save = ft_strjoin(save, buf);
			if (ret_read < 0)
				return (-1);
		}
		while (save[i] != '\n')
			i++;
		*line = ft_strdup_mod(save, i);
		save = ft_strdup_mod(&save[i + 1], ft_strlen(&save[i + 1]));
		if (ret_read == 0)
		{
			save = NULL;
			free(save);
			return (0);
		}
		return (1);
	}
	return (0);
}

#include <stdio.h>

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
