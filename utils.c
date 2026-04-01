/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safidian <safidian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:40:39 by safidian          #+#    #+#             */
/*   Updated: 2026/03/10 09:30:21 by safidian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp && temp->next)
	{
		if (temp->next->value < temp->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	get_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = stack;
	while (current)
	{
		compare = stack;
		index = 0;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	get_min_pos(t_stack *stack)
{
	int		min_val;
	int		min_pos;
	int		current_pos;

	if (!stack)
		return (-1);
	min_val = stack->index;
	min_pos = 0;
	current_pos = 0;
	while (stack)
	{
		if (stack->index < min_val)
		{
			min_val = stack->index;
			min_pos = current_pos;
		}
		stack = stack->next;
		current_pos++;
	}
	return (min_pos);
}

int	get_max_index(t_stack *stack)
{
	int		max_index;
	t_stack	*temp;

	temp = stack;
	max_index = -2147483648;
	while (temp)
	{
		if (temp->index > max_index)
			max_index = temp->index;
		temp = temp->next;
	}
	return (max_index);
}

int	get_pos(t_stack *stack, int target_index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target_index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}
