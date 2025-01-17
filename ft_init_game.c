/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:48:59 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/17 11:44:35 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win()
{
	printf("You Win!...\n");
	exit(1);
}


static void	ft_load_sprites(t_mlx_data *mlx)
{
	int	size;

	size = SIZE;
	mlx->sprites.wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/wall.xpm", &size, &size);
	mlx->sprites.player_closed = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/pac_closed.xpm", &size, &size);
	mlx->sprites.player_right_open = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/pac_open_right.xpm", &size, &size);
	mlx->sprites.player_left_open = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/pac_open_left.xpm", &size, &size);
	mlx->sprites.player_up_open = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/pac_open_up.xpm", &size, &size);
	mlx->sprites.player_down_open = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/pac_open_down.xpm", &size, &size);
	mlx->sprites.player_semi_up = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/pac_semi_up.xpm", &size, &size);
	mlx->sprites.player_semi_down = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/pac_semi_down.xpm", &size, &size);
	mlx->sprites.player_semi_right = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/pac_semi_right.xpm", &size, &size);
	mlx->sprites.player_semi_left = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/pac_semi_left.xpm", &size, &size);
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
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.player_closed, j * SIZE, i * SIZE);
				mlx->player_pos_x = j;
				mlx->player_pos_y = i;
			}
			if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.exit, j * SIZE, i * SIZE);
			if (map[i][j] == 'C')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.food, j * SIZE, i * SIZE);
				mlx->n_of_collectibles++;
			}
			j++;
		}
		i++;
	}
}