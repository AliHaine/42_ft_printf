/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:15:20 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/03 14:15:21 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		x;
	char	*dst;

	i = ft_strlen(((char *)s1)) + ft_strlen(((char *)s2));
	x = 0;
	dst = (char *) malloc((i + 1) * sizeof(char));
	if (dst == NULL)
		return (0);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
		x++;
	}
	i = 0;
	while (s2[i])
	{
		dst[x] = s2[i];
		i++;
		x++;
	}
	dst[x] = '\0';
	return (dst);
}
