/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:25:15 by acanelas          #+#    #+#             */
/*   Updated: 2023/03/16 05:00:45 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_stack *a, t_stack *b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}

void	ra(t_stack *a, int j)
{
	int	save_first;
	int	i;

	if (a->top_number == -1)
		return ;
	save_first = a->int_array[a->top_number];
	i = a->top_number;
	while (i > 0)
	{
		a->int_array[i] = a->int_array[i - 1];
		i--;
	}
	a->int_array[0] = save_first;
	if (j == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b, int j)
{
	int	save_first;
	int	i;

	if (b->top_number == -1)
		return ;
	save_first = b->int_array[b->top_number];
	i = b->top_number;
	while (i > 0)
	{
		b->int_array[i] = b->int_array[i - 1];
		i--;
	}
	b->int_array[0] = save_first;
	if (j == 0)
		write(1, "rb\n", 3);
}
