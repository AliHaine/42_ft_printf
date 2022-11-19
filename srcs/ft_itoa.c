/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:25:53 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/03 16:25:55 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	maxminint(void)
{
	int		v;

	v = ft_putstr("-2147483648");
	if (v == -1)
		return (-1);
	return (11);
}

static int	negatifint(int n, int size)
{
	char	*dst;
	int		v;

	dst = NULL;
	dst = (char *)malloc(((int) size + 2) * sizeof(char));
	if (dst == NULL)
		return (-1);
	dst[size + 1] = '\0';
	while (size > 0)
	{
		dst[size] = (n % 10) + '0';
		size--;
		n /= 10;
	}
	dst[size] = '-';
	v = ft_putstr(dst);
	free(dst);
	if (v == -1)
		return (v);
	return (1);
}

static int	positifint(int n, int size)
{
	char	*dst;
	int		v;

	dst = NULL;
	dst = (char *)malloc(((int) size + 1) * sizeof(char));
	if (dst == NULL)
		return (-1);
	dst[size] = '\0';
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
	if (v == -1)
		return (v);
	return (1);
}

static int	get_size(int i)
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

int	ft_itoa(int n)
{
	int		size;
	short	isnegat;
	int		v;

	size = 1;
	isnegat = 0;
	if (n == -2147483648)
		return (maxminint());
	if (n < 0)
	{
		isnegat++;
		n *= -1;
	}
	size += get_size(n);
	if (isnegat == 0)
		v = positifint(n, size);
	else
		v = negatifint(n, size);
	if (v == -1)
		return (-1);
	return (size + isnegat);
}
