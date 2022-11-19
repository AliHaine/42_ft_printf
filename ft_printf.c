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

static int	process(va_list params, const char *args, int *i)
{
	int	len;

	len = 0;
	if (isconvchar(args[1]) != 0)
	{
		len += definetype(args[1], params);
		*i = *i + 1;
	}
	else
	{
		ft_putchar(args[0]);
		len++;
	}
	return (len);
}

int	ft_printf(const char *args, ...)
{
	int		i;
	int		len;
	va_list	params;

	i = 0;
	len = 0;
	va_start(params, args);
	while (args[i])
	{
		if (args[i] == '%')
			len += process(params, args + i, &i);
		else
		{
			ft_putchar(args[i]);
			len++;
		}
		i++;
	}
	va_end(params);
	return (len);
}
/*
int main(void)
{
    unsigned long long int i = 42;
	//char q[] = "null";
    int vl = 0;
    char c = '0';
    char s[] = "salut a %x";

	printf("---------------------------\n");
	printf("\nMy result = %i\n", ft_printf(s, i));
	printf("---------------------------\n");
    vl = printf(s, i);
    printf("\nDefault result = %d", vl);
	printf("\n---------------------------");
    return 0;
}*/