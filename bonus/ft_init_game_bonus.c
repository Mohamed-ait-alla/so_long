/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:48:59 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/25 11:12:45 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_win()
{
	ft_printf("\n╔══════════════════════════════════════════╗\n");
	ft_printf("║         🎉 Congratulations! 🎉           ║\n");
	ft_printf("║     You're Boss, You Won the Game! 🎯    ║\n");
	ft_printf("╚══════════════════════════════════════════╝\n\n");
	ft_printf("\n╔══════════════════════════════════════╗\n");
	ft_printf("║   👨‍💻 Code Crafted with Passion by: ║\n");
	ft_printf("║            \033[1m🌟 mait-all 🌟\033[0m            ║\n");
	ft_printf("╠══════════════════════════════════════╣\n");
	ft_printf("║       Thank you for playing! 🎮      ║\n");
	ft_printf("╚══════════════════════════════════════╝\n\n");
	exit(1);
}

void	ft_lose()
{
	ft_printf("\n╔══════════════════════════════╗\n");
	ft_printf("║          💀 Oops! 💀         ║\n");
	ft_printf("║   You're Noop, Game Over!    ║\n");
	ft_printf("╚══════════════════════════════╝\n\n");
	ft_printf("\n╔══════════════════════════════════════╗\n");
	ft_printf("║   👨‍💻 Code Crafted with Passion by: ║\n");
	ft_printf("║            \033[1m🌟 mait-all 🌟\033[0m            ║\n");
	ft_printf("╠══════════════════════════════════════╣\n");
	ft_printf("║       Thank you for playing! 🎮      ║\n");
	ft_printf("╚══════════════════════════════════════╝\n\n");
	exit(1);
}


static void	ft_load_sprites(t_mlx_data *mlx)
{
	int	size;

	size = SIZE;
	mlx->sprites.wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/others/wall.xpm", &size, &size); // if (image == NULL) return error;
	mlx->sprites.exit = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/others/exit.xpm", &size, &size);
	mlx->sprites.food = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/others/pacdot_food.xpm", &size, &size);
	mlx->sprites.black_wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/others/black.xpm", &size, &size);
	mlx->sprites.ghost_up[0] = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghosts/blue_ghosts/ghost_up.xpm", &size, &size);
	mlx->sprites.ghost_up[1] = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghosts/green_ghosts/ghost_up.xpm", &size, &size);
	mlx->sprites.ghost_up[2] = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghosts/red_ghosts/ghost_up.xpm", &size, &size);
	mlx->sprites.ghost_up[3] = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghosts/yellow_ghosts/ghost_up.xpm", &size, &size);
	mlx->sprites.ghost_down[0] = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghosts/blue_ghosts/ghost_down.xpm", &size, &size);
	mlx->sprites.ghost_down[1] = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghosts/green_ghosts/ghost_down.xpm", &size, &size);
	mlx->sprites.ghost_down[2] = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghosts/red_ghosts/ghost_down.xpm", &size, &size);
	mlx->sprites.ghost_down[3] = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghosts/yellow_ghosts/ghost_down.xpm", &size, &size);
	mlx->sprites.ghost_right[0] = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghosts/blue_ghosts/ghost_right.xpm", &size, &size);
	mlx->sprites.ghost_right[1] = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghosts/green_ghosts/ghost_right.xpm", &size, &size);
	mlx->sprites.ghost_right[2] = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghosts/red_ghosts/ghost_right.xpm", &size, &size);
	mlx->sprites.ghost_right[3] = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghosts/yellow_ghosts/ghost_right.xpm", &size, &size);
	mlx->sprites.ghost_left[0] = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghosts/blue_ghosts/ghost_left.xpm", &size, &size);
	mlx->sprites.ghost_left[1] = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghosts/green_ghosts/ghost_left.xpm", &size, &size);
	mlx->sprites.ghost_left[2] = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghosts/red_ghosts/ghost_left.xpm", &size, &size);
	mlx->sprites.ghost_left[3] = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghosts/yellow_ghosts/ghost_left.xpm", &size, &size);
}

static void	ft_calc_number_of_ghosts(t_mlx_data *mlx)
{
	int	i;
	int	j;
	
	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'G')
				mlx->n_of_ghosts++;
			j++;
		}
		i++;
	}
}

void	ft_init_game(t_mlx_data *mlx)
{
	int			i;
	int			j;
	int			x;
	int			y;

	ft_load_sprites(mlx);
	ft_calc_number_of_ghosts(mlx);
	mlx->ghosts = malloc(mlx->n_of_ghosts * sizeof(t_ghost));
	if (!mlx->ghosts)
	{
		printf("failed to allocate memory for ghosts!\n");
		exit(1);
	}
	
	i = 0;
	x = 0;
	y = 0;
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
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.ghost_up[y], j * SIZE, i * SIZE);
				mlx->ghosts[x].n_pos_x = j;
				mlx->ghosts[x].n_pos_y = i;                                                                                                                                                                                                                                                  
				mlx->ghosts[x].old_pos_x = j;                                                                                                                                                                                                                                                  
				mlx->ghosts[x].old_pos_y = i;
				mlx->ghosts[x].c_index = y;
				x++; 
				y++;
				if (y > 4)
					y = 0;                                                                                                                                                                                                                                             
			}
			j++;
		}
		i++;
	}
}