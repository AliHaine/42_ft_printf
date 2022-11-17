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
        ft_putstr(str);
        return (ft_strlen(((const char *)str)));
    }
    else
    {
        c = va_arg(params, int);
        ft_putchar(c);
		return (1);
    }
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
	else
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
            }
			else
			{
				ft_putchar(args[i]);
				len++;
			}
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
    //int i = 1;li
	char q[] = "je try";
    int vl = 0;
    char c = '0';
    char s[] = "salut a %p";

	printf("---------------------------\n");
	printf("\nMy result = %i\n", ft_printf(s, -1));
	printf("---------------------------\n");
    vl = printf(s, -1);
    printf("\nDefault result = %d", vl);
	printf("\n---------------------------");
    return 0;
}