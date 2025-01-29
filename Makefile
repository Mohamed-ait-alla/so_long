SRCS = srcs/so_long.c \
		srcs/ft_check_map.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		./ft_printf/ft_printf.c \
		./ft_printf/ft_printf_utils.c \
		srcs/ft_init_game.c \
		srcs/ft_move_player.c \
		srcs/ft_clear.c \
		srcs/ft_is_map_valid.c \
		srcs/ft_check_sprites.c \
		srcs/ft_check_path.c 

BSCRS = bonus/so_long_bonus.c \
		bonus/ft_check_map_bonus.c \
		bonus/ft_clear_bonus.c \
		bonus/ft_init_game_bonus.c \
		bonus/ft_ghost_bonus.c \
		bonus/ft_is_map_valid_bonus.c \
		bonus/ft_move_player_bonus.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		./ft_printf/ft_printf.c \
		./ft_printf/ft_printf_utils.c


OBJS = ${SRCS:.c=.o}
BOBJS = ${BSCRS:.c=.o}


NAME = libft.a
# B_NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f
MLX = -lmlx -lXext -lX11

all: ${NAME}

# bonus: ${B_NAME}

LIB:
	make -C ./libft

${NAME}: LIB ${OBJS}
		${CC} ${CFLAGS} ${OBJS}	-Llibft -lft ${MLX} -o so_long

${B_NAME}: LIB ${BOBJS}
		${CC} ${CFLAGS} ${BOBJS} -Llibft -lft ${MLX} -o so_long_bonus


clean:
	${RM} ${OBJS}
	${RM} ${BOBJS}
	make clean -C ./libft

fclean: clean
		${RM} ${NAME}
		${RM} ${B_NAME}
		${RM} so_long
		${RM} so_long_bonus
		${RM} ./libft/libft.a


re: fclean all

.PHONY: all fclean re clean

.SECONDARY: ${OBJS} ${BOBJS}
		