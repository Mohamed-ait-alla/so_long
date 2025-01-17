/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:02:20 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/17 15:32:08 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#define SIZE 32
#include <stdio.h> // we don't this header when we gonna push this shit 
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "./minilibx-linux/mlx.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include <X11/keysym.h>

typedef struct  s_img_data
{
	void	*img;
}	t_img_data;

typedef struct s_frame
{
	int	n_col;
	int	n_row;
}	t_frame;

typedef struct s_sprites
{
	void	*wall;
	void	*black_wall;
	void	*player_closed;
	void	*player_right_open;
	void	*player_left_open;
	void	*player_down_open;
	void	*player_up_open;
	void	*player_semi_up;
	void	*player_semi_down;
	void	*player_semi_right;
	void	*player_semi_left;
	void	*food;
	void	*exit;
}	t_sprites;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*mlx_window;
	char		**map;
	char		*player_actions[4][3];
	int			player_pos_x;
	int			player_pos_y;
	int			n_of_collectibles;
	int			n_check;
	int			direction;
	t_sprites	sprites;
}	t_mlx_data;

int	ft_animation(t_mlx_data *mlx);
void	ft_win();
int		close_window_with_x(t_mlx_data *data);
void	ft_calc_width_and_height(char	*file, t_frame *frame);
void	ft_init_game(char **map, t_mlx_data *mlx);
void	ft_check_error_map(char **map);
char	**ft_read_map(char *file, t_frame *frame);
int	ft_move_player(int keycode, t_mlx_data *mlx);
#endif