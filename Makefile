NAME        := so_long
CC          := gcc
FLAGS       := -Wall -Wextra -Werror -g
LIBFT		= ./libft/libft.a

MLX_DIR     := ./minilibx-linux
MLX_LNK     := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
MLX_INC     := -I$(MLX_DIR)

SRC         := 	so_long.c \
				parsing.c \
				parsing_utils.c \
				utils.c \
				valid_walls.c \
				render.c \
				GNL/get_next_line.c \
				GNL/get_next_line_utils.c

OBJ         := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@make -C $(MLX_DIR)
	$(CC) $(FLAGS) $(OBJ) $(MLX_LNK) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

%.o: %.c
	$(CC) $(FLAGS) $(MLX_INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus