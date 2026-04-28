NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I include

SRC =	src/main.c \
		src/error_handling/errors.c \
		src/exit.c \
		src/init/init_mlx.c \
		src/parsing/parse.c \

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
		make -C ${LIBFT_DIR} clean
		make -C ${MLX_DIR} clean
		rm -f ${OBJS}

fclean: clean
		make -C ${LIBFT_DIR} fclean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
