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

static int	cstrptype(char args, va_list params)
{
	char	c;
	char	*str;

	if (args == 'c')
	{
		c = va_arg(params, int);
		ft_putchar(c);
		return (1);
	}
	else if (args == 's')
	{
		str = va_arg(params, char *);
		if (str == NULL)
		{
			ft_putstr("(null)");
			return (6);
		}
		ft_putstr(str);
		return (ft_strlen(((const char *)str)));
	}
	ft_putchar('%');
	return (1);
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
	if (args == 'c' || args == 's' || args == '%')
		len += cstrptype(args, params);
	else if (args == 'd' || args == 'i' || args == 'u')
		len += intdndn(args, params);
	else if (args == 'p' || args == 'x' || args == 'X')
		len += psixteen(args, params);
	return (len);
}
