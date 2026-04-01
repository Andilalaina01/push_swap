/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamy-and <mamy-and@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:10:39 by mamy-and          #+#    #+#             */
/*   Updated: 2026/01/27 12:43:26 by mamy-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	dest = (char *) malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (i < len && start + i < ft_strlen(s))
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
