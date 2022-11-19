/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_basesix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:22:33 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/19 19:22:35 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	convertor_char(unsigned long long int i, short up)
{
	int	v;

	if (i > 9)
		v = ft_putchar((i + up) + '0');
	else
		v = ft_putchar(i + '0');
	return (v);
}

static int	convertor_deci(unsigned long long int i, int size, short up)
{
	char	*dst;
	int		tmp;

	dst = (char *)malloc((sizeof(char) * (int) size + 1));
	if (dst == NULL)
		return (-1);
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
	tmp = ft_putstr(dst);
	free(dst);
	return (tmp);
}

static int	convertor_adress(unsigned long long int i, int size)
{
	char	*dst;
	int		tmp;

	dst = (char *)malloc(((int) size + 1) * sizeof(char));
	if (dst == NULL)
		return (-1);
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
	tmp = ft_putstr(dst);
	free(dst);
	return (tmp);
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
	int	v;

	size = get_size(n, up);
	if (size == 1 && up != 0)
	{
		v = convertor_char(n, up);
		if (v == -1)
			return (-1);
		return (size);
	}
	if (up == 39 || up == 7)
		v = convertor_deci(n, size, up);
	else
	{
		v = convertor_adress(n, size + 2);
		size += 2;
	}
	if (v == -1)
		return (-1);
	return (size);
}
