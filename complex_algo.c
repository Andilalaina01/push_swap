/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safidian <safidian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:18:04 by safidian          #+#    #+#             */
/*   Updated: 2026/03/12 08:27:15 by safidian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_max_and_push_to_a(t_stack **a, t_stack **b, t_app *app,
	int max_idx)
{
	if (get_pos(*b, max_idx) <= ft_stack_size(*b) / 2)
	{
		while ((*b)->index != max_idx)
		{
			if ((*b)->index == max_idx - 1)
				push_a(a, b, app);
			else
				rotate_b(b, app);
		}
	}
	else
	{
		while ((*b)->index != max_idx)
		{
			if ((*b)->index == max_idx - 1)
				push_a(a, b, app);
			else
				r_rotate_b(b, app);
		}
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b, t_app *app)
{
	int	max_idx;

	while (*b)
	{
		max_idx = get_max_index(*b);
		find_max_and_push_to_a(a, b, app, max_idx);
		push_a(a, b, app);
		if ((*a) && (*a)->next && (*a)->index > (*a)->next->index)
			swap_a(a, app);
	}
}

static void	push_to_b(t_stack **stack_a, t_stack **stack_b, t_app *app,
	int range)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			push_b(stack_a, stack_b, app);
			if (*stack_a && (*stack_a)->index > i + range)
				rotate_ab(stack_a, stack_b, app);
			else
				rotate_b(stack_b, app);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			push_b(stack_a, stack_b, app);
			i++;
		}
		else
			rotate_a(stack_a, app);
	}
	push_back_to_a(stack_a, stack_b, app);
}

void	complex_sort(t_stack **stack_a, t_stack **stack_b, t_app *app)
{
	int	range;

	if (ft_stack_size(*stack_a) <= 100)
		range = ft_stack_size(*stack_a) / 7;
	else
		range = ft_stack_size(*stack_a) / 14;
	push_to_b(stack_a, stack_b, app, range);
}
