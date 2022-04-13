/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltenhage <ltenhage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:02:44 by ltenhage          #+#    #+#             */
/*   Updated: 2022/04/12 16:36:27 by ltenhage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//The number of the highest number of bits in a present number is returned.
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

//All the present indexes are iterated and checked per bit,
//starting from the rightmost bit to the left.
//By comparing (with '&' bitwise operator) the bits with 1. 
//The first bit is checked on the presence of 1 instead of 0.
//When the bit contains 0, it is added to base 2.
//Eventually all the numbers are set back in order.
void	radix_sort(t_numbers **stack_a, t_numbers **stack_b, int size)
{
	t_numbers	*head_a;
	int			i;
	int			j;
	int			max_bits;

	i = 0;
	head_a = *stack_a;
	max_bits = get_max_bit(stack_a);
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
