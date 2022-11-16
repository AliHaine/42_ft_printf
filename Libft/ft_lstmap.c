/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:25:22 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/11 11:25:23 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*freeall(t_list *lst, void (*del)(void *))
{
	t_list	*tmp;

	while (lst)
	{
		(*del)(lst->content);
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dst;
	t_list	*firstindex;

	if (!lst || !del)
		return (0);
	dst = malloc(sizeof(*dst));
	if (dst == NULL)
		return (0);
	dst->content = (*f)(lst->content);
	firstindex = dst;
	dst->next = 0;
	lst = lst->next;
	while (lst)
	{
		dst->next = malloc(sizeof(*dst));
		dst = dst->next;
		if (dst == 0)
			return (freeall(firstindex, del));
		dst->content = (*f)(lst->content);
		dst->next = 0;
		lst = lst->next;
	}
	return (firstindex);
}
