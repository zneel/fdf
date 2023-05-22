# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 22:09:21 by ebouvier          #+#    #+#              #
#    Updated: 2023/05/22 22:12:32 by ebouvier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3 -I./include
MLX_PATH := ./mlx_linux

SRCS := src/main.c \
		src/events/handlers.c \
		src/events/loop.c

OBJS := $(SRCS:.c=.o)
LIBFT_PATH := ./libft
LIBFT_FLAGS := -L$(LIBFT_PATH) -lft
MLX_FLAGS := -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_PATH)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re