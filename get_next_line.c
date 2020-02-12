/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:03:02 by ophelieba         #+#    #+#             */
/*   Updated: 2020/02/11 23:39:55 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_switch(char *save, int i, int signal, char *buf)
{
	char *tmp;

	if (signal == 0)
		tmp = ft_strdup_mod(&save[i + 1], ft_strlen(&save[i + 1]));
	if (signal == 1)
		tmp = ft_strjoin(save, buf);
	free(save);
	save = NULL;
	save = ft_strdup_mod(tmp, ft_strlen(tmp));
	free(tmp);
}

int	ft_ret_read(char *save, char **line, int ret_read, int fd, char *buf, int i)
{
	while (!(ft_strchr(save, '\n')) && ret_read > 0)
	{
		ret_read = read(fd, buf, BUFFER_SIZE);
		if (ret_read < 0)
			return (-1);
		buf[ret_read] = '\0';
		if (ret_read > 0)
			ft_switch(save, 0, 1, buf);
	}
	if (ret_read > 0)
	{
		while (save[i] && save[i] != '\n')
			i++;
		*line = ft_strdup_mod(save, i);
		ft_switch(save, i, 0, buf);
	}
	if (ret_read == 0)
	{
		*line = ft_strdup_mod(save, ft_strlen(save));
		free(save);
		save = NULL;
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		buf[BUFFER_SIZE + 1];
	int		i;
	static int	ret_read;

	i = 0;
	if (!BUFFER_SIZE || fd < 0 || !line)
		return (-1);
	if (save == NULL)
	{
		ret_read = read(fd, buf, BUFFER_SIZE);
		if (ret_read < 0)
			return (-1);		
		buf[ret_read] = '\0';
		save = ft_strdup_mod(buf, ft_strlen(buf));
	}
	if(ft_strchr(save, '\n'))
	{
		while (save[i] && save[i] != '\n')
			i++;
		*line = ft_strdup_mod(save, i);
		ft_switch(save, i, 0, buf);
		return (1);
	}
	if (ret_read >= 0)
		return(ft_ret_read(save, line, ret_read, fd, buf, i));
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
	int	w;

	j = 1;
	w = 1;
	printf("\n==========================================\n");
	printf("========== TEST 1 : The Alphabet =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("coucou.txt", O_RDONLY)))
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
