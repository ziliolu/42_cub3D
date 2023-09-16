NAME = cub3D
LIBDIR = ./lib/
LIB = lib.a
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wextra -Werror -Wall -g -I./includes
MLXFLAGS = -g -L./mlx -lmlx -lXext -lX11 -lm -lbsd 
RM = rm -f

SRC =	./main.c									\
		./src/print/ft_print_textures.c 			\
		./src/print/ft_print_arr.c					\
		./src/print/ft_print_info.c					\
		./src/free/ft_panic.c						\
		./src/validations/valid_file.c				\
		./src/validations/valid_identifiers.c		\
		./src/validations/valid_map.c				\
		./src/utils/ft_err.c						\
		./src/utils/ft_get_trimmed_line.c				


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