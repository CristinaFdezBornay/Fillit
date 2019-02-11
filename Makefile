# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibaran <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 16:48:47 by ibaran            #+#    #+#              #
#    Updated: 2018/12/16 17:56:21 by ibaran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = \
	./c_alloc_and_free.c \
	./c_checks.c \
	./c_getinput.c \
	./c_insert_and_organize.c \
	./c_main.c \
	./c_move_and_copy.c \
	./c_solve.c \
	./c_print_fillit.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I ./ -I ./libft/
FLAGS = -Wall -Wextra -Werror
LIBRARY = -L./libft -lft

all: $(NAME)

$(NAME): $(SRCS)
	@make -C ./libft/
	@gcc $(FLAGS) -c $? $(INCLUDES)
	@gcc -o $(NAME) $(LIBRARY) $(OBJS)

clean: libclean
	@/bin/rm -f $(OBJS)

fclean: clean libfclean
	@/bin/rm -f $(NAME)

libclean:
	@make clean -C ./libft/

libfclean:
	@make fclean -C ./libft/

libre:
	@make re -C ./libft/

re: fclean all
