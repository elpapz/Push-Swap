/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:46:31 by acanelas          #+#    #+#             */
/*   Updated: 2023/03/17 00:53:32 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_head(t_stack *a, t_stack *b, int mid_number)
{
	while (a->int_array[a->top_number] < mid_number)
		pb(a, b);
}

void	move_butt(t_stack *a, t_stack *b, int mid_number)
{
	while (a->int_array[0] < mid_number)
	{
		rra(a, 0);
		pb(a, b);
	}
}

void	last_move_to_b(t_stack *a, t_stack *b, int mid_number, int chunks)
{
	while ((a->top_number -1) > (b->top_number / chunks))
	{
		if (a->int_array[a->top_number] < mid_number)
			pb(a, b);
		else
			ra(a, 0);
	}
}

void	push_up_to_a(t_stack *b, t_stack *a, int max_number)
{
	while (b->int_array[b->top_number] < max_number)
		rb(b, 0);
	pa(a, b);
}

void	push_down_to_a(t_stack *b, t_stack *a, int max_number)
{
	while (b->int_array[b->top_number] < max_number)
		rrb(b, 0);
	pa(a, b);
}
