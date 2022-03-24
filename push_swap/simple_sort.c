/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltenhage <ltenhage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:34:25 by ltenhage          #+#    #+#             */
/*   Updated: 2022/03/24 14:32:29 by ltenhage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_numbers **stack, int size)
{
	t_numbers	*head;
	int			*values;
	int			i;

	i = 0;
	values = ft_calloc(size, sizeof(int));
	head = *stack;
	while (head)
	{
		values[i] = head->value;
		head = head->next;
		i++;
	}
	i = 0;
	while ((values[i] < values[i + 1]) && (i < size - 1))
		i++;
	free(values);
	if (i == (size - 1))
		return (1);
	else
		return (0);
}

static void	sort_3(t_numbers **stack_a, int size)
{
	t_numbers	*head;
	int			min;
	int			next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (head->index == min && head->next->index != next_min)
	{
		ra(stack_a, size);
		sa(stack_a);
		rra(stack_a, size);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(stack_a);
		else
			rra(stack_a, size);
	}
	else
	{
		if (head->next->index == min)
			ra(stack_a, size);
		else
		{
			sa(stack_a);
			rra(stack_a, size);
		}
	}
}

static void	sort_4(t_numbers **stack_a, t_numbers **stack_b, int size)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a, size);
	else if (distance == 2)
	{
		ra(stack_a, size);
		ra(stack_a, size);
	}
	else if (distance == 3)
		rra(stack_a, size);
	if (is_sorted(stack_a, size))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a, size);
	pa(stack_a, stack_b);
}

static void	sort_5(t_numbers **stack_a, t_numbers **stack_b, int size)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a, size);
	else if (distance == 2)
	{
		ra(stack_a, size);
		ra(stack_a, size);
	}
	else if (distance == 3)
	{
		rra(stack_a, size);
		rra(stack_a, size);
	}
	else if (distance == 4)
		rra(stack_a, size);
	if (is_sorted(stack_a, size))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b, size);
	pa(stack_a, stack_b);
}

void	simple_sort(t_numbers **stack_a, t_numbers **stack_b, int size)
{
	if (is_sorted(stack_a, size) || size == 0 || \
	size == 1)
	{
		ft_printf("numbers are already sorted");
		return ;
	}
	if (size == 2)
		ra(stack_a, size);
	else if (size == 3)
		sort_3(stack_a, size);
	else if (size == 4)
		sort_4(stack_a, stack_b, size);
	else if (size == 5)
		sort_5(stack_a, stack_b, size);
}
