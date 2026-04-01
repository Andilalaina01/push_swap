/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safidian <safidian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 21:26:21 by safidian          #+#    #+#             */
/*   Updated: 2026/03/09 16:19:18 by safidian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_new_stack(int new_value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = new_value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

static void	ft_stack_add_back(t_stack **first, int new_value)
{
	t_stack	*current;

	if (*first == NULL)
	{
		*first = ft_new_stack(new_value);
		return ;
	}
	current = *first;
	while (current->next != NULL)
		current = current->next;
	current->next = ft_new_stack(new_value);
}

int	ft_stack_size(t_stack *first)
{
	int	size;

	size = 0;
	while (first)
	{
		first = first->next;
		size++;
	}
	return (size);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

t_stack	*ft_init_stack(char **av)
{
	t_stack	*stack_a;
	int		i;

	i = 0;
	stack_a = NULL;
	while (av[i])
	{
		ft_stack_add_back(&stack_a, ft_atol(av[i]));
		i++;
	}
	return (stack_a);
}
