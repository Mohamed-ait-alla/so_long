/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:01:59 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/30 11:13:37 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_init_helper(t_mlx_data *mlx, int size)
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

static	void	ft_init_mlx_list(t_mlx_data *mlx)
{
	int	size;

	size = SIZE;
	mlx->n_of_collectibles = 0;
	mlx->n_of_moves = 0;
	mlx->n_check = 0;
	mlx->direction = 0;
	mlx->map_len = 0;
	ft_init_helper(mlx, size);
}

int	close_window_with_x(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(1);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx_data	mlx;
	t_frame		frame;

	if (ac != 2)
		return (0);
	ft_bzero(&mlx, sizeof(t_mlx_data));
	check_file_extention(av[1]);
	ft_calc_width_and_height(av[1], &frame);
	mlx.map_len = frame.n_row;
	mlx.map = ft_read_map(av[1], &frame);
	ft_check_error_map(mlx.map, frame);
	ft_check_path(&mlx, frame);
	mlx.mlx_ptr = mlx_init();
	mlx.mlx_window = mlx_new_window(mlx.mlx_ptr,
			(frame.n_col - 1) * SIZE, frame.n_row * SIZE, "so_long");
	ft_load_sprites(&mlx);
	ft_init_mlx_list(&mlx);
	ft_init_game(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, ft_animation, &mlx);
	mlx_hook(mlx.mlx_window, 17, 0, close_window_with_x, &mlx);
	mlx_key_hook(mlx.mlx_window, ft_move_player, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
