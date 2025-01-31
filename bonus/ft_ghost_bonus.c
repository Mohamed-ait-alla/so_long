/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghost_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:31:44 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/31 15:23:09 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_distance_with_ghosts(t_mlx_data *mlx, int P_new_pos_x, int P_new_pos_y)
{
	int	i;
	i = 0;

	while (i < mlx->n_of_ghosts)
	{
		if ((abs(mlx->ghosts[i].old_pos_x - P_new_pos_x) + abs(mlx->ghosts[i].old_pos_y - P_new_pos_y)) == 0)
			mlx->is_died = 0;
		if ((abs(mlx->ghosts[i].old_pos_x - P_new_pos_x) + abs(mlx->ghosts[i].old_pos_y - P_new_pos_y)) < 3)
		{
			mlx->wanted_ghost = i;	
			return (0);
		}
		i++;	
	}
	
	return(1);
}

static void	ft_set_ghost_directions(t_mlx_data *mlx, int i)
{
	int	diff_x;
	int	diff_y;

	diff_x = mlx->player_pos_x - mlx->ghosts[i].old_pos_x;
	diff_y = mlx->player_pos_y - mlx->ghosts[i].old_pos_y;
	if (abs(diff_x) > abs(diff_y))
	{
		if (diff_x > 0 && mlx->map[mlx->ghosts[i].old_pos_y][mlx->ghosts[i].old_pos_x + 1] != '1')
			mlx->ghosts[i].n_pos_x++;
		else if (diff_x < 0 && mlx->map[mlx->ghosts[i].old_pos_y][mlx->ghosts[i].old_pos_x - 1] != '1')
			mlx->ghosts[i].n_pos_x--;
	}
	else
	{
		if (diff_y > 0 && mlx->map[mlx->ghosts[i].old_pos_y + 1][mlx->ghosts[i].old_pos_x] != '1')
			mlx->ghosts[i].n_pos_y++;
		else if (diff_y < 0 && mlx->map[mlx->ghosts[i].old_pos_y - 1][mlx->ghosts[i].old_pos_x] != '1')
			mlx->ghosts[i].n_pos_y--;
	}
}

static void ft_chase_player(t_mlx_data *mlx)
{
    int i;

    i = 0;
    while (i < mlx->n_of_ghosts)
    {
        if (mlx->wanted_ghost == i)
        {
			ft_set_ghost_directions(mlx, i);
            if (mlx->map[mlx->ghosts[i].old_pos_y][mlx->ghosts[i].old_pos_x] == 'C')
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.food,
					mlx->ghosts[i].old_pos_x * SIZE, mlx->ghosts[i].old_pos_y * SIZE);
            else
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.black_wall,
					mlx->ghosts[i].old_pos_x * SIZE, mlx->ghosts[i].old_pos_y * SIZE);
            mlx->ghosts[i].old_pos_x = mlx->ghosts[i].n_pos_x;
            mlx->ghosts[i].old_pos_y = mlx->ghosts[i].n_pos_y;
            mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.ghost_left[i % 6],
				mlx->ghosts[i].n_pos_x * SIZE, mlx->ghosts[i].n_pos_y * SIZE);
        }
        i++;
    }
}

static	void	ft_draw_ghost_animation(t_mlx_data *mlx, int i, int j)
{
	if (i == 59999)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.ghost_right[j % 6],
			mlx->ghosts[j].old_pos_x * SIZE, mlx->ghosts[j].old_pos_y * SIZE);
	else if (i == 69990)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.ghost_down[j % 6], 
			mlx->ghosts[j].old_pos_x * SIZE, mlx->ghosts[j].old_pos_y  * SIZE);
	else if (i == 89999)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.ghost_left[j % 6], 
			mlx->ghosts[j].old_pos_x * SIZE, mlx->ghosts[j].old_pos_y  * SIZE);
}

void	ft_ghost_animation(t_mlx_data *mlx)
{
	static int i = 0;
	int j = 0;
	i++;

	if (!mlx->is_died)
		return ;
	if (!ft_check_distance_with_ghosts(mlx, mlx->player_pos_x, mlx->player_pos_y))
	{
		if (i == 1000)
			ft_chase_player(mlx);
	}
	while (j < mlx->n_of_ghosts)
	{
		ft_draw_ghost_animation(mlx, i, j);
		j++;
	}
	if (i == 89999)
		i = 0;
}