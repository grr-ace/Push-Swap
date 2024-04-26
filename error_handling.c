/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmullin <grmullin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:14:35 by grmullin          #+#    #+#             */
/*   Updated: 2024/02/21 10:12:37 by grmullin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_check(int ac, char **av)
{
	dup_check(ac, av);
	num_check(ac, av);
}

int	dup_check(int ac, char **av)
{
	int			i;
	int			j;
	long int	x;
	long int	y;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			x = ft_atol(av[i]);
			y = ft_atol(av[j]);
			if (x == y)
				print_error(ac, av);
			j++;
		}
		i++;
	}
	return (1);
}

int	num_check(int ac, char **av)
{
	int			i;
	int			j;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] == '-' || av[i][j] == '+') && 
				(av[i][j + 1] >= '0' && av[i][j] <= '9'))
				j++;
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				print_error(ac, av);
			if (ft_atol(av[i]) < INT_MIN || ft_atol(av[i]) > INT_MAX)
				print_error(ac, av);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_error(int ac, char **av)
{
	if (ac == 2)
		free_space(av);
	write(2, "Error\n", 6);
	exit (1);
}
