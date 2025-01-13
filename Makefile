SRCS = so_long.c ft_check_map.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		ft_init_game.c


OBJS = ${SRCS:.c=.o}


NAME = libft.a
CC = cc
CFLAGS = #-Wall -Wextra -Werror
RM = rm -f
MLX = -Lmlx -lmlx -lXext -lX11

all: ${NAME}

LIB:
	make -C ./libft
	cp ./libft/libft.a $(NAME)


${NAME}: LIB ${OBJS}
		${CC} ${CFLAGS} ${OBJS} libft.a ${MLX} -o so_long


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
		