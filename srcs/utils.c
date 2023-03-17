/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 04:09:04 by acanelas          #+#    #+#             */
/*   Updated: 2023/03/17 23:35:18 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error(t_stack *a, t_stack *b)
{
	clean_n_go(a, b);
	write(STDERR_FILENO, "Error\n", 6);
	return (EXIT_FAILURE);
}

t_stack	*init_struct(int size)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->int_array = malloc((size) * sizeof(int));
	new->stack_size = size;
	new->top_number = -1;
	return (new);
}

bool	is_sorted(t_stack *stack_a)
{
	int	i;

	i = 0;
	if (stack_a->stack_size > 3)
	{
		while (i < stack_a->top_number)
		{
			if (stack_a->int_array[i] < stack_a->int_array[i + 1])
				return (false);
			i++;
		}
		return (true);
	}
	else
	{
		while (i < stack_a->top_number)
		{
			if (stack_a->int_array[i] > stack_a->int_array[i + 1])
				return (false);
			i++;
		}
	}
	return (true);
}

void	push_number(t_stack *stack, int value)
{
	if (stack->top_number == stack->stack_size)
		return ;
	else
	{
		stack->top_number++;
		stack->int_array[stack->top_number] = value;
	}
}

int	pop_number(t_stack *stack)
{
	int	number_to_pop;

	number_to_pop = stack->int_array[stack->top_number];
	stack->top_number--;
	return (number_to_pop);
}
