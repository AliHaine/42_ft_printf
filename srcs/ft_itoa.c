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

static void maxminint(char *n, int i)
{
	char	*dst;

	dst = NULL;
	dst = (char *)malloc(((int) 12) * sizeof(char));
	if (dst == NULL)
		return ;
	while (n[i])
	{
		dst[i] = n[i];
		i++;
	}
	dst[i] = '\0';
    ft_putstr(dst);
    free(dst);
}

static void negatifint(int n, int size)
{
	char	*dst;

	dst = NULL;
	dst = (char *)malloc(((int) size + 2) * sizeof(char));
	if (dst == NULL)
		return ;
	dst[(size + 1)] = '\0';
	while (size > 0)
	{
		dst[size] = (n % 10) + '0';
		size--;
		n /= 10;
	}
	dst[size] = '-';
    ft_putstr(dst);
    free(dst);
}

static void positifint(int n, int size)
{
	char	*dst;

	dst = NULL;
	dst = (char *)malloc(((int) size + 1) * sizeof(char));
	if (dst == NULL)
		return ;
	dst[(size)] = '\0';
	size--;
	while (size > 0)
	{
		dst[size] = (n % 10) + '0';
		size--;
		n /= 10;
	}
	dst[size] = n + '0';
    ft_putstr(dst);
    free(dst);
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

int ft_itoa(int n)
{
	int		size;
	short	isnegat;

	size = 1;
	isnegat = 0;
	if (n == -2147483648) {
        maxminint("-2147483648", 0);
        return (11);
    }
	if (n < 0)
	{
		isnegat++;
		n *= -1;
	}
	size += get_size(n);
	if (isnegat == 0)
		positifint(n, size);
	else
		negatifint(n, size);
    return (size);
}
