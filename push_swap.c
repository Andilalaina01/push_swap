/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamy-and <mamy-and@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:35:36 by safidian          #+#    #+#             */
/*   Updated: 2026/03/25 18:37:59 by mamy-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			i;
	char		**final_args;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_app		app;

	select_strategy(ac, &i, av, &app);
	if (i == ac || ac < 2)
		return (0);
	final_args = NULL;
	get_final_arg(ac, i, av, &final_args);
	check_input_and_error(ac, i, &final_args);
	stack_a = ft_init_stack(final_args);
	stack_b = NULL;
	get_index(stack_a);
	run_strategy(&app, &stack_a, &stack_b, compute_disorder(&stack_a));
	if (ac - i == 1)
		free_tab(final_args);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
