/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:03:02 by ophelieba         #+#    #+#             */
/*   Updated: 2020/02/11 16:50:54 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		buf[BUFFER_SIZE + 1];
	int		i;
	static int	ret_read;
	char		*tmp;

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
		tmp = ft_strdup_mod(&save[i + 1], ft_strlen(&save[i + 1]));
		free(save);
		save = NULL;
		save = ft_strdup_mod(tmp, ft_strlen(tmp));
		free(tmp);
		return (1);
	}
	if (ret_read >= 0)
	{
		while (!(ft_strchr(save, '\n')) && ret_read > 0)
		{
			ret_read = read(fd, buf, BUFFER_SIZE);
			if (ret_read < 0)
				return (-1);
			buf[ret_read] = '\0';
			if (ret_read > 0)
			{
				tmp = ft_strjoin(save, buf);
				free(save);
				save = NULL;
				save = ft_strdup_mod(tmp, ft_strlen(tmp));
				free(tmp);
			}	
		}
		if (ret_read > 0)
		{
			while (save[i] && save[i] != '\n')
				i++;
			*line = ft_strdup_mod(save, i);
			tmp = ft_strdup_mod(&save[i + 1], ft_strlen(&save[i+ 1]));
			free(save);
			save = NULL;
			save = ft_strdup_mod(tmp, ft_strlen(tmp));
			free(tmp);
		}
		if (ret_read == 0)
		{
			*line = ft_strdup_mod(save, ft_strlen(save));
			free(save);
			save = NULL;
			return (0);
		}
		return(1);
	}
	return (0);
}

#include <stdio.h>

/*int main()
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
}*/
