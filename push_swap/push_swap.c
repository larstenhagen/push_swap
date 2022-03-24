/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltenhage <ltenhage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:23:14 by ltenhage          #+#    #+#             */
/*   Updated: 2022/03/24 17:01:42 by ltenhage         ###   ########.fr       */
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

//Returns a pointer to the list which contains the smallest value present.
static int	*sort_values(int *values, int size)
{
	int			min;
	int			i;
	int			number;
	int			*value_order;
	int			j;

	number = 0;
	value_order = ft_calloc(size, sizeof(int));
	while (number < size)
	{
		i = 0;
		min = 2147483647;
		while (i < size)
		{
			if ((values[i] < min) && (!value_order[i]))
			{
				min = values[i];
				j = i;
			}
			i++;
		}
		value_order[j] = number + 1;
		number++;
	}
	return (value_order);
}

//Give the given array of lists indexes per list.
static void	index_stack(t_numbers **stack, int size)
{
	t_numbers	*head;
	int			index;
	int			*values;
	int			i;

	i = 0;
	values = malloc(sizeof(int) * size);
	index = 0;
	head = *stack;
	while (head)
	{
		values[i] = head->value;
		head = head->next;
		i++;
	}
	values = sort_values(values, size);
	i = 0;
	head = *stack;
	while (head)
	{
		head->index = (values[i]);
		head = head->next;
		i++;
	}
	free(values);
}

//Initialise the numbers into stack_a.
static void	init_stack(t_numbers **stack, int argc, char **argv)
{
	t_numbers	*new;
	char		**args;
	int			i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft2_lstnew(ft_atoi(args[i]), 0);
		ft2_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack, (argc - 1));
	if (argc == 2)
		ft_free(args);
}

int	main(int argc, char **argv)
{
	t_numbers	**stack_a;
	t_numbers	**stack_b;
	t_numbers	*ptr;
	int			i;

	i = 0;
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
		ft_printf("Error, no good input");
	return (0);
}
