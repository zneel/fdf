CC := cc
CFLAGS := -Wall -Wextra -Werror -lm -O3
MLX_PATH := ./mlx_linux
SRCS := main.c
OBJS := $(SRCS:.c=.o)
LIBFT_PATH := ./libft
LIBFT_FLAGS := -L$(LIBFT_PATH) -lft
MLX_FLAGS := -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
NAME := fdf

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_PATH)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -I$(LIBFT_PATH) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
