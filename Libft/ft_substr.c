/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:39:15 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/03 10:39:18 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		size;
	char	*dst;

	i = 0;
	size = ft_strlen(((char *)s));
	if (len == 0 || ((unsigned int) size) < start)
		return (ft_calloc(1, 1));
	if (size - start > len)
		dst = (char *) malloc((len + 1) * sizeof(char));
	else
	{
		dst = (char *) malloc(((size - start) + 1) * sizeof(char));
		len = size - start;
	}
	if (dst == NULL || !s)
		return (dst);
	while (len > 0 && s[i])
	{
		dst[i++] = s[start++];
		len--;
	}
	dst[i] = '\0';
	return (dst);
}
