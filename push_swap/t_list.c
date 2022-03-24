/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltenhage <ltenhage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:31:38 by ltenhage          #+#    #+#             */
/*   Updated: 2022/03/24 14:59:01 by ltenhage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Puts the given list (new) at the end of lst.
void	ft2_lstadd_back(t_numbers **lst, t_numbers *new)
{
	t_numbers	*last;

	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->next = NULL;
	}
	else
	{
		last = ft2_lstlast(*lst);
		last->next = new;
		new->next = NULL;
	}
}

//Creates a new list record with the given value as contents.
t_numbers	*ft2_lstnew(int value, int index)
{
	t_numbers	*new;

	new = (t_numbers *)malloc(sizeof(t_numbers));
	if (!new)
		return (new);
	new->value = value;
	new->index = index;
	new->next = 0;
	return (new);
}

//Returns a pointer to the last record in the list.
t_numbers	*ft2_lstlast(t_numbers *lst)
{
	if (lst == 0)
		return (0);
	if (lst->next != 0)
		return (ft2_lstlast(lst->next));
	return (lst);
}

void	ft2_lstadd_front(t_numbers **lst, t_numbers *new)
{
	new->next = *lst;
	*lst = new;
}

int	ft2_lstsize(t_numbers *lst)
{
	int				count;
	t_numbers		*ptr;

	count = 0;
	ptr = lst;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}
