NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
BONUS = 0

SRC_PATH = src/
OBJ_PATH = objects/
INC = -I include -I libft -I minilibx-linux

LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a
LIBS = -L libft -lft -L minilibx-linux -lmlx -lXext -lX11 -lm -lbsd

SRC =	main.c \
		error_handling/errors.c \
		exit.c \
		init/init_mlx.c \
		init/init_textures.c \
		parsing/parse.c \
		parsing/texture_directions.c \
		parsing/parse_map_utils.c \
		parsing/parse_map.c \
		parsing/parse_rgb.c \
		parsing/parse_spawn.c \
		parsing/check_map.c \
		render/render.c \
		render/raycasting.c \
		render/textures.c \
		render/minimap.c \
		render/dda.c \
		movement/handler_input.c \
		movement/player_direction.c \
		movement/player_move.c \
		movement/player_rotation.c \
		movement/valid_move.c \
		free.c \
		parsing/ft_line_handler.c \
		error_handling/free_error.c \
		error_handling/check_null_str.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJS = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

all:	$(NAME)

bonus:	fclean
	make all BONUS=1

$(NAME):	$(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -DBONUS=$(BONUS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "Cub3D: $(if $(filter 1,$(BONUS)),BONUS,MANDATORY)"

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -DBONUS=$(BONUS) -c $< -o $@ $(INC)

$(LIBFT):
	make -sC libft

$(MLX):
	make -sC minilibx-linux

clean:
	rm -rf $(OBJ_PATH)
	make -C libft clean
	make -C minilibx-linux clean

fclean:	clean
	rm -f $(NAME)
	make -C libft fclean

re:	fclean all

.PHONY: all clean fclean re bonus
