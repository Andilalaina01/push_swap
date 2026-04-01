/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamy-and <mamy-and@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:23:44 by safidian          #+#    #+#             */
/*   Updated: 2026/03/25 18:47:39 by mamy-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack **stack_a)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*current;
	t_stack	*compare;

	mistakes = 0;
	total_pairs = 0;
	current = *stack_a;
	while (current != NULL && current->next != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			total_pairs++;
			if (compare->value < current->value)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	if (mistakes == 0 && total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}

void	select_strategy(int ac, int *i, char **av, t_app *app)
{
	*i = 1;
	app->selected_strat = 0;
	ft_memset(&(app->ops), 0, sizeof(t_stats));
	app->bench_mode = 0;
	while (*i < ac && av[*i][0] == '-' && av[*i][1] == '-')
	{
		if (ft_strncmp(av[*i], "--simple", 20) == 0)
			app->selected_strat = 1;
		else if (ft_strncmp(av[*i], "--medium", 20) == 0)
			app->selected_strat = 2;
		else if (ft_strncmp(av[*i], "--complex", 20) == 0)
			app->selected_strat = 3;
		else if (ft_strncmp(av[*i], "--adaptive", 20) == 0)
			app->selected_strat = 0;
		else if (ft_strncmp(av[*i], "--bench", 20) == 0)
			app->bench_mode = 1;
		else
			ft_exit();
		(*i)++;
	}
}

void	get_final_arg(int ac, int i, char **av, char ***final_args)
{
	if (ac - i == 1)
		*final_args = ft_split(av[i], ' ');
	else
		*final_args = av + i;
}

void	run_strategy(t_app *app, t_stack **stack_a, t_stack **stack_b,
			double dis)
{
	if (is_sorted(stack_a) || !stack_a || !*stack_a || !stack_b)
	{
		if (app->bench_mode == 1)
			display_bench(app, dis);
		return ;
	}
	else if (app->selected_strat == 0)
		adaptive_sort(stack_a, stack_b, dis, app);
	else if (app->selected_strat == 1)
		simple_sort(stack_a, stack_b, app);
	else if (app->selected_strat == 2)
		medium_sort(stack_a, stack_b, app);
	else if (app->selected_strat == 3)
		complex_sort(stack_a, stack_b, app);
	else
		return ;
	if (app->bench_mode == 1)
		display_bench(app, dis);
}
