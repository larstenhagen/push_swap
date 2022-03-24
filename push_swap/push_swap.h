/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltenhage <ltenhage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:10:43 by ltenhage          #+#    #+#             */
/*   Updated: 2022/03/24 17:01:12 by ltenhage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./printf/includes/ft_printf.h"

typedef struct s_numbers
{
	int					value;
	int					index;
	struct s_numbers	*next;
}				t_numbers;

int			ft_check_args(int argc, char **argv);

void		ft_free(char **str);

//Making / sorting the lists
t_numbers	*ft2_lstlast(t_numbers *lst);

t_numbers	*ft2_lstnew(int value, int index);

void		ft2_lstadd_back(t_numbers **lst, t_numbers *new);

void		ft2_lstadd_front(t_numbers **lst, t_numbers *new);

int			ft2_lstsize(t_numbers *lst);

//Algoritims
void		simple_sort(t_numbers **stack_a, t_numbers **stack_b, int size);

void		radix_sort(t_numbers **stack_a, t_numbers **stack_b, int size);

//all the instrucions
void		ra(t_numbers **stack, int size);

void		rra(t_numbers	**stack, int size);

void		sa(t_numbers **numbers);

void		pa(t_numbers **stack_a, t_numbers **stack_b);

void		rb(t_numbers **stack, int size);

void		rrb(t_numbers	**stack, int size);

void		sb(t_numbers **numbers);

void		pb(t_numbers **stack_a, t_numbers **stack_b);

int			push(t_numbers **stack_to, t_numbers **stack_from);

int			arraylenght(int	*numbers);

//tools
int			get_min(t_numbers **stack, int val);

int			get_distance(t_numbers **stack, int index);

#endif