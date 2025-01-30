/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:48:59 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/30 14:59:04 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_mlx_data *mlx)
{
	ft_printf("You Win!...\n");
	ft_cleanup(mlx);
	exit(1);
}

static	void	ft_load_player_actions_sprites(t_mlx_data *mlx, int size)
{
	mlx->player_actions[0][0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_closed.xpm", &size, &size);
	mlx->player_actions[0][1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_semi_right.xpm", &size, &size);
	mlx->player_actions[0][2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_open_right.xpm", &size, &size);
	mlx->player_actions[1][0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_closed.xpm", &size, &size);
	mlx->player_actions[1][1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_semi_up.xpm", &size, &size);
	mlx->player_actions[1][2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_open_up.xpm", &size, &size);
	mlx->player_actions[2][0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_closed.xpm", &size, &size);
	mlx->player_actions[2][1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_semi_left.xpm", &size, &size);
	mlx->player_actions[2][2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_open_left.xpm", &size, &size);
	mlx->player_actions[3][0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_closed.xpm", &size, &size);
	mlx->player_actions[3][1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_semi_down.xpm", &size, &size);
	mlx->player_actions[3][2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_open_down.xpm", &size, &size);
}

void	ft_load_sprites(t_mlx_data *mlx)
{
	int	size;

	size = SIZE;
	mlx->sprites.wall = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/others/wall.xpm", &size, &size);
	mlx->sprites.exit = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/others/exit.xpm", &size, &size);
	mlx->sprites.food = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/others/pacdot_food.xpm", &size, &size);
	mlx->sprites.black_wall = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/others/black.xpm", &size, &size);
	ft_load_player_actions_sprites(mlx, size);
}

static	void	ft_draw_map(t_mlx_data *mlx, int i, int j)
{
	if (mlx->map[i][j] == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
			mlx->sprites.wall, j * SIZE, i * SIZE);
	else if (mlx->map[i][j] == 'P')
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
			mlx->player_actions[0][0], j * SIZE, i * SIZE);
		mlx->player_pos_x = j;
		mlx->player_pos_y = i;
	}
	else if (mlx->map[i][j] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
			mlx->sprites.exit, j * SIZE, i * SIZE);
	else if (mlx->map[i][j] == 'C')
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
			mlx->sprites.food, j * SIZE, i * SIZE);
		mlx->n_of_collectibles++;
	}
}

void	ft_init_game(t_mlx_data *mlx)
{
	int			i;
	int			j;

	if (!ft_check_sprites(mlx))
	{
		ft_printf("failed to load sprites\n");
		exit(1);
	}
	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			ft_draw_map(mlx, i, j);
			j++;
		}
		i++;
	}
}
