/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safidian <safidian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 21:09:38 by safidian          #+#    #+#             */
/*   Updated: 2026/03/24 07:27:13 by safidian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stack **first)
{
	t_stack	*last;
	t_stack	*new_last;

	if (*first == NULL || (*first)->next == NULL)
		return ;
	last = *first;
	while (last->next != NULL)
	{
		new_last = last;
		last = last->next;
	}
	last->next = *first;
	new_last->next = NULL;
	*first = last;
}

void	r_rotate_a(t_stack **first, t_app *app)
{
	r_rotate(first);
	print_op("rra");
	app->ops.rra++;
	app->ops.total++;
}

void	r_rotate_b(t_stack **first, t_app *app)
{
	r_rotate(first);
	print_op("rrb");
	app->ops.rrb++;
	app->ops.total++;
}

void	r_rotate_ab(t_stack **stack_a, t_stack **stack_b, t_app *app)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	print_op("rrr");
	app->ops.rrr++;
	app->ops.total++;
}
