/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:18:13 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/02 09:18:17 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!dst && !src)
		return (dst);
	if (((unsigned char *)(dst)) > ((unsigned char *)(src)))
	{
		while (n-- > 0)
			((unsigned char *)(dst))[n] = ((unsigned char *)(src))[n];
		return (dst);
	}
	while (i++ < n)
		((unsigned char *)(dst))[i - 1] = ((unsigned char *)(src))[i - 1];
	return (dst);
}
