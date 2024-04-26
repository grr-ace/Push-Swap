/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmullin <grmullin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:45:36 by grmullin          #+#    #+#             */
/*   Updated: 2024/02/20 12:31:45 by grmullin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_node **head, long long n)
{
	t_node	*new_node;
	t_node	*last;

	last = NULL;
	if (head == NULL)
		return ;
	new_node = init_node(n);
	if (new_node == NULL)
		return ;
	if (*head == NULL)
		(*head) = new_node;
	else
	{
		last = last_node(*head);
		last->next = new_node;
	}
	new_node->prev = last;
}

t_node	*init_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->prev = NULL;
	new_node->value = value;
	new_node->next = NULL;
	new_node->target_node = NULL;
	new_node->push_price = 0;
	new_node->position = 0;
	new_node->above_median = false;
	new_node->keep = false;
	return (new_node);
}

void	free_space(char **av)
{
	int		i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	free_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	temp = NULL;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
		temp = NULL;
	}
	free(current);
}
