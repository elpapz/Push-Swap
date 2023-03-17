/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:29:41 by acanelas          #+#    #+#             */
/*   Updated: 2023/03/15 21:05:16 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}

void	rra(t_stack *a, int j)
{
	int	save_last;
	int	i;

	if (a->top_number == 0)
		return ;
	save_last = a->int_array[0];
	i = 0;
	while (i < a->top_number)
	{
		a->int_array[i] = a->int_array[i + 1];
		i++;
	}
	a->int_array[a->top_number] = save_last;
	if (j == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int j)
{
	int	save_last;
	int	i;

	if (b->top_number == 0)
		return ;
	save_last = b->int_array[0];
	i = 0;
	while (i < b->top_number)
	{
		b->int_array[i] = b->int_array[i + 1];
		i++;
	}
	b->int_array[b->top_number] = save_last;
	if (j == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
