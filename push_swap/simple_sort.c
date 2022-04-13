/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltenhage <ltenhage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:34:25 by ltenhage          #+#    #+#             */
/*   Updated: 2022/04/13 17:31:53 by ltenhage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_numbers **stack, int size)
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

static void	sort_3(t_numbers **stack_a, int size, int min)
{
	t_numbers	*head;

	head = *stack_a;
	if (head->index == min && head->next->index != get_min(stack_a, min))
	{
		rra(stack_a);
		sa(stack_a);
		return ;
	}
	else if (head->index == get_min(stack_a, min))
	{
		if (head->next->index == min)
			sa(stack_a);
		else
			rra(stack_a);
		return ;
	}
	if (head->next->index == min)
	{
		ra(stack_a, size);
		return ;
	}
	sa(stack_a);
	rra(stack_a);
}

static void	sort_4(t_numbers **stack_a, t_numbers **stack_b, int size)
{
	int			distance;
	t_numbers	*head;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a, size);
	else if (distance == 2)
	{
		ra(stack_a, size);
		ra(stack_a, size);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a, size))
		return ;
	pb(stack_a, stack_b);
	head = *stack_a;
	if (!is_sorted(stack_a, ft2_lstsize(head)))
		sort_3(stack_a, size, get_min(stack_a, -1));
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
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a, size))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b, size);
	pa(stack_a, stack_b);
}

void	simple_sort(t_numbers **stack_a, t_numbers **stack_b, int size)
{
	int	min;

	min = get_min(stack_a, -1);
	if (is_sorted(stack_a, size) || size == 0 || \
	size == 1)
	{
		return ;
	}
	if (size == 2)
		ra(stack_a, size);
	else if (size == 3)
		sort_3(stack_a, size, min);
	else if (size == 4)
		sort_4(stack_a, stack_b, size);
	else if (size == 5)
		sort_5(stack_a, stack_b, size);
}
