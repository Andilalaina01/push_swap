/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamy-and <mamy-and@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:07:03 by mamy-and          #+#    #+#             */
/*   Updated: 2026/01/23 13:07:05 by mamy-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		result;
	char	*s;

	s = (char *)nptr;
	sign = 1;
	result = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == 45 || *s == 43)
	{
		if (*s == 45)
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + *s - '0';
		s++;
	}
	return (sign * result);
}
