/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmullin <grmullin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:32:28 by grmullin          #+#    #+#             */
/*   Updated: 2024/02/21 14:42:29 by grmullin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_nodes(t_node *stack_a, t_node *stack_b)
{
	set_positions(stack_a);
	set_positions(stack_b);
	assign_targets(stack_a, stack_b);
	set_price(stack_a, stack_b);
}

void	push_swap(t_node **stack_a, t_node **stack_b)
{
	push_lowest(stack_a, stack_b);
	while (*stack_b)
	{
		set_nodes(*stack_a, *stack_b);
		pre_sort_nodes(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	ascend_nodes(stack_a);
	free_stack(stack_b);
}

void	push_lowest(t_node **stack_a, t_node **stack_b)
{
	t_node	*next;
	int		len;
	int		avg;

	len = stack_len(*stack_a);
	while (len > 3)
	{
		len = stack_len(*stack_a);
		next = (*stack_a)->next;
		avg = get_average(stack_a);
		if ((*stack_a)->value < avg)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		*stack_a = next;
	}
	order_stack_3(stack_a);
}

void	pre_sort_nodes(t_node **stack_a, t_node **stack_b)
{
	t_node	*a;
	t_node	*b;

	b = find_cheapest(*stack_b);
	a = b->target_node;
	if ((a->above_median) && (b->above_median))
		rotate_case_1(stack_a, stack_b, a, b);
	else if ((!a->above_median) && (!b->above_median))
		rotate_case_2(stack_a, stack_b, a, b);
	else if ((a->above_median) && (!b->above_median))
		rotate_case_3(stack_a, stack_b, a, b);
	else if ((!a->above_median) && (b->above_median))
		rotate_case_4(stack_a, stack_b, a, b);
}

void	ascend_nodes(t_node **stack)
{
	t_node	*lowest;

	lowest = find_lowest(*stack);
	if (lowest->above_median)
	{
		while (*stack != lowest)
			ra(stack);
	}
	else
	{
		while (*stack != lowest)
			rra(stack);
	}
}
