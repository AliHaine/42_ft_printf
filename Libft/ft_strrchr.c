/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:53:38 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/01 10:53:39 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int strchar)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (((char)strchar) == '\0')
		return ((char *)(str + i));
	i--;
	while (i >= 0)
	{
		if (str[i] == ((char)strchar))
			return ((char *)(str + i));
		i--;
	}
	return (0);
}
