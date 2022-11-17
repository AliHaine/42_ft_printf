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

#include "../ft_printf.h"

static void convertor_lower(int i, int size)
{
	char	*dst;
	short tmp;

	dst = (char *)malloc(((int) size) * sizeof(char));
	if (dst == NULL)
		return ;
	dst[(size)] = '\0';
	while (size-- > 0)
	{
		tmp = (i % 16);
		if (tmp > 9)
			dst[size] = (tmp + 39) + '0';
		else
			dst[size] = tmp + '0';
		i /= 16;
	}
	dst[size] = i + '0';
    ft_putstr(dst);
    free(dst);
}

static void convertor_upper(int i, int size)
{
	char	*dst;
	short	tmp;

	dst = (char *)malloc(((int) size + 1) * sizeof(char));
	if (dst == NULL)
		return ;
	dst[(size)] = '\0';
	while (size-- > 0)
	{
		tmp = (i % 16);
		if (tmp > 9)
			dst[size] = (tmp + 7) + '0';
		else
			dst[size] = tmp + '0';
		i /= 16;
	}
	dst[size] = (i % 16) + '0';
    ft_putstr(dst);
    free(dst);
}

static void convertor_adress(long long i, int size)
{
    char	*dst;
    short	tmp;

    dst = (char *)malloc(((int) size + 1) * sizeof(char));
    if (dst == NULL)
        return ;
    dst[(size)] = '\0';
    while (size-- > 0)
    {
        if (size < 2)
        {
            dst[size] = 'x';
            dst[size - 1] = '0';
            break;
        }
        tmp = (i % 16);
        if (tmp > 9)
            dst[size] = (tmp + 39) + '0';
        else
            dst[size] = tmp + '0';
        i /= 16;
    }
    ft_putstr(dst);
    free(dst);
}

int convert_to_basesix(long long int n, short s)
{
	int							size;
	unsigned long long int		i;

	size = 1;
	i = n;
	while (i > 9)
	{
		i /= 16;
		size++;
	}
    if (size == 1)
    {
        ft_putchar(n);
        return (size);
    }
	if (s == 0)
        convertor_lower(n, size);
    else if (s == 1)
        convertor_upper(n, size);
    else
	{
		convertor_adress(n, size + 2);
		size += 2;
	}
    return (size);
}
