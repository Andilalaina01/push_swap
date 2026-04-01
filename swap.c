/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safidian <safidian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:15:55 by safidian          #+#    #+#             */
/*   Updated: 2026/03/24 07:27:45 by safidian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || (*head)->next == NULL)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
}

void	swap_a(t_stack **head, t_app *app)
{
	swap(head);
	print_op("sa");
	app->ops.sa++;
	app->ops.total++;
}

void	swap_b(t_stack **head, t_app *app)
{
	swap(head);
	print_op("sb");
	app->ops.sb++;
	app->ops.total++;
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b, t_app *app)
{
	swap(stack_a);
	swap(stack_b);
	print_op("ss");
	app->ops.ss++;
	app->ops.total++;
}
