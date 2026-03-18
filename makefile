# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/14 19:04:04 by rhrandri          #+#    #+#              #
#    Updated: 2026/03/18 10:36:13 by rhrandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c \
		push.c \
		swap.c \
		rotate.c \
		reverse.c \
		more_utils.c \
		parse_args.c \
		utils.c \
		utils_again.c \
		ft_split.c \
		simple_algorithm.c \
		medium_algorithm.c \
		complex_algorithm.c \
		adaptive.c \
		print_fd.c \
		print_ops.c \
		benchmark.c

BONUS_SRCS = checker.c \
			 push.c \
			 swap.c \
			 rotate.c \
			 reverse.c \
			 more_utils.c \
			 parse_args.c \
			 utils.c \
			 utils_again.c \
			 ft_split.c \
			 simple_algorithm.c \
			 medium_algorithm.c \
			 complex_algorithm.c \
			 adaptive.c \
			 print_fd.c \
			 print_ops.c \
			 benchmark.c \
			 get_next_line.c \
			 get_next_line_utils.c

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
