/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:27:16 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/29 15:39:05 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_animation(t_mlx_data *mlx)
{
	static int	frame_counter = 0;
	frame_counter++;
	if (frame_counter == 35999)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->player_actions[mlx->direction][0], mlx->player_pos_x * SIZE, mlx->player_pos_y * SIZE);
	else if (frame_counter == 45990)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->player_actions[mlx->direction][1], mlx->player_pos_x * SIZE, mlx->player_pos_y * SIZE);
	}
	else if (frame_counter == 59999)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->player_actions[mlx->direction][2], mlx->player_pos_x * SIZE, mlx->player_pos_y * SIZE);
		frame_counter = 0;
	}
	return (0);
}

static void	ft_move_to_direction(t_mlx_data *mlx, int new_pos_x, int new_pos_y)
{
	if (mlx->map[new_pos_y][new_pos_x] == 'C')
	{
		mlx->map[new_pos_y][new_pos_x] = '0';
		mlx->n_check++;

	}
	if (mlx->map[new_pos_y][new_pos_x] != '1')
	{
		if (mlx->map[new_pos_y][new_pos_x] == 'E' && mlx->n_of_collectibles == mlx->n_check)
			ft_win(mlx);
		else if (mlx->map[new_pos_y][new_pos_x] != 'E' || mlx->n_of_collectibles == mlx->n_check)
		{
			mlx->n_of_moves++;
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.black_wall, mlx->player_pos_x * SIZE, mlx->player_pos_y * SIZE);
			mlx->player_pos_x = new_pos_x;
			mlx->player_pos_y = new_pos_y;
		}
	}
}

int	ft_move_player(int keycode, t_mlx_data *mlx)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = mlx->player_pos_x;
	new_pos_y = mlx->player_pos_y;
	if (keycode == XK_Escape)
		close_window_with_x(mlx);
	if (keycode == XK_w || keycode == XK_Up)
	{
		new_pos_y--;
		mlx->direction = 1;
		ft_move_to_direction(mlx, new_pos_x, new_pos_y);
	}
	else if (keycode == XK_d || keycode == XK_Right)
	{
		new_pos_x++;
		mlx->direction = 0;
		ft_move_to_direction(mlx, new_pos_x, new_pos_y);
	}
	else if (keycode == XK_s || keycode == XK_Down)
	{
		new_pos_y++;
		mlx->direction = 3;
		ft_move_to_direction(mlx, new_pos_x, new_pos_y);
	}
	else if (keycode == XK_a || keycode == XK_Left)
	{
		new_pos_x--;
		mlx->direction = 2;
		ft_move_to_direction(mlx, new_pos_x, new_pos_y);
	}
	ft_printf("number of movements: %d |\n", mlx->n_of_moves);
	return (0);
}