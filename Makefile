NAME := fdf

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3 -I./include
MLX_PATH := ./mlx_linux

SRCS := src/main.c \
        src/events/handlers.c \
        src/events/loop.c \
        src/helpers/colors.c \
		src/parser/map.c \
		src/matrix/operations.c \
		src/draw/draw.c \
		src/draw/image.c

OBJS := $(SRCS:.c=.o)
LIBFT_PATH := ./libft
LIBFT_FLAGS := -L$(LIBFT_PATH) -lft
MLX_FLAGS := -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# Header file dependencies for each source file
DEPS := include/fdf.h

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_PATH)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)

%.o: %.c $(DEPS)
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