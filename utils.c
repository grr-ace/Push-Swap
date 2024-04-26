/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmullin <grmullin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:15:01 by grmullin          #+#    #+#             */
/*   Updated: 2024/02/07 11:18:47 by grmullin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_average(t_node **stack)
{
	t_node	*temp;
	int		len;
	long	avg;

	avg = 0;
	temp = *stack;
	len = stack_len(*stack);
	while (temp)
	{
		avg += (temp)->value;
		temp = temp->next;
	}
	temp = *stack;
	avg = avg / len;
	return (avg);
}

t_node	*find_cheapest(t_node *stack_b)
{
	long	lowest_push_price;
	t_node	*cheapest_node;

	lowest_push_price = LONG_MAX;
	cheapest_node = NULL;
	while (stack_b)
	{
		if (stack_b->push_price < lowest_push_price)
		{
			lowest_push_price = stack_b->push_price;
			cheapest_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (cheapest_node);
}

long	ft_atol(char *s)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
		res = res * 10 + (s[i++] - '0');
	return (sign * res);
}

t_node	*last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_len(const t_node *stack)
{
	const t_node	*temp;
	int				i;

	temp = stack;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
