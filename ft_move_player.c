/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:27:16 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/17 16:00:35 by mait-all         ###   ########.fr       */
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

static void	ft_move_up(t_mlx_data *mlx, int new_pos_x, int new_pos_y)
{
	new_pos_y--;
	if (mlx->map[new_pos_y][new_pos_x] == 'C')
	{
		mlx->map[new_pos_y][new_pos_x] = '0';
		mlx->n_check++;
	}
	else if (mlx->map[new_pos_y][new_pos_x] != '1')
	{
		if (mlx->map[new_pos_y][new_pos_x] == 'E' && mlx->n_of_collectibles == mlx->n_check)
			ft_win();
		else if (mlx->map[new_pos_y][new_pos_x] != 'E' || mlx->n_of_collectibles == mlx->n_check)
		{
			printf("up\n");
			mlx->direction = 1;
			// mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.player_closed, new_pos_x * SIZE, new_pos_y * SIZE);
			// mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.black_wall, mlx->player_pos_x * SIZE, mlx->player_pos_y * SIZE);
			// mlx->player_pos_x = new_pos_x;
			// mlx->player_pos_y = new_pos_y;
		}
	}
}

static void	ft_move_down(t_mlx_data *mlx, int new_pos_x, int new_pos_y)
{
	new_pos_y++;
	if (mlx->map[new_pos_y][new_pos_x] == 'C')
	{
		mlx->map[new_pos_y][new_pos_x] = '0';
		mlx->n_check++;

	}
	else if (mlx->map[new_pos_y][new_pos_x] != '1')
	{
		if (mlx->map[new_pos_y][new_pos_x] == 'E' && mlx->n_of_collectibles == mlx->n_check)
			ft_win();
		else if (mlx->map[new_pos_y][new_pos_x] != 'E' || mlx->n_of_collectibles == mlx->n_check)
		{
			printf("down\n");
			mlx->direction = 3;
			// mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.player_closed, new_pos_x * SIZE, new_pos_y * SIZE);
			// mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.black_wall, mlx->player_pos_x * SIZE, mlx->player_pos_y * SIZE);
			// mlx->player_pos_x = new_pos_x;
			// mlx->player_pos_y = new_pos_y;
		}
	}
}

static void	ft_move_right(t_mlx_data *mlx, int new_pos_x, int new_pos_y)
{
	new_pos_x++;
	if (mlx->map[new_pos_y][new_pos_x] == 'C')
	{
		mlx->map[new_pos_y][new_pos_x] = '0';
		mlx->n_check++;
	}
	else if (mlx->map[new_pos_y][new_pos_x] != '1')
	{
		if (mlx->map[new_pos_y][new_pos_x] == 'E' && mlx->n_of_collectibles == mlx->n_check)
			ft_win();
		else if (mlx->map[new_pos_y][new_pos_x] != 'E' || mlx->n_of_collectibles == mlx->n_check)
		{
			printf("right\n");
			mlx->direction = 0;
				// mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.player_closed, new_pos_x * SIZE, new_pos_y * SIZE);
				// mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.black_wall, mlx->player_pos_x * SIZE, mlx->player_pos_y * SIZE);
				// mlx->player_pos_x = new_pos_x;
				// mlx->player_pos_y = new_pos_y;
		}
	}
}

static void	ft_move_left(t_mlx_data *mlx, int new_pos_x, int new_pos_y)
{
	new_pos_x--;
	if (mlx->map[new_pos_y][new_pos_x] == 'C')
	{
		mlx->map[new_pos_y][new_pos_x] = '0';
		mlx->n_check++;

	}
	else if (mlx->map[new_pos_y][new_pos_x] != '1')
	{
		if (mlx->map[new_pos_y][new_pos_x] == 'E' && mlx->n_of_collectibles == mlx->n_check)
			ft_win();
		else if (mlx->map[new_pos_y][new_pos_x] != 'E' || mlx->n_of_collectibles == mlx->n_check)
		{
			printf("left\n");
			mlx->direction = 2;
			// mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.player_closed, new_pos_x * SIZE, new_pos_y * SIZE);
			// mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.black_wall, mlx->player_pos_x * SIZE, mlx->player_pos_y * SIZE);
			// mlx->player_pos_x = new_pos_x;
			// mlx->player_pos_y = new_pos_y;
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
	if (keycode == XK_w)
		ft_move_up(mlx, new_pos_x, new_pos_y);
	if (keycode == XK_d)
		ft_move_right(mlx, new_pos_x, new_pos_y);
	if (keycode == XK_s)
		ft_move_down(mlx, new_pos_x, new_pos_y);
	if (keycode == XK_a)
		ft_move_left(mlx, new_pos_x, new_pos_y);
	return (0);
}