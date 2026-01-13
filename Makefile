NAME        := so_long
CC          := gcc
FLAGS       := -Wall -Wextra -Werror

MLX_DIR     := ./minilibx-linux
MLX_LNK     := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
MLX_INC     := -I$(MLX_DIR)

SRC         := so_long.c
OBJ         := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_DIR)
	$(CC) $(OBJ) $(MLX_LNK) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(MLX_INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus