/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larstenhagen <larstenhagen@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:29:35 by ltenhage          #+#    #+#             */
/*   Updated: 2022/04/14 19:47:29 by larstenhage      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_commands(char *line, t_numbers **stack_a, t_numbers **stack_b, int size)
{
	if (!(ft_strncmp(line, "sa", 2)))
		sa(stack_a);
	else if (!(ft_strncmp(line, "sb", 2)))
		sb(stack_b);
	else if (!(ft_strncmp(line, "pa", 2)))
		pa(stack_a, stack_b);
	else if (!(ft_strncmp(line, "pb", 2)))
		pb(stack_a, stack_b);
	else if (!(ft_strncmp(line, "ra", 2)))
		ra(stack_a, size);
	else if (!(ft_strncmp(line, "rb", 2)))
		rb(stack_b, size);
	else if (!(ft_strncmp(line, "rra", 3)))
		rra(stack_a);
	else if (!(ft_strncmp(line, "rrb", 3)))
		rrb(stack_b, size);
	else if (!(ft_strncmp(line, "rrr", 3)))
	{
		rra(stack_a);
		rrb(stack_b, size);
	}
	else
		return (1);
	return (0);
}

void	print_checker_res(t_numbers **stack_a, t_numbers **stack_b, int size)
{
	if (is_sorted(stack_a, size))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (*stack_a)
		free_stack(stack_a);
	if (*stack_b)
		free_stack(stack_b);
}

static int	ft_print_result(t_numbers **stack_a, t_numbers **stack_b, int size)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (do_commands(line, stack_a, stack_b, size))
		{
			ft_error("Error");
			return (-1);
		}
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_numbers	**stack_a;
	t_numbers	**stack_b;

	if (argc < 2 || ft_check_args(argc, argv) == 0)
	{
		ft_error("Error");
		return (0);
	}
	stack_a = (t_numbers **)malloc(sizeof(t_numbers));
	stack_b = (t_numbers **)malloc(sizeof(t_numbers));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, argc, argv);
	if (ft_print_result(stack_a, stack_b, argc - 1) == -1)
		return (-1);
	print_checker_res(stack_a, stack_b, argc - 1);
}
