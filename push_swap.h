/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:49:58 by acanelas          #+#    #+#             */
/*   Updated: 2023/03/17 23:47:11 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdbool.h>

# define MAX_INT "2147483647"
# define MIN_INT "-2147483648"

typedef struct s_stack
{
	int	top_number;
	int	stack_size;
	int	*int_array;
}	t_stack;

int		error(t_stack *a, t_stack *b);
t_stack	*init_struct(int size);
bool	is_sorted(t_stack *stack_a);
bool	process_input(t_stack *stack_a, int size, char **argv);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a, int j);
void	sb(t_stack *b, int j);
void	rr(t_stack *a, t_stack *b);
void	ra(t_stack *a, int j);
void	rb(t_stack *b, int j);
void	ss(t_stack *a, t_stack *b);
void	rra(t_stack *a, int j);
void	rrb(t_stack *b, int j);
void	rrr(t_stack *a, t_stack *b);
void	push_up_to_a(t_stack *b, t_stack *a, int max_number);
void	push_down_to_a(t_stack *b, t_stack *a, int max_number);
void	move_head(t_stack *a, t_stack *b, int mid_number);
void	move_butt(t_stack *a, t_stack *b, int mid_number);
void	last_move_to_b(t_stack *a, t_stack *b, int mid_number, int chunks);
void	sort_int(int *int_array, int chunk_size);
int		max_number(t_stack *stack);
void	sort_smaller(t_stack *a, t_stack *b);
void	push_number(t_stack *stack, int value);
int		pop_number(t_stack *stack);
void	big_boy_sort(t_stack *a, t_stack *b);
bool	repeated_arg(char **str);
void	clean_n_go(t_stack *a, t_stack *b);

#endif