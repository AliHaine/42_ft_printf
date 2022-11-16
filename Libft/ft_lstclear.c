/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:05:14 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/10 17:05:16 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (!(*del) || !lst)
		return ;
	while (*lst)
	{
		(*del)((*lst)->content);
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}
