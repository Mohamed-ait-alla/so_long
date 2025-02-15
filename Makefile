
#__________VARIABLES__________#
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MLX = -lmlx -lXext -lX11
NAME = so_long
B_NAME = so_long_bonus


#__________SOURCE FILES__________#
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


#__________BONUS FILES_________#
BSRCS = bonus/so_long_bonus.c \
        bonus/ft_check_map_bonus.c \
        bonus/ft_check_path_bonus.c \
        bonus/ft_clear_bonus.c \
        bonus/ft_init_game_bonus.c \
        bonus/ft_load_sprites_bonus.c \
        bonus/ft_check_sprites_bonus.c \
        bonus/ft_ghost_bonus.c \
        bonus/ft_animation_bonus.c \
        bonus/ft_is_map_valid_bonus.c \
        bonus/ft_move_player_bonus.c \
		bonus/ft_chase_player_bonus.c \
        ./get_next_line/get_next_line.c \
        ./get_next_line/get_next_line_utils.c \
        ./ft_printf/ft_printf.c \
        ./ft_printf/ft_printf_utils.c


#__________OBJECT FILES__________#
OBJS = ${SRCS:.c=.o}
BOBJS = ${BSRCS:.c=.o}


#__________TARGETS && RULES__________#
all: ${NAME}

${NAME}: ${OBJS} | LIB
	${CC} ${CFLAGS} ${OBJS} -Llibft -lft ${MLX} -o ${NAME}

bonus: ${B_NAME}

${B_NAME}: ${BOBJS} | LIB
	${CC} ${CFLAGS} ${BOBJS} -Llibft -lft ${MLX} -o ${B_NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

LIB:
	make -C ./libft

clean:
	${RM} ${OBJS} ${BOBJS}
	make clean -C ./libft

fclean: clean
	${RM} ${NAME} ${B_NAME}
	${RM} ./libft/libft.a

re: fclean all


#__________SPECIAL RULES__________#
.PHONY: all bonus clean fclean re

.SECONDARY: ${OBJS} ${BOBJS}
