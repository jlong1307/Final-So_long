/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:04:55 by jlong             #+#    #+#             */
/*   Updated: 2021/04/26 15:05:03 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_of_sep(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*s == '\0')
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
			j = 0;
		else if (j == 0)
		{
			j = 1;
			i++;
		}
		s++;
	}
	return (i);
}

static int	len_of_str(const char *ss, char c, int start)
{
	int	i;

	i = 0;
	while (ss[start] != c && ss[start] != '\0')
	{
		i++;
		start++;
	}
	return (i);
}

static char	**free_t(const char **tab, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		free ((void *)tab[n]);
		i++;
	}
	free (tab);
	return (NULL);
}

static char	**split_str(const char *str, char **ftab, char c, int nb)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	while (str[i] != '\0' && j < nb)
	{
		k = 0;
		while (str[i] == c)
			i++;
		ftab[j] = malloc(sizeof(char) * len_of_str(str, c, i) + 1);
		if (ftab[j] == NULL)
			return (free_t((const char **)ftab, j));
		while (str[i] != '\0' && str[i] != c)
		{
			ftab[j][k] = str[i];
			k++;
			i++;
		}
		ftab[j][k] = '\0';
		j++;
	}
	ftab[j] = 0;
	return (ftab);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	i = nbr_of_sep(s, c);
	tab = malloc(sizeof(char **) * (i + 1));
	if (!tab)
		return (NULL);
	return (split_str(s, tab, c, i));
}
