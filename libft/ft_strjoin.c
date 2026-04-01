/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamy-and <mamy-and@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:15 by mamy-and          #+#    #+#             */
/*   Updated: 2026/01/23 14:14:19 by mamy-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		res[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		res[i] = *s2;
		i++;
		s2++;
	}
	res[i] = '\0';
	return (res);
}
