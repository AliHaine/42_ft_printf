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

#include "../libft.h"

static char	*maxminint(char *n, int i)
{
	char	*dst;

	dst = NULL;
	dst = (char *)malloc(((int) 12) * sizeof(char));
	if (dst == NULL)
		return (0);
	while (n[i])
	{
		dst[i] = n[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*negatifint(int n, int size)
{
	char	*dst;

	dst = NULL;
	dst = (char *)malloc(((int) size + 2) * sizeof(char));
	if (dst == NULL)
		return (0);
	dst[(size + 1)] = '\0';
	while (size > 0)
	{
		dst[size] = (n % 10) + '0';
		size--;
		n /= 10;
	}
	dst[size] = '-';
	return (dst);
}

static char	*positifint(int n, int size)
{
	char	*dst;

	dst = NULL;
	dst = (char *)malloc(((int) size + 1) * sizeof(char));
	if (dst == NULL)
		return (0);
	dst[(size)] = '\0';
	size--;
	while (size > 0)
	{
		dst[size] = (n % 10) + '0';
		size--;
		n /= 10;
	}
	dst[size] = n + '0';
	return (dst);
}

char	*ft_itoa(int n)
{
	int		size;
	int		i;
	char	*dst;
	short	isnegat;

	size = 1;
	dst = NULL;
	isnegat = 0;
	if (n == -2147483648)
		return (maxminint("-2147483648", 0));
	if (n < 0)
	{
		isnegat++;
		n *= -1;
	}
	i = n;
	while (i > 9)
	{
		i /= 10;
		size++;
	}
	if (isnegat == 0)
		return (positifint(n, size));
	else
		return (negatifint(n, size));
}
