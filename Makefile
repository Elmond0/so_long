NAME = so_long

MLX_DIR = mlx

MLX_PATH = $(MLX_DIR)/libmlx.a

CC = cc

CFLAG = -Wall -Wextra -Werror -fsanitize=address

MLXFLAG = -ldl -lmlx -L$(MLX_DIR) -lm -lXext -lX11 -IMlx $(MLX_PATH)

SRCS = main.c ft.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAG) $^ -o $@ $(MLXFLAG) 
	@echo -e "\033[32m $(NAME) Created successfully\033[0m"

%.o: %.c
	$(CC) $(CFLAG) -g -c $? -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
