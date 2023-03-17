/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_boy_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:43:30 by acanelas          #+#    #+#             */
/*   Updated: 2023/03/17 00:36:42 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	decomp_ints(t_stack *stack, int *sorted_array)
{
	int	i;
	int	*temp;
	int	j;

	i = -1;
	temp = malloc(stack->stack_size * sizeof(int));
	while (++i < stack->stack_size)
	{
		j = -1;
		while (++j < stack->stack_size)
		{
			if (sorted_array[i] == stack->int_array[j])
				temp[j] = i;
		}
	}
	i = -1;
	while (++i < stack->stack_size)
		stack->int_array[i] = temp[i];
	free(temp);
	free(sorted_array);
}

static	int	*sorted_big_array(t_stack *stack)
{
	int		i;
	int		*sorted_arr;

	i = -1;
	sorted_arr = malloc(stack->stack_size * sizeof(int));
	while (++i < stack->stack_size)
		sorted_arr[i] = stack->int_array[i];
	sort_int(sorted_arr, stack->stack_size);
	return (sorted_arr);
}

void	big_boy_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	num;
	int	i;
	int	j;

	max_bits = 0;
	decomp_ints(a, sorted_big_array(a));
	num = max_number(a);
	while ((num >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (!is_sorted(a) && (++j < a->stack_size))
		{
			num = a->int_array[a->top_number];
			if (((num >> i) & 0b00000001) == 1)
				ra(a, 0);
			else
				pb(a, b);
		}
		while (b->top_number >= 0)
			pa(a, b);
	}
}
