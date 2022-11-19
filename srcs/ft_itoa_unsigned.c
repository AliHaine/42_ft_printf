/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:01:13 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/17 16:01:14 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	positifint(unsigned int n, int size)
{
	char	*dst;
	int		v;

	dst = NULL;
	dst = (char *)malloc(((int) size + 1) * sizeof(char));
	if (dst == NULL)
		return (-1);
	dst[(size)] = '\0';
	size--;
	while (size > 0)
	{
		dst[size] = (n % 10) + '0';
		size--;
		n /= 10;
	}
	dst[size] = n + '0';
	v = ft_putstr(dst);
	free(dst);
	return (v);
}

static int	get_size(unsigned int i)
{
	int	size;

	size = 0;
	while (i > 9)
	{
		i /= 10;
		size++;
	}
	return (size);
}

int	ft_itoa_unsigned(unsigned int n)
{
	int	size;
	int	v;

	size = 1;
	size += get_size(n);
	v = positifint(n, size);
	if (v == -1)
		return (-1);
	return (size);
}
