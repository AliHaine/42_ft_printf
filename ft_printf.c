/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:35:06 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/13 14:43:33 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process(va_list params, const char *args)
{
	int	len;

	if (isconvchar(args[1]) != 0)
	{
		len = definetype(args[1], params);
		if (len == -1)
			return (-1);
	}
	else
	{
		len = ft_putchar(args[0]);
		if (len == -1)
			return (-1);
		len++;
	}
	return (len);
}

static int	pre_process(const char *args, va_list params, int *p)
{
	int	v;
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (args[i] == '%')
	{
		v = process(params, args + i);
		*p = *p + 2;
		len += v;
	}
	else
	{
		v = ft_putchar(args[i]);
		*p = *p + 1;
		len++;
	}
	if (v == -1)
		return (-1);
	return (len);
}

int	ft_printf(const char *args, ...)
{
	int		i;
	int		len;
	int		v;
	va_list	params;

	i = 0;
	len = 0;
	va_start(params, args);
	while (args[i])
	{
		v = pre_process(args + i, params, &i);
		len += v;
		if (v == -1)
			return (-1);
	}
	va_end(params);
	return (len);
}
