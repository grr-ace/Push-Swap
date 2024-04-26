/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmullin <grmullin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:27:22 by grmullin          #+#    #+#             */
/*   Updated: 2024/02/21 14:42:59 by grmullin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct node
{
	int			value;
	int			push_price;
	int			position;
	struct node	*target_node;
	struct node	*prev;
	struct node	*next;
	bool		above_median;
	bool		keep;
}	t_node;

/*
	Error handling
*/
int			num_check(int ac, char **av);
int			dup_check(int ac, char **av);
void		print_error(int ac, char **av);
void		error_check(int ac, char **av);
void		free_space(char **av);
void		free_stack(t_node **stack);

/*
	Node utils
*/

void		init_stack(t_node **head, long long n);
t_node		*init_node(int value);
t_node		*last_node(t_node *stack);
t_node		*find_highest(t_node *stack);
t_node		*find_lowest(t_node *stack);
void		print_stack(t_node *head);
void		print_node(t_node *node);
void		ascend_nodes(t_node **stack);
long		ft_atol(char *s);
int			stack_len(const t_node *stack);
int			get_average(t_node **stack);

/*
	Sorting stacks
*/

void		push_swap(t_node **stack_a, t_node **stack_b);
void		pre_sort_nodes(t_node **stack_a, t_node **stack_b);
void		set_nodes(t_node *stack_a, t_node *stack_b);
void		ft_sort_args(t_node **stack_a, int size);
void		order_stack_3(t_node **stack);
void		order_stack_5(t_node **sa, t_node **sb, int size);
void		push_lowest(t_node **stack_a, t_node **stack_b);
void		assign_targets(t_node *stack_a, t_node *stack_b);
void		set_positions(t_node *stack);
void		set_price(t_node *stack_a, t_node *stack_b);
void		above_median_pricing(t_node *stack_b, int len_a);
void		below_median_pricing(t_node *stack_b, int len_a);
void		rotate_case_1(t_node **sa, t_node **sb, t_node *a, t_node *b);
void		rotate_case_2(t_node **sa, t_node **sb, t_node *a, t_node *b);
void		rotate_case_3(t_node **sa, t_node **sb, t_node *a, t_node *b);
void		rotate_case_4(t_node **sa, t_node **sb, t_node *a, t_node *b);
bool		check_sorted(t_node *stack);
t_node		*find_cheapest(t_node *stack_b);

/*
	Push functions
*/

void		pa(t_node **a, t_node **b);
void		pb(t_node **b, t_node **a);
void		push(t_node **from, t_node **to);

/*
	Swap
*/

void		swap(t_node **stack);
void		sa(t_node **stack_a);
void		sb(t_node **stack_b);
void		ss(t_node **stack_a, t_node **stack_b);

/*
	Rotate
*/

void		rotate(t_node **stack);
void		ra(t_node **stack_a);
void		rb(t_node **stack_b);
void		rr(t_node **stack_a, t_node **stack_b);
void		reverse_rotate(t_node **stack);
void		rra(t_node **stack_a);
void		rrb(t_node **stack_b);
void		rrr(t_node **stack_a, t_node **stack_b);

#endif
