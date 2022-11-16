/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:55:52 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/09 13:55:56 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**splitfree(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	countword(char const *s, char c)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			number++;
			while (s[i] != c && s[i])
				i++;
		}
		if (!s[i])
			break ;
		i++;
	}
	return (number);
}

static char	*getword(char const *s, char c)
{
	int		i;
	int		size;
	char	*word;

	i = 0;
	size = 0;
	word = NULL;
	while (s[size] != c && s[size])
	{
		size++;
	}
	word = malloc(sizeof(char) * (size + 1));
	if (word == NULL)
		return (0);
	while (i < size)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		x;
	int		nbrword;
	char	**tab;

	i = 0;
	x = 0;
	nbrword = countword((s + i), c);
	tab = malloc((sizeof(char *) * (nbrword + 1)));
	if (tab == NULL)
		return (0);
	while (nbrword-- > 0)
	{
		while (s[i] == c)
			i++;
		tab[x] = getword((s + i), c);
		if (tab[x] == 0)
			return (splitfree(tab));
		while (s[i] != c && s[i])
			i++;
		x++;
	}
	tab[x] = NULL;
	return (tab);
}
