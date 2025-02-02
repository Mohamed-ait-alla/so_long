/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:02:20 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/02 09:34:19 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define SIZE 32 
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <X11/keysym.h>

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
	void	*ghost_up[6];
	void	*ghost_down[6];
	void	*ghost_right[6];
	void	*ghost_left[6];
	void	*food;
	void	*exit;
}	t_sprites;

typedef struct s_ghost
{
	int		n_pos_x;
	int		n_pos_y;
	int		old_pos_x;
	int		old_pos_y;
	char	tile;
}	t_ghost;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*mlx_window;
	char		**map;
	char		**copy_map;
	char		*player_actions[4][3];
	char		*player_dying[11];
	int			player_pos_x;
	int			player_pos_y;
	int			ghost_pos_x;
	int			ghost_pos_y;
	int			old_ghost_pos_x;
	int			old_ghost_pos_y;
	int			n_of_collectibles;
	int			n_of_moves;
	int			n_check;
	int			wanted_ghost;
	int			is_died;
	int			direction;
	int			n_of_ghosts;
	int			r_map_len;
	int			c_map_len;
	t_ghost		*ghosts;
	t_sprites	sprites;
}	t_mlx_data;

void	ft_display_moves_on_screen(t_mlx_data *mlx);
void	ft_cleanup(t_mlx_data *mlx);
void	ft_free_window(t_mlx_data *mlx);
void	check_file_extention(char *file);
void	ft_check_path(t_mlx_data *mlx, t_frame frame);
void	ft_player_dying_animation(t_mlx_data *mlx);
void	ft_free_map(char **map, int i);
void	ft_ghost_animation(t_mlx_data *mlx);
void	ft_win(t_mlx_data *mlx);
void	ft_lose(t_mlx_data *mlx);
void	ft_calc_width_and_height(char	*file, t_frame *frame);
void	ft_load_sprites(t_mlx_data *mlx);
void	ft_init_game(t_mlx_data *mlx);
void	ft_check_error_map(char **map, t_frame frame);
char	**ft_read_map(char *file, t_frame *frame);
int		ft_check_sprites(t_mlx_data *mlx);
int		is_map_has_other_chars(char **map);
int		is_map_closed_by_walls(char **map, t_frame frame);
int		is_map_rectangular(char **map);
int		is_epc_in_map(char **map);
int		ft_check_distance_with_ghosts(t_mlx_data *mlx,
			int P_new_pos_x, int P_new_pos_y);
int		ft_animation(t_mlx_data *mlx);
int		close_window_with_x(t_mlx_data *data);
int		ft_move_player(int keycode, t_mlx_data *mlx);

#endif