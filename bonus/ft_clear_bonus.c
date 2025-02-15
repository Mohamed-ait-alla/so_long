/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:34:43 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/15 16:28:04 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long_bonus.h"

void	ft_free_map(char **map, int i)
{
	while (i--)
		free(map[i]);
	free(map);
}

void	ft_free_window(t_mlx_data *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
}

static void	ft_cleanup_ghost_sprites(t_mlx_data *mlx)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (mlx->sprites.ghost_up[i])
			mlx_destroy_image(mlx->mlx_ptr, mlx->sprites.ghost_up[i]);
		if (mlx->sprites.ghost_down[i])
			mlx_destroy_image(mlx->mlx_ptr, mlx->sprites.ghost_down[i]);
		if (mlx->sprites.ghost_right[i])
			mlx_destroy_image(mlx->mlx_ptr, mlx->sprites.ghost_right[i]);
		if (mlx->sprites.ghost_left[i])
			mlx_destroy_image(mlx->mlx_ptr, mlx->sprites.ghost_left[i]);
		i++;
	}
}

static void	ft_cleanup_player_sprites(t_mlx_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			if (mlx->player_actions[i][j])
				mlx_destroy_image(mlx->mlx_ptr, mlx->player_actions[i][j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 11)
	{
		if (mlx->player_dying[i])
			mlx_destroy_image(mlx->mlx_ptr, mlx->player_dying[i]);
		i++;
	}
}

void	ft_cleanup(t_mlx_data *mlx)
{
	if (mlx->sprites.black_wall)
		mlx_destroy_image(mlx->mlx_ptr, mlx->sprites.black_wall);
	if (mlx->sprites.wall)
		mlx_destroy_image(mlx->mlx_ptr, mlx->sprites.wall);
	if (mlx->sprites.exit)
		mlx_destroy_image(mlx->mlx_ptr, mlx->sprites.exit);
	if (mlx->sprites.food)
		mlx_destroy_image(mlx->mlx_ptr, mlx->sprites.food);
	if (mlx->ghosts)
		free(mlx->ghosts);
	ft_cleanup_player_sprites(mlx);
	ft_cleanup_ghost_sprites(mlx);
	ft_free_map(mlx->map, mlx->r_map_len);
	ft_free_window(mlx);
}
