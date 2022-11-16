/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:10:04 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/12 15:22:41 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_start(char const *s1, char const *set, unsigned int start)
{
	char			c;
	unsigned int	x;

	c = 0;
	x = 0;
	start = 0;
	while (set[x])
	{
		c = set[x];
		while (s1[start] == c)
		{
			x = -1;
			start++;
		}
		x++;
	}
	return (start);
}

static int	set_end(char const *s1, char const *set, unsigned int end)
{
	char			c;
	unsigned int	x;
	unsigned int	defend;

	c = 0;
	x = 0;
	end = ft_strlen(((char *)s1)) - 1;
	defend = end;
	while (set[x])
	{
		c = set[x];
		while (s1[end] == c)
		{
			end--;
			x = -1;
		}
		x++;
	}
	return (end + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*dst;

	start = set_start(s1, set, 0);
	if (start == ft_strlen(((char *)s1)))
		return (ft_calloc(1, 1));
	end = set_end(s1, set, 0);
	dst = (char *) malloc(((end - start) + 1) * sizeof(char));
	if (dst == NULL)
		return (0);
	ft_strlcpy(dst, s1 + start, (end - start) + 1);
	return (dst);
}
