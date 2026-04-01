/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamy-and <mamy-and@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:51:00 by safidian          #+#    #+#             */
/*   Updated: 2026/03/25 18:38:39 by mamy-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **av)
{
	int	i;

	i = 0;
	if (!av)
		return ;
	while (av[i])
		free(av[i++]);
	free(av);
}

int	ft_sqrt(int nb)
{
	int	n;

	if (nb <= 0)
		return (0);
	n = 1;
	while (n * n <= nb)
		n++;
	return (n - 1);
}

long	ft_atol(const char *nptr)
{
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	while (*nptr && ((*nptr >= 9 && *nptr <= 13) || *nptr == 32))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr && (*nptr >= 48 && *nptr <= 57))
		result = result * 10 + (*nptr++ - 48);
	return (result * sign);
}

void	ft_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit (1);
}

void	print_op(char *str)
{
	ft_putendl_fd(str, 1);
}
