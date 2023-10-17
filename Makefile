NAME = cub3D

LIBDIR = ./lib/
LIB = lib.a
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wextra -Werror -Wall -g -I./includes
MLXFLAGS = -g -L./mlx  -lXext -lX11 -lmlx -lm #-fsanitize=address
RM = rm -f

SRC =	./mandatory/main.c										\
		./mandatory/src/free/ft_panic.c							\
		./mandatory/src/free/ft_free.c							\
		./mandatory/src/validations/valid_file.c				\
		./mandatory/src/validations/valid_file_utils.c			\
		./mandatory/src/validations/valid_identifiers.c			\
		./mandatory/src/validations/valid_identifiers_utils.c	\
		./mandatory/src/validations/valid_map.c					\
		./mandatory/src/validations/valid_map_utils.c			\
		./mandatory/src/validations/valid_map_utils2.c			\
		./mandatory/src/utils/utils.c							\
		./mandatory/src/utils/game_loop.c						\
		./mandatory/src/utils/game_loop_utils.c					\
		./mandatory/src/utils/ft_init_structs.c					\
		./mandatory/src/raycaster/my_mlx_pixel_put.c			\
		./mandatory/src/raycaster/ft_display_player.c			\
		./mandatory/src/raycaster/render_map.c					\
		./mandatory/src/raycaster/rays.c						\
		./mandatory/src/raycaster/print_rays.c					\
		./mandatory/src/raycaster/dda_algorithm.c

all: $(NAME)

$(NAME): $(OBJ) $(LIBDIR)$(LIB)
	$(CC) $(OBJ) $(MLXFLAGS) -L$(LIBDIR) -l:$(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR)$(LIB):
	@make -C $(LIBDIR)

clean:
	rm -f $(OBJ)
	@make clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	rm -f map_file

re: fclean all

.SILENT: