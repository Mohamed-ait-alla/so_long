/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:50:37 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/02 12:34:37 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	void	ft_draw_ghost_animation(t_mlx_data *mlx, int i, int j)
{
	if (i == 59999)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
			mlx->sprites.ghost_right[j % 6], mlx->ghosts[j].old_pos_x * SIZE,
			mlx->ghosts[j].old_pos_y * SIZE);
	else if (i == 69990)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
			mlx->sprites.ghost_down[j % 6], mlx->ghosts[j].old_pos_x * SIZE,
			mlx->ghosts[j].old_pos_y * SIZE);
	else if (i == 89999)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
			mlx->sprites.ghost_left[j % 6], mlx->ghosts[j].old_pos_x * SIZE,
			mlx->ghosts[j].old_pos_y * SIZE);
}

void	ft_ghost_animation(t_mlx_data *mlx)
{
	static int	i = 0;
	int			j;

	i++;
	j = 0;
	if (!mlx->is_died)
		return ;
	if (!ft_check_distance_with_ghosts(mlx,
			mlx->player_pos_x, mlx->player_pos_y))
	{
		if (i == 100)
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
