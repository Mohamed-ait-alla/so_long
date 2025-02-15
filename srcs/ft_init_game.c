/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:48:59 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/15 16:26:55 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	ft_win(t_mlx_data *mlx)
{
	ft_printf(B_CYAN "\n		╔══════════════════════════════════════╗\n");
	ft_printf(B_CYAN "		║        🎉 Congratulations! 🎉        ║\n");
	ft_printf(B_CYAN "		║           You Won the Game! 🎯💪     ║\n");
	ft_printf(B_CYAN "		╚══════════════════════════════════════╝\n\n" RST);
	ft_printf(B_GREEN "		╔══════════════════════════════════════╗\n");
	ft_printf(B_GREEN "		║   👨‍💻 Code Crafted with Passion by: ║\n");
	ft_printf(B_GREEN "		║            🌟 mait-all 🌟            ║\n");
	ft_printf(B_GREEN "		╠══════════════════════════════════════╣\n");
	ft_printf(B_GREEN "		║       Thank you for playing! 🎮      ║\n");
	ft_printf(B_GREEN "		╠══════════════════════════════════════╣\n");
	ft_printf(B_GREEN "		║              1  3  3  7              ║\n");
	ft_printf(B_GREEN "		╚══════════════════════════════════════╝\n\n" RST);
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
	if (!ft_check_sprites(mlx))
	{
		ft_printf(RED "Error\n: Failed to load sprites!\n" RST);
		ft_cleanup(mlx);
		exit(1);
	}
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
