/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltenhage <ltenhage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:05:45 by ltenhage          #+#    #+#             */
/*   Updated: 2022/04/13 17:41:38 by ltenhage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_numbers **stack_to, t_numbers **stack_from)
{
	t_numbers	*tmp;
	t_numbers	*head_to;
	t_numbers	*head_from;

	if (ft2_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

//takes care of ra and rb
void	ra(t_numbers **stack, int size)
{
	t_numbers	*head;
	t_numbers	*tail;

	if (size < 2)
		ft_printf("Error");
	head = *stack;
	tail = ft2_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	ft_printf("ra\n");
}

// //takes care of rra and rrb
void	rra(t_numbers **stack_a)
{
	t_numbers	*head;
	t_numbers	*tail;

	if (ft2_lstsize(*stack_a) < 2)
		return ;
	head = *stack_a;
	tail = ft2_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack_a;
	*stack_a = tail;
	ft_printf("rra\n");
}

// // takes care of sa and sb
void	sa(t_numbers **stack_a)
{
	t_numbers	*head;
	t_numbers	*next;
	int			tmp_val;
	int			tmp_index;

	if (ft2_lstsize(*stack_a) < 2)
		return ;
	head = *stack_a;
	next = head->next;
	if (!head && !next)
		ft_error("Error occured while swapping!");
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	ft_printf("sa\n");
}

void	pa(t_numbers **stack_a, t_numbers **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		ft_printf("Error");
	else
		ft_printf("pa\n");
}
