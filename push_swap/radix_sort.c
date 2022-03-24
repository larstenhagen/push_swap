/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltenhage <ltenhage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:02:44 by ltenhage          #+#    #+#             */
/*   Updated: 2022/03/24 16:58:54 by ltenhage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bit(t_numbers	**stack)
{
	t_numbers	*head;
	int			max;
	int			max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_numbers **stack_a, t_numbers **stack_b, int size)
{
	t_numbers	*head_a;
	int			i;
	int			j;
	int			max_bits;

	i = 0;
	head_a = *stack_a;
	max_bits = get_max_bit(stack_a);
	// ra(stack_a, size);
	// pb(stack_a, stack_b);
	// pb(stack_a, stack_b);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a, size);
			else
				pb(stack_a, stack_b);
		}
		while (ft2_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
