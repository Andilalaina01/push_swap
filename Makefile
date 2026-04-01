# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamy-and <mamy-and@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/18 10:28:17 by safidian          #+#    #+#              #
#    Updated: 2026/03/25 18:37:40 by mamy-and         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a
ALGO        = ./algorithm/

SRCS = push_swap.c check_input.c stack.c utils.c utils1.c bench.c \
			complex_algo.c medium_algo.c simple_algo.c adaptive_algo.c strategy.c\
			push.c r_rotate.c rotate.c swap.c

OBJS = $(SRCS:.c=.o)

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iinclude -I$(LIBFT_DIR)
all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
