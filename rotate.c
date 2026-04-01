/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safidian <safidian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:50:17 by safidian          #+#    #+#             */
/*   Updated: 2026/03/24 07:27:20 by safidian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **first)
{
	t_stack	*last;

	if (*first == NULL || (*first)->next == NULL)
		return ;
	last = *first;
	while (last->next != NULL)
		last = last->next;
	last->next = *first;
	*first = (*first)->next;
	last->next->next = NULL;
}

void	rotate_a(t_stack **first, t_app *app)
{
	rotate(first);
	print_op("ra");
	app->ops.ra++;
	app->ops.total++;
}

void	rotate_b(t_stack **first, t_app *app)
{
	rotate(first);
	print_op("rb");
	app->ops.rb++;
	app->ops.total++;
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b, t_app *app)
{
	rotate(stack_a);
	rotate(stack_b);
	print_op("rr");
	app->ops.rr++;
	app->ops.total++;
}
