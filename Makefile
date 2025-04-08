NAME = so_long

MLX_DIR = mlx

MLX_PATH = $(MLX_DIR)/libmlx.a

CC = cc

CFLAG = -Wall -Wextra -Werror

MLXFLAG = -ldl -lmlx -L$(MLX_DIR) -lm -lXext -lX11 -IMlx $(MLX_PATH)

SRCS = 	main.c ft_utils.c map_init.c ft_free.c map_validation.c map_validation2.c \
	game_init.c get_images.c game_utils.c ft_free2.c game_draw.c game_draw2.c \
	game_render.c game_play.c game_keypress.c game_animation.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	make -C libft
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLXFLAG) -Llibft -lft
	@echo -e "\033[32m $(NAME) Created successfully\033[0m"

%.o: %.c
	$(CC) $(CFLAG) -g -c $? -o $@

clean:
	rm -f $(OBJS)
	make clean -C libft
	@echo "\033[32mObject files removed successfully\033[0m"

fclean:	clean
	rm -f $(NAME)
	make fclean -C libft
	@echo "\033[32m$(NAME) removed successfully\033[0m"

re:	fclean all

.PHONY: all clean fclean re
