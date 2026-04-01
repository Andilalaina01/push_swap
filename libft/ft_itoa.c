/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamy-and <mamy-and@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:08:04 by mamy-and          #+#    #+#             */
/*   Updated: 2026/01/23 13:08:06 by mamy-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_nbrlen(long n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	j;
	long	nb;

	nb = n;
	j = ft_nbrlen(nb);
	res = malloc(sizeof(char) * (j + 1));
	if (res == NULL)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		res[0] = '-';
	}
	if (nb == 0)
		res[0] = '0';
	res[j] = '\0';
	j--;
	while (nb > 0)
	{
		res[j] = (nb % 10) + '0';
		nb = (nb / 10);
		j--;
	}
	return (res);
}
