/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isconvchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:59:24 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/15 12:59:26 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	isconvchar(char args)
{
	if (args == 'c' || args == 's' || args == 'p'
		|| args == 'd' || args == 'i' || args == 'u'
		|| args == 'x' || args == 'X' || args == '%')
	{
		return (args);
	}
	return (0);
}
