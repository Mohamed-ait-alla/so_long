/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:50:37 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/15 16:28:29 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long_bonus.h"

void	ft_player_dying_animation(t_mlx_data *mlx)
{
	static int	frame = 0;
	static int	delay = 0;

	if (mlx->is_died == 0)
	{
		if (delay++ % 15000 == 0)
		{
			if (frame < 10)
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
					mlx->player_dying[frame], mlx->player_pos_x * SIZE,
					mlx->player_pos_y * SIZE);
				frame++;
			}
			else
				ft_lose(mlx);
		}
	}
}

static	void	ft_draw_ghost_animation(t_mlx_data *mlx, int i, int j)
{
	if (i == 59999)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
			mlx->sprites.ghost_right[j % 6], mlx->ghosts[j].o_pos_x * SIZE,
			mlx->ghosts[j].o_pos_y * SIZE);
	else if (i == 69990)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
			mlx->sprites.ghost_down[j % 6], mlx->ghosts[j].o_pos_x * SIZE,
			mlx->ghosts[j].o_pos_y * SIZE);
	else if (i == 89999)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
			mlx->sprites.ghost_left[j % 6], mlx->ghosts[j].o_pos_x * SIZE,
			mlx->ghosts[j].o_pos_y * SIZE);
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
		if (i == 6)
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

int	ft_animation(t_mlx_data *mlx)
{
	static int	frame_counter = 0;
	static int	frame_index = 0;

	ft_ghost_animation(mlx);
	ft_player_dying_animation(mlx);
	if (!mlx->is_died)
		return (0);
	frame_counter++;
	if (frame_counter >= 15000)
	{
		frame_index = (frame_index + 1) % 3;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
			mlx->player_actions[mlx->direction][frame_index],
			mlx->player_pos_x * SIZE, mlx->player_pos_y * SIZE);
		frame_counter = 0;
	}
	return (0);
}
