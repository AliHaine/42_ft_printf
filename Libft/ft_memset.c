/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:51:35 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/01 10:51:38 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t size)
{
	int	i;

	i = 0;
	while (size > 0)
	{
		((unsigned char *) pointer)[i++] = (unsigned char) value;
		size--;
	}
	return (pointer);
}
