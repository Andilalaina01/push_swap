/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamy-and <mamy-and@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:16:27 by mamy-and          #+#    #+#             */
/*   Updated: 2026/01/26 14:16:32 by mamy-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc (sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
