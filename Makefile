NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include

SRC =	src/main.c \
		src/error_handling/errors.c \
		src/exit.c \
		src/init/init_mlx.c \
		src/init/init_textures.c \
		src/parsing/parse.c \
		src/parsing/texture_directions.c \
		src/parsing/parse_map.c \
		src/render/render.c \
		src/render/raycasting.c \
		src/render/textures.c \
		src/render/minimap.c \
		src/movement/handler_input.c \
		src/movement/player_direction.c \
		src/movement/player_move.c \
		src/movement/player_rotation.c \
		src/movement/valid_move.c \
		src/parsing/parse_rgb.c \
		src/parsing/parse_spawn.c \
		src/parsing/check_map.c

OBJS = ${SRC:.c=.o}

LIBFT_DIR = libft
MLX_DIR = minilibx-linux
LIBFT = -L ${LIBFT_DIR} -lft
MLX	= -L ${MLX_DIR} -lmlx -Ilmlx -lXext -lX11 -lm

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		make -C ${LIBFT_DIR}
		make -C ${MLX_DIR}
		${CC} ${OBJS} ${LIBFT} ${MLX} -o ${NAME}

all:	${NAME}

clean:
	rm -rf $(OBJ_PATH)
	make -C libft clean
	make -C minilibx-linux clean

fclean:	clean
	rm -f $(NAME)
	make -C libft fclean

re:	fclean all

.PHONY: all clean fclean re bonus