NAME= sclolus.filler
SRC= srcs/main.c \
	srcs/ft_init_champion.c \
	srcs/ft_error.c \
	srcs/ft_free_champ.c \
	srcs/ft_free_lines.c \
	srcs/ft_free_champs.c \
	srcs/ft_free_board.c \
	srcs/ft_free_piece.c \
	srcs/ft_cleanup_piece_coord.c \
	srcs/ft_cleanup_map.c \
	srcs/ft_read_board.c \
	srcs/ft_lines_to_long.c \
	srcs/ft_piece_to_long.c \
	srcs/ft_check_board_lines.c \
	srcs/ft_lst_push_back.c \
	srcs/ft_get_piece.c \
	srcs/ft_check_piece_lines.c \
	srcs/ft_get_filler_lens.c \
	srcs/ft_read_piece.c \
	srcs/ft_claim.c \
	srcs/ft_get_sandbox.c \
	srcs/ft_put_piece.c \
	srcs/ft_solve.c \
	srcs/ft_print_coord.c \
	srcs/ft_get_pos.c \
	srcs/ft_get_distance.c \
	srcs/ft_update_distance_tabs.c \
	srcs/ft_get_manhattan_distance.c \
	srcs/ft_normalize_lines.c \
	srcs/ft_normalize_col.c \
	srcs/ft_normalize_piece.c \
	srcs/ft_normalize_extra_lines.c \
	srcs/ft_normalize_extra_col.c
OBJ= $(SRC:.c=.o)
HDR_PATH= ./libft/includes/
CC= gcc
CC_FLAGS= -Wall -Werror -Wextra

all: submodule $(NAME)

submodule:
	@make -C libft/

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $^ -L./libft -lft -o $(NAME)
%.o : %.c
	$(CC) $(CC_FLAGS) $< -c -I$(HDR_PATH) -I./includes -o $@

clean:
	rm -f $(OBJ)
	make -C libft/ clean
fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
