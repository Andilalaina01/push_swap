/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamy-and <mamy-and@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:37:14 by mamy-and          #+#    #+#             */
/*   Updated: 2026/03/25 19:30:53 by mamy-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_strat_name(t_app *strategy, double dis)
{
	if (strategy->selected_strat == 1)
		return ("Simple (O(n" "\xc2\xb2" "))");
	else if (strategy->selected_strat == 2)
		return ("Medium (O(n\xe2\x88\x9an))");
	else if (strategy->selected_strat == 3)
		return ("Complex (O(nlogn))");
	else if (strategy->selected_strat == 0 && dis < 0.2)
		return ("Adaptive / (O(n" "\xc2\xb2" "))");
	else if (strategy->selected_strat == 0 && (dis >= 0.2 && dis < 0.50))
		return ("Adaptive / (O(n\xe2\x88\x9an))");
	else if (strategy->selected_strat == 0 && dis >= 0.50)
		return ("Adaptive / O(nlogn)");
	return ("Unknown Strategy");
}

static char	*get_disorder_in_str(double disorder)
{
	char	*str;
	int		whole;
	int		dec;
	long	total;

	str = malloc(sizeof(char) * 8);
	if (!str)
		return (NULL);
	total = (long)(disorder * 10000);
	whole = total / 100;
	dec = total % 100;
	if (whole == 100)
	{
		ft_strlcpy(str, "100.00%", 8);
		return (str);
	}
	str[0] = (whole / 10) + 48;
	str[1] = (whole % 10) + 48;
	str[2] = '.';
	str[3] = (dec / 10) + 48;
	str[4] = (dec % 10) + 48;
	str[5] = '%';
	str[6] = '\0';
	return (str);
}

static void	ft_printf(const char *str, ...)
{
	va_list	args;
	int		index;

	index = 0;
	va_start(args, str);
	while (str[index])
	{
		if (str[index] == '%' && str[index + 1])
		{
			if (str[index + 1] == 's')
				ft_putstr_fd(va_arg(args, char *), 2);
			else if (str[index + 1] == 'd')
				ft_putnbr_fd(va_arg(args, int), 2);
			index++;
		}
		else
			ft_putchar_fd(str[index], 2);
		index++;
	}
	va_end(args);
}

void	display_bench(t_app *app, double disorder)
{
	char	*dis;

	dis = get_disorder_in_str(disorder);
	ft_printf("[bench] disorder: %s\n", dis);
	ft_printf("[bench] strategie: %s\n", get_strat_name(app, disorder));
	ft_printf("[bench] total_ops: %d\n", app->ops.total);
	ft_printf("[bench] sa: %d	sb: %d	ss: %d	pa: %d	pb: %d\n", app->ops.sa,
		app->ops.sb, app->ops.ss, app->ops.pa, app->ops.pb);
	ft_printf("[bench] ra: %d	rb: %d	rr: %d	rra: %d	rrb: %d	rrr: %d\n",
		app->ops.ra, app->ops.rb, app->ops.rr, app->ops.rra,
		app->ops.rrb, app->ops.rrr);
	free (dis);
}
