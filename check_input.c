/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamy-and <mamy-and@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:37:30 by mamy-and          #+#    #+#             */
/*   Updated: 2026/03/25 18:37:31 by mamy-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_number(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	if (!av[i])
		return (0);
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	check_doubles(char **av)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	while (av[len])
		len++;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_input(char **av)
{
	int			i;
	long		tmp;

	i = 0;
	while (av[i])
	{
		if (!check_number(av[i]))
			return (0);
		tmp = ft_atol(av[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
			return (0);
		i++;
	}
	if (check_doubles(av))
		return (0);
	return (1);
}

void	check_input_and_error(int ac, int i, char ***final_args)
{
	if (!*final_args || !(*final_args)[0] || !check_input(*final_args))
	{
		if (*final_args && (ac - i == 1))
			free_tab(*final_args);
		ft_exit();
	}
}
