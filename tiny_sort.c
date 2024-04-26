/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmullin <grmullin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:08:42 by grmullin          #+#    #+#             */
/*   Updated: 2024/02/20 13:46:02 by grmullin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_stack_3(t_node **stack)
{
	t_node	*highest;
	t_node	*lowest;

	highest = find_highest(*stack);
	lowest = find_lowest(*stack);
	if ((*stack) == highest)
		ra(stack);
	else if ((*stack)->next == highest)
		rra(stack);
	if ((*stack) != lowest)
		sa(stack);
	highest->next = NULL;
}

void	order_stack_5(t_node **sa, t_node **sb, int size)
{
	t_node	*lowest;

	lowest = find_lowest(*sa);
	set_positions(*sa);
	while (*sa != lowest)
	{
		if (lowest->above_median)
			ra(sa);
		else
			rra(sa);
	}
	while (size > 3 && (!check_sorted(*sa)))
	{
		pb(sa, sb);
		size--;
		order_stack_5(sa, sb, size);
	}
	order_stack_3(sa);
	while (*sb)
		pa(sa, sb);
}

t_node	*find_highest(t_node *stack)
{
	t_node	*head;
	t_node	*highest_node;
	int		highest;

	head = stack;
	highest_node = NULL;
	highest = INT_MIN;
	while (head)
	{
		if ((head)->value > highest)
		{
			highest = (head)->value;
			highest_node = head;
		}
		head = (head)->next;
	}
	return (highest_node);
}

t_node	*find_lowest(t_node *stack)
{
	t_node	*head;
	t_node	*min_node;
	int		min;

	head = stack;
	min_node = NULL;
	min = INT_MAX;
	while (head)
	{
		if (head->value < min)
		{
			min = head->value;
			min_node = head;
		}
		head = head->next;
	}
	return (min_node);
}
