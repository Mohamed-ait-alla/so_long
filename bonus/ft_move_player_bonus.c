/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:27:16 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/15 16:27:36 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long_bonus.h"

static void	ft_move_to_direction(t_mlx_data *mlx, int new_pos_x, int new_pos_y)
{
	if (mlx->map[new_pos_y][new_pos_x] == 'C')
	{
		mlx->map[new_pos_y][new_pos_x] = '0';
		mlx->n_check++;
	}
	if (mlx->map[new_pos_y][new_pos_x] != '1')
	{
		if (mlx->map[new_pos_y][new_pos_x] == 'E'
			&& mlx->n_of_collectibles == mlx->n_check)
			ft_win(mlx);
		else if (mlx->map[new_pos_y][new_pos_x] != 'E'
			|| mlx->n_of_collectibles == mlx->n_check)
		{
			mlx->n_of_moves++;
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
				mlx->sprites.black_wall, mlx->player_pos_x * SIZE,
				mlx->player_pos_y * SIZE);
			mlx->player_pos_x = new_pos_x;
			mlx->player_pos_y = new_pos_y;
		}
	}
}

static void	ft_set_directions(t_mlx_data *mlx, int sc, int n_pos_x, int n_pos_y)
{
	if (sc == XK_w || sc == XK_Up)
	{
		n_pos_y--;
		mlx->direction = 1;
		ft_move_to_direction(mlx, n_pos_x, n_pos_y);
	}
	else if (sc == XK_d || sc == XK_Right)
	{
		n_pos_x++;
		mlx->direction = 0;
		ft_move_to_direction(mlx, n_pos_x, n_pos_y);
	}
	else if (sc == XK_s || sc == XK_Down)
	{
		n_pos_y++;
		mlx->direction = 3;
		ft_move_to_direction(mlx, n_pos_x, n_pos_y);
	}
	else if (sc == XK_a || sc == XK_Left)
	{
		n_pos_x--;
		mlx->direction = 2;
		ft_move_to_direction(mlx, n_pos_x, n_pos_y);
	}
}

int	ft_move_player(int keycode, t_mlx_data *mlx)
{
	int		new_pos_x;
	int		new_pos_y;

	new_pos_x = mlx->player_pos_x;
	new_pos_y = mlx->player_pos_y;
	if (!mlx->is_died)
		return (0);
	if (keycode == XK_Escape)
		close_window_with_x(mlx);
	ft_set_directions(mlx, keycode, new_pos_x, new_pos_y);
	ft_display_moves_on_screen(mlx);
	return (0);
}
