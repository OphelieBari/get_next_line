/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:57:49 by ophelieba         #+#    #+#             */
/*   Updated: 2020/01/27 13:31:41 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE];
	int	i;
	int	ret_read;

	i = 0;
	while (i < BUFFER_SIZE && (ret_read = read(fd, buf + i, 1)) && buf[i] != '\n')
	{
		if(ret_read == -1)
			return (-1);
		i++;
	}	
	if (i == BUFFER_SIZE)
		return(-1);
	buf[i] = '\0';
	if (!(*line = malloc(sizeof(char) * (i + 1))))
		return (-1);
	ft_strcpy(*line, buf);
	if(ret_read == 0)
		return(0);
	else
		return(1);
}

int	main()
{
	char	*tmp;
	int	fd;
	int	cont;
	int	ret;

	cont = 1;
	ret = 0;
	fd = open("vide.txt", O_RDONLY);
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
