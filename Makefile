NAME = cub3D
SOURCES =	main.c

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./mlx_linux
MLX = $(MLX_DIR)/libmlx.a

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror
LIBFT_FLAGS = -L $(LIBFT_DIR) -l ft
MLX_FLAGS = -Lmlx_linux -lmlx_Linux  -L/usr/lib/X11 -lXext -lX11
LIBS_FLAGS = $(LIBFT_FLAGS) $(MLX_FLAGS)

CC = cc
RM = rm -f

all: $(NAME)

$(LIBFT):
	$(info Compiling Libft...)
	@make -s -C $(LIBFT_DIR)

$(MLX):
	$(info CREATED $(MLX))
	@make -s -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS_FLAGS) -o $(NAME)
	$(info CREATED $(NAME))

clean:
	$(RM) $(OBJECTS)
	@make -s -C $(LIBFT_DIR) clean
	$(info REMOVED OBJECTS AND LIBFT/OBJECTS)

compclean: all clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLX_DIR) clean
	$(info REMOVED $(NAME), $(MLX) AND -IN CASE THESE EXISTED YET- OBJECTS)

re: fclean all

.PHONY: all clean fclean re compclean
