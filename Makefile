SRCS = srcs/so_long.c \
		srcs/ft_check_map.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		./ft_printf/ft_printf.c \
		./ft_printf/ft_printf_utils.c \
		srcs/ft_init_game.c \
		srcs/ft_move_player.c \
		srcs/ft_clear.c \
		srcs/ft_is_map_valid.c 


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
		${CC} ${CFLAGS} ${OBJS}	-Llibft -lft ${MLX} -o so_long


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
		