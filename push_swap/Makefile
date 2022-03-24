# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltenhage <ltenhage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 15:09:50 by ltenhage          #+#    #+#              #
#    Updated: 2022/03/24 14:29:27 by ltenhage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Werror -Wextra -Wall

SRCS =	push_swap.c \
		instructions.c \
		t_list.c \
		check_args.c \
		simple_sort.c \
		radix_sort.c \
		instructions2.c \
		tools.c

SRC_O=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRC_O)
	$(MAKE) -C ./printf
	cp printf/libftprintf.a $(NAME)
	ar -r  $(NAME) $(SRC_O)

clean:
	rm -f $(SRC_O)

fclean: clean
	rm -f $(NAME)

re: fclean all
