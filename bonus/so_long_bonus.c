/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:01:59 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/31 15:21:01 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_mlx_list(t_mlx_data *mlx)
{
	mlx->n_of_collectibles = 0;
	mlx->n_of_moves = 0;
	mlx->n_check = 0;
	mlx->direction = 0;
	mlx->n_of_ghosts = 0;
	mlx->wanted_ghost = 0;
	mlx->is_died = 1;
	mlx->c_map_len = 0;
	mlx->r_map_len = 0;
}

int close_window_with_x(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(1); // exit with success
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx_data	mlx;
	t_frame		frame;
	
	if (ac != 2)
		return (0);
	
	ft_calc_width_and_height(av[1], &frame);
	mlx.r_map_len = frame.n_row;
	mlx.c_map_len = frame.n_col;
	mlx.map = ft_read_map(av[1], &frame);
	ft_check_error_map(mlx.map, frame);
	ft_check_path(&mlx, frame);
	mlx.mlx_ptr = mlx_init();
	ft_load_sprites(&mlx);
	mlx.mlx_window = mlx_new_window(mlx.mlx_ptr, (frame.n_col - 1) * SIZE, frame.n_row * SIZE, "so_long");
	ft_init_mlx_list(&mlx);
	ft_init_game(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, ft_animation,&mlx);
	mlx_hook(mlx.mlx_window, 17, 0, close_window_with_x, &mlx);
	mlx_hook(mlx.mlx_window, 2, 1L << 0, ft_move_player, &mlx);
	// mlx_key_hook(mlx.mlx_window, ft_move_player, &mlx);w
	mlx_loop(mlx.mlx_ptr);
}