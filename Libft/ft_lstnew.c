/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:10:15 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/09 17:10:16 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nc;

	nc = malloc(sizeof(t_list));
	if (nc == NULL)
		return (0);
	nc->content = content;
	nc->next = NULL;
	return (nc);
}
