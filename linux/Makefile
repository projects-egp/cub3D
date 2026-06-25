# ==============================
# PROJECT
# ==============================

NAME = cub3D
BONUS_NAME = cub3D_bonus

# ==============================
# SOURCES
# ==============================

COMMON_SOURCES =	main.c\
		$(addprefix parse/, parse_main.c add_scene_data.c read_data.c\
		checklist.c store_rgb_values.c map_lines_utils.c store_map.c\
		read_map_lines.c check_stored_map.c)\
		$(addprefix window_mlx_management/, key_events.c background.c\
		link_images.c render_3d_scene.c throw_ray.c)\
		$(addprefix clean/, clean_file_data.c clean_up.c destroy_mlx.c)

MANDATORY_SOURCES =	mlx_utils.c\
			$(addprefix window_mlx_management/, update_frame.c)

BONUS_SOURCES =	$(addprefix bonus/, minimap.c mlx_utils_bonus.c\
		update_frame_bonus.c)

SRCS = $(addprefix sources/, $(COMMON_SOURCES) $(MANDATORY_SOURCES))
SRCS_BONUS = $(addprefix sources/, $(COMMON_SOURCES)) $(BONUS_SOURCES)

OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

# ==============================
# COMPILER
# ==============================

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# ==============================
# LIBFT
# ==============================

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L $(LIBFT_DIR) -lft

# ==============================
# MLX
# ==============================

MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm

# ==============================
# INCLUDES
# ==============================

INCLUDE = -I./include -I./libft -Imlx
CFLAGS += $(INCLUDE)

LIBS_FLAGS = $(LIBFT_FLAGS) $(MLX_FLAGS)

# ==============================
# RULES
# ==============================

all: $(NAME)

$(LIBFT):
	@echo "Compiling Libft..."
	@make -s -C $(LIBFT_DIR)

$(MLX):
	@echo "Compiling MLX..."
	@make -s -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS_FLAGS) -o $(NAME)
	@echo "$(NAME) created"

sources/%.o: sources/%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(MLX) $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBS_FLAGS) -o $(BONUS_NAME)
	@echo "$(BONUS_NAME) created"

clean:
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(MLX_DIR) clean
	@echo "Objects removed"

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	@make -s -C $(LIBFT_DIR) fclean
	@echo "Binary removed"

re: fclean all

bonus_re: fclean bonus

.PHONY: all bonus clean fclean re bonus_re
