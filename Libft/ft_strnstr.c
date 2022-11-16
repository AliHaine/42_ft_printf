/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:54:26 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/01 10:54:27 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trytofind(const char *s2, const char *s1, size_t len, int size)
{
	size_t	i;
	int		a;

	i = 0;
	a = 0;
	while (i < len && s2[i])
	{
		if (s1[a] == s2[i])
			a++;
		else
			a = 0;
		if (a == size)
			return (((char *)s2 + (i - (size - 1))));
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *s2, const char *s1, size_t len)
{
	size_t	i;
	int		size;

	i = 0;
	size = 0;
	while (s1[size])
		size++;
	if (size < 1)
		return (((char *)s2));
	if (len <= 0)
		return (0);
	while (s2[i])
	{
		if ((len - i) > len)
			return (0);
		if (trytofind(s2 + i, s1, (len - i), size) != 0)
			return (trytofind(s2 + i, s1, (len - i), size));
		i++;
	}
	return (0);
}
