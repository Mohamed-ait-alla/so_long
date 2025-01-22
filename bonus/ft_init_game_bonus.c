/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:48:59 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/22 10:21:05 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_win()
{
	ft_printf("You Win!...\n");
	exit(1);
}


static void	ft_load_sprites(t_mlx_data *mlx)
{
	int	size;

	size = SIZE;
	mlx->sprites.wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/wall.xpm", &size, &size);
	mlx->sprites.exit = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/exit.xpm", &size, &size);
	mlx->sprites.food = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/pacdot_food.xpm", &size, &size);
	mlx->sprites.black_wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/black.xpm", &size, &size);
	mlx->sprites.ghost_up = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghost_up1.xpm", &size, &size);
}

void	ft_init_game(t_mlx_data *mlx)
{
	int			i;
	int			j;

	ft_load_sprites(mlx);
	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.wall, j * SIZE,i * SIZE);
			if (mlx->map[i][j] == 'P')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->player_actions[0][0], j * SIZE, i * SIZE);
				mlx->player_pos_x = j;
				mlx->player_pos_y = i;
			}
			if (mlx->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.exit, j * SIZE, i * SIZE);
			if (mlx->map[i][j] == 'C')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.food, j * SIZE, i * SIZE);
				mlx->n_of_collectibles++;
			}
			if (mlx->map[i][j] == 'G')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.ghost_up, j * SIZE, i * SIZE);
				mlx->ghost_pos_x = j;
				mlx->ghost_pos_y = i;
			}
			j++;
		}
		i++;
	}
}