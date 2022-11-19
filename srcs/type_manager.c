/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:12:31 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/19 17:12:33 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	perchar(char args, va_list params)
{
	char	c;
	int		v;

	if (args == 'c')
	{
		c = va_arg(params, int);
		v = ft_putchar(c);
	}
	else
		v = ft_putchar('%');
	if (v == -1)
		return (-1);
	return (1);
}

static int	cstrptype(va_list params)
{
	char	*str;
	int		v;

	str = va_arg(params, char *);
	if (str == NULL)
	{
		v = ft_putstr("(null)");
		if (v == -1)
			return (-1);
		return (6);
	}
	v = ft_putstr(str);
	if (v == -1)
		return (-1);
	return (ft_strlen(((const char *)str)));
}

static int	intdndn(char args, va_list params)
{
	unsigned int	u;
	int				i;
	int				len;

	i = 0;
	len = 0;
	if (args == 'i' || args == 'd')
	{
		i = va_arg(params, int);
		len = ft_itoa(i);
	}
	else
	{
		u = va_arg(params, unsigned int);
		len = ft_itoa_unsigned(u);
	}
	return (len);
}

static int	psixteen(char args, va_list params)
{
	int					i;
	int					len;
	unsigned long long	p;

	if (args == 'p')
	{
		p = va_arg(params, unsigned long long);
		len = convert_to_basesix(p, 0);
	}
	else if (args == 'x')
	{
		i = va_arg(params, int);
		len = convert_to_basesix(i, 39);
	}
	else
	{
		i = va_arg(params, int);
		len = convert_to_basesix(i, 7);
	}
	return (len);
}

int	definetype(char args, va_list params)
{
	int	len;

	len = 0;
	if (args == 's')
		len += cstrptype(params);
	else if (args == 'd' || args == 'i' || args == 'u')
		len += intdndn(args, params);
	else if (args == 'p' || args == 'x' || args == 'X')
		len += psixteen(args, params);
	else if (args == 'c' || args == '%')
		len += perchar(args, params);
	return (len);
}
