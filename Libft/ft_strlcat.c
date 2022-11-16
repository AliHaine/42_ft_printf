/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:53:27 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/12 15:20:38 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	dst_size;
	size_t	src_size;

	i = 0;
	if ((!dst || !src) && !size)
		return (0);
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(((char *)src));
	if (size == 0)
		return (src_size);
	if (size < dst_size)
		src_size += size;
	else
		src_size += dst_size;
	while (src[i] && (dst_size + i) < (size - 1))
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (src_size);
}
