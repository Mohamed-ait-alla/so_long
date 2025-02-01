/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_sprites_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:39:37 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/01 09:41:07 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	void	ft_load_ghost_right_and_left_sprites(t_mlx_data *mlx, int size)
{
	mlx->sprites.ghost_right[0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/blue_ghosts/ghost_right.xpm", &size, &size);
	mlx->sprites.ghost_right[1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/green_ghosts/ghost_right.xpm", &size, &size);
	mlx->sprites.ghost_right[2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/red_ghosts/ghost_right.xpm", &size, &size);
	mlx->sprites.ghost_right[3] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/yellow_ghosts/ghost_right.xpm", &size, &size);
	mlx->sprites.ghost_right[4] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/orange_ghosts/ghost_right.xpm", &size, &size);
	mlx->sprites.ghost_right[5] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/pink_ghosts/ghost_right.xpm", &size, &size);
	mlx->sprites.ghost_left[0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/blue_ghosts/ghost_left.xpm", &size, &size);
	mlx->sprites.ghost_left[1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/green_ghosts/ghost_left.xpm", &size, &size);
	mlx->sprites.ghost_left[2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/red_ghosts/ghost_left.xpm", &size, &size);
	mlx->sprites.ghost_left[3] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/yellow_ghosts/ghost_left.xpm", &size, &size);
	mlx->sprites.ghost_left[4] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/orange_ghosts/ghost_left.xpm", &size, &size);
	mlx->sprites.ghost_left[5] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/pink_ghosts/ghost_left.xpm", &size, &size);
}

static	void	ft_load_ghost_up_and_down_sprites(t_mlx_data *mlx, int size)
{
	mlx->sprites.ghost_up[0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/blue_ghosts/ghost_up.xpm", &size, &size);
	mlx->sprites.ghost_up[1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/green_ghosts/ghost_up.xpm", &size, &size);
	mlx->sprites.ghost_up[2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/red_ghosts/ghost_up.xpm", &size, &size);
	mlx->sprites.ghost_up[3] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/yellow_ghosts/ghost_up.xpm", &size, &size);
	mlx->sprites.ghost_up[4] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/orange_ghosts/ghost_up.xpm", &size, &size);
	mlx->sprites.ghost_up[5] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/pink_ghosts/ghost_up.xpm", &size, &size);
	mlx->sprites.ghost_down[0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/blue_ghosts/ghost_down.xpm", &size, &size);
	mlx->sprites.ghost_down[1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/green_ghosts/ghost_down.xpm", &size, &size);
	mlx->sprites.ghost_down[2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/red_ghosts/ghost_down.xpm", &size, &size);
	mlx->sprites.ghost_down[3] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/yellow_ghosts/ghost_down.xpm", &size, &size);
	mlx->sprites.ghost_down[4] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/orange_ghosts/ghost_down.xpm", &size, &size);
	mlx->sprites.ghost_down[5] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/ghosts/pink_ghosts/ghost_down.xpm", &size, &size);
}

static	void	ft_load_player_dying_sprites(t_mlx_data *mlx, int size)
{
	mlx->player_dying[0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_dying/pacman_dying1.xpm", &size, &size);
	mlx->player_dying[1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_dying/pacman_dying2.xpm", &size, &size);
	mlx->player_dying[2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_dying/pacman_dying3.xpm", &size, &size);
	mlx->player_dying[3] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_dying/pacman_dying4.xpm", &size, &size);
	mlx->player_dying[4] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_dying/pacman_dying5.xpm", &size, &size);
	mlx->player_dying[5] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_dying/pacman_dying6.xpm", &size, &size);
	mlx->player_dying[6] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_dying/pacman_dying7.xpm", &size, &size);
	mlx->player_dying[7] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_dying/pacman_dying8.xpm", &size, &size);
	mlx->player_dying[8] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_dying/pacman_dying9.xpm", &size, &size);
	mlx->player_dying[9] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_dying/pacman_dying10.xpm", &size, &size);
	mlx->player_dying[10] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/player/pac_dying/pacman_woosh.xpm", &size, &size);
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
	ft_load_player_dying_sprites(mlx, size);
	ft_load_ghost_up_and_down_sprites(mlx, size);
	ft_load_ghost_right_and_left_sprites(mlx, size);
	if (!ft_check_sprites(mlx))
	{
		ft_printf("Error\n: Failed to load sprites!\n");
		exit(1);
	}
}
