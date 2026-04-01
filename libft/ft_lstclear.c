/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamy-and <mamy-and@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 08:56:08 by mamy-and          #+#    #+#             */
/*   Updated: 2026/02/06 08:10:29 by mamy-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temporary;

	if (!(*lst) || !del || !lst)
		return ;
	temporary = NULL;
	while (*lst)
	{
		temporary = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temporary;
	}
}
