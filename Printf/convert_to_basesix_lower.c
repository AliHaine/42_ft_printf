/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_basesix_lower.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:40:54 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/15 16:40:55 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*convertor_lower(int i, int size)
{
	char	*dst;
	short tmp;

	if (size == 0)
		size++;
	dst = (char *)malloc(((int) size) * sizeof(char));
	if (dst == NULL)
		return (0);
	dst[(size)] = '\0';
	size--;
	while (size > 0)
	{
		tmp = (i % 16);
		if (tmp > 9)
			dst[size] = (tmp + 39) + '0';
		else
			dst[size] = tmp + '0';
		size--;
		i /= 16;
	}
	dst[size] = i + '0';
	return (dst);
}

static char	*convertor_upper(int i, int size)
{
	char	*dst;
	short	tmp;

	if (size == 0)
		size++;
	dst = (char *)malloc(((int) size) * sizeof(char));
	if (dst == NULL)
		return (0);
	dst[(size)] = '\0';
	size--;
	while (size > 0)
	{
		tmp = (i % 16);
		if (tmp > 9)
			dst[size] = (tmp + 7) + '0';
		else
			dst[size] = tmp + '0';
		size--;
		i /= 16;
	}
	dst[size] = (i % 16) + '0';
	return (dst);
}

char	*convert_to_basesix(int n, short s)
{
	int					size;
	unsigned int		i;

	size = 0;
	i = n;
	while (i > 9)
	{
		i /= 10;
		size++;
	}
	if (s == 0)
		return (convertor_lower(n, size));
	return (convertor_upper(n, size));

}
