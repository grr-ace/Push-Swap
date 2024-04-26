/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmullin <grmullin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:54:00 by grmullin          #+#    #+#             */
/*   Updated: 2024/02/12 11:55:04 by grmullin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_case_1(t_node **sa, t_node **sb, t_node *a, t_node *b)
{
	int		ap;
	int		bp;

	ap = a->position;
	bp = b->position;
	if (bp > ap)
	{
		while (a != (*sa))
			rr(sa, sb);
		while (b != (*sb))
			rb(sb);
	}
	else
	{
		while (b != (*sb))
			rr(sa, sb);
		while (a != (*sa))
			ra(sa);
	}
}

void	rotate_case_2(t_node **sa, t_node **sb, t_node *a, t_node *b)
{
	int		len_a;
	int		len_b;

	len_a = stack_len(*sa);
	len_b = stack_len(*sb);
	if (len_a > len_b)
	{
		while (a != (*sa)) 
			rrr(sa, sb);
		while (b != (*sb))
			rrb(sb);
	}
	else
	{
		while (b != (*sb))
			rrr(sa, sb);
		while (a != (*sa))
			rra(sa);
	}
}

void	rotate_case_3(t_node **sa, t_node **sb, t_node *a, t_node *b)
{
	while (a != (*sa))
		ra(sa);
	while (b != (*sb))
		rrb(sb);
}

void	rotate_case_4(t_node **sa, t_node **sb, t_node *a, t_node *b)
{
	while (a != (*sa))
		rra(sa);
	while (b != (*sb))
		rb(sb);
}
