/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltenhage <ltenhage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:23:14 by ltenhage          #+#    #+#             */
/*   Updated: 2022/04/13 14:41:52 by ltenhage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Function initialise sort functions based on the list length.
static void	sort_stack(t_numbers **stack_a, t_numbers **stack_b, int size)
{
	if (size <= 5)
		simple_sort(stack_a, stack_b, size);
	else
		radix_sort(stack_a, stack_b, size);
}

int	main(int argc, char **argv)
{
	t_numbers	**stack_a;
	t_numbers	**stack_b;
	t_numbers	*head;

	if (argc < 2)
		return (-1);
	if (ft_check_args(argc, argv) != 0)
	{
		stack_a = (t_numbers **)malloc(sizeof(t_numbers));
		stack_b = (t_numbers **)malloc(sizeof(t_numbers));
		*stack_a = NULL;
		*stack_b = NULL;
		init_stack(stack_a, argc, argv);
		sort_stack(stack_a, stack_b, (argc - 1));
	}
	else
		ft_error("Error");
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
