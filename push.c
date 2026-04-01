/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safidian <safidian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:38:53 by safidian          #+#    #+#             */
/*   Updated: 2026/03/24 07:27:05 by safidian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;

	if (stack1 == NULL || *stack1 == NULL)
		return ;
	tmp = *stack1;
	*stack1 = (*stack1)->next;
	if (stack2 == NULL)
		*stack2 = tmp;
	else
	{
		tmp->next = *stack2;
		*stack2 = tmp;
	}
}

void	push_a(t_stack **stack_a, t_stack **stack_b, t_app *app)
{
	push(stack_b, stack_a);
	print_op("pa");
	app->ops.pa++;
	app->ops.total++;
}

void	push_b(t_stack **stack_a, t_stack **stack_b, t_app *app)
{
	push(stack_a, stack_b);
	print_op("pb");
	app->ops.pb++;
	app->ops.total++;
}
