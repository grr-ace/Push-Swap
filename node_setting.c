/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmullin <grmullin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:32:11 by grmullin          #+#    #+#             */
/*   Updated: 2024/02/21 12:03:12 by grmullin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_positions(t_node *stack)
{
	int	middle;
	int	i;

	middle = stack_len(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->position = i;
		if (stack->position <= middle)
			stack->above_median = true;
		else
			stack->above_median = false;
		i++;
		stack = stack->next;
	}
}

void	assign_targets(t_node *stack_a, t_node *stack_b)
{
	t_node	*temp_a;
	t_node	*target_node;
	long	best_match;

	while (stack_b)
	{
		best_match = LONG_MAX;
		temp_a = stack_a;
		while (temp_a)
		{
			if ((temp_a->value > stack_b->value)
				&& (temp_a->value < best_match))
			{
				best_match = temp_a->value;
				target_node = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (best_match == LONG_MAX)
			stack_b->target_node = find_lowest(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	set_price(t_node *stack_a, t_node *stack_b)
{
	int		len_a;
	int		len_b;
	t_node	*target;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_b && stack_b->next)
	{
		target = stack_b->target_node;
		if (stack_b->above_median)
			above_median_pricing(stack_b, len_a);
		else
			below_median_pricing(stack_b, len_b);
		stack_b = stack_b->next;
	}
}

void	above_median_pricing(t_node *stack_b, int len_a)
{
	t_node	*target;

	target = stack_b->target_node;
	stack_b->push_price = stack_b->position;
	if (target->above_median)
	{
		if (target->position > stack_b->position)
			stack_b->push_price += (target->position - stack_b->position);
	}
	else
		stack_b->push_price += (len_a - target->position);
}

void	below_median_pricing(t_node *stack_b, int len_b)
{
	t_node	*target;

	target = stack_b->target_node;
	stack_b->push_price = len_b - (stack_b->position);
	if (target->above_median)
		stack_b->push_price += target->position;
	else if (!(target->above_median))
	{
		if (stack_b->position > target->position)
			stack_b->push_price += (stack_b->position - target->position);
		else
			stack_b->push_price += target->position - stack_b->position;
	}
}
