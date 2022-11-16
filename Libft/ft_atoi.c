/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:04:47 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/01 11:04:49 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *src)
{
	int	result;
	int	i;
	int	negat;

	result = 0;
	i = 0;
	negat = 1;
	while ((src[i] >= 9 && src[i] <= 13) || src[i] == ' ')
		i++;
	if (src[i] == '\0')
		return (result);
	if (src[i] == '+' || src[i] == '-')
	{
		if (src[i] == '-')
			negat = -1;
		i++;
	}
	while (src[i])
	{
		if (!(src[i] >= '0' && src[i] <= '9'))
			return (result * negat);
		result = (result * 10) + (src[i] - '0');
		i++;
	}
	return (result * negat);
}
