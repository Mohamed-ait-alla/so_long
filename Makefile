SRCS = so_long.c ft_check_map.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		./ft_printf/ft_printf.c ./ft_printf/ft_printf_utils.c ft_init_game.c ft_move_player.c ft_ghost.c \
		ft_clear.c ft_is_map_valid.c 


OBJS = ${SRCS:.c=.o}


NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MLX = -lmlx -lXext -lX11

all: ${NAME}

LIB:
	make -C ./libft


${NAME}: LIB ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -Llibft -lft ${MLX} -o so_long


clean:
	${RM} ${OBJS}
	make clean -C ./libft

fclean: clean
		${RM} ${NAME}
		${RM} so_long
		${RM} ./libft/libft.a


re: fclean all

.PHONY: all fclean re clean

.SECONDARY: ${OBJS}
		