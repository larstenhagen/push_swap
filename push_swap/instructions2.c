/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltenhage <ltenhage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:55:28 by ltenhage          #+#    #+#             */
/*   Updated: 2022/03/24 17:00:56 by ltenhage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltenhage <ltenhage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:05:45 by ltenhage          #+#    #+#             */
/*   Updated: 2022/03/24 13:39:30 by ltenhage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arraylenght(int	*numbers)
{
	int	count;

	count = 0;
	while (numbers[count] != 0)
		count++;
	return (count - 1);
}

//takes care of ra and rb
void	rb(t_numbers **stack, int size)
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
	ft_printf("rb\n");
}

// //takes care of rra and rrb
void	rrb(t_numbers	**stack, int size)
{
	t_numbers	*head;
	t_numbers	*tail;

	if (size < 2)
		ft_printf("Error");
	head = *stack;
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
	tail->next = *stack;
	*stack = tail;
	ft_printf("rrb\n");
}

// // takes care of sa and sb
void	sb(t_numbers **numbers)
{
	int			temp;
	int			temp2;
	t_numbers	*head;

	head = *numbers;
	temp = head->index;
	head = head->next;
	temp2 = head->index;
	head->index = temp;
	head = *numbers;
	head->index = temp2;
	ft_printf("sb\n");
}

void	pb(t_numbers **stack_a, t_numbers **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		ft_printf("Error");
	else
		ft_printf("pb\n");
}
