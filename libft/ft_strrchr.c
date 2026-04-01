/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamy-and <mamy-and@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:05:48 by mamy-and          #+#    #+#             */
/*   Updated: 2026/01/23 13:05:51 by mamy-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*str;

	str = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
