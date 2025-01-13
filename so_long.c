/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:01:59 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/13 09:26:57 by mait-all         ###   ########.fr       */
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

int	main()
{
	t_mlx_data	mlx;
	t_img_data	img;
	int w, h;

	mlx.mlx_ptr = mlx_init();
	mlx.mlx_window = mlx_new_window(mlx.mlx_ptr, 500, 250, "first window");
	img.relative_path = "./textures/wall.xpm";
	img.img  = mlx_xpm_file_to_image(mlx.mlx_ptr, img.relative_path, &w, &h);
	img.relative_path = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_window, img.img, 0, 0);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_window, img.img, 20, 0);
	mlx_hook(mlx.mlx_window, 17, 0, close_window_with_x, &mlx);
	mlx_key_hook(mlx.mlx_window, close_window_with_esc, &mlx);
	mlx_loop(mlx.mlx_ptr);
}