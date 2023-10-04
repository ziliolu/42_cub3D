NAME = cub3D
LIBDIR = ./lib/
LIB = lib.a
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wextra -Werror -Wall -g -I./includes
MLXFLAGS = -g -L./mlx    -lm #-lbsd -lmlx -lXext -lX11
RM = rm -f

SRC =	./main.c									\
		./src/print/ft_print_textures.c 			\
		./src/print/ft_print_arr.c					\
		./src/print/ft_print_info.c					\
		./src/free/ft_panic.c						\
		./src/validations/valid_file.c				\
		./src/validations/valid_identifiers.c		\
		./src/validations/valid_map.c				\
		./src/utils/utils.c							\
		./src/utils/game_loop.c						\
		./src/utils/game_loop_utils.c				\
		./src/raycaster/my_mlx_pixel_put.c			\
		./src/raycaster/ft_display_player.c			\
		./src/raycaster/render_map.c				\
		./src/raycaster/rays.c						\
		./src/raycaster/print_rays.c				\
		./src/raycaster/dda_algorithm.c

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

re: fclean all

.SILENT: