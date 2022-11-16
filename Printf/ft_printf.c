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

static void cstrptype (char args, va_list params)
{
    char c;
    char *str;

    if (args == 'c')
    {
        c = va_arg(params, int);
        ft_putchar(c);
    }
    else if (args == 's')
    {
        str = va_arg(params, char *);
        ft_putstr(str);
    }
    else if (args == '%')
    {
        c = va_arg(params, int);
        ft_putchar(c);
    }
}

static void intdndn(char args, va_list params)
{
	unsigned int	u;
    int				i;
    double			d;

    i = 0;
    d = 0;
    if (args == 'd')
    {

    }
    else if (args == 'i')
    {
        i = va_arg(params, int);
        ft_putstr(ft_itoa(i));
    }
    else if (args == 'u')
    {
		u = va_arg(params, unsigned int);
		ft_putstr(ft_itoa_unsigned(u));
    }

}

static void psixteen(char args, va_list params)
{
	int	i;
	void	*ptr;

	if (args == 'p')
	{
		ptr = va_arg(params, char *);
		//printf("p%s", (void *)&ptr);
		ft_putstr(((char *)&ptr));
	}
	else if (args == 'x')
	{
		i = va_arg(params, int);
		ft_putstr(convert_to_basesix(i, 0));
	}
	else if (args == 'X')
	{
		i = va_arg(params, int);
		ft_putstr(convert_to_basesix(i, 1));
	}
}

static void definetype(char args, va_list params)
{
    char c;
    char *str;

    if (args == 'c' || args == 's' || args == '%')
        cstrptype(args, params);
    else if (args == 'd' || args == 'i' || args == 'u')
        intdndn(args, params);
	else if (args == 'p' || args == 'x' || args == 'X')
		psixteen(args, params);
}

int ft_printf(const char *args, ...)
{
	int	i;
	va_list params;

	i = 0;
	va_start(params, args);
	while(args[i])
	{
		if (args[i] == '%') {
            if (isconvchar(args[i + 1]) != 0) {
                definetype(args[i + 1], params);
                i++;
            } else
                ft_putchar(args[i]);
        }
        else
            ft_putchar(args[i]);
        i++;
	}
    return (0);
}

int main(void)
{
    int i = 489498;
    char c = 'a';
    char s[] = "salut";
	ft_printf("salut a %p l%x", i, 4);
    return 0;
}