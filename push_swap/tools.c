/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltenhage <ltenhage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:28:55 by ltenhage          #+#    #+#             */
/*   Updated: 2022/04/12 19:46:46 by ltenhage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_distance(t_numbers **stack, int index)
{
	t_numbers	*head;
	int			distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

int	get_min(t_numbers **stack, int val)
{
	t_numbers	*head;
	int			min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

//Returns a pointer to the list which contains the smallest value present.
int	*sort_values(int *values, int size, int number)
{
	int			min;
	int			i;
	int			*value_order;
	int			j;

	value_order = ft_calloc(size, sizeof(int));
	while (number < (size + 1))
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
		value_order[j] = number;
		number++;
	}
	free(values);
	return (value_order);
}

//Give the given array of lists indexes per list.
void	index_stack(t_numbers **stack, int size)
{
	t_numbers	*head;
	int			*values;
	int			i;

	i = 0;
	values = malloc(sizeof(int) * size);
	head = *stack;
	while (head)
	{
		values[i] = head->value;
		head = head->next;
		i++;
	}
	values = sort_values(values, size, 0);
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
void	init_stack(t_numbers **stack, int argc, char **argv)
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
