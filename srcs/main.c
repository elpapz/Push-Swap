/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:17:53 by acanelas          #+#    #+#             */
/*   Updated: 2023/03/17 23:45:56 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	sort_if_max_at_1(t_stack *a)
{
	if (a->int_array[0] > a->int_array[2])
		rra(a, 0);
	else
	{
		rra(a, 0);
		sa(a, 0);
	}
}

static	void	sort_if_max_at_0(t_stack *a)
{
	if (a->int_array[1] > a->int_array[2])
	{
		sa(a, 0);
		rra(a, 0);
	}
	else
		ra(a, 0);
}

static	void	sort3(t_stack *a)
{
	int	max;

	max = max_number(a);
	if (a->stack_size == 2)
		sa(a, 0);
	else
	{
		if (a->int_array[0] == max)
			sort_if_max_at_0(a);
		else if (a->int_array[1] == max)
			sort_if_max_at_1(a);
		else if (a->int_array[2] == max && a->int_array[0] > a->int_array[1])
			sa(a, 0);
	}
}

void	clean_n_go(t_stack *a, t_stack *b)
{
	free(a->int_array);
	free(b->int_array);
	free(a);
	free(b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (argc < 2)
		return (EXIT_SUCCESS);
	size = argc - 1;
	a = init_struct(size);
	b = init_struct(size);
	if (!process_input(a, size, argv))
		return (error(a, b));
	if (!is_sorted(a))
	{
		if (a->stack_size <= 3)
			sort3(a);
		else if (a->stack_size < 200)
			sort_smaller(a, b);
		else
			big_boy_sort(a, b);
	}
	clean_n_go(a, b);
	return (EXIT_SUCCESS);
}
