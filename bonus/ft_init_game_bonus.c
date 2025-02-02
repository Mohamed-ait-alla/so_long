/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:48:59 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/02 14:36:46 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_win(t_mlx_data *mlx)
{
	ft_printf(CYAN_BOLD "\n		╔══════════════════════════════════════╗\n");
	ft_printf(CYAN_BOLD "		║        🎉 Congratulations! 🎉        ║\n");
	ft_printf(CYAN_BOLD "		║           You Won the Game! 🎯💪     ║\n");
	ft_printf(CYAN_BOLD "		╚══════════════════════════════════════╝\n\n" RESET);
	ft_printf(GREEN_BOLD "		╔══════════════════════════════════════╗\n");
	ft_printf(GREEN_BOLD "		║   👨‍💻 Code Crafted with Passion by: ║\n");
	ft_printf(GREEN_BOLD "		║            🌟 mait-all 🌟            ║\n");
	ft_printf(GREEN_BOLD "		╠══════════════════════════════════════╣\n");
	ft_printf(GREEN_BOLD "		║       Thank you for playing! 🎮      ║\n");
	ft_printf(GREEN_BOLD "		╠══════════════════════════════════════╣\n");
	ft_printf(GREEN_BOLD "		║              1  3  3  7              ║\n");
	ft_printf(GREEN_BOLD "		╚══════════════════════════════════════╝\n\n" RESET);
	ft_cleanup(mlx);
	exit(1);
}

void	ft_lose(t_mlx_data *mlx)
{
	ft_printf(RED_BOLD "\n   		    ╔══════════════════════════════╗\n");
	ft_printf(RED_BOLD "   		    ║          💀 Oops! 💀         ║\n");
	ft_printf(RED_BOLD "   		    ║   You're Noop, Game Over!    ║\n");
	ft_printf(RED_BOLD "   		    ╚══════════════════════════════╝\n\n" RESET);
	ft_printf(GREEN_BOLD "		╔══════════════════════════════════════╗\n");
	ft_printf(GREEN_BOLD "		║   👨‍💻 Code Crafted with Passion by: ║\n");
	ft_printf(GREEN_BOLD "		║            🌟 mait-all 🌟            ║\n");
	ft_printf(GREEN_BOLD "		╠══════════════════════════════════════╣\n");
	ft_printf(GREEN_BOLD "		║       Thank you for playing! 🎮      ║\n");
	ft_printf(GREEN_BOLD "		╠══════════════════════════════════════╣\n");
	ft_printf(GREEN_BOLD "		║              1  3  3  7              ║\n");
	ft_printf(GREEN_BOLD "		╚══════════════════════════════════════╝\n\n" RESET);
	ft_cleanup(mlx);
	exit(1);
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
	mlx->ghosts = malloc(mlx->n_of_ghosts * sizeof(t_ghost));
	if (!mlx->ghosts)
	{
		ft_printf(RED "Error\n: Failed to allocate memory for ghosts!\n");
		exit(1);
	}
}

static void	ft_draw_map(t_mlx_data *mlx, int i, int j, int x)
{
	if (mlx->map[i][j] == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
			mlx->sprites.wall, j * SIZE, i * SIZE);
	if (mlx->map[i][j] == 'P')
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
			mlx->player_actions[0][0], j * SIZE, i * SIZE);
		mlx->player_pos_x = j;
		mlx->player_pos_y = i;
	}
	if (mlx->map[i][j] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
			mlx->sprites.exit, j * SIZE, i * SIZE);
	if (mlx->map[i][j] == 'C')
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
			mlx->sprites.food, j * SIZE, i * SIZE);
		mlx->n_of_collectibles++;
	}
	if (mlx->map[i][j] == 'G')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window,
			mlx->sprites.ghost_up[x % 6], j * SIZE, i * SIZE);
}

void	ft_init_game(t_mlx_data *mlx)
{
	int			i;
	int			j;
	int			x;

	ft_calc_number_of_ghosts(mlx);
	i = 0;
	x = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			ft_draw_map(mlx, i, j, x);
			if (mlx->map[i][j] == 'G')
			{
				mlx->ghosts[x].n_pos_x = j;
				mlx->ghosts[x].n_pos_y = i;
				mlx->ghosts[x].old_pos_x = j;
				mlx->ghosts[x].old_pos_y = i;
				x++;
			}
			j++;
		}
		i++;
	}
}
