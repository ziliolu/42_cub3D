NAME = cub3D
LIBDIR = ./lib/
LIB = lib.a
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wextra -Werror -Wall -g -I./includes
MLXFLAGS = -L./mlx -lX11 -lXext -lm
RM = rm -f

SRC =	./main.c							\
		./src/print/ft_print_textures.c 	\
		./src/print/ft_print_arr.c			\
		./src/free/ft_panic.c						

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