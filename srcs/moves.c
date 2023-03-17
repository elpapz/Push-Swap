/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 03:23:05 by acanelas          #+#    #+#             */
/*   Updated: 2023/03/17 00:28:29 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (b->top_number == -1)
		return ;
	push_number(a, pop_number(b));
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->top_number == -1)
		return ;
	push_number(b, pop_number(a));
	write(1, "pb\n", 3);
}

void	sa(t_stack *a, int j)
{
	int	temp;

	if (a->top_number == -1)
		return ;
	temp = a->int_array[a->top_number - 1];
	a->int_array[a->top_number - 1] = a->int_array[a->top_number];
	a->int_array[a->top_number] = temp;
	if (j == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int j)
{
	int	temp;

	if (b->top_number == -1)
		return ;
	temp = b->int_array[b->top_number - 1];
	b->int_array[b->top_number - 1] = b->int_array[b->top_number];
	b->int_array[b->top_number] = temp;
	if (j == 0)
		write(1, "sb\n", 3);
}
