SRCS = so_long.c


OBJS = ${SRCS:.c=.o}


NAME = so_long
CC = cc
CFLAGS = #-Wall -Wextra -Werror
RM = rm
MLX = -Lmlx -lmlx -lXext -lX11

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} ${MLX} -o so_long

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}
re: fclean all

.PHONY: all fclean re clean

.SECONDARY: ${OBJS}
		