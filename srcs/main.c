/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:17:53 by acanelas          #+#    #+#             */
/*   Updated: 2023/03/17 00:52:26 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	sort_stack_of_three(t_stack *a)
{
	if (a->int_array[0] < a->int_array[1] && a->int_array[0]
		< a->int_array[2] && a->int_array[1] < a->int_array[2])
	{
		write(1, "sa\n", 3);
		write(1, "rra\n", 4);
	}
	else if (a->int_array[0] < a->int_array[1] && a->int_array[0]
		> a->int_array[2] && a->int_array[1] > a->int_array[2])
	{
		write(1, "rra\n", 4);
		write(1, "sa\n", 3);
	}
	else if (a->int_array[0] < a->int_array[1] && a->int_array[0]
		< a->int_array[2] && a->int_array[1] > a->int_array[2])
		write(1, "rra\n", 4);
	else if (a->int_array[0] > a->int_array[1] && a->int_array[0]
		> a->int_array[2] && a->int_array[1] < a->int_array[2])
		write(1, "sa\n", 3);
	else if (a->int_array[0] > a->int_array[1] && a->int_array[0]
		< a->int_array[2] && a->int_array[1] < a->int_array[2])
		write(1, "ra\n", 3);
}

static	void	clean_n_go(t_stack *a, t_stack *b)
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
		return (0);
	size = argc - 1;
	a = init_struct(size);
	b = init_struct(size);
	process_input(a, size, argv);
	if (!is_sorted(a))
	{
		if (a->stack_size == 3)
			sort_stack_of_three(a);
		else if (a->stack_size < 200)
			sort_smaller(a, b);
		else
			big_boy_sort(a, b);
	}
	clean_n_go(a, b);
}
