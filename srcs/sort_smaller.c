/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smaller.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:42:14 by acanelas          #+#    #+#             */
/*   Updated: 2023/03/17 21:23:53 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_int(int *int_array, int chunk_size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < chunk_size)
	{
		key = int_array[i];
		j = i - 1;
		while (j >= 0 && int_array[j] > key)
		{
			int_array[j + 1] = int_array[j];
			j--;
		}
		int_array[j + 1] = key;
		i++;
	}
}

static	bool	if_max_number_on_top_half(t_stack *b, int max_number)
{
	int	i;

	i = b->top_number;
	while (i > (b->top_number / 2))
	{
		if (b->int_array[i] == max_number)
			return (true);
		i--;
	}
	return (false);
}

int	max_number(t_stack *stack)
{
	int	i;
	int	max_number;

	i = 0;
	max_number = stack->int_array[0];
	while (i <= stack->top_number)
	{
		if (max_number < stack->int_array[i])
			max_number = stack->int_array[i];
		i++;
	}
	return (max_number);
}

static	int	mid_index(t_stack *stack)
{
	int		mid_point;
	int		i;
	int		chunk_size;
	int		*sorted_arr;

	mid_point = 0;
	i = 0;
	chunk_size = (stack->top_number + 1);
	sorted_arr = malloc(chunk_size * sizeof(int));
	while (i < (stack->top_number + 1))
	{
		sorted_arr[i] = stack->int_array[i];
		i++;
	}
	sort_int(sorted_arr, chunk_size);
	mid_point = sorted_arr[(chunk_size / 2)];
	free(sorted_arr);
	sorted_arr = NULL;
	return (mid_point);
}

void	sort_smaller(t_stack *a, t_stack *b)
{
	int	chunks;
	int	mid_int;

	chunks = 1;
	if (a->int_array[a->top_number] > a->int_array[a->top_number - 1])
		sa(a, 0);
	while (a->top_number > 1)
	{
		mid_int = mid_index(a);
		move_head(a, b, mid_int);
		move_butt(a, b, mid_int);
		last_move_to_b(a, b, mid_int, chunks);
		chunks++;
	}
	if (a->int_array[a->top_number] > a->int_array[a->top_number - 1])
		sa(a, 0);
	while (b->top_number != -1)
	{
		if (if_max_number_on_top_half(b, max_number(b)))
			push_up_to_a(b, a, max_number(b));
		else
			push_down_to_a(b, a, max_number(b));
	}
}
