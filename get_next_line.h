/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:28:54 by ophelieba         #+#    #+#             */
/*   Updated: 2020/01/30 18:43:58 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

typedef unsigned long int size_t;

char	*ft_strcpy(char *s1, const char *s2);
int		get_next_line(int fd, char **line);
char	*ft_strcat(char *s1, const char *s2);
int	ft_strlen(const char *s);

#endif
