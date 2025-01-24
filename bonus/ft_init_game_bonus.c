/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:48:59 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/24 10:23:41 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_win()
{
	ft_printf("You Win!...\n");
	exit(1);
}

void	ft_lose()
{
	ft_printf("Oops! You Lose...");
	exit(1);
}


static void	ft_load_sprites(t_mlx_data *mlx)
{
	int	size;

	size = SIZE;
	mlx->sprites.wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/wall.xpm", &size, &size); // if (image == NULL) return error;
	mlx->sprites.exit = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/exit.xpm", &size, &size);
	mlx->sprites.food = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/pacdot_food.xpm", &size, &size);
	mlx->sprites.black_wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/black.xpm", &size, &size);
	mlx->sprites.ghost_up = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghost_up1.xpm", &size, &size);
	mlx->sprites.ghost_down = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghost_down1.xpm", &size, &size);
	mlx->sprites.ghost_right = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghost_right1.xpm", &size, &size);
	mlx->sprites.ghost_left = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghost_left1.xpm", &size, &size);
	mlx->sprites.ghost_panic1 = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/ghost_right2.xpm", &size, &size);
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

	ft_load_sprites(mlx);
	ft_calc_number_of_ghosts(mlx);
	printf("n=%d\n", mlx->n_of_ghosts);
	mlx->ghosts = malloc(mlx->n_of_ghosts * sizeof(t_ghost));
	if (!mlx->ghosts)
	{
		printf("failed to allocate memory for ghosts!\n");
		exit(1);
	}
	
	i = 0;
	x = 0;
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
				mlx->ghosts[x].n_pos_x = j;
				mlx->ghosts[x].n_pos_y = i;                                                                                                                                                                                                                                                  
				mlx->ghosts[x].old_pos_x = j;                                                                                                                                                                                                                                                  
				mlx->ghosts[x].old_pos_y = i; 
				mlx->ghosts[x].direction = 0;
				mlx->ghosts[x].c_sprite = mlx->sprites.ghost_up;
				mlx->ghosts[x].c_frame = 0;
				x++;                                                                                                                                                                                                                                               
			}
			j++;
		}
		i++;
	}
}