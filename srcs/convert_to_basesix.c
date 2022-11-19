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

static void	convertor_char(unsigned long long int i, short up)
{
	if (i > 9)
		ft_putchar((i + up) + '0');
	else
		ft_putchar(i + '0');
}

static void	convertor_deci(unsigned long long int i, int size, short up)
{
	char	*dst;
	short	tmp;

	dst = (char *)malloc((sizeof(char) * (int) size + 1));
	if (dst == NULL)
		return ;
	dst[size] = '\0';
	while (size-- > 0)
	{
		tmp = (i % 16);
		if (tmp > 9)
			dst[size] = (tmp + up) + '0';
		else
			dst[size] = tmp + '0';
		i /= 16;
	}
	dst[size] = (i % 16) + '0';
	ft_putstr(dst);
	free(dst);
}

static void	convertor_adress(unsigned long long int i, int size)
{
	char	*dst;
	short	tmp;

	dst = (char *)malloc(((int) size + 1) * sizeof(char));
	if (dst == NULL)
		return ;
	dst[size] = '\0';
	while (size-- > 0)
	{
		if (size < 2)
			break ;
		tmp = (i % 16);
		if (tmp > 9)
			dst[size] = (tmp + 39) + '0';
		else
			dst[size] = tmp + '0';
		i /= 16;
	}
	dst[size] = 'x';
	dst[size - 1] = '0';
	ft_putstr(dst);
	free(dst);
}

static int	get_size(unsigned long long int val, short up)
{
	int	size;

	size = 1;
	while (val > 15)
	{
		val /= 16;
		size++;
	}
	if (size > 8 && up != 0)
		return (8);
	return (size);
}

int	convert_to_basesix(unsigned long long int n, short up)
{
	int	size;

	size = get_size(n, up);
	if (size == 1 && up != 0)
	{
		convertor_char(n, up);
		return (size);
	}
	if (up == 39 || up == 7)
		convertor_deci(n, size, up);
	else
	{
		convertor_adress(n, size + 2);
		size += 2;
	}
	return (size);
}
