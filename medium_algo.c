/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamy-and <mamy-and@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:47:55 by safidian          #+#    #+#             */
/*   Updated: 2026/03/25 19:46:24 by mamy-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_back_to_a(t_stack **a, t_stack **b, t_app *app)
{
	int	max_idx;
	int	pos;
	int	size;

	while (*b)
	{
		max_idx = get_max_index(*b);
		pos = get_pos(*b, max_idx);
		size = ft_stack_size(*b);
		if (pos <= size / 2)
			while ((*b)->index != max_idx)
				rotate_b(b, app);
		else
			while ((*b)->index != max_idx)
				r_rotate_b(b, app);
		push_a(a, b, app);
	}
}

void	medium_sort(t_stack **stack_a, t_stack **stack_b, t_app *app)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(ft_stack_size(*stack_a));
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			push_b(stack_a, stack_b, app);
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
