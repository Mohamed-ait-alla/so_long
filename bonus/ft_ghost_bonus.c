/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghost_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:31:44 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/15 16:28:00 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long_bonus.h"

int	ft_can_move_toward_player(t_mlx_data *mlx, int ghost_index,
								int P_new_pos_x, int P_new_pos_y)
{
	int	ghost_x;
	int	ghost_y;

	ghost_x = mlx->ghosts[ghost_index].o_pos_x;
	ghost_y = mlx->ghosts[ghost_index].o_pos_y;
	if (P_new_pos_x < ghost_x && mlx->map[ghost_y][ghost_x - 1] != '1'
		&& mlx->map[ghost_y][ghost_x - 1] != 'E')
		return (1);
	if (P_new_pos_x > ghost_x && mlx->map[ghost_y][ghost_x + 1] != '1'
		&& mlx->map[ghost_y][ghost_x + 1] != 'E')
		return (1);
	if (P_new_pos_y < ghost_y && mlx->map[ghost_y - 1][ghost_x] != '1'
		&& mlx->map[ghost_y - 1][ghost_x] != 'E')
		return (1);
	if (P_new_pos_y > ghost_y && mlx->map[ghost_y + 1][ghost_x] != '1'
		&& mlx->map[ghost_y + 1][ghost_x] != 'E')
		return (1);
	return (0);
}

static int	ft_check(t_mlx_data *mlx, int wanted)
{
	if (wanted != -1)
	{
		mlx->wanted_ghost = wanted;
		return (0);
	}
	return (1);
}

int	ft_check_distance_with_ghosts(t_mlx_data *mlx,
								int P_new_pos_x, int P_new_pos_y)
{
	int	i;
	int	wanted;
	int	min_distance;
	int	distance;

	wanted = -1;
	min_distance = -1;
	i = 0;
	while (i < mlx->n_of_ghosts)
	{
		distance = (abs(mlx->ghosts[i].o_pos_x - P_new_pos_x)
				+ abs(mlx->ghosts[i].o_pos_y - P_new_pos_y));
		if (distance == 0)
			mlx->is_died = 0;
		if (distance < 4 && ((min_distance == -1 || distance < min_distance)
				&& ft_can_move_toward_player(mlx, i, P_new_pos_x, P_new_pos_y)))
		{
			min_distance = distance;
			wanted = i;
		}
		i++;
	}
	return (ft_check(mlx, wanted));
}
