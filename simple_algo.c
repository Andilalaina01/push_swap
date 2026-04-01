/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safidian <safidian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:53:05 by safidian          #+#    #+#             */
/*   Updated: 2026/03/11 15:14:20 by safidian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min_to_b(t_stack **stack_a, t_stack **stack_b, t_app *app)
{
	int	size;
	int	pos;

	size = ft_stack_size(*stack_a);
	pos = get_min_pos(*stack_a);
	if (pos <= size / 2)
		while (pos-- > 0)
			rotate_a(stack_a, app);
	else
		while (pos++ < size)
			r_rotate_a(stack_a, app);
	push_b(stack_a, stack_b, app);
}

static void	sort_three(t_stack **stack_a, t_app *app)
{
	int	max_index;

	max_index = get_max_index(*stack_a);
	if ((*stack_a)->index == max_index)
		rotate_a(stack_a, app);
	else if ((*stack_a)->next->index == max_index)
		r_rotate_a(stack_a, app);
	if ((*stack_a)->next->index < (*stack_a)->index)
		swap_a(stack_a, app);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b, t_app *app)
{
	while (ft_stack_size(*stack_a) > 3)
		push_min_to_b(stack_a, stack_b, app);
	sort_three(stack_a, app);
	while (ft_stack_size(*stack_b) > 0)
		push_a(stack_a, stack_b, app);
}
