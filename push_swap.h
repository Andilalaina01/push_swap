/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamy-and <mamy-and@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:10:36 by safidian          #+#    #+#             */
/*   Updated: 2026/03/25 19:45:45 by mamy-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stats
{
	int	total;
	int	sa;
	int	sb;
	int	ss;
	int	pb;
	int	rb;
	int	rr;
	int	rrb;
	int	rrr;
	int	pa;
	int	ra;
	int	rra;
}	t_stats;

typedef struct s_app
{
	int		selected_strat;
	int		bench_mode;
	t_stats	ops;
}	t_app;

void	swap(t_stack **head);
void	swap_a(t_stack **head, t_app *app);
void	swap_b(t_stack **head, t_app *app);
void	swap_ab(t_stack **stack_a, t_stack **stack_b, t_app *app);
void	push(t_stack **stack1, t_stack **stack2);
void	push_a(t_stack **stack_a, t_stack **stack_b, t_app *app);
void	push_b(t_stack **stack_a, t_stack **stack_b, t_app *app);
void	rotate(t_stack **first);
void	rotate_a(t_stack **first, t_app *app);
void	rotate_b(t_stack **first, t_app *app);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b, t_app *app);
void	r_rotate(t_stack **first);
void	r_rotate_a(t_stack **first, t_app *app);
void	r_rotate_b(t_stack **first, t_app *app);
void	r_rotate_ab(t_stack **stack_a, t_stack **stack_b, t_app *app);

double	compute_disorder(t_stack **stack_a);
void	select_strategy(int ac, int *i, char **av, t_app *app);
void	run_strategy(t_app *app, t_stack **stack_a, t_stack **stack_b,
			double dis);
void	check_input_and_error(int ac, int i, char ***final_args);
void	get_final_arg(int ac, int i, char **av, char ***final_args);

void	simple_sort(t_stack **stack_a, t_stack **stack_b, t_app *app);
void	medium_sort(t_stack **stack_a, t_stack **stack_b, t_app *app);
void	complex_sort(t_stack **stack_a, t_stack **stack_b, t_app *app);
void	adaptive_sort(t_stack **stack_a, t_stack **stack_b,
			double dis, t_app *app);

int		ft_stack_size(t_stack *first);
t_stack	*ft_init_stack(char **av);

int		is_sorted(t_stack **stack);
void	get_index(t_stack *stack);
int		get_min_pos(t_stack *stack);
int		get_max_index(t_stack *stack);
int		get_pos(t_stack *stack, int target_index);

void	free_tab(char **av);
void	free_stack(t_stack **stack);
int		ft_sqrt(int nb);
long	ft_atol(const char *nptr);
void	ft_exit(void);
void	print_op(char *str);

void	display_bench(t_app *app, double disorder);

#endif
