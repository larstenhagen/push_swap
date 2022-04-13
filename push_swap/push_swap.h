/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltenhage <ltenhage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:10:43 by ltenhage          #+#    #+#             */
/*   Updated: 2022/04/13 17:40:01 by ltenhage         ###   ########.fr       */
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

//checking arguments
int			ft_check_args(int argc, char **argv);

void		ft_error(char *message);

//initialising stack_a
void		index_stack(t_numbers **stack, int size);

void		init_stack(t_numbers **stack, int argc, char **argv);

int			*sort_values(int *values, int size, int number);

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

void		rra(t_numbers	**stack);

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

void		ft_free(char **str);

int			is_sorted(t_numbers **stack, int size);

void		free_stack(t_numbers **stack);

#endif