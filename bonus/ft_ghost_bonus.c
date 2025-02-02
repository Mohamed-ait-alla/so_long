/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghost_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:31:44 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/02 12:24:37 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_distance_with_ghosts(t_mlx_data *mlx,
								int P_new_pos_x, int P_new_pos_y)
{
	int	i;

	i = 0;
	while (i < mlx->n_of_ghosts)
	{
		if ((abs(mlx->ghosts[i].old_pos_x - P_new_pos_x)
				+ abs(mlx->ghosts[i].old_pos_y - P_new_pos_y)) == 0)
			mlx->is_died = 0;
		if ((abs(mlx->ghosts[i].old_pos_x - P_new_pos_x)
				+ abs(mlx->ghosts[i].old_pos_y - P_new_pos_y)) < 3)
		{
			mlx->wanted_ghost = i;
			return (0);
		}
		i++;
	}
	return (1);
}

static void	ft_set_ghost_directions_diagonal(t_mlx_data *mlx, int i, int dx, int dy)
{
	if (dx > 0 && mlx->map[mlx->ghosts[i].old_pos_y][mlx->ghosts[i].old_pos_x + 1] != '1')
		mlx->ghosts[i].n_pos_x++;
    else if (dx < 0 && mlx->map[mlx->ghosts[i].old_pos_y][mlx->ghosts[i].old_pos_x - 1] != '1')
         mlx->ghosts[i].n_pos_x--;
	else if (dy > 0 && mlx->map[mlx->ghosts[i].old_pos_y + 1][mlx->ghosts[i].old_pos_x] != '1')
		mlx->ghosts[i].n_pos_y++;
	else if (dy < 0 && mlx->map[mlx->ghosts[i].old_pos_y - 1][mlx->ghosts[i].old_pos_x] != '1')
		mlx->ghosts[i].n_pos_y--;
}

static void	ft_set_ghost_directions_cardinal(t_mlx_data *mlx, int i, int dx, int dy)
{
	if (abs(dx) >= abs(dy))
	{
		if (dx > 0 && mlx->map[mlx->ghosts[i].old_pos_y][mlx->ghosts[i].old_pos_x + 1] != '1')
			mlx->ghosts[i].n_pos_x++;
		else if (dx < 0 && mlx->map[mlx->ghosts[i].old_pos_y][mlx->ghosts[i].old_pos_x - 1] != '1')
			mlx->ghosts[i].n_pos_x--;
	}
	else
	{
		if (dy > 0 && mlx->map[mlx->ghosts[i].old_pos_y + 1][mlx->ghosts[i].old_pos_x] != '1')
			mlx->ghosts[i].n_pos_y++;
		else if (dy < 0 && mlx->map[mlx->ghosts[i].old_pos_y - 1][mlx->ghosts[i].old_pos_x] != '1')
			mlx->ghosts[i].n_pos_y--;
    }	
}

static void ft_set_ghost_directions(t_mlx_data *mlx, int i)
{
	int dx;
	int dy;

	dx = mlx->player_pos_x - mlx->ghosts[i].old_pos_x;
	dy = mlx->player_pos_y - mlx->ghosts[i].old_pos_y;
	if (abs(dx) <= 1 && abs(dy) <= 1)
		ft_set_ghost_directions_diagonal(mlx, i, dx, dy);
	else
		ft_set_ghost_directions_cardinal(mlx, i, dx, dy);
}

void	ft_chase_player(t_mlx_data *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->n_of_ghosts)
	{
		if (mlx->wanted_ghost == i)
		{
			ft_set_ghost_directions(mlx, i);
			if (mlx->map[mlx->ghosts[i].old_pos_y][mlx->ghosts[i].old_pos_x]
				== 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
					mlx->sprites.food, mlx->ghosts[i].old_pos_x * SIZE,
					mlx->ghosts[i].old_pos_y * SIZE);
			else
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
					mlx->sprites.black_wall, mlx->ghosts[i].old_pos_x * SIZE,
					mlx->ghosts[i].old_pos_y * SIZE);
			mlx->ghosts[i].old_pos_x = mlx->ghosts[i].n_pos_x;
			mlx->ghosts[i].old_pos_y = mlx->ghosts[i].n_pos_y;
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
				mlx->sprites.ghost_left[i % 6], mlx->ghosts[i].n_pos_x * SIZE,
				mlx->ghosts[i].n_pos_y * SIZE);
		}
		i++;
	}
}
