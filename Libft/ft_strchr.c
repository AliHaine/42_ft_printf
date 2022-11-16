/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:52:39 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/01 10:52:41 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int strchar)
{
	int	i;

	i = 0;
	if (((char)strchar) == 0)
		return (((char *)(str + ft_strlen(str))));
	while (str[i])
	{
		if (str[i] == ((char)(strchar)))
			return (((char *)(str + i)));
		i++;
	}
	return (0);
}
