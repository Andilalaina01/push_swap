/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamy-and <mamy-and@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:07:19 by mamy-and          #+#    #+#             */
/*   Updated: 2026/01/23 13:07:21 by mamy-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	size_t	total;

	total = nmemb * size;
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	pointer = (void *) malloc(total);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, total);
	return (pointer);
}
