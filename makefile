# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tandrian <tandrian@student.42antanana      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/19 10:20:39 by tandrian          #+#    #+#              #
#    Updated: 2026/03/19 10:20:44 by tandrian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	./src/main.c \
		./src/push.c \
		./src/swap.c \
		./src/rotate.c \
		./src/reverse.c \
		./src/more_utils.c \
		./src/parse_args.c \
		./src/utils.c \
		./src/utils_again.c \
		./src/ft_split.c \
		./src/simple_algorithm.c \
		./src/medium_algorithm.c \
		./src/complex_algorithm.c \
		./src/adaptive.c \
		./src/print_fd.c \
		./src/print_ops.c \
		./src/benchmark.c

BONUS_SRCS = ./bonus/checker.c \
			 ./src/push.c \
			 ./src/swap.c \
			 ./src/rotate.c \
			 ./src/reverse.c \
			 ./src/more_utils.c \
			 ./src/parse_args.c \
			 ./src/utils.c \
			 ./src/utils_again.c \
			 ./src/ft_split.c \
			 ./src/simple_algorithm.c \
			 ./src/medium_algorithm.c \
			 ./src/complex_algorithm.c \
			 ./src/adaptive.c \
			 ./src/print_fd.c \
			 ./src/print_ops.c \
			 ./src/benchmark.c \
			 ./bonus/get_next_line.c \
			 ./bonus/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o checker

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f checker

re: fclean all

.PHONY: all bonus clean fclean re 
