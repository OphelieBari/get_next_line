/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:23:16 by ophelieba         #+#    #+#             */
/*   Updated: 2020/01/30 15:06:04 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	re_malloc(char *buf)
{
	static char	*save;
	char		*tmp;

	if(!(tmp = malloc(ft_strlen(save) + 1)));
		return (0);
	ft_strcpy(tmp, save);
	if(!(save = malloc(ft_strlen(buf) + ft_strlen(tmp) + 1)))
		return (0);
	*save = ft_strcat(tmp, buf);
	free(tmp);
	return (save);
}	

int	get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE];
	int	ret_read;
	int	i;

	while (ret_read = read(fd, buf + i, 1))
	{
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			//*line = re_malloc(buf); (dans l'idée)
			return (1);
		}
		if (i == BUFFER_SIZE)
		{
			re_malloc(buf);
			i = 0;
		}
		else
			i++
	}
	//*line = re_malloc(buf); (dans l'idée)
	return (0);
}

int main()
{
	while (count)
	{
		
	}
}
