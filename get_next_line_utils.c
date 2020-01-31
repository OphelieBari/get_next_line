/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:34:17 by ophelieba         #+#    #+#             */
/*   Updated: 2020/01/31 00:00:48 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	size_t i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	j = 0;
	i = ft_strlen(s1);
	if (!s1 || !s2)
		return (0);
	while (s2[j])
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == '\0')
			i++;
		else
		{
			((char*)s)[i] = '\0';
			i++;
		}
	}
}
