/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safidian <safidian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:36:05 by safidian          #+#    #+#             */
/*   Updated: 2026/03/11 15:09:40 by safidian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack **stack_a, t_stack **stack_b,
			double dis, t_app *app)
{
	if (ft_stack_size(*stack_a) <= 5)
	{
		simple_sort(stack_a, stack_b, app);
		return ;
	}
	else if (dis < 0.2)
		simple_sort(stack_a, stack_b, app);
	else if (dis >= 0.2 && dis < 0.50)
		medium_sort(stack_a, stack_b, app);
	else
		complex_sort(stack_a, stack_b, app);
}
