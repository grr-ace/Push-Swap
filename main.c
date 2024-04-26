/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmullin <grmullin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:59:04 by grmullin          #+#    #+#             */
/*   Updated: 2024/02/21 14:42:00 by grmullin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	int		i;

	i = 1;
	if (ac == 1)
		return (1);
	else if (ac == 2)
	{
		if (!av[1][0])
			print_error(1, av);
		av = ft_split(av[1], ' ');
		i = 0;
	}
	stack_a = NULL;
	error_check(ac, av);
	while (av[i])
	{
		init_stack(&stack_a, ft_atol(av[i]));
		i++;
	}
	if (ac == 2)
		free_space(av);
	ft_sort_args(&stack_a, stack_len(stack_a));
	free_stack(&stack_a);
	return (0);
}

void	ft_sort_args(t_node **stack_a, int size)
{
	t_node	*stack_b;

	stack_b = NULL;
	if (!check_sorted(*stack_a))
	{
		if (size == 2)
			sa(stack_a);
		else if (size == 3)
			order_stack_3(stack_a);
		else if (size <= 10)
			order_stack_5(stack_a, &stack_b, size);
		else
			push_swap(stack_a, &stack_b);
	}
	free_stack(&stack_b);
}

bool	check_sorted(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (false);
		temp = temp->next;
	}
	return (true);
}
