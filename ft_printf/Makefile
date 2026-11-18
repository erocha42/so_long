NAME        = libftprintf.a
LIBFT_DIR   = ../libft
LIBFT       = $(LIBFT_DIR)/libft.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

SRC_DIR     = src
SRCS        = $(SRC_DIR)/ft_printf.c \
			$(SRC_DIR)/print_c.c \
			$(SRC_DIR)/print_d.c \
			$(SRC_DIR)/print_p.c \
			$(SRC_DIR)/print_s.c \
			$(SRC_DIR)/print_u.c \
			$(SRC_DIR)/print_x.c \
			$(SRC_DIR)/print_x_upp.c \
			$(SRC_DIR)/put_hex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "→ Création de $(NAME)"
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	@echo "→ Compilation de libft"
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@echo "→ Compilation de $<"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)
	rm -f $(NAME)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
