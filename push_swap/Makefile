# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltenhage <ltenhage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 15:09:50 by ltenhage          #+#    #+#              #
#    Updated: 2022/04/13 19:06:43 by ltenhage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECK = checker

FLAGS = -Werror -Wextra -Wall

SRCS =	push_swap.c \
		instructions.c \
		t_list.c \
		check_args.c \
		simple_sort.c \
		radix_sort.c \
		instructions2.c \
		tools.c \
		tools2.c

CHECK_SRC = instructions.c \
			instructions2.c \
			t_list.c \
			tools.c \
			tools2.c \
			check_args.c \
			simple_sort.c \
			checker.c
			
SRC_O=$(SRCS:.c=.o)
CHECK_SRC_O=$(CHECK_SRC:.c=.o)

all: $(NAME) ${CHECK}

$(NAME): $(SRC_O)
	$(MAKE) -C ./printf
	gcc $(FLAGS) $(SRC_O) printf/libftprintf.a -o ${NAME}

bonus : ${CHECK}

${CHECK} : ${CHECK_SRC_O}
	gcc ${FLAGS} ${CHECK_SRC_O} printf/libftprintf.a -o ${CHECK}

clean:
	rm -f $(SRC_O)
	rm -f $(CHECK_SRC_O)

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECK)

re: fclean all
