/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:01:59 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/13 17:13:52 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	close_window_with_esc(int keysymbol, t_mlx_data	*data)
{
	if (keysymbol == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	return (0);
}

int close_window_with_x(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0); // exit with success
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx_data	mlx;
	t_img_data	img;
	t_frame		frame;
	
	if (ac != 2)
		return (0);
	ft_calc_width_and_height(av[1], &frame);
	mlx.mlx_ptr = mlx_init();
	mlx.mlx_window = mlx_new_window(mlx.mlx_ptr, frame.n_col * SIZE, frame.n_row * SIZE, "first window");
	ft_init_game(av[1], &mlx);
	mlx_hook(mlx.mlx_window, 17, 0, close_window_with_x, &mlx);
	mlx_key_hook(mlx.mlx_window, close_window_with_esc, &mlx);
	mlx_loop(mlx.mlx_ptr);
}