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

#include "../libft.h"

static int cstrptype (char args, va_list params)
{
    char c;
    char *str;

    if (args == 'c')
    {
        c = va_arg(params, int);
        ft_putchar(c);
        return (1);
    }
    else if (args == 's')
    {
        str = va_arg(params, char *);
        ft_putstr(str);
        return (ft_strlen(((const char *)str)));
    }
    else if (args == '%')
    {
        c = va_arg(params, int);
        ft_putchar(c);
        return (1);
    }
}

static int intdndn(char args, va_list params)
{
	unsigned int	u;
    int				i;
    double			d;
    int             len;

    i = 0;
    d = 0;
    len = 0;
    if (args == 'd')
    {

    }
    else if (args == 'i')
    {
        i = va_arg(params, int);
        len = ft_itoa(i);
    }
    else if (args == 'u')
    {
		u = va_arg(params, unsigned int);
		len = ft_itoa_unsigned(u);
    }
    return (len);
}

static int psixteen(char args, va_list params)
{
	int                 i;
    int                 len;
    unsigned long long  p;

    len = 0;
	if (args == 'p')
	{
		p = va_arg(params, unsigned long long);
		len = convert_to_basesix(p, 2);
	}
	else if (args == 'x')
	{
		i = va_arg(params, int);
		len = convert_to_basesix(i, 0);
	}
	else if (args == 'X')
	{
		i = va_arg(params, int);
		len = convert_to_basesix(i, 1);
	}
    return (len);
}

static int definetype(char args, va_list params)
{
    int len;

    len = 0;
    if (args == 'c' || args == 's' || args == '%')
        len += cstrptype(args, params);
    else if (args == 'd' || args == 'i' || args == 'u')
        len += intdndn(args, params);
	else if (args == 'p' || args == 'x' || args == 'X')
		len += psixteen(args, params);
    return (len);
}

int ft_printf(const char *args, ...)
{
	int	i;
    int len;
	va_list params;

	i = 0;
    len = 0;
	va_start(params, args);
	while(args[i])
	{
		if (args[i] == '%')
        {
            if (isconvchar(args[i + 1]) != 0) {
                len += definetype(args[i + 1], params);
                i++;
            } else
                ft_putchar(args[i]);
            len++;
        }
        else {
            ft_putchar(args[i]);
            len++;
        }
        i++;
	}
    return (len);
}

int main(void)
{
    int i = 459;
    int vl = 0;
    char c = 'a';
    char s[] = "salut";
	printf("\nMy result = %d\n", ft_printf("salut a %p l", &s, 4));
    vl = printf("salut a %p l\n", &s, 4);
    printf("Default result = %d", vl);
    return 0;
}