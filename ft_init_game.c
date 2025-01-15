/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:48:59 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/15 11:51:32 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_load_sprites(t_mlx_data *mlx)
{
	int	size;

	size = SIZE;
	mlx->sprites.wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/wall.xpm", &size, &size);
	mlx->sprites.player = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/pac_open_right.xpm", &size, &size);
	mlx->sprites.exit = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/exit.xpm", &size, &size);
	mlx->sprites.food = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/pacdot_food.xpm", &size, &size);
	mlx->sprites.black_wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/black.xpm", &size, &size);
}

void	ft_init_game(char **map, t_mlx_data *mlx)
{
	int			i;
	int			j;

	ft_load_sprites(mlx);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.wall, j * SIZE,i * SIZE);
			if (map[i][j] == 'P')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.player, j * SIZE, i * SIZE);
				mlx->player_pos_x = j;
				mlx->player_pos_y = i;
			}
			if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.exit, j * SIZE, i * SIZE);
			if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.food, j * SIZE, i * SIZE);
			j++;
		}
		
		i++;
	}
}