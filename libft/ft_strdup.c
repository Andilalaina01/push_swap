/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamy-and <mamy-and@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:07:35 by mamy-and          #+#    #+#             */
/*   Updated: 2026/01/23 13:07:37 by mamy-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy_s;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	copy_s = (char *)malloc(sizeof(char) * (len + 1));
	if (copy_s == NULL)
		return (NULL);
	while (len > i)
	{
		copy_s[i] = s[i];
		i++;
	}
	copy_s[i] = '\0';
	return (copy_s);
}
