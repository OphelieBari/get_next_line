/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:34:17 by ophelieba         #+#    #+#             */
/*   Updated: 2020/01/31 18:42:27 by obaribau         ###   ########.fr       */
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

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
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

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		i;

	i = 0;
	if (!s1)
		return (0);
	if (!(tab = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char*tab;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	if (s1)
	{
		while (s1[i])
		{
			tab[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		tab[i] = s2[j];
		i++;
		j++;
	}
	tab[i] = 0;
	return (tab);
}
