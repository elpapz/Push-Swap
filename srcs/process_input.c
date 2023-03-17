/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 04:26:02 by acanelas          #+#    #+#             */
/*   Updated: 2023/03/17 00:51:39 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	bool	check_char(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' && argv[i][j + 1] != '\0')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (false);
			j++;
		}
	i++;
	}
	if (repeated_arg(argv) == false)
		return (false);
	return (true);
}

bool	repeated_arg(char **str)
{
	int	i;
	int	j;
	int	res;

	i = -1;
	res = 0;
	while (str[++i])
	{
		j = i + 1;
		while (str[j])
		{
			res = ft_strncmp(str[i], str[j], ft_strlen(MIN_INT));
			if (res == 0)
				return (false);
			j++;
		}
	}
	return (true);
}

static	int	atoi_long(char *str)
{
	long long	res;
	int			sinal;
	int			i;

	i = 0;
	sinal = 1;
	res = 0;
	if (str[0] == '-')
	{
		i++;
		sinal *= -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	res *= sinal;
	if (res > INT_MAX || res < INT_MIN)
		return (0);
	return ((int)res);
}

static	int	*convert_to_int(int size, char **argv)
{
	int	*list;
	int	i;
	int	j;

	list = malloc(sizeof(int) * size);
	i = 0;
	j = 1;
	while (argv[j])
	{
		list[i] = atoi_long(argv[j]);
		if (list[i] == 0 && argv[j][0] != '0')
		{
			free(list);
			return (NULL);
		}
	i++;
	j++;
	}
	return (list);
}

void	process_input(t_stack *stack_a, int size, char **argv)
{
	int	i;
	int	*temp_array;

	i = size - 1;
	if (check_char(argv) == false)
		return ;
	temp_array = convert_to_int(size, argv);
	if (!temp_array)
		return ;
	while (i >= 0)
	{
		push_number(stack_a, temp_array[i]);
		i--;
	}
	free(temp_array);
}
