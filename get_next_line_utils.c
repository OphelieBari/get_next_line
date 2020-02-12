/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opheliebaribaud <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:34:17 by ophelieba         #+#    #+#             */
/*   Updated: 2020/02/12 17:16:51 by obaribau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup_mod(const char *s1, int j)
{
	char	*tab;
	int		i;

	i = 0;
	if (!s1)
		return (0);
	if (!(tab = malloc(sizeof(char) * (j + 1))))
		return (0);
	while (s1[i] && i < j)
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

int		ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while (*str != (char)c && *str != '\0')
		str++;
	if (*str == (char)c)
		return (1);
	return (0);
}
